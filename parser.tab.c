/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "symboltable.c"
    #include "ast.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror(const char* s );
    void print_error_variable_redeclarada (char* name, int line);
    void print_error_variable_no_declarada (char* name, int line);
    SymbolTableList* symbol_table_stack;
    int yyerrstatus = 0; // Declaración de yyerrstatus
    struct NodeAST* root = NULL;

#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_ADDOP = 15,                     /* ADDOP  */
  YYSYMBOL_MINUSOP = 16,                   /* MINUSOP  */
  YYSYMBOL_MULOP = 17,                     /* MULOP  */
  YYSYMBOL_DIVOP = 18,                     /* DIVOP  */
  YYSYMBOL_INCR = 19,                      /* INCR  */
  YYSYMBOL_OROP = 20,                      /* OROP  */
  YYSYMBOL_ANDOP = 21,                     /* ANDOP  */
  YYSYMBOL_NOTOP = 22,                     /* NOTOP  */
  YYSYMBOL_EQUOP = 23,                     /* EQUOP  */
  YYSYMBOL_RELOP = 24,                     /* RELOP  */
  YYSYMBOL_LPAREN = 25,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 26,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 27,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 28,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_SEMI = 31,                      /* SEMI  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_COMMA = 33,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_REFER = 35,                     /* REFER  */
  YYSYMBOL_ID = 36,                        /* ID  */
  YYSYMBOL_ICONST = 37,                    /* ICONST  */
  YYSYMBOL_FCONST = 38,                    /* FCONST  */
  YYSYMBOL_CCONST = 39,                    /* CCONST  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_functions = 43,                 /* functions  */
  YYSYMBOL_function = 44,                  /* function  */
  YYSYMBOL_function_head = 45,             /* function_head  */
  YYSYMBOL_return_type = 46,               /* return_type  */
  YYSYMBOL_parameters_optional = 47,       /* parameters_optional  */
  YYSYMBOL_parameters = 48,                /* parameters  */
  YYSYMBOL_parameter = 49,                 /* parameter  */
  YYSYMBOL_function_tail = 50,             /* function_tail  */
  YYSYMBOL_statements_optional = 51,       /* statements_optional  */
  YYSYMBOL_return_optional = 52,           /* return_optional  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_if_statement = 55,              /* if_statement  */
  YYSYMBOL_else_if = 56,                   /* else_if  */
  YYSYMBOL_optional_else = 57,             /* optional_else  */
  YYSYMBOL_for_statement = 58,             /* for_statement  */
  YYSYMBOL_inicio_for = 59,                /* inicio_for  */
  YYSYMBOL_while_statement = 60,           /* while_statement  */
  YYSYMBOL_inicio_while = 61,              /* inicio_while  */
  YYSYMBOL_tail = 62,                      /* tail  */
  YYSYMBOL_optional_statements = 63,       /* optional_statements  */
  YYSYMBOL_endtail = 64,                   /* endtail  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_names = 67,                     /* names  */
  YYSYMBOL_new_variable = 68,              /* new_variable  */
  YYSYMBOL_variable = 69,                  /* variable  */
  YYSYMBOL_pointer = 70,                   /* pointer  */
  YYSYMBOL_array = 71,                     /* array  */
  YYSYMBOL_constant = 72,                  /* constant  */
  YYSYMBOL_init = 73,                      /* init  */
  YYSYMBOL_var_init = 74,                  /* var_init  */
  YYSYMBOL_array_init = 75,                /* array_init  */
  YYSYMBOL_values = 76,                    /* values  */
  YYSYMBOL_optional_expression = 77,       /* optional_expression  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_incr_id = 79,                   /* incr_id  */
  YYSYMBOL_sign = 80,                      /* sign  */
  YYSYMBOL_assigment = 81,                 /* assigment  */
  YYSYMBOL_var_ref = 82,                   /* var_ref  */
  YYSYMBOL_function_call = 83,             /* function_call  */
  YYSYMBOL_call_params = 84,               /* call_params  */
  YYSYMBOL_call_param = 85,                /* call_param  */
  YYSYMBOL_semi_token = 86,                /* semi_token  */
  YYSYMBOL_rbrace_token = 87,              /* rbrace_token  */
  YYSYMBOL_lbrace_token = 88               /* lbrace_token  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    74,    74,    76,    78,    80,    80,    83,
      84,    86,    87,    89,    91,    95,    95,    97,    97,    97,
     103,   103,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   111,   112,   116,   117,   120,   120,   122,   124,   127,
     132,   135,   138,   141,   141,   143,   149,   152,   152,   152,
     152,   152,   155,   155,   155,   155,   157,   166,   176,   186,
     192,   198,   204,   204,   206,   206,   208,   213,   219,   222,
     222,   224,   234,   237,   237,   240,   240,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   260,   266,   272,   272,   272,   274,   276,   276,   278,
     280,   280,   280,   282,   282,   284,   284,   285,   285,   286,
     286
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INT", "FLOAT",
  "DOUBLE", "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "BREAK", "VOID",
  "RETURN", "ADDOP", "MINUSOP", "MULOP", "DIVOP", "INCR", "OROP", "ANDOP",
  "NOTOP", "EQUOP", "RELOP", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "SEMI", "DOT", "COMMA", "ASSIGN", "REFER", "ID",
  "ICONST", "FCONST", "CCONST", "STRING", "$accept", "program",
  "functions", "function", "function_head", "return_type",
  "parameters_optional", "parameters", "parameter", "function_tail",
  "statements_optional", "return_optional", "statements", "statement",
  "if_statement", "else_if", "optional_else", "for_statement",
  "inicio_for", "while_statement", "inicio_while", "tail",
  "optional_statements", "endtail", "declaration", "type", "names",
  "new_variable", "variable", "pointer", "array", "constant", "init",
  "var_init", "array_init", "values", "optional_expression", "expression",
  "incr_id", "sign", "assigment", "var_ref", "function_call",
  "call_params", "call_param", "semi_token", "rbrace_token",
  "lbrace_token", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-103)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     252,  -129,  -129,  -129,  -129,  -129,    33,   252,  -129,    11,
       3,    36,  -129,  -129,  -129,  -129,  -129,   169,    25,  -129,
      39,    37,    40,    43,    23,    23,    44,    47,    92,    72,
     169,  -129,  -129,  -129,   205,  -129,   209,  -129,    61,  -129,
      62,    23,    23,    13,    23,   252,  -129,   224,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,    64,  -129,  -129,   197,   224,
      86,    93,    28,  -129,   135,   135,  -129,  -129,   224,   224,
      88,   322,  -129,   124,  -129,  -129,    -8,    15,  -129,    65,
    -129,  -129,  -129,  -129,  -129,  -129,   224,  -129,    90,    87,
    -129,    68,   274,  -129,   322,    96,   101,   246,   224,   176,
    -129,  -129,  -129,  -129,  -129,    23,    23,   322,   286,    11,
     224,   224,   224,   224,   224,   224,   224,   224,  -129,  -129,
    -129,  -129,   224,    73,    61,  -129,  -129,   322,  -129,   252,
      64,  -129,    11,  -129,   224,  -129,   260,  -129,   209,   209,
    -129,  -129,   169,   118,   118,   332,   332,   102,  -129,    82,
      69,   322,    11,  -129,  -129,  -129,    86,   129,   322,  -129,
     117,   123,   169,    28,   124,    30,   145,  -129,    11,    11,
    -129,  -129,    22,   130,  -129,    31,  -129,  -129,  -129,   124,
    -129,   224,   131,  -129,   298,   224,    11,   310,  -129,    11,
    -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    48,    47,    49,    50,    51,     0,     2,     4,     0,
       0,     7,     1,     3,   110,   109,     5,    16,     0,    63,
       8,     0,     0,     0,     0,     0,     0,     0,    59,    19,
      15,    21,    22,    23,     0,    24,    95,    30,     0,    97,
       0,     0,     0,     0,     0,    10,    62,    95,    41,    39,
     106,   105,    26,    27,    92,    59,    98,    91,    95,    95,
      61,     0,     0,    20,    95,    95,    93,    94,    95,    95,
       0,    75,    81,     0,    88,    90,    56,     0,    54,     0,
      55,    69,    70,    60,    29,    25,    95,    28,     0,     9,
      12,     0,     0,   101,   104,     0,   100,     0,    95,     0,
      18,   108,   107,    14,    45,     0,     0,    84,     0,     0,
      95,    95,    95,    95,    95,    95,    95,    95,    66,    67,
      68,    89,    95,    58,     0,    46,    57,    96,     6,     0,
      56,    13,     0,    99,    95,    65,     0,    17,    95,    95,
      87,    40,    43,    77,    78,    79,    80,    82,    83,    85,
      86,    71,     0,    52,    53,    11,    58,    36,   103,    64,
       0,     0,    44,     0,     0,     0,    36,    32,     0,     0,
      42,    74,     0,     0,    35,     0,    31,    37,    38,     0,
      72,    95,     0,    73,     0,    95,     0,     0,    34,     0,
      33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   151,  -129,  -129,  -129,  -129,    35,  -129,
    -129,  -129,    17,   -27,  -129,  -129,    -1,  -129,  -129,  -129,
    -129,  -102,  -129,     5,   133,     4,  -129,   -81,   142,    -3,
     -67,  -128,    59,  -129,  -129,  -129,   -43,   -41,   -17,  -129,
    -129,   -16,   -15,  -129,  -129,     0,    12,    -4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    88,    89,    90,    16,
      29,    62,    30,    31,    32,   166,   167,    33,    34,    35,
      36,   174,   163,   103,    37,    38,    77,    78,    39,    40,
      60,   121,    80,    81,    82,   172,    70,    71,    72,    73,
      42,    74,    75,    95,    96,    52,   104,   142
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    43,    44,    63,    11,    17,    92,   141,    20,   123,
     131,    11,    14,    41,    43,    44,    50,    94,    97,    59,
      99,   105,   106,   101,    50,    53,   122,   107,   108,   101,
     157,    14,    14,    12,    65,    79,   171,   173,   182,    18,
      15,    84,    85,   153,    87,   127,    51,    86,   124,    91,
      45,   183,   102,    19,    51,   179,    46,   136,   102,    15,
      15,   100,    47,   156,    19,    48,   177,   178,    49,   143,
     144,   145,   146,   147,   148,   149,   150,   125,    19,    46,
      54,   151,    46,    55,   188,    19,    61,   190,    79,   114,
     115,    59,   116,   158,    50,   160,   161,    76,    83,   137,
      98,   126,   114,   115,   130,   138,   139,   152,    66,    67,
      19,    57,    26,    98,   109,    68,   128,    58,    69,    59,
     129,    79,   133,   115,    51,    41,    43,    44,    27,    28,
     -95,   -95,   -95,    91,   134,    63,   -76,   165,   114,   115,
     184,   116,   117,   168,   187,    41,    43,    44,   164,   169,
      66,    67,    19,   175,    26,   181,   185,    68,    13,   162,
      69,   118,   119,   120,   155,   176,   -76,    64,   170,    56,
      27,    28,     1,     2,     3,     4,    21,    50,    22,    23,
      24,    25,     5,   154,   180,     0,    19,     0,    26,     0,
       0,   110,   111,   112,   113,     0,   114,   115,     0,   116,
     117,     0,     0,     0,    27,    28,    50,    51,     1,     2,
       3,     4,    66,    67,    19,     0,    26,     0,     5,    68,
       0,     0,    69,  -102,    66,    67,    19,     0,    26,     0,
       0,    68,    27,    28,    69,   -76,    51,    93,     0,    66,
      67,    19,     0,    26,    27,    28,    68,     0,     0,    69,
       0,     0,     0,     0,     0,     1,     2,     3,     4,    27,
      28,   110,   111,   112,   113,     5,   114,   115,     0,   116,
     117,     0,     0,     0,   135,   110,   111,   112,   113,     0,
     114,   115,     0,   116,   117,     0,     0,     0,   159,   110,
     111,   112,   113,     0,   114,   115,     0,   116,   117,     0,
     132,   110,   111,   112,   113,     0,   114,   115,     0,   116,
     117,     0,   140,   110,   111,   112,   113,     0,   114,   115,
       0,   116,   117,     0,   186,   110,   111,   112,   113,     0,
     114,   115,     0,   116,   117,     0,   189,   110,   111,   112,
     113,     0,   114,   115,     0,   116,   117,   110,   111,     0,
       0,     0,   114,   115,     0,   116,   117
};

static const yytype_int16 yycheck[] =
{
      17,    17,    17,    30,     0,     9,    47,   109,    11,    76,
      91,     7,     1,    30,    30,    30,     1,    58,    59,    27,
      61,    64,    65,     1,     1,    25,    34,    68,    69,     1,
     132,     1,     1,     0,    34,    38,   164,     7,     7,    36,
      29,    41,    42,   124,    44,    86,    31,    34,    33,    45,
      25,   179,    30,    17,    31,    33,    17,    98,    30,    29,
      29,    61,    25,   130,    17,    25,   168,   169,    25,   110,
     111,   112,   113,   114,   115,   116,   117,    77,    17,    17,
      36,   122,    17,    36,   186,    17,    14,   189,    91,    20,
      21,    27,    23,   134,     1,   138,   139,    36,    36,    99,
      27,    36,    20,    21,    36,   105,   106,    34,    15,    16,
      17,    19,    19,    27,    26,    22,    26,    25,    25,    27,
      33,   124,    26,    21,    31,   142,   142,   142,    35,    36,
      37,    38,    39,   129,    33,   162,     1,     8,    20,    21,
     181,    23,    24,    26,   185,   162,   162,   162,   152,    26,
      15,    16,    17,     8,    19,    25,    25,    22,     7,   142,
      25,    37,    38,    39,   129,   166,    31,    34,   163,    27,
      35,    36,     3,     4,     5,     6,     7,     1,     9,    10,
      11,    12,    13,   124,   172,    -1,    17,    -1,    19,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    35,    36,     1,    31,     3,     4,
       5,     6,    15,    16,    17,    -1,    19,    -1,    13,    22,
      -1,    -1,    25,    26,    15,    16,    17,    -1,    19,    -1,
      -1,    22,    35,    36,    25,    26,    31,    40,    -1,    15,
      16,    17,    -1,    19,    35,    36,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    35,
      36,    15,    16,    17,    18,    13,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    28,    15,    16,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    28,    15,
      16,    17,    18,    -1,    20,    21,    -1,    23,    24,    -1,
      26,    15,    16,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    26,    15,    16,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    26,    15,    16,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    26,    15,    16,    17,
      18,    -1,    20,    21,    -1,    23,    24,    15,    16,    -1,
      -1,    -1,    20,    21,    -1,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    13,    42,    43,    44,    45,
      46,    66,     0,    44,     1,    29,    50,    88,    36,    17,
      70,     7,     9,    10,    11,    12,    19,    35,    36,    51,
      53,    54,    55,    58,    59,    60,    61,    65,    66,    69,
      70,    79,    81,    82,    83,    25,    17,    25,    25,    25,
       1,    31,    86,    86,    36,    36,    69,    19,    25,    27,
      71,    14,    52,    54,    65,    86,    15,    16,    22,    25,
      77,    78,    79,    80,    82,    83,    36,    67,    68,    70,
      73,    74,    75,    36,    86,    86,    34,    86,    47,    48,
      49,    66,    78,    40,    78,    84,    85,    78,    27,    78,
      86,     1,    30,    64,    87,    77,    77,    78,    78,    26,
      15,    16,    17,    18,    20,    21,    23,    24,    37,    38,
      39,    72,    34,    71,    33,    86,    36,    78,    26,    33,
      36,    68,    26,    26,    33,    28,    78,    86,    86,    86,
      26,    62,    88,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    34,    68,    73,    49,    71,    62,    78,    28,
      77,    77,    53,    63,    88,     8,    56,    57,    26,    26,
      64,    72,    76,     7,    62,     8,    57,    62,    62,    33,
      87,    25,     7,    72,    78,    25,    26,    78,    62,    26,
      62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    46,    46,    47,
      47,    48,    48,    49,    50,    51,    51,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      60,    61,    62,    63,    63,    64,    65,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    74,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    80,    81,    82,    82,    83,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     5,     1,     2,     1,
       0,     3,     1,     2,     4,     1,     0,     3,     2,     0,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     7,     6,     7,     6,     2,     0,     7,     7,     2,
       4,     2,     3,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     2,     1,
       2,     2,     2,     1,     4,     3,     1,     1,     1,     1,
       1,     3,     6,     3,     1,     1,     0,     3,     3,     3,
       3,     1,     3,     3,     2,     3,     3,     3,     1,     2,
       1,     2,     2,     1,     1,     0,     3,     1,     2,     4,
       1,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 39: /* inicio_for: FOR LPAREN  */
