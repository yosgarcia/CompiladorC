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
    int estoy_main = 0;


#line 91 "parser.tab.c"

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
  YYSYMBOL_DECR = 25,                      /* DECR  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 28,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 29,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_SEMI = 32,                      /* SEMI  */
  YYSYMBOL_DOT = 33,                       /* DOT  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 35,                    /* ASSIGN  */
  YYSYMBOL_REFER = 36,                     /* REFER  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_ICONST = 38,                    /* ICONST  */
  YYSYMBOL_FCONST = 39,                    /* FCONST  */
  YYSYMBOL_CCONST = 40,                    /* CCONST  */
  YYSYMBOL_STRING = 41,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_functions = 44,                 /* functions  */
  YYSYMBOL_function = 45,                  /* function  */
  YYSYMBOL_function_head = 46,             /* function_head  */
  YYSYMBOL_return_type = 47,               /* return_type  */
  YYSYMBOL_parameters_optional = 48,       /* parameters_optional  */
  YYSYMBOL_parameters = 49,                /* parameters  */
  YYSYMBOL_parameter = 50,                 /* parameter  */
  YYSYMBOL_function_tail = 51,             /* function_tail  */
  YYSYMBOL_statements_optional = 52,       /* statements_optional  */
  YYSYMBOL_return_optional = 53,           /* return_optional  */
  YYSYMBOL_statements = 54,                /* statements  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_if_statement = 56,              /* if_statement  */
  YYSYMBOL_else_if = 57,                   /* else_if  */
  YYSYMBOL_optional_else = 58,             /* optional_else  */
  YYSYMBOL_for_statement = 59,             /* for_statement  */
  YYSYMBOL_inicio_for = 60,                /* inicio_for  */
  YYSYMBOL_while_statement = 61,           /* while_statement  */
  YYSYMBOL_inicio_while = 62,              /* inicio_while  */
  YYSYMBOL_tail = 63,                      /* tail  */
  YYSYMBOL_optional_statements = 64,       /* optional_statements  */
  YYSYMBOL_endtail_function = 65,          /* endtail_function  */
  YYSYMBOL_end_tail = 66,                  /* end_tail  */
  YYSYMBOL_declaration = 67,               /* declaration  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_names = 69,                     /* names  */
  YYSYMBOL_new_variable = 70,              /* new_variable  */
  YYSYMBOL_variable = 71,                  /* variable  */
  YYSYMBOL_pointer = 72,                   /* pointer  */
  YYSYMBOL_array = 73,                     /* array  */
  YYSYMBOL_constant = 74,                  /* constant  */
  YYSYMBOL_init = 75,                      /* init  */
  YYSYMBOL_var_init = 76,                  /* var_init  */
  YYSYMBOL_array_init = 77,                /* array_init  */
  YYSYMBOL_values = 78,                    /* values  */
  YYSYMBOL_optional_expression = 79,       /* optional_expression  */
  YYSYMBOL_expression = 80,                /* expression  */
  YYSYMBOL_incr_id = 81,                   /* incr_id  */
  YYSYMBOL_decr_id = 82,                   /* decr_id  */
  YYSYMBOL_sign = 83,                      /* sign  */
  YYSYMBOL_assigment = 84,                 /* assigment  */
  YYSYMBOL_var_ref = 85,                   /* var_ref  */
  YYSYMBOL_function_call = 86,             /* function_call  */
  YYSYMBOL_call_params = 87,               /* call_params  */
  YYSYMBOL_call_param = 88,                /* call_param  */
  YYSYMBOL_semi_token = 89,                /* semi_token  */
  YYSYMBOL_rbrace_token = 90,              /* rbrace_token  */
  YYSYMBOL_lbrace_token = 91               /* lbrace_token  */
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
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    99,   104,   108,   117,   130,   134,   137,
     139,   145,   149,   154,   162,   172,   179,   185,   189,   192,
     201,   205,   209,   211,   213,   215,   217,   219,   221,   223,
     226,   229,   235,   245,   257,   263,   271,   276,   282,   290,
     299,   306,   315,   321,   330,   334,   341,   351,   359,   368,
     371,   374,   377,   380,   386,   390,   394,   398,   405,   415,
     425,   437,   446,   455,   467,   470,   476,   476,   479,   482,
     485,   492,   494,   500,   515,   518,   521,   528,   530,   536,
     540,   544,   548,   552,   555,   558,   562,   566,   569,   573,
     577,   579,   581,   583,   590,   599,   610,   619,   630,   633,
     636,   642,   650,   653,   662,   671,   673,   675,   680,   683,
     688,   688,   689,   689,   690,   690
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
  "NOTOP", "EQUOP", "RELOP", "DECR", "LPAREN", "RPAREN", "LBRACK",
  "RBRACK", "LBRACE", "RBRACE", "SEMI", "DOT", "COMMA", "ASSIGN", "REFER",
  "ID", "ICONST", "FCONST", "CCONST", "STRING", "$accept", "program",
  "functions", "function", "function_head", "return_type",
  "parameters_optional", "parameters", "parameter", "function_tail",
  "statements_optional", "return_optional", "statements", "statement",
  "if_statement", "else_if", "optional_else", "for_statement",
  "inicio_for", "while_statement", "inicio_while", "tail",
  "optional_statements", "endtail_function", "end_tail", "declaration",
  "type", "names", "new_variable", "variable", "pointer", "array",
  "constant", "init", "var_init", "array_init", "values",
  "optional_expression", "expression", "incr_id", "decr_id", "sign",
  "assigment", "var_ref", "function_call", "call_params", "call_param",
  "semi_token", "rbrace_token", "lbrace_token", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     262,  -144,  -144,  -144,  -144,  -144,    25,   262,  -144,    50,
       2,    35,  -144,  -144,  -144,  -144,  -144,   110,    64,  -144,
      44,    68,    71,    83,     8,     8,    75,    88,    10,    80,
     114,   110,  -144,  -144,  -144,    53,  -144,   217,  -144,    54,
    -144,    65,     8,     8,     8,   101,     8,   262,  -144,   233,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   121,  -144,
    -144,  -144,   204,   233,   122,   144,    31,  -144,   170,   170,
    -144,  -144,   233,   233,   111,   328,  -144,  -144,   139,  -144,
    -144,    72,    12,  -144,    66,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   233,  -144,   129,   123,  -144,    81,   276,  -144,
     328,   135,   130,   256,   233,   193,  -144,  -144,  -144,  -144,
    -144,     8,     8,   328,   289,    50,   233,   233,   233,   233,
     233,   233,   233,   233,  -144,  -144,  -144,  -144,   233,   102,
      54,  -144,  -144,   328,  -144,   262,   121,  -144,    50,  -144,
     233,  -144,   266,  -144,   217,   217,  -144,  -144,   110,   119,
     119,   338,   338,   146,  -144,    17,   152,   328,    50,  -144,
    -144,  -144,   122,   157,   328,  -144,   141,   147,   110,    31,
     139,    62,   180,  -144,    50,    50,  -144,  -144,  -144,    19,
     164,  -144,    94,  -144,  -144,  -144,   139,  -144,   233,   165,
    -144,   302,   233,    50,   315,  -144,    50,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    50,    49,    51,    52,    53,     0,     2,     4,     0,
       0,     7,     1,     3,   115,   114,     5,    16,     0,    65,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      19,    15,    21,    22,    23,     0,    24,   100,    31,     0,
     102,     0,     0,     0,     0,     0,     0,    10,    64,   100,
      42,    40,   111,   110,    26,    27,    95,    97,    61,   103,
      94,    96,   100,   100,    63,     0,     0,    20,   100,   100,
      98,    99,   100,   100,     0,    77,    83,    84,     0,    91,
      93,    58,     0,    56,     0,    57,    71,    72,    62,    29,
      30,    25,   100,    28,     0,     9,    12,     0,     0,   106,
     109,     0,   105,     0,   100,     0,    18,   113,   112,    14,
      46,     0,     0,    87,     0,     0,   100,   100,   100,   100,
     100,   100,   100,   100,    68,    69,    70,    92,   100,    60,
       0,    48,    59,   101,     6,     0,    58,    13,     0,   104,
     100,    67,     0,    17,   100,   100,    90,    41,    44,    79,
      80,    81,    82,    85,    86,    88,    89,    73,     0,    54,
      55,    11,    60,    37,   108,    66,     0,     0,    45,     0,
       0,     0,    37,    33,     0,     0,    43,    47,    76,     0,
       0,    36,     0,    32,    38,    39,     0,    74,   100,     0,
      75,     0,   100,     0,     0,    35,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   186,  -144,  -144,  -144,  -144,    63,  -144,
    -144,  -144,    49,   -27,  -144,  -144,    27,  -144,  -144,  -144,
    -144,  -107,  -144,  -144,  -144,   166,    23,  -144,   -75,   172,
      -4,   -71,  -137,    73,  -144,  -144,  -144,   -57,   -44,   -17,
     -16,  -144,  -144,   -15,   -14,  -144,  -144,    -1,  -143,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    94,    95,    96,    16,
      30,    66,    31,    32,    33,   172,   173,    34,    35,    36,
      37,   181,   169,   109,   176,    38,    39,    82,    83,    40,
      41,    64,   127,    85,    86,    87,   179,    74,    75,    76,
      77,    78,    44,    79,    80,   101,   102,    54,   110,   148
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    43,    45,    46,    67,    98,    17,    20,   147,    52,
     129,   111,   112,    52,    42,    43,    45,    46,   100,   103,
     107,   105,   137,    11,    55,    12,   177,    19,   113,   114,
      11,   163,   107,   178,    69,    84,   187,   120,   121,    18,
      53,    89,    90,    91,    53,    93,   130,    58,   133,   190,
     108,    14,    19,   186,    52,   159,     1,     2,     3,     4,
     142,    48,   108,    14,   106,   162,     5,   184,   185,   180,
      97,    19,   149,   150,   151,   152,   153,   154,   155,   156,
      15,   131,    48,    48,   157,    53,   195,   166,   167,   197,
      47,    81,    15,    84,    49,    14,   164,    50,    19,    60,
      63,   189,    88,   132,   143,    61,    62,   128,    63,    51,
     144,   145,    56,     1,     2,     3,     4,    21,   136,    22,
      23,    24,    25,     5,    15,    57,    84,    19,    65,    26,
     104,    42,    43,    45,    46,    27,    92,   158,   115,   120,
     121,    67,   122,   123,   191,    52,    28,    29,   194,    63,
     104,    42,    43,    45,    46,   170,   134,   135,    97,    70,
      71,    19,   139,    26,   140,   171,    72,   121,   174,    27,
      73,   -78,   120,   121,   175,   122,    53,   124,   125,   126,
      28,    29,  -100,  -100,  -100,    70,    71,    19,   182,    26,
     188,   192,    72,    13,    52,    27,    73,   168,   161,   183,
      59,    68,   -78,   160,     0,     0,    28,    29,   116,   117,
     118,   119,     0,   120,   121,     0,   122,   123,     0,    70,
      71,    19,     0,    26,     0,    53,    72,     0,     0,    27,
      73,  -107,    70,    71,    19,     0,    26,     0,     0,    72,
      28,    29,    27,    73,   -78,    99,     0,     0,    70,    71,
      19,     0,    26,    28,    29,    72,     0,     0,    27,    73,
       0,     0,     0,     0,     0,     1,     2,     3,     4,    28,
      29,   116,   117,   118,   119,     5,   120,   121,     0,   122,
     123,   116,   117,   118,   119,   141,   120,   121,     0,   122,
     123,   116,   117,   118,   119,   165,   120,   121,     0,   122,
     123,     0,     0,   138,   116,   117,   118,   119,     0,   120,
     121,     0,   122,   123,     0,     0,   146,   116,   117,   118,
     119,     0,   120,   121,     0,   122,   123,     0,     0,   193,
     116,   117,   118,   119,     0,   120,   121,     0,   122,   123,
       0,     0,   196,   116,   117,   118,   119,     0,   120,   121,
       0,   122,   123,   116,   117,     0,     0,     0,   120,   121,
       0,   122,   123
};

