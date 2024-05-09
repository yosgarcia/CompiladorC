#include "preprocessor.h"
#include <stdio.h>

/*
 * Funcion que se encarga de iniciar el preprocesamiento
 * @param source_file: archivo fuente
 */
void start_preprocess(const char* source_file) {
    const char* temp_file = "temp.tmp";
    const char* final_file = "processedfile.c";
    pre_process(source_file, temp_file,final_file);

    printf("Preprocesamiento completado. Archivo procesado final: <%s>.\n", final_file);
}

/*
 * Funcion que se encarga de preprocesar un archivo fuente
 * @param filename: nombre del archivo fuente
 * @param temp_file: nombre del archivo temporal
 * @param final_file: nombre del archivo final ya preprocesado
*/
void pre_process(const char* filename, const char* temp_file, const char* final_file){
    FILE *output_file = fopen(temp_file, "w");
    if (output_file == NULL) {
        printf("Error al abrir el archivo temporal <%s>.\n", temp_file);
        return exit(1);
    }
    linkedList* macros = create_list();
    
    process_file(filename,output_file,macros);
    fclose(output_file);
    //reemplazar macros
    replace_macros(temp_file,macros,final_file);
}

/*
 * Funcion que se encarga de procesar un archivo fuente
 * @param filename: nombre del archivo fuente
 * @param output_file: archivo de salida
 * @param macros: lista de macros que se encuentren
 */
void process_file(const char *filename, FILE *output_file, linkedList* macros) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error al abrir el archivo fuente <%s>.\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int deletetabs = 0;
    while (fgets(line, sizeof(line), input_file)) {
        if (strncmp(line, "#include", strlen("#include")) == 0) {
            //inicia con #include
            char include_file[MAX_LINE_LENGTH];
            //scanear el nombre del archivo, que debe ir entre comillas
            sscanf(line, "#include \"%[^\"]\"", include_file);
            // Procesar el archivo incluido recursivamente
            process_include(include_file, output_file, macros);
        }
          else if (strncmp(line, "#define", strlen("#define")) == 0) {
            //inicia con #define
            read_define(line, output_file, macros);
        } else {
            //No inicia con define o include
            // Unir lineas cuando hay salto de linea con \ al final
            if (deletetabs){
                char line2[MAX_LINE_LENGTH];
                for (int i = 0;i<MAX_LINE_LENGTH;i++){
                    line2[i] = '\0';
                }
                int pos_to_put_char = 0;
                int terminar_borrar = 0;
                for(int i=0;i<strlen(line);i++){
                    if (line[i]!='\t' && line[i]!=' '){
                        line2[pos_to_put_char]=line[i];
                        pos_to_put_char++;
                        terminar_borrar = 1;
                    }
                    else{
                        if (terminar_borrar){
                            line2[pos_to_put_char]=line[i];
                            pos_to_put_char++;
                        }
                    }
                }
                for (int i=0;i<MAX_LINE_LENGTH;i++){
                    line[i]='\0';
                }
                for (int i=0;i<strlen(line2);i++){
                    line[i]=line2[i];
                }
            }
            
            if (line[strlen(line)-2] == '\\'){
                line[strlen(line)-2] = '\0';
                fprintf(output_file,"%s",line);
                deletetabs = 1;
            }
            else{
                fprintf(output_file, "%s", line);
                deletetabs = 0;
            }
        }            
    }

    fprintf(output_file,"\n");
    fclose(input_file);
}

/*
 * Funcion que se encarga de procesar los includes de un archivo
 * @param filename: nombre del archivo incluido
 * @param output_file: archivo de salida
 * @param macros: lista de macros que se encuentren
 */
void process_include(const char *filename, FILE *output_file, linkedList* macros) {
    FILE *include_file = fopen(filename, "r");
    if (include_file == NULL) {
        printf("Error al abrir el archivo incluido <%s>.\n", filename);
        exit(1);
    }

    // Preprocesar el archivo incluido recursivamente
    process_file(filename, output_file, macros);

    fclose(include_file);
}