#line 127 "parser.y"
                        {
        insert_new_symboltable_on_list(symbol_table_stack);
}
#line 1339 "parser.tab.c"
    break;

  case 41: /* inicio_while: WHILE LPAREN  */
#line 135 "parser.y"
                            {
        insert_new_symboltable_on_list(symbol_table_stack);
}
#line 1347 "parser.tab.c"
    break;

  case 45: /* endtail: rbrace_token  */
#line 143 "parser.y"
                      {
    //printf("voy a hacer pop endtail\n");
    SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
    print_symbol_table(st);
}
#line 1357 "parser.tab.c"
    break;

  case 56: /* new_variable: ID  */
#line 157 "parser.y"
                 {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            insert_word_on_top(symbol_table_stack,(yyvsp[0].value).sval);
        }
        else{
            print_error_variable_redeclarada(((yyvsp[0].value).sval), lineno);
        }
    }
#line 1370 "parser.tab.c"
    break;

  case 57: /* new_variable: pointer ID  */
#line 167 "parser.y"
    {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            insert_word_on_top(symbol_table_stack,(yyvsp[0].value).sval);
        }
        else{
            print_error_variable_redeclarada(((yyvsp[0].value).sval), lineno);
        }
    }
#line 1383 "parser.tab.c"
    break;

  case 58: /* new_variable: ID array  */