static const yytype_int16 yycheck[] =
{
      17,    17,    17,    17,    31,    49,     9,    11,   115,     1,
      81,    68,    69,     1,    31,    31,    31,    31,    62,    63,
       1,    65,    97,     0,    25,     0,   169,    17,    72,    73,
       7,   138,     1,   170,    35,    39,   179,    20,    21,    37,
      32,    42,    43,    44,    32,    46,    34,    37,    92,   186,
      31,     1,    17,    34,     1,   130,     3,     4,     5,     6,
     104,    17,    31,     1,    65,   136,    13,   174,   175,     7,
      47,    17,   116,   117,   118,   119,   120,   121,   122,   123,
      30,    82,    17,    17,   128,    32,   193,   144,   145,   196,
      26,    37,    30,    97,    26,     1,   140,    26,    17,    19,
      28,     7,    37,    37,   105,    25,    26,    35,    28,    26,
     111,   112,    37,     3,     4,     5,     6,     7,    37,     9,
      10,    11,    12,    13,    30,    37,   130,    17,    14,    19,
      28,   148,   148,   148,   148,    25,    35,    35,    27,    20,
      21,   168,    23,    24,   188,     1,    36,    37,   192,    28,
      28,   168,   168,   168,   168,   158,    27,    34,   135,    15,
      16,    17,    27,    19,    34,     8,    22,    21,    27,    25,
      26,     1,    20,    21,    27,    23,    32,    38,    39,    40,
      36,    37,    38,    39,    40,    15,    16,    17,     8,    19,
      26,    26,    22,     7,     1,    25,    26,   148,   135,   172,
      28,    35,    32,   130,    -1,    -1,    36,    37,    15,    16,
      17,    18,    -1,    20,    21,    -1,    23,    24,    -1,    15,
      16,    17,    -1,    19,    -1,    32,    22,    -1,    -1,    25,
      26,    27,    15,    16,    17,    -1,    19,    -1,    -1,    22,
      36,    37,    25,    26,    27,    41,    -1,    -1,    15,    16,
      17,    -1,    19,    36,    37,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    36,
      37,    15,    16,    17,    18,    13,    20,    21,    -1,    23,
      24,    15,    16,    17,    18,    29,    20,    21,    -1,    23,
      24,    15,    16,    17,    18,    29,    20,    21,    -1,    23,
      24,    -1,    -1,    27,    15,    16,    17,    18,    -1,    20,
      21,    -1,    23,    24,    -1,    -1,    27,    15,    16,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    27,
      15,    16,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    -1,    27,    15,    16,    17,    18,    -1,    20,    21,
      -1,    23,    24,    15,    16,    -1,    -1,    -1,    20,    21,
      -1,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    13,    43,    44,    45,    46,
      47,    68,     0,    45,     1,    30,    51,    91,    37,    17,
      72,     7,     9,    10,    11,    12,    19,    25,    36,    37,
      52,    54,    55,    56,    59,    60,    61,    62,    67,    68,
      71,    72,    81,    82,    84,    85,    86,    26,    17,    26,
      26,    26,     1,    32,    89,    89,    37,    37,    37,    71,
      19,    25,    26,    28,    73,    14,    53,    55,    67,    89,
      15,    16,    22,    26,    79,    80,    81,    82,    83,    85,
      86,    37,    69,    70,    72,    75,    76,    77,    37,    89,
      89,    89,    35,    89,    48,    49,    50,    68,    80,    41,
      80,    87,    88,    80,    28,    80,    89,     1,    31,    65,
      90,    79,    79,    80,    80,    27,    15,    16,    17,    18,
      20,    21,    23,    24,    38,    39,    40,    74,    35,    73,
      34,    89,    37,    80,    27,    34,    37,    70,    27,    27,
      34,    29,    80,    89,    89,    89,    27,    63,    91,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    35,    70,
      75,    50,    73,    63,    80,    29,    79,    79,    54,    64,
      91,     8,    57,    58,    27,    27,    66,    90,    74,    78,
       7,    63,     8,    58,    63,    63,    34,    90,    26,     7,
      74,    80,    26,    27,    80,    63,    27,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    61,    62,    63,    64,    64,    65,    66,    67,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    75,    75,    76,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    85,    85,    86,    87,    87,    87,    88,    88,
      89,    89,    90,    90,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     5,     1,     2,     1,
       0,     3,     1,     2,     4,     1,     0,     3,     2,     0,
       2,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     7,     6,     7,     6,     2,     0,     7,     7,
       2,     4,     2,     3,     0,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       2,     1,     2,     2,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     3,     6,     3,     1,     1,     0,     3,
       3,     3,     3,     1,     1,     3,     3,     2,     3,     3,
       3,     1,     2,     1,     2,     2,     2,     2,     1,     1,
       0,     3,     1,     2,     4,     1,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1
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
#line 88 "parser.y"
              {
        root = create_ast_node(PROGRAM_NODE, "PROGRAM");
        add_child(root, (yyvsp[0].node));
    }
#line 1347 "parser.tab.c"
    break;

  case 3: /* functions: functions function  */
#line 99 "parser.y"
                       {
        (yyval.node) = create_ast_node(FUNCTIONS_NODE, "FUNCTIONS");
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
        }
#line 1357 "parser.tab.c"
    break;

  case 4: /* functions: function  */
#line 104 "parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1365 "parser.tab.c"
    break;

  case 5: /* function: function_head function_tail  */
#line 108 "parser.y"
                                      {
    (yyval.node) = create_ast_node(FUNCTION_NODE, "FUNCTION"); 
    add_child((yyval.node), (yyvsp[-1].node));
    add_child((yyval.node), (yyvsp[0].node));
    }
#line 1375 "parser.tab.c"
    break;

  case 6: /* function_head: return_type ID LPAREN parameters_optional RPAREN  */
#line 117 "parser.y"
                                                     {
        insert_new_symboltable_on_list(symbol_table_stack);
        (yyval.node) = create_ast_node(FUNCTION_HEAD_NODE, "FUNCTION_HEAD"); // Crear nodo de cabecera de función
        add_child((yyval.node), create_ast_node(TYPE_NODE, ((yyvsp[-4].node)->lexema))); // Añadir nodo de tipo como hijo
        add_child((yyval.node), create_ast_node(ID_NODE, ((yyvsp[-3].value).sval))); // Añadir nodo de identificador como hijo
        //$$ = create_and_add_node(FUNCTION_HEAD_NODE, "FUNCTION_HEAD", NULL); // Crear nodo de cabecera de función
        //add_child($$, create_ast_node(TYPE_NODE, $1.lexema)); // Añadir nodo de tipo como hijo
        //add_child($$, create_ast_node(ID_NODE, $2)); // Añadir nodo de identificador como hijo
        //add_child($$, $4); // Añadir los parámetros (si los hay) como hijos
    }
#line 1390 "parser.tab.c"
    break;

  case 7: /* return_type: type  */
#line 130 "parser.y"
        {
        (yyval.node) = create_ast_node(RETURN_TYPE_NODE, "RETURN_TYPE"); // Crear nodo de tipo de retorno
        add_child((yyval.node), create_ast_node(TYPE_NODE, (yyvsp[0].node)->lexema)); // Añadir nodo de tipo como hijo
    }
#line 1399 "parser.tab.c"
    break;

  case 9: /* parameters_optional: parameters  */
#line 137 "parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1407 "parser.tab.c"
    break;

  case 10: /* parameters_optional: %empty  */
#line 139 "parser.y"
                    {
        (yyval.node) = NULL;
    }
#line 1415 "parser.tab.c"
    break;

  case 11: /* parameters: parameters COMMA parameter  */
#line 145 "parser.y"
                               {   
        add_child((yyvsp[-2].node), (yyvsp[0].node)); // Añadir nuevo parámetro a la lista de parámetros
        (yyval.node) = (yyvsp[-2].node); // Devolver la lista de parámetros actualizada
    }
#line 1424 "parser.tab.c"
    break;

  case 12: /* parameters: parameter  */
#line 149 "parser.y"
                {
    }
#line 1431 "parser.tab.c"
    break;

  case 13: /* parameter: type new_variable  */
#line 154 "parser.y"
                      {
        (yyval.node) = create_ast_node(PARAMETER_NODE, "PARAMETER"); // Crear nodo de parámetro
        add_child((yyval.node), create_ast_node(TYPE_NODE, (yyvsp[-1].node)->lexema)); // Añadir nodo de tipo como hijo
        add_child((yyval.node), (yyvsp[0].node)); // Añadir nodo de identificador como hijo
    }
#line 1441 "parser.tab.c"
    break;

  case 14: /* function_tail: lbrace_token statements_optional return_optional endtail_function  */
#line 162 "parser.y"
                                                                      {
        (yyval.node) = create_ast_node(FUNCTION_TAIL_NODE, "FUNCTION_TAIL"); // Crear nodo de cola de función
        add_child((yyval.node), (yyvsp[-2].node)); // Añadir las declaraciones y las instrucciones como hijos
        if ((yyvsp[-1].node) != NULL) {
            add_child((yyval.node), (yyvsp[-1].node)); // Añadir el nodo de retorno (si lo hay) como hijo
        }
    }
#line 1453 "parser.tab.c"
    break;

  case 15: /* statements_optional: statements  */
#line 172 "parser.y"
               {
        if (((yyvsp[0].node) != NULL)) {
            (yyval.node) = create_ast_node(STATEMENTS_NODE, "STATEMENTS"); // Crear nodo de instrucciones
            add_child((yyval.node), (yyvsp[0].node)); // Añadir las instrucciones como hijo
        } else {
            (yyval.node) = NULL;
        }
    }
#line 1466 "parser.tab.c"
    break;

  case 16: /* statements_optional: %empty  */
#line 179 "parser.y"
                    {
        (yyval.node) = NULL;
    }
#line 1474 "parser.tab.c"
    break;

  case 17: /* return_optional: RETURN expression semi_token  */
#line 185 "parser.y"
                                 {
        (yyval.node) = create_ast_node(RETURN_NODE, "RETURN"); // Crear nodo de retorno
        add_child((yyval.node), (yyvsp[-1].node)); // Añadir la expresión como hijo
    }
#line 1483 "parser.tab.c"
    break;

  case 18: /* return_optional: RETURN semi_token  */
#line 189 "parser.y"
                        {
        (yyval.node) = create_ast_node(RETURN_NODE, "RETURN"); // Crear nodo de retorno
    }
#line 1491 "parser.tab.c"
    break;

  case 19: /* return_optional: %empty  */
#line 192 "parser.y"
                  {
        (yyval.node) = NULL;
    }
#line 1499 "parser.tab.c"
    break;

  case 20: /* statements: statements statement  */
#line 201 "parser.y"
                         { 
        (yyval.node) = create_ast_node(STATEMENT_LIST_NODE, "STATEMENTS");
        add_child((yyval.node), (yyvsp[-1].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1509 "parser.tab.c"
    break;

  case 22: /* statement: if_statement  */
#line 209 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1517 "parser.tab.c"
    break;

  case 23: /* statement: for_statement  */
#line 211 "parser.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1525 "parser.tab.c"
    break;

  case 24: /* statement: while_statement  */
#line 213 "parser.y"
                       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1533 "parser.tab.c"
    break;

  case 25: /* statement: assigment semi_token  */
#line 215 "parser.y"
                             {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1541 "parser.tab.c"
    break;

  case 26: /* statement: CONTINUE semi_token  */
#line 217 "parser.y"
                           {
        (yyval.node) = create_ast_node(CONTINUE_NODE,"");
    }
#line 1549 "parser.tab.c"
    break;

  case 27: /* statement: BREAK semi_token  */
#line 219 "parser.y"
                         {
        (yyval.node) = create_ast_node(BREAK_NODE,"");
    }
#line 1557 "parser.tab.c"
    break;

  case 28: /* statement: function_call semi_token  */
#line 221 "parser.y"
                                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1565 "parser.tab.c"
    break;

  case 29: /* statement: incr_id semi_token  */
#line 223 "parser.y"
                          {
        (yyval.node) = create_ast_node(INCR_ID_NODE_NODE,"INCR_ID_NODE_NODE");
        add_child((yyval.node),(yyvsp[-1].node));
    }
#line 1574 "parser.tab.c"
    break;

  case 30: /* statement: decr_id semi_token  */
#line 226 "parser.y"
                          {
        (yyval.node) = create_ast_node(DECR_ID_NODE_NODE,"DECR_ID_NODE_NODE");
        add_child((yyval.node),(yyvsp[-1].node));
    }
#line 1583 "parser.tab.c"
    break;

  case 31: /* statement: declaration  */
#line 229 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1591 "parser.tab.c"
    break;

  case 32: /* if_statement: IF LPAREN expression RPAREN tail else_if optional_else  */
#line 235 "parser.y"
                                                               {
        (yyval.node) = create_ast_node(IF_STATEMENT_NODE, "IF_STATEMENT_NODE");
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-1].node));
        if((yyvsp[0].node) != NULL){
            add_child((yyval.node), (yyvsp[0].node));
        }
    }
#line 1605 "parser.tab.c"
    break;

  case 33: /* if_statement: IF LPAREN expression RPAREN tail optional_else  */
#line 245 "parser.y"
                                                       {
        
        (yyval.node) = create_ast_node(IF_STATEMENT_NODE, "IF_STATEMENT"); 
        add_child((yyval.node), (yyvsp[-3].node)); 
        add_child((yyval.node), (yyvsp[-1].node));  
        if ((yyvsp[0].node) != NULL) {
            add_child((yyval.node), (yyvsp[0].node)); 
        }
    }
#line 1619 "parser.tab.c"
    break;

  case 34: /* else_if: else_if ELSE IF LPAREN expression RPAREN tail  */
#line 257 "parser.y"
                                                      {
        (yyval.node) = create_ast_node(ELSE_IF_NODE, "ELSE_IF");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node)); 
    }
