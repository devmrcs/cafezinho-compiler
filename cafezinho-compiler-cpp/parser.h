/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    VIRGULA = 258,
    PONTOVIRGULA = 259,
    INTERROGACAO = 260,
    DOISPONTOS = 261,
    EXCLAMACAO = 262,
    ABRECHAVES = 263,
    ABREPARENTESES = 264,
    ABRECOLCHETES = 265,
    FECHACHAVES = 266,
    FECHAPARENTESES = 267,
    FECHACOLCHETES = 268,
    MENOR = 269,
    MAIOR = 270,
    MENORIGUAL = 271,
    MAIORIGUAL = 272,
    MENOS = 273,
    MAIS = 274,
    VEZES = 275,
    DIVIDIR = 276,
    RESTO = 277,
    IGUAL = 278,
    IGUALDUPLO = 279,
    DIFERENTE = 280,
    E = 281,
    OU = 282,
    ENQUANTO = 283,
    SE = 284,
    ENTAO = 285,
    SENAO = 286,
    RETORNE = 287,
    ESCREVA = 288,
    LEIA = 289,
    EXECUTE = 290,
    INT = 291,
    CAR = 292,
    INTCONST = 293,
    ID = 294,
    NOVALINHA = 295,
    PROGRAMA = 296,
    CARCONST = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
