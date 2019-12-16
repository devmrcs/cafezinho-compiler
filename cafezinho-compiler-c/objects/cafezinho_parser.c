/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cafezinho_parser.y"

/* Secao prologo*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cafezinho_types.h"

extern char * yytext;
extern int yylex();
extern int numLinha;
extern FILE* yyin;
extern int errorLexical;
extern int errorInput;

void yyerror(char const *messageError);

//Definicões das funções utilizadas na Árvore Abstrata
NodeTree* makeNode(TypesOperators typeOperator,  int line, NodeTree* nodeTree1, NodeTree* nodeTree2, char* lexema);
NodeTree* makeNodeTernary(TypesOperators typeOperator,  int line, NodeTree* nodeTree1, NodeTree* nodeTree2, NodeTree* nodeTree3, char* lexema);
void walkTree(NodeTree* nodeInTree, int count);
void getNameOperatorAndLine(NodeTree* nodeInTree, char* nameOperator);
void printTabs(int count);

NodeTree* rootTree;
char nameOperator[200];
char nameTypeOperator[200];
//FIM ARVORE

//PILHAS
typedef struct nodeStackTree {
    struct nodeStackTree *nodeStackTreeLeft;
    struct nodeStackTree *nodeStackTreeRight;
    char strTypeOperator[40];
    char id[40];
} NodeTreeStack;

typedef struct stackNode {
    struct nodeStackTree* pointerNodeStackTree;
    struct stackNode* next;
}NodeStack;

void preorderStackSearch(NodeTreeStack *root);
void inserirNoArvorePilha(NodeTreeStack **root,char identifier[], char strTypeOperator[]);
void printStack (NodeStack *topStack);
void inserir (NodeStack **topStack, char lexema[], char strTypeOperator[]);

NodeStack* topStack = NULL;

void getTypeOperator2String(TypesOperators typeOperator, char* nameTypeOperator);


#line 122 "cafezinho_parser.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CAFEZINHO_PARSER_H_INCLUDED
# define YY_YY_CAFEZINHO_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    CONSCAR = 259,
    CONSINT = 260,
    CADEIACARACTERES = 261,
    PROGRAMA = 262,
    CAR = 263,
    INT = 264,
    RETORNE = 265,
    LEIA = 266,
    ESCREVA = 267,
    NOVALINHA = 268,
    SE = 269,
    ENTAO = 270,
    SENAO = 271,
    ENQUANTO = 272,
    EXECUTE = 273,
    MAIS = 274,
    MENOS = 275,
    VEZES = 276,
    DIVIDIDO = 277,
    RESTO = 278,
    IGUAL = 279,
    IGUALIGUAL = 280,
    MAIOR = 281,
    MAIORIGUAL = 282,
    MENOR = 283,
    MENORIGUAL = 284,
    E = 285,
    OU = 286,
    PAREN_E = 287,
    PAREN_D = 288,
    COLCH_E = 289,
    COLCH_D = 290,
    CHAVE_E = 291,
    CHAVE_D = 292,
    INTERROGACAO = 293,
    EXCLAMACAO = 294,
    DOISPONTOS = 295,
    PONTOVIRGULA = 296,
    VIRGULA = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "cafezinho_parser.y"

    int nlinha;
    char* tokenLexema;
    NodeTree* PointerTreeNode;

#line 214 "cafezinho_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

#define YYUNDEFTOK  2
#define YYMAXUTOK   297

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    87,    91,    96,   101,   105,   112,   116,
     120,   124,   128,   129,   133,   137,   141,   145,   152,   153,
     157,   158,   162,   169,   170,   174,   175,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   193,   197,
     198,   202,   203,   207,   208,   212,   213,   217,   218,   219,
     223,   224,   225,   226,   227,   231,   232,   233,   237,   238,
     239,   240,   244,   245,   246,   250,   251,   255,   256,   257,
     258,   259,   260,   261,   265,   266
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONSCAR", "CONSINT",
  "CADEIACARACTERES", "PROGRAMA", "CAR", "INT", "RETORNE", "LEIA",
  "ESCREVA", "NOVALINHA", "SE", "ENTAO", "SENAO", "ENQUANTO", "EXECUTE",
  "MAIS", "MENOS", "VEZES", "DIVIDIDO", "RESTO", "IGUAL", "IGUALIGUAL",
  "MAIOR", "MAIORIGUAL", "MENOR", "MENORIGUAL", "E", "OU", "PAREN_E",
  "PAREN_D", "COLCH_E", "COLCH_D", "CHAVE_E", "CHAVE_D", "INTERROGACAO",
  "EXCLAMACAO", "DOISPONTOS", "PONTOVIRGULA", "VIRGULA", "$accept",
  "Programa", "DeclFuncVar", "DeclProg", "DeclVar", "DeclFunc",
  "ListaParametros", "ListaParametrosCont", "Bloco", "ListaDeclVar",
  "Tipo", "ListaComando", "Comando", "Expr", "AssignExpr", "CondExpr",
  "OrExpr", "AndExpr", "EqExpr", "DesigExpr", "AddExpr", "MulExpr",
  "UnExpr", "LValueExpr", "PrimExpr", "ListExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,  -120,  -120,     9,    12,    22,  -120,    -7,  -120,    82,
      84,  -120,    84,    27,    38,    48,    84,    10,    50,    62,
    -120,   101,    91,    37,    84,  -120,    -6,  -120,  -120,    98,
     114,    58,    78,    93,    97,    79,    98,  -120,    79,  -120,
    -120,   111,    55,   106,  -120,  -120,    19,   125,    -8,   112,
      90,   110,  -120,   132,  -120,    43,    -7,    71,   115,   153,
    -120,  -120,    95,    98,   118,   126,   120,   121,   122,  -120,
      98,    98,    42,  -120,   131,  -120,  -120,  -120,  -120,   103,
      98,   103,   103,   141,   103,   103,   103,   103,   103,   103,
     103,   103,   103,    98,   161,   127,  -120,   134,    84,   129,
     136,  -120,  -120,     6,   137,  -120,    98,  -120,  -120,  -120,
     140,   142,    98,  -120,   125,   138,    -8,   112,   103,    90,
      90,    90,    90,   110,   110,  -120,  -120,  -120,  -120,   139,
      84,   135,  -120,    84,   115,  -120,    98,   143,   144,   165,
     158,   146,   103,   112,   115,  -120,    84,  -120,  -120,  -120,
    -120,    55,    55,  -120,  -120,   145,  -120,   166,  -120,    84,
      55,  -120,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    24,    23,     0,     0,     0,     1,     0,     2,    10,
      20,     7,    12,     0,     0,     0,     6,     0,     0,     0,
      13,     0,     0,    10,     6,     5,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    27,
      37,     0,    25,     0,    38,    39,    41,    44,    46,    49,
      54,    57,    61,     0,    64,    10,     0,    14,    10,     0,
       8,     3,     0,     0,     0,    66,     0,     0,     0,    33,
       0,     0,    70,    62,     0,    63,    18,    26,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,    68,    74,     0,     0,    29,     0,    30,    32,    31,
       0,     0,     0,    73,    43,     0,    45,    47,     0,    51,
      52,    50,    53,    55,    56,    58,    59,    60,    40,     0,
      20,    15,    16,     6,    10,    67,     0,    69,     0,     0,
       0,     0,     0,    48,    10,    21,     0,     4,     9,    75,
      65,     0,     0,    69,    42,     0,    17,    34,    36,    20,
       0,    22,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,   -12,  -120,   -22,  -120,  -120,   -90,    -1,  -119,
     -10,   147,  -117,   -26,   -55,    41,  -120,   105,   104,   -66,
      59,    65,    60,   157,    35,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     8,    15,    16,    19,    20,    40,    17,
       5,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    60,    21,    64,    25,    68,    11,   102,   132,     6,
      74,   145,    61,    26,    27,    28,   117,    82,   -66,     7,
      29,    30,    31,    32,    33,     9,    62,    34,    63,    10,
      35,    83,    22,    95,   157,   158,    99,   104,   128,   135,
     161,    23,    36,   162,   110,   111,    10,    37,   136,    38,
      79,    39,   143,    55,   115,    96,   156,    80,    26,    27,
      28,    26,    27,    28,    67,    29,    30,    31,    32,    33,
      73,    59,    34,    75,    62,    35,   112,    94,    35,    14,
     138,   149,    72,    27,    28,    14,   141,    36,    21,    24,
      36,    10,     1,     2,    38,    56,    39,    38,    26,    27,
      28,    26,    27,    28,    57,    97,    72,    27,    28,    88,
      89,    36,   148,    98,    12,    35,    13,    65,    35,    69,
      18,   147,   155,    35,    14,    70,    58,    36,   101,    71,
      36,    90,    91,    92,    38,    36,    21,    38,    84,    85,
      86,    87,    38,   119,   120,   121,   122,    78,    76,    18,
     125,   126,   127,   123,   124,    81,    93,    14,   100,   105,
     106,   107,   108,   109,   113,   118,   129,   -65,   130,   131,
     133,   134,   137,   139,   144,   140,   152,   146,   142,   150,
     151,   153,   160,   154,   114,   116,   159,    66,     0,    77
};

static const yytype_int16 yycheck[] =
{
      10,    23,    12,    29,    16,    31,     7,    62,    98,     0,
      36,   130,    24,     3,     4,     5,    82,    25,    24,     7,
      10,    11,    12,    13,    14,     3,    32,    17,    34,    36,
      20,    39,     5,    55,   151,   152,    58,    63,    93,    33,
     159,     3,    32,   160,    70,    71,    36,    37,    42,    39,
      31,    41,   118,     3,    80,    56,   146,    38,     3,     4,
       5,     3,     4,     5,     6,    10,    11,    12,    13,    14,
      35,    34,    17,    38,    32,    20,    34,    34,    20,    42,
     106,   136,     3,     4,     5,    42,   112,    32,    98,    41,
      32,    36,     8,     9,    39,    33,    41,    39,     3,     4,
       5,     3,     4,     5,     3,    34,     3,     4,     5,    19,
      20,    32,   134,    42,    32,    20,    34,     3,    20,    41,
     130,   133,   144,    20,    42,    32,    35,    32,    33,    32,
      32,    21,    22,    23,    39,    32,   146,    39,    26,    27,
      28,    29,    39,    84,    85,    86,    87,    41,    37,   159,
      90,    91,    92,    88,    89,    30,    24,    42,     5,    41,
      34,    41,    41,    41,    33,    24,     5,    24,    41,    35,
      41,    35,    35,    33,    35,    33,    18,    42,    40,    35,
      15,    35,    16,   142,    79,    81,    41,    30,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    44,    45,    53,     0,     7,    46,     3,
      36,    51,    32,    34,    42,    47,    48,    52,    53,    49,
      50,    53,     5,     3,    41,    45,     3,     4,     5,    10,
      11,    12,    13,    14,    17,    20,    32,    37,    39,    41,
      51,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     3,    33,     3,    35,    34,
      47,    45,    32,    34,    56,     3,    66,     6,    56,    41,
      32,    32,     3,    67,    56,    67,    37,    54,    41,    31,
      38,    30,    25,    39,    26,    27,    28,    29,    19,    20,
      21,    22,    23,    24,    34,    47,    51,    34,    42,    47,
       5,    33,    57,    68,    56,    41,    34,    41,    41,    41,
      56,    56,    34,    33,    60,    56,    61,    62,    24,    63,
      63,    63,    63,    64,    64,    65,    65,    65,    57,     5,
      41,    35,    50,    41,    35,    33,    42,    35,    56,    33,
      33,    56,    40,    62,    35,    52,    42,    45,    47,    57,
      35,    15,    18,    35,    58,    47,    50,    55,    55,    41,
      16,    52,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    45,    45,    46,    47,    47,
      47,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     8,     4,     0,     2,     3,     6,
       0,     4,     0,     1,     2,     4,     4,     6,     4,     3,
       0,     5,     8,     1,     1,     1,     2,     1,     2,     3,
       3,     3,     3,     2,     6,     8,     6,     1,     1,     1,
       3,     1,     5,     3,     1,     3,     1,     3,     4,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     4,     1,     4,     3,     4,
       1,     1,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
  case 2:
#line 83 "cafezinho_parser.y"
    { 	rootTree = makeNode(program, numLinha, (yyvsp[-1].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1422 "cafezinho_parser.c"
    break;

  case 3:
#line 87 "cafezinho_parser.y"
    {
																			NodeTree* newNodeTree = makeNode((yyvsp[-4].PointerTreeNode)->typeOperator, (yyvsp[-4].PointerTreeNode)->line, NULL, NULL, (yyvsp[-3].tokenLexema));
                                                                        	(yyval.PointerTreeNode) = makeNodeTernary(declarations, numLinha, newNodeTree , (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL);
																		}
#line 1431 "cafezinho_parser.c"
    break;

  case 4:
#line 91 "cafezinho_parser.y"
    {
	  																		TypesOperators tmp = (yyvsp[-7].PointerTreeNode)->typeOperator == integer ? integer_array : character_array;
	  																		NodeTree* newNodeTree = makeNode(tmp, (yyvsp[-7].PointerTreeNode)->line, NULL, NULL, (yyvsp[-6].tokenLexema));
                                                                        	(yyval.PointerTreeNode) = makeNodeTernary(declarations, numLinha, newNodeTree, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL);
                                                                      	}
#line 1441 "cafezinho_parser.c"
    break;

  case 5:
#line 96 "cafezinho_parser.y"
    {
	  																		(yyvsp[-1].PointerTreeNode)->typeOperator = ((yyvsp[-3].PointerTreeNode)->typeOperator == integer ? integer_method : character_method);
																			(yyvsp[-1].PointerTreeNode)->lexema = (yyvsp[-2].tokenLexema);
	  																		(yyval.PointerTreeNode) = makeNode(declarations, numLinha, (yyvsp[-1].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL);
																		}
#line 1451 "cafezinho_parser.c"
    break;

  case 6:
#line 101 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(declarations, numLinha, NULL, NULL, NULL); }
#line 1457 "cafezinho_parser.c"
    break;

  case 7:
#line 105 "cafezinho_parser.y"
    { 
                                                                            (yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode);
                                                                            (yyval.PointerTreeNode)->typeOperator = typeDeclProg;
                                                                        }
#line 1466 "cafezinho_parser.c"
    break;

  case 8:
#line 112 "cafezinho_parser.y"
    {
																			NodeTree* newNodeTree = makeNode(unknown, numLinha, NULL, NULL, (yyvsp[-1].tokenLexema));
																			(yyval.PointerTreeNode) = makeNode(variable_list, numLinha, newNodeTree, (yyvsp[0].PointerTreeNode), NULL);
																		}
#line 1475 "cafezinho_parser.c"
    break;

  case 9:
#line 116 "cafezinho_parser.y"
    {
	  																		NodeTree* newNodeTree = makeNode(unknown, numLinha, NULL, NULL, (yyvsp[-4].tokenLexema));
																			(yyval.PointerTreeNode) = makeNode(variable_list, numLinha, newNodeTree, (yyvsp[0].PointerTreeNode), NULL);
																		}
#line 1484 "cafezinho_parser.c"
    break;

  case 10:
#line 120 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(variable_list, numLinha, NULL, NULL, NULL); }
#line 1490 "cafezinho_parser.c"
    break;

  case 11:
#line 124 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(unknown, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1496 "cafezinho_parser.c"
    break;

  case 12:
#line 128 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, NULL, NULL, NULL); }
#line 1502 "cafezinho_parser.c"
    break;

  case 13:
#line 129 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1508 "cafezinho_parser.c"
    break;

  case 14:
#line 133 "cafezinho_parser.y"
    {
												 							NodeTree* newNodeTree = makeNode((yyvsp[-1].PointerTreeNode)->typeOperator, (yyvsp[-1].PointerTreeNode)->line, NULL, NULL, (yyvsp[0].tokenLexema));
																			(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, newNodeTree, NULL, NULL);; 
																		}
#line 1517 "cafezinho_parser.c"
    break;

  case 15:
#line 137 "cafezinho_parser.y"
    {
												 							NodeTree* newNodeTree = makeNode((yyvsp[-3].PointerTreeNode)->typeOperator == integer ? integer_array: character_array, (yyvsp[-3].PointerTreeNode)->line, NULL, NULL, (yyvsp[-2].tokenLexema));
																			(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, newNodeTree, NULL, NULL);; 
																		}
#line 1526 "cafezinho_parser.c"
    break;

  case 16:
#line 141 "cafezinho_parser.y"
    {
												 							NodeTree* newNodeTree = makeNode((yyvsp[-3].PointerTreeNode)->typeOperator, (yyvsp[-3].PointerTreeNode)->line, NULL, NULL, (yyvsp[-2].tokenLexema));
																			(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, newNodeTree, (yyvsp[0].PointerTreeNode), NULL);; 
																		}
#line 1535 "cafezinho_parser.c"
    break;

  case 17:
#line 145 "cafezinho_parser.y"
    {
												 							NodeTree* newNodeTree = makeNode((yyvsp[-5].PointerTreeNode)->typeOperator == integer ? integer_array: character_array, (yyvsp[-5].PointerTreeNode)->line, NULL, NULL, (yyvsp[-4].tokenLexema));
																			(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, newNodeTree, (yyvsp[0].PointerTreeNode), NULL);; 
																		}
#line 1544 "cafezinho_parser.c"
    break;

  case 18:
#line 152 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(block, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[-1].PointerTreeNode), NULL); }
#line 1550 "cafezinho_parser.c"
    break;

  case 19:
#line 153 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(block, numLinha, (yyvsp[-1].PointerTreeNode), NULL, NULL); }
#line 1556 "cafezinho_parser.c"
    break;

  case 20:
#line 157 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(variable_list, numLinha, NULL, NULL, NULL); }
#line 1562 "cafezinho_parser.c"
    break;

  case 21:
#line 158 "cafezinho_parser.y"
    {
												 							NodeTree* newNodeTree = makeNode((yyvsp[-4].PointerTreeNode)->typeOperator, (yyvsp[-4].PointerTreeNode)->line, NULL, NULL, (yyvsp[-3].tokenLexema));
																			(yyval.PointerTreeNode) = makeNodeTernary(variable_list, numLinha, newNodeTree, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL);; 
																		}
#line 1571 "cafezinho_parser.c"
    break;

  case 22:
#line 162 "cafezinho_parser.y"
    {
												 							NodeTree* newNodeTree = makeNode((yyvsp[-7].PointerTreeNode)->typeOperator, (yyvsp[-7].PointerTreeNode)->line, NULL, NULL, (yyvsp[-6].tokenLexema));
																			(yyval.PointerTreeNode) = makeNodeTernary(variable_list, numLinha, newNodeTree, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL);; 
																		}
#line 1580 "cafezinho_parser.c"
    break;

  case 23:
#line 169 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(integer, numLinha, NULL, NULL, NULL); }
#line 1586 "cafezinho_parser.c"
    break;

  case 24:
#line 170 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(character, numLinha, NULL, NULL, NULL); }
#line 1592 "cafezinho_parser.c"
    break;

  case 25:
#line 174 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(statements, numLinha, (yyvsp[0].PointerTreeNode), NULL, NULL); }
#line 1598 "cafezinho_parser.c"
    break;

  case 26:
#line 175 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(statements, numLinha, (yyvsp[-1].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1604 "cafezinho_parser.c"
    break;

  case 27:
#line 179 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(statements, numLinha, NULL, NULL, NULL); }
#line 1610 "cafezinho_parser.c"
    break;

  case 28:
#line 180 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[-1].PointerTreeNode); }
#line 1616 "cafezinho_parser.c"
    break;

  case 29:
#line 181 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(returns, numLinha, (yyvsp[-1].PointerTreeNode), NULL, NULL); }
#line 1622 "cafezinho_parser.c"
    break;

  case 30:
#line 182 "cafezinho_parser.y"
    {	(yyval.PointerTreeNode) = (yyvsp[-1].PointerTreeNode); }
#line 1628 "cafezinho_parser.c"
    break;

  case 31:
#line 183 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[-1].PointerTreeNode); }
#line 1634 "cafezinho_parser.c"
    break;

  case 32:
#line 184 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(statements, numLinha, NULL, NULL, NULL); }
#line 1640 "cafezinho_parser.c"
    break;

  case 33:
#line 185 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(statements, numLinha, NULL, NULL, NULL); }
#line 1646 "cafezinho_parser.c"
    break;

  case 34:
#line 186 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(if_while, numLinha, (yyvsp[-3].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1652 "cafezinho_parser.c"
    break;

  case 35:
#line 187 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNodeTernary(if_while, numLinha, (yyvsp[-5].PointerTreeNode), (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1658 "cafezinho_parser.c"
    break;

  case 36:
#line 188 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(if_while, numLinha, (yyvsp[-3].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1664 "cafezinho_parser.c"
    break;

  case 37:
#line 189 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1670 "cafezinho_parser.c"
    break;

  case 38:
#line 193 "cafezinho_parser.y"
    {	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1676 "cafezinho_parser.c"
    break;

  case 39:
#line 197 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1682 "cafezinho_parser.c"
    break;

  case 40:
#line 198 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(assignment, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1688 "cafezinho_parser.c"
    break;

  case 41:
#line 202 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1694 "cafezinho_parser.c"
    break;

  case 42:
#line 203 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNodeTernary(if_while, numLinha, (yyvsp[-4].PointerTreeNode), (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1700 "cafezinho_parser.c"
    break;

  case 43:
#line 207 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(logical_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1706 "cafezinho_parser.c"
    break;

  case 44:
#line 208 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1712 "cafezinho_parser.c"
    break;

  case 45:
#line 212 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(logical_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1718 "cafezinho_parser.c"
    break;

  case 46:
#line 213 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1724 "cafezinho_parser.c"
    break;

  case 47:
#line 217 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(relational_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1730 "cafezinho_parser.c"
    break;

  case 48:
#line 218 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(relational_operator, numLinha, (yyvsp[-3].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1736 "cafezinho_parser.c"
    break;

  case 49:
#line 219 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1742 "cafezinho_parser.c"
    break;

  case 50:
#line 223 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(relational_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1748 "cafezinho_parser.c"
    break;

  case 51:
#line 224 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(relational_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1754 "cafezinho_parser.c"
    break;

  case 52:
#line 225 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(relational_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1760 "cafezinho_parser.c"
    break;

  case 53:
#line 226 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(relational_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1766 "cafezinho_parser.c"
    break;

  case 54:
#line 227 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1772 "cafezinho_parser.c"
    break;

  case 55:
#line 231 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(arithmetic_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1778 "cafezinho_parser.c"
    break;

  case 56:
#line 232 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(arithmetic_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1784 "cafezinho_parser.c"
    break;

  case 57:
#line 233 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1790 "cafezinho_parser.c"
    break;

  case 58:
#line 237 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(arithmetic_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1796 "cafezinho_parser.c"
    break;

  case 59:
#line 238 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(arithmetic_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1802 "cafezinho_parser.c"
    break;

  case 60:
#line 239 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(arithmetic_operator, numLinha, (yyvsp[-2].PointerTreeNode), (yyvsp[0].PointerTreeNode), NULL); }
#line 1808 "cafezinho_parser.c"
    break;

  case 61:
#line 240 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1814 "cafezinho_parser.c"
    break;

  case 62:
#line 244 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(arithmetic_operator, numLinha, (yyvsp[0].PointerTreeNode), NULL, NULL); }
#line 1820 "cafezinho_parser.c"
    break;

  case 63:
#line 245 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(logical_operator, numLinha, (yyvsp[0].PointerTreeNode), NULL, NULL); }
#line 1826 "cafezinho_parser.c"
    break;

  case 64:
#line 246 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[0].PointerTreeNode); }
#line 1832 "cafezinho_parser.c"
    break;

  case 65:
#line 250 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(single, numLinha, NULL, NULL, (yyvsp[-3].tokenLexema)); }
#line 1838 "cafezinho_parser.c"
    break;

  case 66:
#line 251 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(any, numLinha, NULL, NULL, (yyvsp[0].tokenLexema)); }
#line 1844 "cafezinho_parser.c"
    break;

  case 67:
#line 255 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(invocation, numLinha, (yyvsp[-1].PointerTreeNode), NULL, (yyvsp[-3].tokenLexema)); }
#line 1850 "cafezinho_parser.c"
    break;

  case 68:
#line 256 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(invocation, numLinha, NULL, NULL, (yyvsp[-2].tokenLexema)); }
#line 1856 "cafezinho_parser.c"
    break;

  case 69:
#line 257 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(single, numLinha, NULL, NULL, (yyvsp[-3].tokenLexema)); }
#line 1862 "cafezinho_parser.c"
    break;

  case 70:
#line 258 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(any, numLinha, NULL, NULL, NULL); }
#line 1868 "cafezinho_parser.c"
    break;

  case 71:
#line 259 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(character, numLinha, NULL, NULL, NULL); }
#line 1874 "cafezinho_parser.c"
    break;

  case 72:
#line 260 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(integer, numLinha, NULL, NULL, NULL); }
#line 1880 "cafezinho_parser.c"
    break;

  case 73:
#line 261 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = (yyvsp[-1].PointerTreeNode); }
#line 1886 "cafezinho_parser.c"
    break;

  case 74:
#line 265 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, (yyvsp[0].PointerTreeNode), NULL, NULL); }
#line 1892 "cafezinho_parser.c"
    break;

  case 75:
#line 266 "cafezinho_parser.y"
    { 	(yyval.PointerTreeNode) = makeNode(parameter_list, numLinha, (yyvsp[0].PointerTreeNode), NULL, NULL); }
#line 1898 "cafezinho_parser.c"
    break;


#line 1902 "cafezinho_parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 268 "cafezinho_parser.y"
 /* Secao Epilogo*/   

