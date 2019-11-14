%{
//Autor: Marcos Antônio de Souza
//Matricula: 201514357

#include <stdio.h>
#include "cafezinho.tab.h"

static void comment(void);
static void multiLineString(void);

%}

NUMBER [0-9]+
CHAR [a-zA-Z_]
CHAR2 [a-zA-Z_0-9]
IDENT ({NUMBER}|({CHAR}{CHAR2}*))

%%
","   { return (VIRGULA); }
";"   { return (PONTOVIRGULA); }
"?"   { return (INTERROGACAO); }
":"   { return (DOISPONTOS); }
"!"   { return (EXCLAMACAO); }

"{"   { return (ABRECHAVES); }
"}"   { return (FECHACHAVES); }
"("   { return (ABREPARENTESES); }
")"   { return (FECHAPARENTESES); }
"["   { return (ABRECOLCHETES); }
"]"   { return (FECHACOLCHETES); }

">"   { return (MENOR); }
"<"   { return (MAIOR); }
">="  { return (MENORIGUAL); }
"<="  { return (MAIORIGUAL); }
"-"   { return (MENOS); }
"+"   { return (MAIS); }
"*"   { return (VEZES); }
"/"   { return (DIVIDIR); }
"%"   { return (RESTO); }
"="   { return (IGUAL); }
"=="  { return (IGUALDUPLO); }
"!="  { return (DIFERENTE); }
"&"   { return (E); }
"|"   { return (OU); }

"enquanto"  { return (ENQUANTO); }
"se"        { return (SE); }
"entao"     { return (ENTAO); }
"senao"     { return (SENAO); }
"escreva"   { return (ESCREVA); }
"retorne"   { return (RETORNE); }
"leia"      { return (LEIA); }
"execute"   { return (EXECUTE); }
"programa"  { return (PROGRAMA); }
"int"       { return (INT); }
"car"       { return (CAR); }
"novalinha" { return (NOVALINHA); }

{NUMBER}        { return (INTCONST); }
{IDENT}         { return (ID); }

["\""]({IDENT}|[" "]|[":"])*["\""]    { return (CARCONST); }
["\""]{IDENT}["\n"]     { multiLineString(); }
"/*"                    { comment(); }

[\n]           { yylineno++; }
[\t]*          { }
[ ]+           { }

. { yyerror("invalid character"); }

%%

static void comment(void) {
    int c;

    //printf("/");
    //printf("*");

    while ((c = input()) != 0) {
        //printf("%c", c);

        if (c == '*') {
            c = input();
            if (c == '/'){
                //printf("%c", c);
                return;
            }

            if (c == 0)
                break;
            //printf("%c", c);
        }
    }

    yyerror("unterminated comment");
}

static void multiLineString(void) {
    int c;
    yylineno++;
    
    while ((c = input()) != 0) {
        printf("%c", c);

        if (c == '\n')
            yylineno++;

        if (c == ';')
            break;
    }

    yyerror("multiline string");
    yylineno++;
}