/*
 * Funcion que se encarga de leer un define y guardarlo en la lista de macros
 * @param line: linea que contiene el define
 * @param output_file: archivo de salida
 * @param macros: lista de macros que se encuentren
 */
void read_define(const char *line, FILE *output_file, linkedList* macros) {
    char* macro_name = calloc(MAX_LINE_LENGTH,sizeof(char));
    char* macro_value = calloc(MAX_LINE_LENGTH,sizeof(char));

    // Escanear el nombre del macro y su valor de la línea
    sscanf(line, "#define %s %[^\n]", macro_name, macro_value);

    // Agregar el macro a la lista de macros
    insert_values(macros, macro_name, macro_value);
}

/*
 * Funcion que se encarga de reemplazar los macros en una linea
 * @param line: linea que contiene la macro a sustituir
 * @param macro_list: lista de macros que se encuentren
 */
void substitute_macros(char* line, linkedList* macro_list) {
    listNode* current_macro = macro_list->start;
    while (current_macro != NULL) {
        char* pos = strstr(line, current_macro->name);
        while (pos != NULL) {
            if ((pos == line || !isalnum(*(pos - 1))) && !isalnum(*(pos + strlen(current_macro->name)))) {
                memmove(pos + strlen(current_macro->value), pos + strlen(current_macro->name), strlen(pos + strlen(current_macro->name)) + 1);
                memcpy(pos, current_macro->value, strlen(current_macro->value));
            }
            pos = strstr(pos + strlen(current_macro->value), current_macro->name);
        }
        current_macro = current_macro->next;
    }
}

/*
 * Funcion que se encarga de reemplazar los macros en un archivo
 * @param filename: nombre del archivo fuente
 * @param macros: lista de macros que se encuentren
 * @param finalfile: archivo final ya preprocesado
 */
void replace_macros(const char *filename, linkedList *macros, const char* finalfile) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error al abrir el archivo <%s>.\n", filename);
        return;
    }
    
    FILE *output_file = fopen(finalfile, "w");
    if (output_file == NULL) {
        printf("Error al crear el archivo procesado\n");
        fclose(input_file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input_file)) {
        char modified_line[MAX_LINE_LENGTH*2];
        size_t line_length = strlen(line);

        // Copiar la línea original en la línea modificada
        memcpy(modified_line, line, line_length + 1); // +1 para incluir el carácter nulo de terminación
        
        for (listNode *current = macros->start; current != NULL; current = current->next) {
            // Calcular la longitud del nombre del macro y su valor
            size_t name_length = strlen(current->name);
            size_t value_length = strlen(current->value);

            // Buscar todas las ocurrencias del nombre del macro en la línea y reemplazarlas por su valor
            char *pos = modified_line;
            while ((pos = strstr(pos, current->name)) != NULL) {
                // Verificar si la ocurrencia coincide exactamente con el nombre del macro
                if ((pos == modified_line || !isalnum(*(pos - 1))) && !isalnum(pos[name_length])) {
                    // Calcular la cantidad de caracteres que se deben desplazar (si el valor es más largo que el nombre)
                    size_t move_length = value_length - name_length;

                    // Desplazar los caracteres hacia adelante o hacia atrás según sea necesario
                    if (move_length > 0) {
                        // Mover los caracteres hacia adelante (si el valor es más largo que el nombre)
                        memmove(pos + value_length, pos + name_length, line_length - (pos - modified_line) - name_length + 1);
                    } else if (move_length < 0) {
                        // Mover los caracteres hacia atrás (si el nombre es más largo que el valor)
                        memmove(pos + value_length, pos + name_length, line_length - (pos - modified_line) - name_length + 1);
                    }

                    // Copiar el valor del macro en lugar del nombre del macro en la línea
                    memcpy(pos, current->value, value_length);
                }
                // Mover el puntero de posición para continuar buscando más ocurrencias
                pos += value_length;
            }
        }
        
        fputs(modified_line, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}