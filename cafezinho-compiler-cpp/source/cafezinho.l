%option noyywrap

%top{ 
	
	#pragma warning (disable: 4005)

	#include <iostream>
	#include <cmath>

	using namespace std;

	#include "cafezinho_parser.h"

    static void comment(void);
    static void multiLineString(void);

    extern void yyerror(const char* msg);
}

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

    //cout << "/";
    //cout << "*";

    while ((c = yyinput()) != 0) {
        //cout << c;

          if (c == '*') {
            c = yyinput();
            if (c == '/'){
                //cout << c;
                return;
            }

            if (c == 0)
                break;
            //cout << c;
        }
    }

    yyerror("unterminated comment");
}

static void multiLineString(void) {
    int c;
    yylineno++;
    
    while ((c = yyinput()) != 0) {
        //cout << c;

        if (c == '\n')
            yylineno++;

        if (c == ';')
            break;
    }

    yyerror("multiline string");
    yylineno++;
}