#line 1629 "parser.tab.c"
    break;

  case 35: /* else_if: ELSE IF LPAREN expression RPAREN tail  */
#line 263 "parser.y"
                                              {
        (yyval.node) = create_ast_node(ELSE_IF_NODE, "ELSE_IF");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1639 "parser.tab.c"
    break;

  case 36: /* optional_else: ELSE tail  */
#line 271 "parser.y"
              {
        (yyval.node) = create_ast_node(ELSE_NODE, "ELSE");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1648 "parser.tab.c"
    break;

  case 37: /* optional_else: %empty  */
#line 276 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1656 "parser.tab.c"
    break;

  case 38: /* for_statement: inicio_for declaration optional_expression semi_token optional_expression RPAREN tail  */
#line 282 "parser.y"
                                                                                           {
        (yyval.node) = create_ast_node(FOR_STATEMENT_NODE, "FOR_DECLARATION_STATEMENT");
        add_child((yyval.node), (yyvsp[-5].node));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1668 "parser.tab.c"
    break;

  case 39: /* for_statement: inicio_for semi_token optional_expression semi_token optional_expression RPAREN tail  */
#line 290 "parser.y"
                                                                                         {
        (yyval.node) = create_ast_node(FOR_STATEMENT_NODE, "FOR_STATEMENT");
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1679 "parser.tab.c"
    break;

  case 40: /* inicio_for: FOR LPAREN  */
#line 299 "parser.y"
               {
        insert_new_symboltable_on_list(symbol_table_stack);
    }
#line 1687 "parser.tab.c"
    break;

  case 41: /* while_statement: inicio_while optional_expression RPAREN tail  */
#line 306 "parser.y"
                                                 {
        (yyval.node) = create_ast_node(WHILE_STATEMENT_NODE, "WHILE_STATEMENT");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1697 "parser.tab.c"
    break;

  case 42: /* inicio_while: WHILE LPAREN  */
#line 315 "parser.y"
                 {
        insert_new_symboltable_on_list(symbol_table_stack);
    }
#line 1705 "parser.tab.c"
    break;

  case 43: /* tail: lbrace_token optional_statements end_tail  */
#line 321 "parser.y"
                                              {
        (yyval.node) = create_ast_node(TAIL_NODE, "TAIL");
        if ((yyvsp[-1].node) != NULL) {
            add_child((yyval.node), (yyvsp[-1].node)); // Añadir las instrucciones opcionales como hijo
        }
    }
#line 1716 "parser.tab.c"
    break;

  case 44: /* optional_statements: %empty  */
#line 330 "parser.y"
                {
        (yyval.node) = NULL; // Nodo vacío si no hay instrucciones
    }
#line 1724 "parser.tab.c"
    break;

  case 45: /* optional_statements: statements  */
#line 334 "parser.y"
               {
        (yyval.node) = (yyvsp[0].node); // Devolver el nodo de instrucciones
    }
#line 1732 "parser.tab.c"
    break;

  case 46: /* endtail_function: rbrace_token  */
#line 341 "parser.y"
                 {
        SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
        print_symbol_table(st);
        if(estoy_main){
            estoy_main = 0; //Salir del main
        }
    }
#line 1744 "parser.tab.c"
    break;

  case 47: /* end_tail: rbrace_token  */
#line 351 "parser.y"
                 {
        SymbolTable* st = pop_symboltable_stack(symbol_table_stack);
        print_symbol_table(st);
    }
#line 1753 "parser.tab.c"
    break;

  case 48: /* declaration: type names semi_token  */
#line 359 "parser.y"
                          {
        (yyval.node) = create_ast_node(DECLARATION_NODE, "DECLARATION"); // Crear nodo de declaración
        add_child((yyval.node), (yyvsp[-2].node)); // Añadir el tipo como hijo
        add_child((yyval.node), (yyvsp[-1].node)); // Añadir los nombres como hijo
    }
#line 1763 "parser.tab.c"
    break;

  case 49: /* type: INT  */
#line 368 "parser.y"
        {
        (yyval.node) = create_ast_node(TYPE_NODE, "INT");
    }
#line 1771 "parser.tab.c"
    break;

  case 50: /* type: CHAR  */
#line 371 "parser.y"
           {
        (yyval.node) = create_ast_node(TYPE_NODE, "CHAR");
    }
#line 1779 "parser.tab.c"
    break;

  case 51: /* type: FLOAT  */
#line 374 "parser.y"
            {
        (yyval.node) = create_ast_node(TYPE_NODE, "FLOAT");
    }
#line 1787 "parser.tab.c"
    break;

  case 52: /* type: DOUBLE  */
#line 377 "parser.y"
             {
        (yyval.node) = create_ast_node(TYPE_NODE, "DOUBLE");
    }
#line 1795 "parser.tab.c"
    break;

  case 53: /* type: VOID  */
#line 380 "parser.y"
           {
        (yyval.node) = create_ast_node(TYPE_NODE, "VOID");
    }
#line 1803 "parser.tab.c"
    break;

  case 54: /* names: names COMMA new_variable  */
#line 386 "parser.y"
                             {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[0].node)); // Añadir la nueva variable como hijo
    }
#line 1812 "parser.tab.c"
    break;

  case 55: /* names: names COMMA init  */
#line 390 "parser.y"
                       {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[0].node)); // Añadir la inicialización como hijo
    }
#line 1821 "parser.tab.c"
    break;

  case 56: /* names: new_variable  */
#line 394 "parser.y"
                   {
        (yyval.node) = create_ast_node(NAMES_NODE, "NAMES"); // Crear nodo de nombres
        add_child((yyval.node), (yyvsp[0].node)); // Añadir la nueva variable como hijo
    }
#line 1830 "parser.tab.c"
    break;

  case 57: /* names: init  */
#line 398 "parser.y"
           {
        (yyval.node) = create_ast_node(NAMES_NODE, "NAMES"); // Crear nodo de nombres
        add_child((yyval.node), (yyvsp[0].node)); // Añadir la inicialización como hijo
    }
#line 1839 "parser.tab.c"
    break;

  case 58: /* new_variable: ID  */
#line 405 "parser.y"
       {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            insert_word_on_top(symbol_table_stack,(yyvsp[0].value).sval);
            (yyval.node) = create_ast_node(VARIABLE_NODE, (yyvsp[0].value).sval);
        }
        else{
            print_error_variable_redeclarada(((yyvsp[0].value).sval), lineno);
            (yyval.node) = NULL;
        }
    }