/*..................... MAIN..................*/
int main(int argc, char** argv){
    printf("> Start - Compiler Coffee\n\n");

    if(argc != 2){
        errorInput = 1;
        yyerror("Error: Input Mode: ./cafezinho namefile");
    }

    yyin=fopen(argv[1], "r");
    if(!yyin)
        yyerror("Error: File cannot be opened\n");

    yyparse();

    printf("\n> . . . . . . . . Árvore abstrata . . . . . . . .\n\n");
    walkTree(rootTree, 0);
    printf("> . . . . . . . . . . . . . . . . . . . . . . . .\n\n");

    printf("\n> . . . . . . . Tabela de simbolos . . . . . . .\n");
    preorderStackSearch(topStack);
    printf("> . . . . . . . . . . . . . . . . . . . . . . . .\n\n");

    printf("\n> End - Compiler Coffee\n");
}
/*..................... MAIN..................*/

void yyerror(char const *messageError) {
    if(errorLexical) {
        printf("%s in line %d - token: %s\n", messageError, numLinha, yytext);
    }
    else if(errorInput){
        printf("%s\n", messageError);
    }
    else{
        printf("Syntatic error in %s ", yytext);
        printf(" - line: %d \n", numLinha);
        errorLexical = 1;
    }

    printf("\n> End - Compiler Coffee\n");
    exit(1);
}

