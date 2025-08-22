
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int line_num;
extern FILE *yyin;
extern int get_token_count();
void yyerror(const char *s);

struct symbol {
    char name[50];
    char type[10];
    int value;
    int is_array;
    int array_size;
    int is_used;
};

struct symbol symbol_table[100];
int symbol_count = 0;

int var_count = 0;
int array_count = 0;
int assignment_count = 0;
int expression_count = 0;
int loop_count = 0;
int condition_count = 0;
int print_count = 0;

int find_symbol(char *name);
void add_symbol(char *name, char *type, int is_array, int size);
void print_symbol_table();
void print_statistics();
void check_unused_variables();


/* Line 189 of yacc.c  */
#line 111 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INT_NUM = 259,
     INT = 260,
     FLOAT = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     PRINT = 266,
     READ = 267,
     PLUS = 268,
     MINUS = 269,
     MULTIPLY = 270,
     DIVIDE = 271,
     ASSIGN = 272,
     EQ = 273,
     NE = 274,
     LT = 275,
     GT = 276,
     LE = 277,
     GE = 278,
     LPAREN = 279,
     RPAREN = 280,
     LBRACE = 281,
     RBRACE = 282,
     LBRACKET = 283,
     RBRACKET = 284,
     SEMICOLON = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "parser.y"

    int ival;
    char *str;



/* Line 214 of yacc.c  */
#line 184 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 196 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNRULES -- Number of states.  */
#define YYNSTATES  89

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    28,    32,    39,    41,    43,    48,    56,
      62,    70,    76,    85,    91,    97,   103,   107,   111,   115,
     119,   123,   125,   129,   133,   135,   137,   139
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    -1,    33,    34,    -1,    34,    -1,
      35,    -1,    37,    -1,    38,    -1,    39,    -1,    40,    -1,
      41,    -1,    42,    -1,    26,    33,    27,    -1,    36,     3,
      30,    -1,    36,     3,    28,     4,    29,    30,    -1,     5,
      -1,     6,    -1,     3,    17,    43,    30,    -1,     3,    28,
      43,    29,    17,    43,    30,    -1,     7,    24,    43,    25,
      34,    -1,     7,    24,    43,    25,    34,     8,    34,    -1,
       9,    24,    43,    25,    34,    -1,    10,    24,    37,    43,
      30,    37,    25,    34,    -1,    11,    24,    43,    25,    30,
      -1,    11,    24,     3,    25,    30,    -1,    12,    24,     3,
      25,    30,    -1,    43,    13,    44,    -1,    43,    14,    44,
      -1,    43,    18,    44,    -1,    43,    20,    44,    -1,    43,
      21,    44,    -1,    44,    -1,    44,    15,    45,    -1,    44,
      16,    45,    -1,    45,    -1,     4,    -1,     3,    -1,    24,
      43,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    72,    73,    77,    78,    79,    80,    81,
      82,    83,    84,    88,    94,   103,   104,   108,   120,   139,
     144,   152,   160,   168,   173,   187,   200,   206,   212,   218,
     224,   230,   237,   242,   252,   259,   263,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_NUM", "INT", "FLOAT",
  "IF", "ELSE", "WHILE", "FOR", "PRINT", "READ", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "GT", "LE", "GE",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "SEMICOLON", "$accept", "program", "statement_list", "statement",
  "declaration_statement", "type", "assignment_statement", "if_statement",
  "while_statement", "for_statement", "print_statement", "read_statement",
  "expression", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      34,    34,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    39,    40,    41,    41,    42,    43,    43,    43,    43,
      43,    43,    44,    44,    44,    45,    45,    45
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     6,     1,     1,     4,     7,     5,
       7,     5,     8,     5,     5,     5,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     5,     0,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       3,     0,    36,    35,     0,     0,    31,    34,     0,     0,
       0,     0,    36,     0,     0,    12,     0,    13,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    26,    27,    28,    29,
      30,    32,    33,     0,    19,    21,     0,    24,    23,    25,
       0,     0,     0,     0,    14,    18,    20,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -22
static const yytype_int8 yypact[] =
{
      27,   -13,   -22,   -22,   -17,    -8,    -6,     0,    11,    27,
      44,    27,   -22,   -22,    46,   -22,   -22,   -22,   -22,   -22,
     -22,     5,     5,     5,     5,    47,     7,    48,    16,   -22,
     -22,   -16,   -22,   -22,     5,    42,    25,   -22,    82,    92,
     101,     5,    29,   110,    33,   -22,    55,   -22,   119,     5,
       5,     5,     5,     5,   -22,     5,     5,    52,    27,    27,
      60,    31,    40,    45,    50,   -22,    25,    25,    25,    25,
      25,   -22,   -22,     5,    69,   -22,    47,   -22,   -22,   -22,
      53,    71,    27,    57,   -22,   -22,   -22,    27,   -22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,    77,   -11,   -22,   -22,   -19,   -22,   -22,   -22,
     -22,   -22,   -21,    15,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    38,    39,    40,    21,    43,    41,    23,    32,    33,
      42,    33,    46,    48,    47,    22,    24,    30,    25,     1,
      60,     2,     3,     4,    26,     5,     6,     7,     8,    34,
       1,    34,     2,     3,     4,    27,     5,     6,     7,     8,
      55,    56,     9,    45,    29,    71,    72,    74,    75,    31,
       1,    44,    81,     9,    61,    49,    50,    83,    63,    64,
      51,    77,    52,    53,    66,    67,    68,    69,    70,    73,
      78,    86,    54,    49,    50,    79,    88,    82,    51,    80,
      52,    53,    87,    84,    49,    50,    28,     0,     0,    51,
      76,    52,    53,     0,     0,    49,    50,     0,     0,     0,
      51,    85,    52,    53,     0,    49,    50,     0,     0,     0,
      51,    57,    52,    53,    49,    50,     0,    58,     0,    51,
       0,    52,    53,    49,    50,     0,    59,     0,    51,     0,
      52,    53,    49,    50,     0,    62,     0,    51,     0,    52,
      53,     0,     0,     0,    65
};