#line 1854 "parser.tab.c"
    break;

  case 59: /* new_variable: pointer ID  */
#line 415 "parser.y"
                 {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            insert_word_on_top(symbol_table_stack,(yyvsp[0].value).sval);
            (yyval.node) = create_ast_node(VARIABLE_NODE, (yyvsp[0].value).sval);
        }
        else{
            print_error_variable_redeclarada(((yyvsp[0].value).sval), lineno);
            (yyval.node) = NULL;
        }
    }
#line 1869 "parser.tab.c"
    break;

  case 60: /* new_variable: ID array  */
#line 425 "parser.y"
               {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[-1].value).sval) == NULL){
            insert_word_on_top(symbol_table_stack, ((yyvsp[-1].value).sval));
            (yyval.node) = create_ast_node(VARIABLE_NODE, (yyvsp[-1].value).sval);
        }
        else{
            print_error_variable_redeclarada (((yyvsp[-1].value).sval), lineno);
            (yyval.node) = NULL;
        }
    }
#line 1884 "parser.tab.c"
    break;

  case 61: /* variable: ID  */
#line 437 "parser.y"
             {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            print_error_variable_no_declarada(((yyvsp[0].value).sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
            (yyval.node) = NULL;
        } else{
            (yyval.node) = create_ast_node(VARIABLE_NODE, (yyvsp[0].value).sval);
        }
    }
#line 1898 "parser.tab.c"
    break;

  case 62: /* variable: pointer ID  */
#line 446 "parser.y"
                 {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[0].value).sval) == NULL){
            print_error_variable_no_declarada(((yyvsp[0].value).sval), lineno);
            (yyval.node) = NULL;
            //insert_word_on_top(symbol_table_stack,yytext);
        } else{
            (yyval.node) = create_ast_node(VARIABLE_NODE, (yyvsp[0].value).sval);
        }
    }
