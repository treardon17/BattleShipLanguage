/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STATEMENTNUMSYMBOL = 258,
     STATEMENTNUMSYMBOLSTART = 259,
     BEGINLOOP = 260,
     ENDLOOP = 261,
     ACTIONSYMBOL = 262,
     TRYSINKACTION = 263,
     SHOWVARACTION = 264,
     ADDBOATACTION = 265,
     ATTACKBOATACTION = 266,
     RANDOMADDBOATACTION = 267,
     SEEKACTION = 268,
     BEGINIFCOND = 269,
     ENDIFCOND = 270,
     FINDSBOAT = 271,
     BEGINELSE = 272,
     ENDELSE = 273,
     WHENSTATEMENT = 274,
     TRYSTATEMENT = 275,
     BEGINTRYSTATEMENT = 276,
     ENDTRYSTATEMENT = 277,
     COMPUTERLITERAL = 278,
     PLAYERLITERAL = 279,
     GRIDLITERAL = 280,
     STRINGLITERAL = 281,
     CHARLITERAL = 282,
     INTLITERAL = 283,
     IDENTIFIER = 284,
     INTTYPE = 285,
     CHARTYPE = 286,
     STRINGTYPE = 287,
     GRIDTYPE = 288,
     PLAYERTYPE = 289,
     COMPUTERTYPE = 290,
     ASSIGNOP = 291
   };
#endif
/* Tokens.  */
#define STATEMENTNUMSYMBOL 258
#define STATEMENTNUMSYMBOLSTART 259
#define BEGINLOOP 260
#define ENDLOOP 261
#define ACTIONSYMBOL 262
#define TRYSINKACTION 263
#define SHOWVARACTION 264
#define ADDBOATACTION 265
#define ATTACKBOATACTION 266
#define RANDOMADDBOATACTION 267
#define SEEKACTION 268
#define BEGINIFCOND 269
#define ENDIFCOND 270
#define FINDSBOAT 271
#define BEGINELSE 272
#define ENDELSE 273
#define WHENSTATEMENT 274
#define TRYSTATEMENT 275
#define BEGINTRYSTATEMENT 276
#define ENDTRYSTATEMENT 277
#define COMPUTERLITERAL 278
#define PLAYERLITERAL 279
#define GRIDLITERAL 280
#define STRINGLITERAL 281
#define CHARLITERAL 282
#define INTLITERAL 283
#define IDENTIFIER 284
#define INTTYPE 285
#define CHARTYPE 286
#define STRINGTYPE 287
#define GRIDTYPE 288
#define PLAYERTYPE 289
#define COMPUTERTYPE 290
#define ASSIGNOP 291




/* Copy the first part of user declarations.  */
#line 1 "battle.y"

	#include <algorithm>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <typeinfo>
	#include <stack>
	#include <vector>
	#include <math.h>
	#include <sstream>
	#include <iterator>
	#include "endgame.h"
	#include "types.h"
	#include "symtbl.h"
	#include "actions.h"
	#include "statement.h"

int errors;
char errormsg[255];
int yydebug;
Type tCurr;

std::stack<Expression*> exprs;
std::stack< std::vector<Expression*> > args;
std::vector<Statement*> statements;

Action CurrentAction = NoAction;
BoolCond CurrentBool = NoBool;

int yylex(void);
void yyerror(const char *s);


#define YYDEBUG 0



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 38 "battle.y"
{ /* SEMANTIC RECORD */
		char* sval;
		char* id;
		char* action;
    char* loop;
		char* ifval;
		char* whenval;
		char* tryval;
	}