void walkTree(NodeTree* nodeInTree, int count){
    if(nodeInTree){
		count++;

		getNameOperatorAndLine(nodeInTree, nameOperator);

        /*Inserting nodes into the stack*/

        if (nodeInTree->typeOperator == typeDeclProg){
			inserir(&topStack, NULL,NULL);
        }

		if (nodeInTree->typeOperator == declarations){
			inserir(&topStack, NULL,NULL);
        }  

		// if ((nodeInTree->typeOperator == character) || (nodeInTree->typeOperator == integer)){
	    // 	//strcpy (strTypeOperator,nodeInTree->lexema);   	
        // }

        if ((nodeInTree->typeOperator == variable_list) || (nodeInTree->typeOperator == parameter_list)){
            
	    	if(nodeInTree->nodeTree1 != NULL){
                getTypeOperator2String(nodeInTree->nodeTree1->typeOperator, nameTypeOperator);
                // printf("Token Lexema: %s\n", nodeInTree->nodeTree1->lexema);
                // printf("Token TypeOperator: %s\n", nameTypeOperator);
                
                inserir(&topStack, nodeInTree->nodeTree1->lexema, nameTypeOperator);
            }
        }
        /*-----------------------------*/

		printTabs(count);
		printf("[%d] %s", count, nameOperator);

        if(nodeInTree->nodeTree1 != NULL) {
			printTabs(count);
			printf("> NodeTree 1 | [%d] {\n", count);

			walkTree(nodeInTree->nodeTree1, count);

			printTabs(count);
			printf("}end NodeTree 1 | [%d]\n\n", count);
        }

        if(nodeInTree->nodeTree2 != NULL) {
			printTabs(count);
			printf("> NodeTree 2 | [%d] {\n", count);

			walkTree(nodeInTree->nodeTree2, count);

			printTabs(count);
			printf("}end NodeTree 2 | [%d]\n\n", count);
        }
        if(nodeInTree->nodeTree3 != NULL) {
			printTabs(count);
			printf("> NodeTree 3 | [%d] {\n", count);

			walkTree(nodeInTree->nodeTree3, count);

			printTabs(count);
			printf("}end NodeTree 3 | %d\n\n", count);
        }
		
    }
}

