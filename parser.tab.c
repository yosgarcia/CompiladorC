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
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();
    SymbolTableList* symbol_table_stack;

#line 84 "parser.tab.c"

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
  YYSYMBOL_MULOP = 16,                     /* MULOP  */
  YYSYMBOL_DIVOP = 17,                     /* DIVOP  */
  YYSYMBOL_INCR = 18,                      /* INCR  */
  YYSYMBOL_OROP = 19,                      /* OROP  */
  YYSYMBOL_ANDOP = 20,                     /* ANDOP  */
  YYSYMBOL_NOTOP = 21,                     /* NOTOP  */
  YYSYMBOL_EQUOP = 22,                     /* EQUOP  */
  YYSYMBOL_RELOP = 23,                     /* RELOP  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 26,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 27,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_SEMI = 30,                      /* SEMI  */
  YYSYMBOL_DOT = 31,                       /* DOT  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 33,                    /* ASSIGN  */
  YYSYMBOL_REFER = 34,                     /* REFER  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_ICONST = 36,                    /* ICONST  */
  YYSYMBOL_FCONST = 37,                    /* FCONST  */
  YYSYMBOL_CCONST = 38,                    /* CCONST  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_declarations = 42,              /* declarations  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_type = 44,                      /* type  */
  YYSYMBOL_names = 45,                     /* names  */
  YYSYMBOL_new_variable = 46,              /* new_variable  */
  YYSYMBOL_variable = 47,                  /* variable  */
  YYSYMBOL_pointer = 48,                   /* pointer  */
  YYSYMBOL_array = 49,                     /* array  */
  YYSYMBOL_constant = 50,                  /* constant  */
  YYSYMBOL_init = 51,                      /* init  */
  YYSYMBOL_var_init = 52,                  /* var_init  */
  YYSYMBOL_array_init = 53,                /* array_init  */
  YYSYMBOL_values = 54,                    /* values  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_if_statement = 57,              /* if_statement  */
  YYSYMBOL_else_if = 58,                   /* else_if  */
  YYSYMBOL_optional_else = 59,             /* optional_else  */
  YYSYMBOL_for_statement = 60,             /* for_statement  */
  YYSYMBOL_while_statement = 61,           /* while_statement  */
  YYSYMBOL_tail = 62,                      /* tail  */
  YYSYMBOL_endtail = 63,                   /* endtail  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_sign = 65,                      /* sign  */
  YYSYMBOL_assigment = 66,                 /* assigment  */
  YYSYMBOL_var_ref = 67,                   /* var_ref  */
  YYSYMBOL_function_call = 68,             /* function_call  */
  YYSYMBOL_call_params = 69,               /* call_params  */
  YYSYMBOL_call_param = 70,                /* call_param  */
  YYSYMBOL_functions = 71,                 /* functions  */
  YYSYMBOL_function = 72,                  /* function  */
  YYSYMBOL_function_head = 73,             /* function_head  */
  YYSYMBOL_return_type = 74,               /* return_type  */
  YYSYMBOL_parameters_optional = 75,       /* parameters_optional  */
  YYSYMBOL_parameters = 76,                /* parameters  */
  YYSYMBOL_parameter = 77,                 /* parameter  */
  YYSYMBOL_function_tail = 78,             /* function_tail  */
  YYSYMBOL_declarations_optional = 79,     /* declarations_optional  */
  YYSYMBOL_statements_optional = 80,       /* statements_optional  */
  YYSYMBOL_return_optional = 81            /* return_optional  */
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
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    56,    58,    60,    60,    60,    60,
      60,    62,    62,    62,    62,    64,    76,    81,    86,    92,
      92,    93,    93,    95,    95,    97,    97,    97,   100,   100,
     102,   112,   116,   116,   119,   119,   122,   122,   122,   122,
     123,   123,   123,   123,   123,   127,   128,   132,   133,   136,
     136,   138,   142,   146,   148,   155,   156,   157,   158,   163,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   178,
     178,   180,   182,   182,   184,   186,   186,   186,   188,   188,
     193,   193,   195,   200,   203,   205,   209,   212,   214,   217,
     219,   221,   223,   223,   225,   225,   227,   227
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
  "RETURN", "ADDOP", "MULOP", "DIVOP", "INCR", "OROP", "ANDOP", "NOTOP",
  "EQUOP", "RELOP", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE",
  "RBRACE", "SEMI", "DOT", "COMMA", "ASSIGN", "REFER", "ID", "ICONST",
  "FCONST", "CCONST", "STRING", "$accept", "program", "declarations",
  "declaration", "type", "names", "new_variable", "variable", "pointer",
  "array", "constant", "init", "var_init", "array_init", "values",
  "statements", "statement", "if_statement", "else_if", "optional_else",
  "for_statement", "while_statement", "tail", "endtail", "expression",
  "sign", "assigment", "var_ref", "function_call", "call_params",
  "call_param", "functions", "function", "function_head", "return_type",
  "parameters_optional", "parameters", "parameter", "function_tail",
  "declarations_optional", "statements_optional", "return_optional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,  -127,  -127,  -127,  -127,  -127,    25,    14,   118,  -127,
      30,    18,  -127,  -127,    68,  -127,   118,  -127,    63,  -127,
     118,  -127,     7,    59,   118,  -127,   -11,    16,  -127,    39,
    -127,  -127,  -127,    71,    80,    84,    83,   109,   107,    65,
     232,  -127,    70,    59,  -127,  -127,  -127,  -127,   127,   115,
     151,   155,    76,   153,   154,  -127,    91,   156,    17,  -127,
      85,  -127,    91,    91,    56,  -127,  -127,   159,   171,  -127,
     170,    64,   177,  -127,  -127,  -127,    91,  -127,    91,   182,
     171,  -127,  -127,   118,  -127,   173,    91,    91,   235,   139,
      81,  -127,  -127,  -127,    91,   186,   -11,  -127,  -127,   157,
     168,   189,  -127,  -127,  -127,   223,   197,   193,   223,   121,
    -127,  -127,   177,  -127,  -127,   223,   179,  -127,    91,    91,
      91,    91,    91,    91,    91,  -127,  -127,  -127,  -127,  -127,
     148,    81,    17,   202,   202,    91,  -127,    91,  -127,  -127,
     110,   229,   229,   213,  -127,    77,   243,  -127,  -127,    15,
      59,   228,  -127,   130,   223,  -127,    81,    22,    -2,   233,
    -127,    91,  -127,  -127,   230,  -127,     9,  -127,   190,    91,
     231,   202,   201,    91,  -127,   202,   212,  -127,   202,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     6,     8,     9,    10,     0,    84,     2,    81,
       0,     0,     1,    22,    85,    80,    93,    82,     0,    21,
      92,     4,     0,    95,    87,     3,    15,     0,    13,     0,
      14,    28,    29,     0,     0,     0,     0,     0,     0,     0,
      18,    72,     0,    94,    35,    36,    37,    38,     0,     0,
       0,    97,     0,     0,    86,    89,    70,     0,    17,     5,
       0,    16,    70,    70,     0,    40,    41,     0,    18,    73,
       0,    70,    20,    19,    34,    39,    70,    42,    70,     0,
      15,    90,    83,     0,    69,     0,    70,    70,    18,     0,
       0,    66,    68,    30,    70,     0,    18,    11,    12,     0,
       0,     0,    44,    43,    76,    79,     0,    75,    71,     0,
      54,    91,    17,    88,    59,    62,     0,    58,    70,    70,
      70,    70,    70,    70,    70,    24,    25,    26,    27,    67,
       0,     0,    20,     0,     0,    70,    74,    70,    96,    65,
      55,    56,    57,    60,    61,    63,    64,    23,    33,     0,
       0,    50,    52,     0,    78,    31,     0,     0,     0,    50,
      46,    70,    32,    53,     0,    49,     0,    45,     0,    70,
       0,     0,     0,    70,    51,     0,     0,    48,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   227,   -10,  -127,   205,   -21,     2,   -13,
    -120,   200,  -127,  -127,  -127,   114,   -41,  -127,  -127,   108,
    -127,  -127,  -126,   111,   -59,  -127,   206,   -23,   -22,  -127,
    -127,  -127,   258,  -127,  -127,  -127,  -127,   188,  -127,  -127,
    -127,  -127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,    20,    21,     7,    27,    28,    41,    42,    72,
     129,    30,    31,    32,   149,    43,    44,    45,   159,   160,
      46,    47,   165,   111,    89,    90,    48,    91,    92,   106,
     107,     8,     9,    10,    11,    53,    54,    55,    17,    23,
      51,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    74,    99,   100,   164,    22,   151,   152,    14,
      22,   148,   105,    58,    52,    56,   170,   108,    69,   109,
      49,    50,    57,    13,    29,    12,   150,   115,   116,    33,
      13,    34,    35,    36,    37,   130,   162,   150,    13,    97,
      38,    49,    26,    94,   155,   174,    59,   156,    60,   177,
      95,   110,   179,    18,    29,    19,    39,    40,    16,   140,
     141,   142,   143,   144,   145,   146,    33,   112,    34,    35,
      36,    37,    13,    52,    61,    13,   153,    38,   154,    84,
      13,    13,    85,   132,    19,    86,    19,    24,    87,   -77,
      39,    68,    13,    39,    40,    62,   121,   122,    39,    88,
      68,    13,   168,   104,    63,    73,    84,    13,    64,    85,
     172,    80,    86,    65,   176,    87,    74,   126,   127,   128,
      96,     1,     2,     3,     4,    39,    88,    49,    50,   121,
     122,     5,   123,   124,    49,    50,   118,   119,   120,    66,
     121,   122,    67,   123,   124,   118,   119,   120,    76,   121,
     122,   138,   123,   124,   118,   119,   120,    75,   121,   122,
     161,   123,   124,   118,   119,   120,   125,   121,   122,    78,
     123,   124,   118,   119,   120,   147,   121,   122,    82,   123,
     124,    77,   133,   118,   119,   120,    83,   121,   122,   102,
     123,   124,    93,   134,   118,   119,   120,    56,   121,   122,
     103,   123,   124,    94,   139,   118,   119,   120,   114,   121,
     122,   110,   123,   124,   131,   171,   118,   119,   120,   135,
     121,   122,   136,   123,   124,   137,   175,   118,   119,   120,
     150,   121,   122,   122,   123,   124,   158,   178,   118,   119,
     120,   166,   121,   122,   118,   123,   124,    25,   121,   122,
      70,   123,   124,   117,   169,   173,    71,    81,    56,    71,
      98,    56,   121,   122,   157,   123,    15,   167,   163,     0,
     101,   113
};

