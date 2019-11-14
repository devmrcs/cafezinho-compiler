%{
//Autor: Marcos Antônio de Souza
//Matricula: 201514357

#include <stdio.h>	
%}

%start programa

%token VIRGULA PONTOVIRGULA INTERROGACAO DOISPONTOS EXCLAMACAO
%token ABRECHAVES ABREPARENTESES ABRECOLCHETES FECHACHAVES FECHAPARENTESES FECHACOLCHETES
%token MENOR MAIOR MENORIGUAL MAIORIGUAL MENOS MAIS VEZES DIVIDIR RESTO IGUAL IGUALDUPLO DIFERENTE E OU
%token ENQUANTO SE ENTAO SENAO RETORNE ESCREVA LEIA EXECUTE

%token INT CAR INTCONST
%token ID NOVALINHA PROGRAMA CARCONST
%%

programa :
	declfuncvar declprog
;

declfuncvar :
	tipo ID declvar PONTOVIRGULA declfuncvar
	| tipo ID ABRECOLCHETES INTCONST FECHACOLCHETES declvar PONTOVIRGULA declfuncvar
	| tipo ID declfunc declfuncvar
	|
;

declprog :
	PROGRAMA bloco
;

declvar :
	VIRGULA ID declvar
	| VIRGULA ID ABRECOLCHETES INTCONST FECHACOLCHETES declvar
	|
;

declfunc :
	ABREPARENTESES listaparametros FECHAPARENTESES bloco
;

listaparametros :
	| listaparametrosCont
;

listaparametrosCont :
	tipo ID 
	| tipo ID ABRECOLCHETES FECHACOLCHETES
	| tipo ID VIRGULA listaparametrosCont
	| tipo ID ABRECOLCHETES FECHACOLCHETES VIRGULA listaparametrosCont
;

bloco :
	ABRECHAVES listadeclvar listacomando FECHACHAVES
	| ABRECHAVES listadeclvar FECHACHAVES
;

listadeclvar :
	| tipo ID declvar PONTOVIRGULA listadeclvar
	| tipo ID ABRECOLCHETES INTCONST FECHACOLCHETES declvar PONTOVIRGULA listadeclvar
;

tipo :
	INT
	| CAR
;

listacomando :
	comando
	| comando listacomando
;

comando :
	PONTOVIRGULA
	| expr PONTOVIRGULA
	| RETORNE expr PONTOVIRGULA
	| LEIA lvalueexpr PONTOVIRGULA
	| ESCREVA expr PONTOVIRGULA
	| ESCREVA CARCONST PONTOVIRGULA
	| NOVALINHA PONTOVIRGULA
	| SE ABREPARENTESES expr FECHAPARENTESES ENTAO comando
	| SE ABREPARENTESES expr FECHAPARENTESES ENTAO comando SENAO comando
	| ENQUANTO ABREPARENTESES expr FECHAPARENTESES EXECUTE comando
	| bloco
;

expr :
	assingexpr
;

assingexpr :
	condexpr
	| lvalueexpr IGUAL assingexpr
;

condexpr :
	orexpr
	| orexpr INTERROGACAO expr DOISPONTOS condexpr
;

orexpr :
	orexpr OU andexpr
	| andexpr
;

andexpr :
	andexpr E eqexpr
	| eqexpr
;

eqexpr :
	eqexpr IGUALDUPLO desigexpr
	| eqexpr DIFERENTE desigexpr
	| desigexpr
;

desigexpr :
	desigexpr MENOR addexpr
	| desigexpr MAIOR addexpr
	| desigexpr MENORIGUAL addexpr
	| desigexpr MAIORIGUAL addexpr
	| addexpr
;

addexpr :
	addexpr MAIS mulexpr
	| addexpr MENOS mulexpr
	| mulexpr
;

mulexpr :
	mulexpr VEZES unexpr
	| mulexpr DIVIDIR unexpr
	| mulexpr RESTO unexpr
	| unexpr
;

unexpr :
	MENOS primexpr
	| EXCLAMACAO primexpr
	| primexpr
;

lvalueexpr :
	ID ABRECOLCHETES expr FECHACOLCHETES
	| ID
;

primexpr :
	ID ABREPARENTESES listexpr FECHAPARENTESES
	| ID ABREPARENTESES FECHAPARENTESES
	| ID ABRECOLCHETES expr FECHACOLCHETES
	| ID
	| INTCONST
	| CARCONST
	| ABREPARENTESES expr FECHAPARENTESES
;

listexpr :
	assingexpr
	| listexpr VIRGULA assingexpr
;

%%
main(){
	printf("+-------------------+\n");
	printf("|       START       |\n");
	printf("+-------------------+\n");
	yyparse();
	printf("+-------------------+\n");
	printf("|        END        |\n");
	printf("+-------------------+\n");
	//printf("| Total de linhas: %d\n", yyget_lineno());

	return 0;
}

yyerror(s)
char *s;
{	
	printf("+-------------------+\n");
	printf("|       ERROR\n");
	printf("| Line: %d\n", yyget_lineno());
	printf("| %s\n", s);
	printf("+-------------------+\n");
}

yywrap()
{
	return(1);
}