///Inserção na pilha de árvores
void inserir (NodeStack **topStack, char lexema[], char strTypeOperator[]) {
    if(lexema == NULL ){
        NodeStack* newNodeStack;
        NodeTreeStack *root = NULL;
        newNodeStack = (NodeStack *) malloc (sizeof(NodeStack));
            
        if(newNodeStack == NULL){
            printf("Error: newNodeStack memory allocation\n");
            exit(1);
        }
        else {
            if(*topStack == NULL){
                newNodeStack->next = NULL;
            }
            else {
                newNodeStack->next = *topStack;
            }
            
            *topStack = newNodeStack;
        }
        (*topStack)->pointerNodeStackTree = root;
    }
    if(lexema != NULL)
    inserirNoArvorePilha(&(*topStack)->pointerNodeStackTree, lexema, strTypeOperator);
}

///Inserção de um nó de uma árvore da NodeStack
void inserirNoArvorePilha(NodeTreeStack **root,char identifier[],char strTypeOperator[]){
    if (identifier != NULL && strTypeOperator != NULL){
        if(*root == NULL) {
            NodeTreeStack *newNodeTreeStack = (NodeTreeStack *) malloc (sizeof(NodeTreeStack));
                if(strTypeOperator != NULL && identifier != NULL){		
                    strcpy (newNodeTreeStack->strTypeOperator, strTypeOperator);
                    strcpy (newNodeTreeStack->id, identifier);
                }
            newNodeTreeStack->nodeStackTreeRight = newNodeTreeStack->nodeStackTreeLeft = NULL;
            *root = newNodeTreeStack;
            //printf("Elemento %s do strTypeOperator %s foi inserido com sucesso! \n", identifier, strTypeOperator);
            return;
        }

        if (identifier > (*root)->id){
            inserirNoArvorePilha(&(*root)->nodeStackTreeRight,identifier, strTypeOperator);
            return;
        }
        if (identifier < (*root)->id){
            inserirNoArvorePilha(&(*root)->nodeStackTreeLeft, identifier, strTypeOperator);
            return;
        }

        printf("Elemento %s ja existe na arvore. \n", identifier);
    }
}