/* Line 193 of yacc.c.  */
#line 215 "battle.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 228 "battle.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   66

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNRULES -- Number of states.  */
#define YYNSTATES  56

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    39,    37,     2,    38,     2,    40,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    14,    18,    21,    23,
      27,    29,    32,    34,    37,    39,    45,    47,    51,    53,
      57,    61,    63,    65,    69,    71,    73,    75,    77,    79,
      81,    83,    85,    87,    89
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    42,    43,    -1,    29,    36,    46,
      -1,    47,    29,    -1,    29,     7,    45,    -1,     5,     4,
      -1,     6,    -1,    14,    44,     4,    -1,    15,    -1,    17,
       4,    -1,    18,    -1,    21,     4,    -1,    22,    -1,    28,
       3,    20,     4,    43,    -1,    19,    -1,    29,     7,    16,
      -1,    10,    -1,    11,     7,    29,    -1,    13,     7,    29,
      -1,     9,    -1,    12,    -1,     8,     7,    29,    -1,    28,
      -1,    27,    -1,    26,    -1,    24,    -1,    23,    -1,    29,
      -1,    30,    -1,    31,    -1,    32,    -1,    34,    -1,    35,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    95,   102,   108,   152,   157,   162,
     168,   173,   178,   183,   188,   193,   199,   205,   215,   220,
     232,   250,   254,   259,   270,   278,   285,   292,   300,   308,
     322,   323,   324,   325,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STATEMENTNUMSYMBOL",
  "STATEMENTNUMSYMBOLSTART", "BEGINLOOP", "ENDLOOP", "ACTIONSYMBOL",
  "TRYSINKACTION", "SHOWVARACTION", "ADDBOATACTION", "ATTACKBOATACTION",
  "RANDOMADDBOATACTION", "SEEKACTION", "BEGINIFCOND", "ENDIFCOND",
  "FINDSBOAT", "BEGINELSE", "ENDELSE", "WHENSTATEMENT", "TRYSTATEMENT",
  "BEGINTRYSTATEMENT", "ENDTRYSTATEMENT", "COMPUTERLITERAL",
  "PLAYERLITERAL", "GRIDLITERAL", "STRINGLITERAL", "CHARLITERAL",
  "INTLITERAL", "IDENTIFIER", "INTTYPE", "CHARTYPE", "STRINGTYPE",
  "GRIDTYPE", "PLAYERTYPE", "COMPUTERTYPE", "ASSIGNOP", "'+'", "'-'",
  "'*'", "'/'", "$accept", "input", "line", "boolcond", "action", "expr",
  "typedecl", 0
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
     285,   286,   287,   288,   289,   290,   291,    43,    45,    42,
      47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    44,    45,    45,
      45,    45,    45,    45,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    47,    47
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     3,     2,     1,     3,
       1,     2,     1,     2,     1,     5,     1,     3,     1,     3,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     8,     0,    10,     0,    12,    16,
       0,    14,     0,     0,    30,    31,    32,    33,    34,     3,
       0,     7,     0,     0,    11,    13,     0,     0,     0,     5,
       0,     9,     0,     0,    21,    18,     0,    22,     0,     6,
      28,    27,    26,    25,    24,    29,     4,    17,     0,     0,
       0,     0,    15,    23,    19,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    19,    23,    39,    46,    20
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int8 yypact[] =
{
     -29,     0,   -29,    -2,   -29,   -28,   -29,    -1,   -29,   -29,
       5,   -29,    13,    -3,   -29,   -29,   -29,   -29,   -29,   -29,
      -9,   -29,    16,    20,   -29,   -29,     6,    30,   -16,   -29,
       9,   -29,    23,    37,   -29,   -29,    40,   -29,    44,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,    31,    25,
      26,    27,   -29,   -29,   -29,   -29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    10,   -29,   -29,   -29,   -29
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       2,    22,    21,    24,    27,     3,     4,    40,    41,    25,
      42,    43,    44,    45,     5,     6,    26,     7,     8,     9,
      29,    10,    11,    30,    31,    47,    32,    48,    12,    13,
      14,    15,    16,    28,    17,    18,     3,     4,    33,    34,
      35,    36,    37,    38,    49,     5,     6,    50,     7,     8,
       9,    51,    10,    11,    53,    54,    55,     0,    52,    12,
      13,    14,    15,    16,     0,    17,    18
};