static const yytype_int8 yycheck[] =
{
      11,    22,    23,    24,    17,    26,    25,    24,     3,     4,
       3,     4,    28,    34,    30,    28,    24,    28,    24,     3,
      41,     5,     6,     7,    24,     9,    10,    11,    12,    24,
       3,    24,     5,     6,     7,    24,     9,    10,    11,    12,
      15,    16,    26,    27,     0,    55,    56,    58,    59,     3,
       3,     3,    73,    26,    25,    13,    14,    76,    25,     4,
      18,    30,    20,    21,    49,    50,    51,    52,    53,    17,
      30,    82,    30,    13,    14,    30,    87,     8,    18,    29,
      20,    21,    25,    30,    13,    14,     9,    -1,    -1,    18,
      30,    20,    21,    -1,    -1,    13,    14,    -1,    -1,    -1,
      18,    30,    20,    21,    -1,    13,    14,    -1,    -1,    -1,
      18,    29,    20,    21,    13,    14,    -1,    25,    -1,    18,
      -1,    20,    21,    13,    14,    -1,    25,    -1,    18,    -1,
      20,    21,    13,    14,    -1,    25,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     9,    10,    11,    12,    26,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    17,    28,    24,    24,    24,    24,    24,    33,     0,
      34,     3,     3,     4,    24,    43,    44,    45,    43,    43,
      43,    37,     3,    43,     3,    27,    28,    30,    43,    13,
      14,    18,    20,    21,    30,    15,    16,    29,    25,    25,
      43,    25,    25,    25,     4,    25,    44,    44,    44,    44,
      44,    45,    45,    17,    34,    34,    30,    30,    30,    30,
      29,    43,     8,    37,    30,    30,    34,    25,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    {
        printf("\n==========================================\n");
        printf("    COMPILATION SUCCESSFUL!\n");
        printf("==========================================\n");
        print_symbol_table();
        print_statistics();
        check_unused_variables();
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {
        printf("Declaring variable: %s (type: %s)\n", (yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].str));
        add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].str), 0, 0);
        var_count++;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {
        printf("Declaring array: %s[%d] (type: %s)\n", (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].ival), (yyvsp[(1) - (6)].str));
        add_symbol((yyvsp[(2) - (6)].str), (yyvsp[(1) - (6)].str), 1, (yyvsp[(4) - (6)].ival));
        array_count++;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyval.str) = "int"; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { (yyval.str) = "float"; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {
        int pos = find_symbol((yyvsp[(1) - (4)].str));
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", (yyvsp[(1) - (4)].str));
        } else {
            printf("Assigning: %s = %d\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].ival));
            symbol_table[pos].value = (yyvsp[(3) - (4)].ival);
            symbol_table[pos].is_used = 1;
            assignment_count++;
        }
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {
        int pos = find_symbol((yyvsp[(1) - (7)].str));
        if (pos == -1) {
            printf("ERROR: Array %s not declared\n", (yyvsp[(1) - (7)].str));
        } else if (!symbol_table[pos].is_array) {
            printf("ERROR: %s is not an array\n", (yyvsp[(1) - (7)].str));
        } else if ((yyvsp[(3) - (7)].ival) >= symbol_table[pos].array_size || (yyvsp[(3) - (7)].ival) < 0) {
            printf("ERROR: Array index out of bounds\n");
        } else {
            printf("Array assignment: %s[%d] = %d\n", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].ival), (yyvsp[(6) - (7)].ival));
            symbol_table[pos].value = (yyvsp[(6) - (7)].ival);
            symbol_table[pos].is_used = 1;
            assignment_count++;
        }
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {
        printf("If statement executed (condition = %d)\n", (yyvsp[(3) - (5)].ival));
        condition_count++;
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {
        printf("If-else statement executed (condition = %d)\n", (yyvsp[(3) - (7)].ival));
        condition_count++;
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {
        printf("While loop executed (condition = %d)\n", (yyvsp[(3) - (5)].ival));
        loop_count++;
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {
        printf("For loop executed\n");
        loop_count++;
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {
        printf("OUTPUT: %d\n", (yyvsp[(3) - (5)].ival));
        print_count++;
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {
        int pos = find_symbol((yyvsp[(3) - (5)].str));
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", (yyvsp[(3) - (5)].str));
        } else {
            printf("OUTPUT: %s = %d\n", (yyvsp[(3) - (5)].str), symbol_table[pos].value);
            symbol_table[pos].is_used = 1;
            print_count++;
        }
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {
        int pos = find_symbol((yyvsp[(3) - (5)].str));
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", (yyvsp[(3) - (5)].str));
        } else {
            printf("Reading input for: %s\n", (yyvsp[(3) - (5)].str));
            symbol_table[pos].is_used = 1;
        }
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival);
        printf("  %d + %d = %d\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival));
        expression_count++;
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival);
        printf("  %d - %d = %d\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival));
        expression_count++;
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {
        (yyval.ival) = ((yyvsp[(1) - (3)].ival) == (yyvsp[(3) - (3)].ival)) ? 1 : 0;
        printf("  %d == %d is %s\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival) ? "TRUE" : "FALSE");
        expression_count++;
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
        (yyval.ival) = ((yyvsp[(1) - (3)].ival) < (yyvsp[(3) - (3)].ival)) ? 1 : 0;
        printf("  %d < %d is %s\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival) ? "TRUE" : "FALSE");
        expression_count++;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    {
        (yyval.ival) = ((yyvsp[(1) - (3)].ival) > (yyvsp[(3) - (3)].ival)) ? 1 : 0;
        printf("  %d > %d is %s\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival) ? "TRUE" : "FALSE");
        expression_count++;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (1)].ival);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival);
        printf("  %d * %d = %d\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {
        if ((yyvsp[(3) - (3)].ival) == 0) {
            printf("ERROR: Division by zero!\n");
            (yyval.ival) = 0;
        } else {
            (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival);
            printf("  %d / %d = %d\n", (yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival), (yyval.ival));
        }
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (1)].ival);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (1)].ival);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {
        int pos = find_symbol((yyvsp[(1) - (1)].str));
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", (yyvsp[(1) - (1)].str));
            (yyval.ival) = 0;
        } else {
            (yyval.ival) = symbol_table[pos].value;
            symbol_table[pos].is_used = 1;
        }
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {
        (yyval.ival) = (yyvsp[(2) - (3)].ival);
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 1766 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 280 "parser.y"


int find_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_symbol(char *name, char *type, int is_array, int size) {
    if (find_symbol(name) != -1) {
        printf("WARNING: Variable %s already declared\n", name);
        return;
    }
    
    memset(&symbol_table[symbol_count], 0, sizeof(struct symbol));
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].value = 0;
    symbol_table[symbol_count].is_array = is_array;
    symbol_table[symbol_count].array_size = size;
    symbol_table[symbol_count].is_used = 0;
    symbol_count++;
}

void print_symbol_table() {
    printf("\n--- SYMBOL TABLE ---\n");
    printf("Name\t\tType\t\tArray\tSize\tUsed\n");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < symbol_count; i++) {
        printf("%s\t\t%s\t\t%s\t%d\t%s\n",
               symbol_table[i].name,
               symbol_table[i].type,
               symbol_table[i].is_array ? "Yes" : "No",
               symbol_table[i].array_size,
               symbol_table[i].is_used ? "Yes" : "No");
    }
    printf("------------------------------------------------\n");
}

void print_statistics() {
    printf("\n===========================================\n");
    printf("              STATISTICS                   \n");
    printf("===========================================\n");
    printf("| Lines processed      : %-15d |\n", line_num);
    printf("| Tokens found         : %-15d |\n", get_token_count());
    printf("| Variables declared   : %-15d |\n", var_count);
    printf("| Arrays declared      : %-15d |\n", array_count);
    printf("| Assignments          : %-15d |\n", assignment_count);
    printf("| Expressions          : %-15d |\n", expression_count);
    printf("| Loops                : %-15d |\n", loop_count);
    printf("| Conditions           : %-15d |\n", condition_count);
    printf("| Print statements     : %-15d |\n", print_count);
    printf("===========================================\n");
}


void check_unused_variables() {
    printf("\n--- UNUSED VARIABLES ---\n");
    int unused_count = 0;
    
    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_used) {
            printf("WARNING: Variable '%s' is not used\n", symbol_table[i].name);
            unused_count++;
        }
    }
    
    if (unused_count == 0) {
        printf("Great! All variables are used.\n");
    }
    printf("---------------------------\n");
}

void yyerror(const char *s) {
    printf("ERROR at line %d: %s\n", line_num, s);
    printf("\n--- PARTIAL SYMBOL TABLE ---\n");
    print_symbol_table();
}

int main(int argc, char **argv) {
    printf("====================================\n");
    printf("      MinLang Compiler\n");
    printf("      Compiler For Beginners\n");
    printf("====================================\n");
    
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("ERROR: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
        printf("Reading file: %s\n\n", argv[1]);
    } else {
        printf("Enter your code:\n\n");
    }
    
    int result = yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    if (result == 0) {
        printf("\nCompilation finished successfully!\n");
    } else {
        printf("\nCompilation failed!\n");
    }
    
    return result;
}

