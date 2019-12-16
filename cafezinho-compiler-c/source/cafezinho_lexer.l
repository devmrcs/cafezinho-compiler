%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <strings.h>

  #include "cafezinho_types.h"
  #include "cafezinho_parser.h"

  extern void yyerror(char const *messageError); 

  char messageError[500];
  int numLinha = 1;
  int errorLexical = 0;
  int errorInput = 0;
%}


WORD                [a-zA-Z_]
SPACE               [ \t\r]
NUMBER              [0-9]
IDENT               [A-Za-z][A-Za-z_0-9]*
INTCONST            [0-9]+
CARCONST            [A-Za-z_0-9]+
CADCHAR             \"(\\.|[^\\"])*\"

%x Comment

%%
"/*"		    BEGIN(Comment);
<Comment>[^*\n]*
<Comment>"*"+[^/\n]  
<Comment><<EOF>> {
  strcpy(messageError,"ERRO: COMENTÁRIO NÃO TERMINA");
  errorLexical = 1; /* erro lexico */ 
  yyerror(messageError);
}
<Comment>\n numLinha++;    
<Comment>"*"+"/"    BEGIN(INITIAL);

"car"               { yylval.nlinha = numLinha; return CAR; }
"entao"             { yylval.nlinha = numLinha; return ENTAO; }
"enquanto"          { yylval.nlinha = numLinha; return ENQUANTO; }
"escreva"           { yylval.nlinha = numLinha; return ESCREVA; }
"execute"           { yylval.nlinha = numLinha; return EXECUTE; }
"int"               { yylval.nlinha = numLinha; return INT; }
"leia"              { yylval.nlinha = numLinha; return LEIA; }
"novalinha"         { yylval.nlinha = numLinha; return NOVALINHA; }
"programa"          { yylval.nlinha = numLinha; return PROGRAMA; }
"retorne"           { yylval.nlinha = numLinha; return RETORNE; }
"se"                { yylval.nlinha = numLinha; return SE; }
"senao"             { yylval.nlinha = numLinha; return SENAO; }

{IDENT}             { yylval.tokenLexema = strdup(yytext); return ID; }
{INTCONST}          { yylval.nlinha = numLinha; return CONSINT; }
{CARCONST}          { yylval.nlinha = numLinha; return CONSCAR; } 
{CADCHAR}           { yylval.nlinha = numLinha; return CADEIACARACTERES; } 

"+"                 { yylval.nlinha = numLinha; return MAIS; }
"-"                 { yylval.nlinha = numLinha; return MENOS; }
"*"                 { yylval.nlinha = numLinha; return VEZES; }
"/"                 { yylval.nlinha = numLinha; return DIVIDIDO; }
"%"                 { yylval.nlinha = numLinha; return RESTO; }

"="                 { yylval.nlinha = numLinha; return IGUAL; }
"=="                { yylval.nlinha = numLinha; return IGUALIGUAL; }
">"                 { yylval.nlinha = numLinha; return MAIOR; }
">="                { yylval.nlinha = numLinha; return MAIORIGUAL; }
"<"                 { yylval.nlinha = numLinha; return MENOR; }
"<="                { yylval.nlinha = numLinha; return MENORIGUAL; }

"&&"                { yylval.nlinha = numLinha;  return E; }
"||"                { yylval.nlinha = numLinha;  return OU; }
"!"                 { yylval.nlinha = numLinha;  return EXCLAMACAO; }

"("                 { yylval.nlinha = numLinha;  return PAREN_E; }	
")"                 { yylval.nlinha = numLinha;  return PAREN_D; }
"["                 { yylval.nlinha = numLinha;  return COLCH_E; }
"]"                 { yylval.nlinha = numLinha;  return COLCH_D; }
"{"                 { yylval.nlinha = numLinha;  return CHAVE_E; }
"}"                 { yylval.nlinha = numLinha;  return CHAVE_D; }
"?"                 { yylval.nlinha = numLinha;  return INTERROGACAO; }
":"                 { yylval.nlinha = numLinha;  return DOISPONTOS; }
";"                 { yylval.nlinha = numLinha;  return PONTOVIRGULA; }
","                 { yylval.nlinha = numLinha;  return VIRGULA; }

{SPACE}             {}
\n 			            numLinha++;

{WORD}({WORD}|{NUMBER})*(\r|\n|\r\n){WORD}({WORD}|{NUMBER})* {
  strcpy(messageError,"ERRO: Palavra não termina");
  errorLexical = 1; /* erro lexico */ 
  yyerror(messageError);
}

. {
  strcpy(messageError,"ERRO: CARACTER INVÁLIDO");
  errorLexical = 1;
  yyerror(messageError);
}

%%

int yywrap(){
  return 1;
}