#line 1912 "parser.tab.c"
    break;

  case 63: /* variable: ID array  */
#line 455 "parser.y"
               {
        if(find_word_on_all_symboltablelist(symbol_table_stack,(yyvsp[-1].value).sval) == NULL){
            print_error_variable_no_declarada(((yyvsp[-1].value).sval), lineno);
            //insert_word_on_top(symbol_table_stack,yytext);
            (yyval.node) = NULL;
        } else{
            (yyval.node) = create_ast_node(VARIABLE_NODE, (yyvsp[-1].value).sval);
        }
    }
#line 1926 "parser.tab.c"
    break;

  case 64: /* pointer: pointer MULOP  */
#line 467 "parser.y"
                  {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1934 "parser.tab.c"
    break;

  case 65: /* pointer: MULOP  */
#line 470 "parser.y"
            {
        (yyval.node) = create_ast_node(POINTER_NODE, "*");
    }
#line 1942 "parser.tab.c"
    break;

  case 68: /* constant: ICONST  */
#line 479 "parser.y"
           {               
        (yyval.node) = create_ast_node(CONSTANT_NODE, intToStr((yyvsp[0].value).ival));
    }
#line 1950 "parser.tab.c"
    break;

  case 69: /* constant: FCONST  */
#line 482 "parser.y"
             {
        (yyval.node) = NULL;
    }
#line 1958 "parser.tab.c"
    break;

  case 70: /* constant: CCONST  */
#line 485 "parser.y"
             {
        (yyval.node) = NULL;
    }
#line 1966 "parser.tab.c"
    break;

  case 71: /* init: var_init  */
#line 492 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1974 "parser.tab.c"
    break;

  case 72: /* init: array_init  */
#line 494 "parser.y"
                   {
        (yyval.node) = NULL;
    }
#line 1982 "parser.tab.c"
    break;

  case 73: /* var_init: ID ASSIGN expression  */
#line 500 "parser.y"
                        {
        if( (find_word_on_start_symboltablelist(symbol_table_stack,(yyvsp[-2].value).sval)) == NULL){
            
            insert_word_on_top(symbol_table_stack,(yyvsp[-2].value).sval);
            (yyval.node) = create_ast_node(VAR_INIT_NODE, "VAR_INIT");
            add_child((yyval.node), create_ast_node(ID_NODE, (yyvsp[-2].value).sval));
            add_child((yyval.node), (yyvsp[0].node));
        }
        else{
            print_error_variable_redeclarada (((yyvsp[-2].value).sval), lineno);
            (yyval.node) = NULL;
        }
    }
#line 2000 "parser.tab.c"
    break;

  case 75: /* values: values COMMA constant  */
#line 518 "parser.y"
                          {
        (yyval.node) = (yyvsp[-2].node);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2009 "parser.tab.c"
    break;

  case 76: /* values: constant  */
#line 521 "parser.y"
                 {
        (yyval.node) = create_ast_node(VALUES_NODE, "VALUES");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2018 "parser.tab.c"
    break;

  case 77: /* optional_expression: expression  */
#line 528 "parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2026 "parser.tab.c"
    break;

  case 78: /* optional_expression: %empty  */
#line 530 "parser.y"
                    {
        (yyval.node) = NULL;
    }
#line 2034 "parser.tab.c"
    break;

  case 79: /* expression: expression ADDOP expression  */
#line 536 "parser.y"
                                {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "ADDOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2044 "parser.tab.c"
    break;

  case 80: /* expression: expression MINUSOP expression  */
#line 540 "parser.y"
                                      {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "MINUSOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2054 "parser.tab.c"
    break;

  case 81: /* expression: expression MULOP expression  */
#line 544 "parser.y"
                                    {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "MULOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2064 "parser.tab.c"
    break;

  case 82: /* expression: expression DIVOP expression  */
#line 548 "parser.y"
                                    {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "DIVOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2074 "parser.tab.c"
    break;

  case 83: /* expression: incr_id  */
#line 552 "parser.y"
                {
        (yyval.node) = create_ast_node(INCR_ID_NODE_NODE, "INCR_ID_NODE_NODE");
        add_child((yyval.node),(yyvsp[0].node));
    }
#line 2083 "parser.tab.c"
    break;

  case 84: /* expression: decr_id  */
#line 555 "parser.y"
                {
        (yyval.node) = create_ast_node(DECR_ID_NODE_NODE, "DECR_ID_NODE_NODE");
        add_child((yyval.node),(yyvsp[0].node));
    }
#line 2092 "parser.tab.c"
    break;

  case 85: /* expression: expression OROP expression  */
#line 558 "parser.y"
                                   {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "OROP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2102 "parser.tab.c"
    break;

  case 86: /* expression: expression ANDOP expression  */
#line 562 "parser.y"
                                    {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "ANDOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2112 "parser.tab.c"
    break;

  case 87: /* expression: NOTOP expression  */
#line 566 "parser.y"
                         {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "NOTOP");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2121 "parser.tab.c"
    break;

  case 88: /* expression: expression EQUOP expression  */
#line 569 "parser.y"
                                    {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "EQUOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2131 "parser.tab.c"
    break;

  case 89: /* expression: expression RELOP expression  */
#line 573 "parser.y"
                                    {
        (yyval.node) = create_ast_node(EXPRESSION_NODE, "RELOP");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2141 "parser.tab.c"
    break;

  case 90: /* expression: LPAREN expression RPAREN  */
#line 577 "parser.y"
                                 {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2149 "parser.tab.c"
    break;

  case 91: /* expression: var_ref  */
#line 579 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2157 "parser.tab.c"
    break;

  case 92: /* expression: sign constant  */
#line 581 "parser.y"
                      {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2165 "parser.tab.c"
    break;

  case 93: /* expression: function_call  */
#line 583 "parser.y"
                      {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2173 "parser.tab.c"
    break;

  case 94: /* incr_id: ID INCR  */
#line 590 "parser.y"
           {
        if (find_word_on_all_symboltablelist(symbol_table_stack, (yyvsp[-1].value).sval) == NULL) {
            print_error_variable_no_declarada (((yyvsp[-1].value).sval), lineno);
            (yyval.node) = NULL;
        } else{
            //
            (yyval.node) = create_ast_node(ID_INCR_NODE, (yyvsp[-1].value).sval);
        }
    }
#line 2187 "parser.tab.c"
    break;

  case 95: /* incr_id: INCR ID  */
#line 599 "parser.y"
              {
        if (find_word_on_all_symboltablelist(symbol_table_stack, (yyvsp[0].value).sval) == NULL) {
            print_error_variable_no_declarada (((yyvsp[0].value).sval), lineno);
            (yyval.node) = NULL;
        } else{
            (yyval.node) = create_ast_node(INCR_ID_NODE, (yyvsp[0].value).sval);
        }
    }
#line 2200 "parser.tab.c"
    break;

  case 96: /* decr_id: ID DECR  */
#line 610 "parser.y"
           {
        if (find_word_on_all_symboltablelist(symbol_table_stack, (yyvsp[-1].value).sval) == NULL) {
            print_error_variable_no_declarada (((yyvsp[-1].value).sval), lineno);
            (yyval.node) = NULL;
        } else{
            //
            (yyval.node) = create_ast_node(ID_DECR_NODE, (yyvsp[-1].value).sval);
        }
    }
#line 2214 "parser.tab.c"
    break;

  case 97: /* decr_id: DECR ID  */
#line 619 "parser.y"
              {
        if (find_word_on_all_symboltablelist(symbol_table_stack, (yyvsp[0].value).sval) == NULL) {
            print_error_variable_no_declarada (((yyvsp[0].value).sval), lineno);
            (yyval.node) = NULL;
        } else{
            (yyval.node) = create_ast_node(DECR_ID_NODE, (yyvsp[0].value).sval);
        }
    }
#line 2227 "parser.tab.c"
    break;

  case 98: /* sign: ADDOP  */
#line 630 "parser.y"
          {
        (yyval.node) = create_ast_node(ADD_NODE, "");
    }
#line 2235 "parser.tab.c"
    break;

  case 99: /* sign: MINUSOP  */
#line 633 "parser.y"
              {
        (yyval.node) = create_ast_node(MINUS_NODE,"");
    }
#line 2243 "parser.tab.c"
    break;

  case 100: /* sign: %empty  */
#line 636 "parser.y"
                  {
        (yyval.node) = NULL;
    }
#line 2251 "parser.tab.c"
    break;

  case 101: /* assigment: var_ref ASSIGN expression  */
#line 642 "parser.y"
                              {
        (yyval.node) = create_ast_node(ASSIGNMENT_NODE, "ASSIGNMENT");
        add_child((yyval.node), (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2261 "parser.tab.c"
    break;

  case 102: /* var_ref: variable  */
#line 650 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2269 "parser.tab.c"
    break;

  case 103: /* var_ref: REFER variable  */
#line 653 "parser.y"
                     {
    /*
    $$ = create_ast_node(REFERENCE_NODE, "REFERENCE", NULL); // Crear nodo de referencia
    add_child($$, $2); // Añadir la variable como hijo
    */
    }
#line 2280 "parser.tab.c"
    break;

  case 104: /* function_call: ID LPAREN call_params RPAREN  */
#line 662 "parser.y"
                                 {
        (yyval.node) = create_ast_node(FUNCTION_CALL_NODE, (yyvsp[-3].value).sval); // Crear nodo de llamada a función
        if ((yyvsp[-1].node) != NULL) {
            add_child((yyval.node), (yyvsp[-1].node)); // Añadir los parámetros de llamada como hijos
        }
    }
#line 2291 "parser.tab.c"
    break;

  case 105: /* call_params: call_param  */
#line 671 "parser.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2299 "parser.tab.c"
    break;

  case 106: /* call_params: STRING  */
#line 673 "parser.y"
               {
        (yyval.node) = create_ast_node(STRING_NODE, (yyvsp[0].value).sval);
    }
#line 2307 "parser.tab.c"
    break;

  case 107: /* call_params: %empty  */
#line 675 "parser.y"
                  {
        (yyval.node) = NULL;
    }
#line 2315 "parser.tab.c"
    break;

  case 108: /* call_param: call_param COMMA expression  */
#line 680 "parser.y"
                                {
        (yyval.node) = create_and_add_node(CALL_PARAM_NODE,"CALL_PARAM_NODE",(yyvsp[0].node));
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 2324 "parser.tab.c"
    break;

  case 109: /* call_param: expression  */
#line 683 "parser.y"
                  {
        (yyval.node) = create_ast_node(CALL_PARAM_NODE, "CALL_PARAM_NODE");
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 2333 "parser.tab.c"
    break;

  case 111: /* semi_token: error  */
#line 688 "parser.y"
                          {yyerror("Falta ; al final de la instruccion"); yyerrok;}
#line 2339 "parser.tab.c"
    break;

  case 113: /* rbrace_token: error  */
#line 689 "parser.y"
                             {yyerror("Falta } al final"); yyerrok;}
#line 2345 "parser.tab.c"
    break;

  case 115: /* lbrace_token: error  */
#line 690 "parser.y"
                              {yyerror("Esperaba un {"); yyerrok;}
#line 2351 "parser.tab.c"
    break;


#line 2355 "parser.tab.c"

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

#line 692 "parser.y"


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


/*
bison -d parser.y
gcc -o programa parser.tab.c lex.yy.c
gcc -o programa ast.c parser.tab.c lex.yy.c
./programa test2.c
*/
int main (int argc, char *argv[]){
    symbol_table_stack = create_symboltable_list();
    insert_new_symboltable_on_list(symbol_table_stack);
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
    print_AST_tree(root, 0);
	printf("bye bye!\n");
	
	// symbol table dump
	//yyout = fopen("symtab_dump.out", "w");
	//symtab_dump(yyout);
	//fclose(yyout);
	
	return flag;
}
