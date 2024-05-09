#ifndef preprocesador_h
#define preprocesador_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "linkedList.h"

#define MAX_LINE_LENGTH 256 // Longitud maxima de una linea

/*
 * Funcion que se encarga de preprocesar un archivo fuente
 * @param filename: nombre del archivo fuente
 * @param temp_file: nombre del archivo temporal
 * @param final_file: nombre del archivo final ya preprocesado
*/
void pre_process(const char* filename, const char* temp_file, const char* final_file);

/*
 * Funcion que se encarga de procesar un archivo fuente
 * @param filename: nombre del archivo fuente
 * @param output_file: archivo de salida
 * @param macros: lista de macros que se encuentren
 */
void process_file(const char *filename, FILE *output_file, linkedList* macros);

/*
 * Funcion que se encarga de procesar los includes de un archivo
 * @param filename: nombre del archivo incluido
 * @param output_file: archivo de salida
 * @param macros: lista de macros que se encuentren
 */
void process_include(const char *filename, FILE *output_file, linkedList* macros);

/*
 * Funcion que se encarga de leer un define y guardarlo en la lista de macros
 * @param line: linea que contiene el define
 * @param output_file: archivo de salida
 * @param macros: lista de macros que se encuentren
 */
void read_define(const char *line, FILE *output_file, linkedList* macros);

/*
 * Funcion que se encarga de reemplazar los macros en un archivo
 * @param filename: nombre del archivo fuente
 * @param macros: lista de macros que se encuentren
 * @param finalfile: archivo final ya preprocesado
 */
void replace_macros(const char *filename, linkedList *macros,  const char* finalfile);

/*
 * Funcion que se encarga de reemplazar los macros en una linea
 * @param line: linea que contiene la macro a sustituir
 * @param macro_list: lista de macros que se encuentren
 */
void substitute_macros(char* line, linkedList* macro_list);

/*
 * Funcion que se encarga de iniciar el preprocesamiento
 * @param source_file: archivo fuente
 */
void start_preprocess(const char* source_file);


#endif