#line 176 "parser.y"
             {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[-1].value).sval) == NULL){
            insert_word_on_top(symbol_table_stack, ((yyvsp[-1].value).sval));
        }
        else{
            print_error_variable_redeclarada (((yyvsp[-1].value).sval), lineno);
        }
    }
#line 1396 "parser.tab.c"
    break;

  case 59: /* variable: ID  */
#line 186 "parser.y"
             {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            print_error_variable_no_declarada(((yyvsp[0].value).sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
#line 1407 "parser.tab.c"
    break;

  case 60: /* variable: pointer ID  */
#line 192 "parser.y"
                 {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[-1].value).sval) == NULL){
            print_error_variable_no_declarada(((yyvsp[0].value).sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
#line 1418 "parser.tab.c"
    break;

  case 61: /* variable: ID array  */
#line 198 "parser.y"
               {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[-1].value).sval) == NULL){
            print_error_variable_no_declarada(((yyvsp[-1].value).sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
#line 1429 "parser.tab.c"
    break;

  case 66: /* constant: ICONST  */
#line 208 "parser.y"
                 {Value new_value;
                new_value.ival = (yyvsp[0].value).ival;
                (yyval.value) = new_value;
                }
#line 1438 "parser.tab.c"
    break;

  case 67: /* constant: FCONST  */
#line 214 "parser.y"
                {Value new_value;
                new_value.ival = (yyvsp[0].value).ival;
                (yyval.value) = new_value;
                }
#line 1447 "parser.tab.c"
    break;

  case 71: /* var_init: ID ASSIGN expression  */
#line 224 "parser.y"
                               {
        if( (find_word_on_start_symboltablelist(symbol_table_stack,(yyvsp[-2].value).sval)) == NULL){
            insert_word_with_value_on_top(symbol_table_stack,(yyvsp[-2].value).sval,(yyvsp[0].value).ival);
        }
        else{
            print_error_variable_redeclarada (((yyvsp[-2].value).sval), lineno);
        }
    }
#line 1460 "parser.tab.c"
    break;

  case 72: /* array_init: ID array ASSIGN lbrace_token values rbrace_token  */
#line 234 "parser.y"
                                                             {
    }
#line 1467 "parser.tab.c"
    break;

  case 89: /* expression: sign constant  */
#line 255 "parser.y"
                  {(yyval.value) = (yyvsp[0].value);}
#line 1473 "parser.tab.c"
    break;

  case 91: /* incr_id: ID INCR  */
#line 260 "parser.y"
                 {
        if (find_word_on_all_symboltablelist(symbol_table_stack, (yyvsp[-1].value).sval) == NULL) {
            print_error_variable_no_declarada (((yyvsp[-1].value).sval), lineno);
        }
    }
#line 1483 "parser.tab.c"
    break;

  case 92: /* incr_id: INCR ID  */
#line 266 "parser.y"
                {
            if (find_word_on_all_symboltablelist(symbol_table_stack, (yyvsp[0].value).sval) == NULL) {
            print_error_variable_no_declarada (((yyvsp[0].value).sval), lineno);
        }
    }
#line 1493 "parser.tab.c"
    break;

  case 106: /* semi_token: error  */
#line 284 "parser.y"
                          {yyerror("Falta ; al final de la instruccion"); yyerrok;}
#line 1499 "parser.tab.c"
    break;

  case 108: /* rbrace_token: error  */
#line 285 "parser.y"
                             {yyerror("Falta } al final"); yyerrok;}
#line 1505 "parser.tab.c"
    break;

  case 110: /* lbrace_token: error  */
#line 286 "parser.y"
                              {yyerror("Esperaba un {"); yyerrok;}
#line 1511 "parser.tab.c"
    break;


#line 1515 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 288 "parser.y"


void print_error_variable_redeclarada (char* name, int line){
    printf("Error: Variable %s redeclarada en la línea %d\n", name, line);
}

void print_error_variable_no_declarada(char* name, int line){
    printf("Error: Variable %s no declarada en la línea %d\n", name, line);
}

void yyerror (const char *s) {
    fprintf(stderr, "Syntax error  en la linea %d: %s\n", lineno, s);
    //yyerrok(); // Permite que el análisis continúe después de un error
    //exit(1);
}

int main (int argc, char *argv[]){
    symbol_table_stack = create_symboltable_list();
    insert_new_symboltable_on_list(symbol_table_stack);
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("bye bye!\n");
	
	// symbol table dump
	//yyout = fopen("symtab_dump.out", "w");
	//symtab_dump(yyout);
	//fclose(yyout);
	
	return flag;
}