static const yytype_int8 yycheck[] =
{
       0,    29,     4,     4,     7,     5,     6,    23,    24,     4,
      26,    27,    28,    29,    14,    15,     3,    17,    18,    19,
      29,    21,    22,     7,     4,    16,    20,     4,    28,    29,
      30,    31,    32,    36,    34,    35,     5,     6,     8,     9,
      10,    11,    12,    13,     7,    14,    15,     7,    17,    18,
      19,     7,    21,    22,    29,    29,    29,    -1,    48,    28,
      29,    30,    31,    32,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,     0,     5,     6,    14,    15,    17,    18,    19,
      21,    22,    28,    29,    30,    31,    32,    34,    35,    43,
      47,     4,    29,    44,     4,     4,     3,     7,    36,    29,
       7,     4,    20,     8,     9,    10,    11,    12,    13,    45,
      23,    24,    26,    27,    28,    29,    46,    16,     4,     7,
       7,     7,    43,    29,    29,    29
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 3:
#line 92 "battle.y"
    { lineNumberGlobal++; ;}
    break;

  case 4:
#line 96 "battle.y"
    {
        CurrentAction = AssignAction;
        Expression* newExpr = exprs.top();
        AssignToVar* assign = new AssignToVar((yyvsp[(1) - (3)].id), newExpr);
        statements.push_back(assign);
			;}
    break;

  case 5:
#line 103 "battle.y"
    {
        CurrentAction = DeclareAction;
				VarDeclare* myVar = new VarDeclare((yyvsp[(2) - (2)].id), tCurr);
        statements.push_back(myVar);
			;}
    break;

  case 6:
#line 109 "battle.y"
    {
    switch(CurrentAction){
      case NoAction:
        printf("Error: No action selected.\n");
        break;
      case AddBoatAction:
          //adds statement to vector
          {Boat* boat = new Boat((yyvsp[(1) - (3)].id), args.top());
          statements.push_back(boat);}
        break;
      case AttackBoatAction:
          //adds statement to vector
          {Attack* attack = new Attack((yyvsp[(1) - (3)].id), exprToString(args.top()[0]), strdup(exprToString(exprs.top()).c_str()));
          statements.push_back(attack);}
        break;
      case ShowVarAction:
          {ShowVar* showVar = new ShowVar((yyvsp[(1) - (3)].id));
          statements.push_back(showVar);}
        break;
      case RandomAddBoatAction:
          {RandBoat* randBoat = new RandBoat((yyvsp[(1) - (3)].id), args.top()[0]);
          statements.push_back(randBoat);}
        break;
			case SeekAction:
					{Seek* seek = new Seek((yyvsp[(1) - (3)].id), exprToInt(args.top()[0]), strdup(exprToString(args.top()[1]).c_str()));
					statements.push_back(seek);}
				break;
			case TrySinkAction:
				//												 		varName, 			varAttackedName, 																		direction, 							afterHitSeekDistance
				//															vv							vv																									vv												vv
				{TrySink* trySink = new TrySink((yyvsp[(1) - (3)].id), strdup(exprToString(args.top()[2]).c_str()), exprToString(args.top()[0]), exprToInt(args.top()[1]));
				statements.push_back(trySink);}
				break;
      default:
        //printf("Error: Invalid Action. Action %d does not exist.\n", (int)CurrentAction);
				{std::string actionNumber = std::to_string((int)CurrentAction);
				std::string errorMessage = "Invalid Action. Action ";
				errorMessage += actionNumber;
				errorMessage += " does not exist.";
				logError(errorMessage);}
        break;
      }
	;}
    break;

  case 7:
#line 153 "battle.y"
    {
        BeginLoop* bLoop = new BeginLoop(lineNumberGlobal, true);
        statements.push_back(bLoop);
      ;}
    break;

  case 8:
#line 158 "battle.y"
    {
        EndLoop* eLoop = new EndLoop();
        statements.push_back(eLoop);
      ;}
    break;

  case 9:
#line 163 "battle.y"
    {
				BeginIfCond* bIfCond = new BeginIfCond(strdup(exprToString(exprs.top()).c_str()), CurrentBool);
				statements.push_back(bIfCond);
				CurrentBool = NoBool;
			;}
    break;

  case 10:
#line 169 "battle.y"
    {
				EndIfCond* eIfCond = new EndIfCond();
				statements.push_back(eIfCond);
			;}
    break;

  case 11:
#line 174 "battle.y"
    {
			BeginElse* bElse = new BeginElse();
			statements.push_back(bElse);
		;}
    break;

  case 12:
#line 179 "battle.y"
    {
			EndElse* eElse = new EndElse();
			statements.push_back(eElse);
		;}
    break;

  case 13:
#line 184 "battle.y"
    {
				BeginTryStatement* bTry = new BeginTryStatement();
				statements.push_back(bTry);
			;}
    break;

  case 14:
#line 189 "battle.y"
    {
				EndTryStatement* eTry = new EndTryStatement();
				statements.push_back(eTry);
		;}
    break;

  case 15:
#line 194 "battle.y"
    {
			TryStatement* myTry = new TryStatement(getIntegerValue(std::string((yyvsp[(1) - (5)].sval))), statements.back());
			statements.pop_back();
			statements.push_back(myTry);
		;}
    break;

  case 16:
#line 200 "battle.y"
    {

		;}
    break;

  case 17:
#line 206 "battle.y"
    {
		Expression* varName = new Expression();
		varName->type = String;
		varName->value = (void*) new std::string((yyvsp[(1) - (3)].id));

		CurrentBool = FindsBoatBool;
		exprs.push(varName);
	;}
    break;

  case 18:
#line 216 "battle.y"
    {
    CurrentAction = AddBoatAction;
    args.push(typifyArgs(getArguments(std::string((yyvsp[(1) - (1)].sval)))));
	;}
    break;

  case 19:
#line 221 "battle.y"
    {
    CurrentAction = AttackBoatAction;

    //store name of boat in expression
    Expression* myExpr = new Expression();
    myExpr->type = String;
    myExpr->value = (void*) new std::string((yyvsp[(3) - (3)].id));

    exprs.push(myExpr); //name of the attacked boat
    args.push(typifyArgs(getArguments(std::string((yyvsp[(1) - (3)].sval))))); //gridpoint to be attacked
  ;}
    break;

  case 20:
#line 233 "battle.y"
    {
		CurrentAction = SeekAction;

		Expression* seeknumber = new Expression();
		seeknumber->type = Int;
		seeknumber->value = (void*) new int(getIntegerValue(std::string((yyvsp[(1) - (3)].sval))));

		Expression* varAttackedName = new Expression();
		varAttackedName->type = String;
		varAttackedName->value = (void*) new std::string((yyvsp[(3) - (3)].id));

		std::vector<Expression*> myArgs;
		myArgs.push_back(seeknumber);
		myArgs.push_back(varAttackedName);

		args.push(myArgs);
	;}
    break;

  case 21:
#line 251 "battle.y"
    {
	  CurrentAction = ShowVarAction;
	;}
    break;

  case 22:
#line 255 "battle.y"
    {
	  CurrentAction = RandomAddBoatAction;
	  args.push(typifyArgs(getArguments(std::string((yyvsp[(1) - (1)].sval)))));
	;}
    break;

  case 23:
#line 260 "battle.y"
    {
		CurrentAction = TrySinkAction;
		args.push(typifyArgs(getArguments(std::string((yyvsp[(1) - (3)].sval))))); //get direction and afterHitSeekDistance

		Expression* myExpr = new Expression();
		myExpr->type = String;
		myExpr->value = (void*) new std::string((yyvsp[(3) - (3)].id)); //get varAttackedName
		args.top().push_back(myExpr);
	;}
    break;

  case 24:
#line 271 "battle.y"
    {
			int r = getIntegerValue(std::string((yyvsp[(1) - (1)].sval)));
      Variable* l = new Variable();
			l->type = Int;
			l->value = (void*) new int(r);
			exprs.push(l);
		;}
    break;

  case 25:
#line 279 "battle.y"
    {
			Variable* l = new Variable();
			l->type = Char;
			l->value = (void*) new char((yyvsp[(1) - (1)].sval)[0]);
			exprs.push(l);
		;}
    break;

  case 26:
#line 286 "battle.y"
    {
			Variable* l = new Variable();
			l->type = String;
			l->value = (void*)(strdup((yyvsp[(1) - (1)].sval)));
			exprs.push(l);
		;}
    break;

  case 27:
#line 293 "battle.y"
    {
    Variable *l = new Variable();
		Player* p = new Player((yyvsp[(1) - (1)].sval));
		l->type = PlayerType;
    l->value = p;
		exprs.push(l);
	;}
    break;

  case 28:
#line 301 "battle.y"
    {
    Variable *l = new Variable();
    Computer* c = new Computer((yyvsp[(1) - (1)].sval));
    l->type = ComputerType;
    l->value = c;
    exprs.push(l);
	;}
    break;

  case 29:
#line 309 "battle.y"
    {
			Variable* v = get_symbol((yyvsp[(1) - (1)].id));
			if (v == NULL) {
				sprintf(errormsg, "symbol not found: %s", (yyvsp[(1) - (1)].id));
				yyerror(errormsg);
			}
			else {
				exprs.push(v);
			}
		;}
    break;

  case 30:
#line 322 "battle.y"
    { tCurr = Int; ;}
    break;

  case 31:
#line 323 "battle.y"
    { tCurr = Char; ;}
    break;

  case 32:
#line 324 "battle.y"
    { tCurr = String; ;}
    break;

  case 33:
#line 325 "battle.y"
    { tCurr = PlayerType; ;}
    break;

  case 34:
#line 326 "battle.y"
    { tCurr = ComputerType; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1800 "battle.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 329 "battle.y"


void setLoopIDs(){
	int loopID = 0; //start initial loopID at 0
	//set all beginning loop ID's
	for(int i = 0; i < statements.size(); i++){
		if(statements[i]->getAction() == BeginLoopAction){
			dynamic_cast<BeginLoop*>(statements[i])->setLoopID(++loopID);
		}
	}
	//set all end loop ID's
	for(int i = statements.size() - 1; i > 0; i--){
		if(statements[i]->getAction() == EndLoopAction){
			dynamic_cast<EndLoop*>(statements[i])->setLoopID(loopID--);
		}
	}
}

void setIfCondIDs(){
	std::map<int, Statement*> ifConds;
	int ifCondID = 0;

	//set all beginning ifCondIDs
	for(int i = 0; i < statements.size(); i++){
		if(statements[i]->getAction() == BeginIfCondAction){
			dynamic_cast<BeginIfCond*>(statements[i])->setIfCondID(++ifCondID);
			ifConds.insert(std::pair<int, Statement*>(ifCondID, statements[i]));
		}
	}

	//set all ending ifCondIDs
	for(int i = statements.size() - 1; i > 0; i--){
		BeginIfCond* bIfCond = dynamic_cast<BeginIfCond*>(ifConds[ifCondID]);

		if(statements[i]->getAction() == EndIfCondAction){
			//look for else statements
			for(int j = i; j < statements.size(); j++){

				//if there is an if condition before the else statement, the else doesn't apply to current statement
				if(statements[j]->getAction() == BeginIfCondAction){
					j = statements.size() - 1; //exit the loop
				}

				//if an else statement comes after the if statement, it applies
				else if(statements[j]->getAction() == BeginElseAction){
					dynamic_cast<BeginElse*>(statements[j])->setIfCondID(ifCondID); //associate the else statement with the if statement
					bIfCond->setElseLine(j); //let the if statement know where the else statement begins

					//look for the end of the else statement
					for(int k = j; k < statements.size(); k++){
						if(statements[k]->getAction() == EndElseAction){
							bIfCond->setElseExitLine(k); //let the if statement know where the else statement ends
							break;
						}
					}
				} //end else if
			} //end for

			bIfCond->setExitLine(i); //set the if statement exit line
			EndIfCond* eIfCond = dynamic_cast<EndIfCond*>(statements[i]); //get the end of the if statement
			eIfCond->setElseExitLine(bIfCond->getElseExitLine()); //let the end of the if statement know where the end of the else statement is
			eIfCond->setIfCondID(ifCondID--); //associate the beginning of the if with the end of the if
		} //end if
	} //end for
}

void setElseIDs(){
	std::map<int, Statement*> elses;
	int elseID = 0;

	for(int i = 0; i < statements.size(); i++){
		if(statements[i]->getAction() == BeginElseAction){
			dynamic_cast<BeginElse*>(statements[i])->setExitLine(++elseID);
			elses.insert(std::pair<int, Statement*>(elseID, statements[i]));
		}
	}

	for(int i = statements.size() - 1; i > 0; i--){
		if(statements[i]->getAction() == EndElseAction){
			dynamic_cast<BeginElse*>(elses[elseID])->setExitLine(i);
			dynamic_cast<EndElse*>(statements[i])->setElseID(elseID--);
		}
	}
}

void setTryStatementIDs(){
	int tryStatementID = 0;
	for(int i = 0; i < statements.size(); i++){

		//look for the beginning of the try statement
		if(statements[i]->getAction() == BeginTryStatementAction){

			//set the try statement ID
			BeginTryStatement* bTry = dynamic_cast<BeginTryStatement*>(statements[i]);
			bTry->setTryStatementID(++tryStatementID);

			//look for the try statement commands between the beginning of the try statement and the end of the try statement
			for(int j = i; j < statements.size(); j++){
				if(statements[j]->getAction() == TryStatementAction){
					TryStatement* myTry = dynamic_cast<TryStatement*>(statements[j]);
					myTry->setTryStatementID(tryStatementID);
				}else if(statements[j]->getAction() == EndTryStatementAction){
					bTry->setTryStatementExitLine(i);
					dynamic_cast<EndTryStatement*>(statements[j])->setTryStatementID(tryStatementID--);
					j = statements.size() - 1; //exit the loop when the end of the try statement is found
				}
			}
		}
	}
}

void runGame(){

	bool debug = true; //turns on debug notifications

  //a map containing the loopID as the key, and the statement number as the value
	std::map<int, int> loopIDs;
  bool continueLoop = true;
	bool skipElse = false;

	int currentStatementNum = 0;
	while(currentStatementNum < statements.size()){
		if(debug){
			printf("Statement Number: %d --> ", currentStatementNum); ///---------------------------------------
			printf("Action: %s\n", strdup(actionnames[(int)statements[currentStatementNum]->getAction()].c_str())); ///----------------------------
		}

		try{
      switch(statements[currentStatementNum]->getAction()){
        case NoAction:
          printf("No action selected.\n");
          currentStatementNum++;
          break;
        case AddBoatAction:
          dynamic_cast<Boat*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case RandomAddBoatAction:
          dynamic_cast<RandBoat*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case AttackBoatAction:
          dynamic_cast<Attack*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case ShowVarAction:
          dynamic_cast<ShowVar*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case AssignAction:
          dynamic_cast<AssignToVar*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case DeclareAction:
          dynamic_cast<VarDeclare*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
				case SeekAction:
					dynamic_cast<Seek*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
        case BeginLoopAction:
	        {
	          BeginLoop* bLoop = dynamic_cast<BeginLoop*>(statements[currentStatementNum]);
	          if(loopIDs.count(bLoop->getLoopID()) == 0){
	            loopIDs.insert(std::pair<int, int>(bLoop->getLoopID(), currentStatementNum));
	          }
	          if(!continueLoop){
	            currentStatementNum = bLoop->getExitLine();
	            continueLoop = true;
	          }else{
							bLoop->execute();
							currentStatementNum++;
						}
	        }
          break;
        case EndLoopAction:
	        {
	          EndLoop* eLoop = dynamic_cast<EndLoop*>(statements[currentStatementNum]);
	          if(loopIDs.count(eLoop->getLoopID())){

	            //tells the beginning of the loop what line to exit
	            dynamic_cast<BeginLoop*>(statements[loopIDs[eLoop->getLoopID()]])->setExitLine(currentStatementNum);

	            //goes to the beginning of the loop again
	            currentStatementNum = loopIDs[eLoop->getLoopID()];
	          }
	        }
          break;
				case BeginIfCondAction:
					{
						BeginIfCond* bIfCond = dynamic_cast<BeginIfCond*>(statements[currentStatementNum]);
						bIfCond->execute();

						//check if the condition is true --> if it is, go through the statements that follow
						//	if it's not, then exit the IfCond and go to the else exit line
						if(bIfCond->getCondition() && bIfCond->getElseLine() != -1){
							skipElse = true;
							currentStatementNum++;
						}else if(bIfCond->getCondition()){
							currentStatementNum++;
						}else if(bIfCond->getElseLine() != -1){
							//if an else statement is associated with the if statement, go to the else statement
							currentStatementNum = bIfCond->getElseLine();
						}else{
							currentStatementNum = bIfCond->getExitLine();
						}
					}
					break;
				case EndIfCondAction:
					{
						if(skipElse){
							currentStatementNum = dynamic_cast<EndIfCond*>(statements[currentStatementNum])->getElseExitLine(); //skip the else statement
							skipElse = false;
						}else{
							currentStatementNum++;
						}
					}
					break;
				case BeginElseAction:
					dynamic_cast<BeginElse*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
				case EndElseAction:
					dynamic_cast<EndElse*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
				case BeginTryStatementAction:
					currentStatementNum++;
					break;
				case TryStatementAction:
					{
						TryStatement* tStatement = dynamic_cast<TryStatement*>(statements[currentStatementNum]);

						//check if the statement should be executed (if it hasn't been tried yet)
						if(tStatement->getTried()){
							tStatement->execute();
						}
					}
					currentStatementNum++;
					break;
				case EndTryStatementAction:
					currentStatementNum++;
					break;
				case TrySinkAction:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nTry sink action called...\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); ///------------------------------------------------
					dynamic_cast<TrySink*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
        default:
          //printf("Could not execute statement.\n");
					logError("Could not execute statement in runGame.");
          currentStatementNum = statements.size() - 1; //quit game
          break;
      }
    }catch(std::exception& e){
      continueLoop = false;
      std::cout << e.what() << std::endl;
			currentStatementNum++;
    }
	}
}

int main (int argc, char *argv[]) {
  srand(time(NULL)); //seed the random

  extern FILE *yyin;
  ++argv; --argc;
  yyin = fopen(argv[0], "r");
  yydebug = 1;
  errors = 0;
  yyparse();

	setLoopIDs();
	setIfCondIDs();
	setElseIDs();
	setTryStatementIDs();

  printf("\n-----------------START GAME-----------------\n");
  runGame();
  printf("\n--------------------Exit--------------------\n");

  cleanupTable();
  printf("Parse Completed: %d errors.\n", errors);
	displayUserErrors();
}

void yyerror(const char *s) {
	errors++;
	printf("%d: syntax error: %s\n", lineNumberGlobal, s);
}

