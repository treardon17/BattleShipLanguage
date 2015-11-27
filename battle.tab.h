/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     COMPUTERLITERAL = 276,
     PLAYERLITERAL = 277,
     GRIDLITERAL = 278,
     STRINGLITERAL = 279,
     CHARLITERAL = 280,
     INTLITERAL = 281,
     IDENTIFIER = 282,
     INTTYPE = 283,
     CHARTYPE = 284,
     STRINGTYPE = 285,
     GRIDTYPE = 286,
     PLAYERTYPE = 287,
     COMPUTERTYPE = 288,
     ASSIGNOP = 289
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
#define COMPUTERLITERAL 276
#define PLAYERLITERAL 277
#define GRIDLITERAL 278
#define STRINGLITERAL 279
#define CHARLITERAL 280
#define INTLITERAL 281
#define IDENTIFIER 282
#define INTTYPE 283
#define CHARTYPE 284
#define STRINGTYPE 285
#define GRIDTYPE 286
#define PLAYERTYPE 287
#define COMPUTERTYPE 288
#define ASSIGNOP 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "battle.y"
{ /* SEMANTIC RECORD */
		char* sval;
		char* id;
		char* action;
    char* loop;
		char* ifval;
		char* whenval;
		char* tryval;
	}
/* Line 1529 of yacc.c.  */
#line 127 "battle.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