static const yytype_int16 yycheck[] =
{
      23,    23,    43,    62,    63,     7,    16,   133,   134,     7,
      20,   131,    71,    26,    24,    26,     7,    76,    39,    78,
      43,    43,    33,    16,    22,     0,    28,    86,    87,     7,
      16,     9,    10,    11,    12,    94,   156,    28,    16,    60,
      18,    64,    35,    26,    29,   171,    30,    32,    32,   175,
      33,    29,   178,    35,    52,    16,    34,    35,    28,   118,
     119,   120,   121,   122,   123,   124,     7,    80,     9,    10,
      11,    12,    16,    83,    35,    16,   135,    18,   137,    15,
      16,    16,    18,    96,    16,    21,    16,    24,    24,    25,
      34,    35,    16,    34,    35,    24,    19,    20,    34,    35,
      35,    16,   161,    39,    24,    35,    15,    16,    24,    18,
     169,    35,    21,    30,   173,    24,   157,    36,    37,    38,
      35,     3,     4,     5,     6,    34,    35,   150,   150,    19,
      20,    13,    22,    23,   157,   157,    15,    16,    17,    30,
      19,    20,    35,    22,    23,    15,    16,    17,    33,    19,
      20,    30,    22,    23,    15,    16,    17,    30,    19,    20,
      30,    22,    23,    15,    16,    17,    27,    19,    20,    14,
      22,    23,    15,    16,    17,    27,    19,    20,    25,    22,
      23,    30,    25,    15,    16,    17,    32,    19,    20,    30,
      22,    23,    36,    25,    15,    16,    17,    26,    19,    20,
      30,    22,    23,    26,    25,    15,    16,    17,    35,    19,
      20,    29,    22,    23,    28,    25,    15,    16,    17,    30,
      19,    20,    25,    22,    23,    32,    25,    15,    16,    17,
      28,    19,    20,    20,    22,    23,     8,    25,    15,    16,
      17,     8,    19,    20,    15,    22,    23,    20,    19,    20,
      18,    22,    23,    18,    24,    24,    24,    52,    26,    24,
      60,    26,    19,    20,   150,    22,     8,   159,   157,    -1,
      64,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    13,    41,    44,    71,    72,
      73,    74,     0,    16,    48,    72,    28,    78,    35,    16,
      42,    43,    44,    79,    24,    43,    35,    45,    46,    48,
      51,    52,    53,     7,     9,    10,    11,    12,    18,    34,
      35,    47,    48,    55,    56,    57,    60,    61,    66,    67,
      68,    80,    44,    75,    76,    77,    26,    33,    49,    30,
      32,    35,    24,    24,    24,    30,    30,    35,    35,    47,
      18,    24,    49,    35,    56,    30,    33,    30,    14,    81,
      35,    46,    25,    32,    15,    18,    21,    24,    35,    64,
      65,    67,    68,    36,    26,    33,    35,    47,    51,    64,
      64,    66,    30,    30,    39,    64,    69,    70,    64,    64,
      29,    63,    49,    77,    35,    64,    64,    18,    15,    16,
      17,    19,    20,    22,    23,    27,    36,    37,    38,    50,
      64,    28,    49,    25,    25,    30,    25,    32,    30,    25,
      64,    64,    64,    64,    64,    64,    64,    27,    50,    54,
      28,    62,    62,    64,    64,    29,    32,    55,     8,    58,
      59,    30,    50,    63,     7,    62,     8,    59,    64,    24,
       7,    25,    64,    24,    62,    25,    64,    62,    25,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    44,    44,    44,
      44,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    48,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    61,    62,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    67,    67,    68,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    79,    79,    80,    80,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     2,     1,     2,
       2,     2,     1,     4,     3,     1,     1,     1,     1,     1,
       3,     6,     3,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     3,     7,     6,     7,     6,     2,
       0,     9,     5,     3,     1,     3,     3,     3,     2,     2,
       3,     3,     2,     3,     3,     3,     1,     2,     1,     1,
       0,     3,     1,     2,     4,     1,     1,     0,     3,     1,
       2,     1,     2,     5,     1,     2,     1,     0,     3,     1,
       2,     5,     1,     0,     1,     0,     3,     0
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
  case 2: /* program: functions  */
#line 53 "parser.y"
                   {printf("empezando programa\n");}
#line 1294 "parser.tab.c"
    break;

  case 15: /* new_variable: ID  */
#line 64 "parser.y"
                 {
        printf("new variable\n");
        if(find_word_on_symboltablelist(symbol_table_stack,(yyvsp[0].str_val_id)) == NULL){
            printf("new variable not on top list\n");
            insert_word_on_top(symbol_table_stack,(yyvsp[0].str_val_id));
        }
        else{
            printf("Error: Creo una variable iniciada xd: %s\n",(yyvsp[0].str_val_id));

        }
    }
#line 1310 "parser.tab.c"
    break;

  case 16: /* new_variable: pointer ID  */
#line 77 "parser.y"
    {
        insert_word_on_top(symbol_table_stack,(yyvsp[0].str_val_id));
    }
#line 1318 "parser.tab.c"
    break;

  case 17: /* new_variable: ID array  */
#line 81 "parser.y"
             {
        insert_word_on_top(symbol_table_stack,(yyvsp[-1].str_val_id));
    }
#line 1326 "parser.tab.c"
    break;

  case 18: /* variable: ID  */
#line 86 "parser.y"
             {
        if(find_word_on_symboltablelist(symbol_table_stack,(yyvsp[0].str_val_id)) == NULL){
            printf("Error: Uso una variable no iniciada %s\n",(yyvsp[0].str_val_id));
            //insert_word_on_top(symbol_table_stack,yytext);
        }
    }
#line 1337 "parser.tab.c"
    break;

  case 30: /* var_init: ID ASSIGN ICONST  */
#line 102 "parser.y"
                           {
        if(find_word_on_symboltablelist(symbol_table_stack,(yyvsp[-2].str_val_id)) == NULL){
            insert_word_with_value_on_top(symbol_table_stack,(yyvsp[-2].str_val_id),(yyvsp[0].int_val));
        }
        else{
            printf("Error: Creo una variable iniciada xd: %s\n",(yyvsp[-2].str_val_id));

        }
    }
#line 1351 "parser.tab.c"
    break;

  case 31: /* array_init: ID array ASSIGN LBRACE values RBRACE  */
#line 112 "parser.y"
                                                 {
        insert_word_on_top(symbol_table_stack,(yyvsp[-5].str_val_id));
    }
#line 1359 "parser.tab.c"
    break;

  case 51: /* for_statement: FOR LPAREN assigment SEMI expression SEMI expression RPAREN tail  */
#line 138 "parser.y"
                                                                                {
    insert_new_symboltable_on_list(symbol_table_stack);
}
#line 1367 "parser.tab.c"
    break;

  case 52: /* while_statement: WHILE LPAREN expression RPAREN tail  */
#line 142 "parser.y"
                                                     {
    insert_new_symboltable_on_list(symbol_table_stack);
}
#line 1375 "parser.tab.c"
    break;

  case 54: /* endtail: RBRACE  */
#line 148 "parser.y"
                {
    printf("voy a hacer pop endtail\n");
    SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
    print_symbol_table(st);
}
#line 1385 "parser.tab.c"
    break;

  case 58: /* expression: ID INCR  */
#line 158 "parser.y"
            {
        if (find_word_on_symboltablelist(symbol_table_stack, (yyvsp[-1].str_val_id)) == NULL) {
            printf("Error: Variable no declarada en la línea %d\n", lineno);
        }
    }
#line 1395 "parser.tab.c"
    break;

  case 59: /* expression: INCR ID  */
#line 163 "parser.y"
            {        if (find_word_on_symboltablelist(symbol_table_stack, (yyvsp[0].str_val_id)) == NULL) {
            printf("Error: Variable no declarada en la línea %d\n", lineno);
        }
    }
#line 1404 "parser.tab.c"
    break;

  case 82: /* function: function_head function_tail  */
#line 195 "parser.y"
                                      { 
    printf("function\n");
    insert_new_symboltable_on_list(symbol_table_stack);
}
#line 1413 "parser.tab.c"
    break;

  case 83: /* function_head: return_type ID LPAREN parameters_optional RPAREN  */
#line 200 "parser.y"
                                                                {
    printf("HOlaaaaa funcction head");}
#line 1420 "parser.tab.c"
    break;

  case 84: /* return_type: type  */
#line 203 "parser.y"
                  {
    printf("type\n");
}
#line 1428 "parser.tab.c"
    break;

  case 85: /* return_type: type pointer  */
#line 206 "parser.y"
    {printf("typepointer\n");}
#line 1434 "parser.tab.c"
    break;

  case 86: /* parameters_optional: parameters  */
#line 209 "parser.y"
                                {
    printf("parameters");
    }
#line 1442 "parser.tab.c"
    break;

  case 87: /* parameters_optional: %empty  */
#line 212 "parser.y"
                  {printf("parametersempty\n");}
#line 1448 "parser.tab.c"
    break;

  case 88: /* parameters: parameters COMMA parameter  */
#line 214 "parser.y"
                                       {
    printf("parameters comma parameter\n");
    }
#line 1456 "parser.tab.c"
    break;

  case 89: /* parameters: parameter  */
#line 217 "parser.y"
                {printf("parameter on parameters\n");}
#line 1462 "parser.tab.c"
    break;


#line 1466 "parser.tab.c"

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

#line 229 "parser.y"



void yyerror (const char *s) {
    fprintf(stderr, "Syntax error  %s\n", s);
    exit(1);
}
/*
int parse_xd (char* file){
	symbol_table_stack = create_symboltable_list();
    SymbolTable* global_table = create_symbol_table();
    insert_symboltable_on_list(symbol_table_stack, global_table);
    yyin = fopen(file, "r");
    if (!yyin) {
        perror(file);
        return 1;
    }

    int flag = yyparse();
    printf("Parsing finished!\n");

    SymbolTable* global = pop_symboltable_stack(symbol_table_stack);
    printf("Global Symbol Table:\n");
    print_symbol_table(global);

    return flag;
}*/

int main (int argc, char *argv[]){
    symbol_table_stack = create_symboltable_list();
    insert_new_symboltable_on_list(symbol_table_stack);
	// parsing
    printf("primero\n");
	int flag;
	yyin = fopen(argv[1], "r");
    printf("yyin leido\n");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!");
	
	// symbol table dump
	//yyout = fopen("symtab_dump.out", "w");
	//symtab_dump(yyout);
	//fclose(yyout);
	
	return flag;
}
/*
int main (int argc, char *argv[]) {
    symbol_table_stack = create_symboltable_list();
    SymbolTable* global_table = create_symbol_table();
    insert_symboltable_on_list(symbol_table_stack, global_table);

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    }

    int flag = yyparse();
    printf("Parsing finished!\n");

    SymbolTable* global = pop_symboltable_stack(symbol_table_stack);
    printf("Global Symbol Table:\n");
    print_symbol_table(global);

    return flag;
}
*/