void printStack (NodeStack *topStack) {
    NodeStack * auxNodeStack ;
    if(topStack == NULL)
        printf("NodeStack vazia!\n");
    else{
        auxNodeStack = topStack;
        while(auxNodeStack!= NULL){
            preorderStackSearch(auxNodeStack->pointerNodeStackTree);
            auxNodeStack = auxNodeStack->next;	
        }
    }
}

void preorderStackSearch(NodeTreeStack *root) {
    if(root == NULL){
        //printf("\n");
        return;
    }
    else{
        if(strcmp(root->strTypeOperator,"integer") == 0 || strcmp(root->strTypeOperator,"character") == 0)	
            printf("%s %s\n",root->id,root->strTypeOperator);	
        else if((strlen(root->strTypeOperator) > 0))
            printf("Error: Semantic error \n");             

        preorderStackSearch(root->nodeStackTreeLeft);
        preorderStackSearch(root->nodeStackTreeRight);				
    }
}

void printTabs(int count){
	for(int count_tabs = 0; count_tabs < (count-1); count_tabs++)
		printf("\t");
	
    return;
}

void getTypeOperator2String(TypesOperators typeOperator, char* nameTypeOperator){
    switch(typeOperator){
        case integer:
            strcpy(nameTypeOperator,"integer");
            break;
        case character:
            strcpy(nameTypeOperator,"character");
            break;
    }
}

