/* A Bison parser, made by GNU Bison 3.4.1.  */

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
#line 33 "cafezinho_parser.y"

    int nlinha;
    char* tokenLexema;
    NodeTree* PointerTreeNode;

#line 106 "cafezinho_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CAFEZINHO_PARSER_H_INCLUDED  */