/*
> . . . . . . . . . . . TREE
*/

NodeTree* makeNode(TypesOperators typeOperator, int line, NodeTree* nodeTree1, NodeTree* nodeTree2, char* lexema){
    
    NodeTree* newNodeTree = (NodeTree*) malloc(sizeof(NodeTree));
    if (newNodeTree){
        newNodeTree->typeOperator=typeOperator;
        newNodeTree->line=line;
        newNodeTree->nodeTree1=nodeTree1;
        newNodeTree->nodeTree2=nodeTree2;
        newNodeTree->nodeTree3=NULL;
        if(lexema){
            newNodeTree->lexema= (char*)malloc(strlen(lexema)+1);
            strcpy(newNodeTree->lexema, lexema);
        }
        return(newNodeTree);
    }
    return(NULL);
}

NodeTree* makeNodeTernary(TypesOperators typeOperator, int line, NodeTree* nodeTree1, NodeTree* nodeTree2, NodeTree* nodeTree3, char* lexema){
    
    NodeTree* newNodeTree = (NodeTree*) malloc(sizeof(NodeTree));
    if (newNodeTree){
        newNodeTree->typeOperator = typeOperator;
        newNodeTree->line = line;
        newNodeTree->nodeTree1 = nodeTree1;
        newNodeTree->nodeTree2 = nodeTree2;
        newNodeTree->nodeTree3 = nodeTree3;
        if(lexema){
            newNodeTree->lexema = (char*)malloc(strlen(lexema)+1);
            strcpy(newNodeTree->lexema, lexema);
        }
        return(newNodeTree);
    }
    return(NULL);
}

void getNameOperatorAndLine(NodeTree* nodeInTree, char* nameOperator){
    switch(nodeInTree->typeOperator){
        case program:
            strcpy(nameOperator,"programa\n");
            break;
        case typeDeclProg:
            sprintf(nameOperator, "DeclProg - Line: %d\n", nodeInTree->line);
            break;
        case any:
            sprintf(nameOperator, "Any - Line: %d\n", nodeInTree->line);
            break;	
        case block:
            sprintf(nameOperator, "Block - Line: %d\n", nodeInTree->line);
            break;
        case single:
            sprintf(nameOperator, "Single - Line: %d\n", nodeInTree->line);
            break;
        case unknown:
            sprintf(nameOperator, "Unknown - Line: %d\n", nodeInTree->line);
            break;
        case integer:
            sprintf(nameOperator, "Integer - Line: %d\n", nodeInTree->line);
            break;
        case returns:
            sprintf(nameOperator, "Returns - Line: %d\n", nodeInTree->line);
            break;
        case if_while:
            sprintf(nameOperator, "If-while - Line: %d\n", nodeInTree->line);
            break;
        case character:
            sprintf(nameOperator, "Character - Line: %d\n", nodeInTree->line);
            break;
        case statements:
            sprintf(nameOperator, "Statements - Line: %d\n", nodeInTree->line);
            break;
        case invocation:
            sprintf(nameOperator, "Invocation - Line: %d\n", nodeInTree->line);
            break;
        case assignment:
            sprintf(nameOperator, "Assignment - Line: %d\n", nodeInTree->line);
            break;
        case declarations:
            sprintf(nameOperator, "Declarations - Line: %d\n", nodeInTree->line);
            break;
        case unknown_array:
            sprintf(nameOperator, "Unlnown_Arry - Line: %d\n", nodeInTree->line);
            break;
        case integer_array:
            sprintf(nameOperator, "Integer_Array - Line: %d\n", nodeInTree->line);
            break;
        case variable_list:
            sprintf(nameOperator, "Variable_List - Line: %d\n", nodeInTree->line);
            break;
        case parameter_list:
            sprintf(nameOperator, "Parameter_list - Line: %d\n", nodeInTree->line);
            break;
        case integer_method:
            sprintf(nameOperator, "Integer_Method - Line: %d\n", nodeInTree->line);
            break;
        case character_array:
            sprintf(nameOperator, "Character_array - Line: %d\n", nodeInTree->line);
            break;
        case character_method:
            sprintf(nameOperator, "Character_Method - Line: %d\n", nodeInTree->line);
            break;
        case logical_operator:
            sprintf(nameOperator, "Logical_Operator - Line: %d\n", nodeInTree->line);
            break;
        case arithmetic_operator:
            sprintf(nameOperator, "Arithmetic_Operator - Line: %d\n", nodeInTree->line);
            break;
        case relational_operator:
            sprintf(nameOperator, "Relational_Operator - Line: %d\n", nodeInTree->line);
            break;
        default:
            sprintf(nameOperator, "DEFAULT - Line: %d\n", nodeInTree->line);
            break;
    }
}
