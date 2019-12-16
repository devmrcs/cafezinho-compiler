%{
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

%}

/* Secao de definicoes para o Bison 
 define os simbolos usados na gramatica e tipos dos valores
 semanticos associados a cada simbolo (terminal e não terminal)*/

%union{
    int nlinha;
    char* tokenLexema;
    NodeTree* PointerTreeNode;
}

//Inicia a gramática na regra Programa
%start Programa

//Declara o tipos dos não terminais como Tpont, ou seja um Nó da arvore abstrata 
%type<PointerTreeNode> Programa DeclFuncVar DeclProg DeclVar DeclFunc
%type<PointerTreeNode> ListaParametros ListaParametrosCont Bloco ListaDeclVar 
%type<PointerTreeNode> Tipo ListaComando Comando Expr AssignExpr CondExpr OrExpr AndExpr 
%type<PointerTreeNode> EqExpr DesigExpr AddExpr MulExpr UnExpr LValueExpr PrimExpr ListExpr

//Declara o tipos tokenLexema, para retornarem o valor do lexico
%token<tokenLexema> ID CONSCAR CONSINT CADEIACARACTERES

//Tokens obtidos no analisador lexico .l, 
%token PROGRAMA CAR INT RETORNE LEIA ESCREVA NOVALINHA SE
%token ENTAO SENAO ENQUANTO EXECUTE MAIS MENOS VEZES DIVIDIDO RESTO 
%token IGUAL IGUALIGUAL MAIOR MAIORIGUAL MENOR MENORIGUAL E OU PAREN_E PAREN_D
%token COLCH_E COLCH_D CHAVE_E CHAVE_D INTERROGACAO EXCLAMACAO DOISPONTOS PONTOVIRGULA VIRGULA 

%%
Programa:
    DeclFuncVar DeclProg                                              	{ 	rootTree = makeNode(program, numLinha, $1, $2, NULL); }
;

DeclFuncVar:
    Tipo ID DeclVar PONTOVIRGULA DeclFuncVar                          	{
																			NodeTree* newNodeTree = makeNode($1->typeOperator, $1->line, NULL, NULL, $2);
                                                                        	$$ = makeNodeTernary(declarations, numLinha, newNodeTree , $3, $5, NULL);
																		}
  | Tipo ID COLCH_E CONSINT COLCH_D DeclVar PONTOVIRGULA DeclFuncVar	{
	  																		TypesOperators tmp = $1->typeOperator == integer ? integer_array : character_array;
	  																		NodeTree* newNodeTree = makeNode(tmp, $1->line, NULL, NULL, $2);
                                                                        	$$ = makeNodeTernary(declarations, numLinha, newNodeTree, $6, $8, NULL);
                                                                      	} 
  | Tipo ID DeclFunc DeclFuncVar                                      	{
	  																		$3->typeOperator = ($1->typeOperator == integer ? integer_method : character_method);
																			$3->lexema = $2;
	  																		$$ = makeNode(declarations, numLinha, $3, $4, NULL);
																		}
  |                                                                   	{ 	$$ = makeNode(declarations, numLinha, NULL, NULL, NULL); }
;

DeclProg:
    PROGRAMA Bloco                                                    	{ 
                                                                            $$ = $2;
                                                                            $$->typeOperator = typeDeclProg;
                                                                        }
;

DeclVar:
    VIRGULA ID DeclVar                                                	{
																			NodeTree* newNodeTree = makeNode(unknown, numLinha, NULL, NULL, $2);
																			$$ = makeNode(variable_list, numLinha, newNodeTree, $3, NULL);
																		}
  | VIRGULA ID COLCH_E CONSINT COLCH_D DeclVar                        	{
	  																		NodeTree* newNodeTree = makeNode(unknown, numLinha, NULL, NULL, $2);
																			$$ = makeNode(variable_list, numLinha, newNodeTree, $6, NULL);
																		}
  |                                                                   	{ 	$$ = makeNode(variable_list, numLinha, NULL, NULL, NULL); }
;
            
DeclFunc: 
    PAREN_E ListaParametros PAREN_D Bloco                             	{ 	$$ = makeNode(unknown, numLinha, $2, $4, NULL); }
;

ListaParametros:
                                                                      	{ 	$$ = makeNode(parameter_list, numLinha, NULL, NULL, NULL); }
  | ListaParametrosCont                                               	{ 	$$ = $1; }
;           

ListaParametrosCont:
    Tipo ID                                                           	{
												 							NodeTree* newNodeTree = makeNode($1->typeOperator, $1->line, NULL, NULL, $2);
																			$$ = makeNode(parameter_list, numLinha, newNodeTree, NULL, NULL);; 
																		}
  | Tipo ID COLCH_E COLCH_D                                           	{
												 							NodeTree* newNodeTree = makeNode($1->typeOperator == integer ? integer_array: character_array, $1->line, NULL, NULL, $2);
																			$$ = makeNode(parameter_list, numLinha, newNodeTree, NULL, NULL);; 
																		}
  | Tipo ID VIRGULA ListaParametrosCont                               	{
												 							NodeTree* newNodeTree = makeNode($1->typeOperator, $1->line, NULL, NULL, $2);
																			$$ = makeNode(parameter_list, numLinha, newNodeTree, $4, NULL);; 
																		}
  | Tipo ID COLCH_E COLCH_D VIRGULA ListaParametrosCont               	{
												 							NodeTree* newNodeTree = makeNode($1->typeOperator == integer ? integer_array: character_array, $1->line, NULL, NULL, $2);
																			$$ = makeNode(parameter_list, numLinha, newNodeTree, $6, NULL);; 
																		}
;
  
Bloco:
    CHAVE_E ListaDeclVar ListaComando CHAVE_D                         	{ 	$$ = makeNode(block, numLinha, $2, $3, NULL); }
  | CHAVE_E ListaDeclVar CHAVE_D                                      	{ 	$$ = makeNode(block, numLinha, $2, NULL, NULL); }
;
  
ListaDeclVar:
                                                                      	{ 	$$ = makeNode(variable_list, numLinha, NULL, NULL, NULL); }
  | Tipo ID DeclVar PONTOVIRGULA ListaDeclVar                         	{
												 							NodeTree* newNodeTree = makeNode($1->typeOperator, $1->line, NULL, NULL, $2);
																			$$ = makeNodeTernary(variable_list, numLinha, newNodeTree, $3, $5, NULL);; 
																		}
  | Tipo ID COLCH_E CONSINT COLCH_D DeclVar PONTOVIRGULA ListaDeclVar 	{
												 							NodeTree* newNodeTree = makeNode($1->typeOperator, $1->line, NULL, NULL, $2);
																			$$ = makeNodeTernary(variable_list, numLinha, newNodeTree, $6, $8, NULL);; 
																		}
;
  
Tipo:
    INT                                                               	{ 	$$ = makeNode(integer, numLinha, NULL, NULL, NULL); }
  | CAR                                                               	{ 	$$ = makeNode(character, numLinha, NULL, NULL, NULL); }
;
            
ListaComando:
    Comando                                                           	{ 	$$ = makeNode(statements, numLinha, $1, NULL, NULL); }
  | Comando ListaComando                                              	{ 	$$ = makeNode(statements, numLinha, $1, $2, NULL); }
;
                    
Comando:
    PONTOVIRGULA                                                      	{ 	$$ = makeNode(statements, numLinha, NULL, NULL, NULL); }
  | Expr PONTOVIRGULA                                                 	{ 	$$ = $1; }
  | RETORNE Expr PONTOVIRGULA                                         	{ 	$$ = makeNode(returns, numLinha, $2, NULL, NULL); }
  | LEIA LValueExpr PONTOVIRGULA                                      	{	$$ = $2; }
  | ESCREVA Expr PONTOVIRGULA                                         	{ 	$$ = $2; }
  | ESCREVA CADEIACARACTERES PONTOVIRGULA                             	{ 	$$ = makeNode(statements, numLinha, NULL, NULL, NULL); }
  | NOVALINHA PONTOVIRGULA                                            	{ 	$$ = makeNode(statements, numLinha, NULL, NULL, NULL); }
  | SE PAREN_E Expr PAREN_D ENTAO Comando                             	{ 	$$ = makeNode(if_while, numLinha, $3, $6, NULL); }
  | SE PAREN_E Expr PAREN_D ENTAO Comando SENAO Comando               	{ 	$$ = makeNodeTernary(if_while, numLinha, $3, $6, $8, NULL); }
  | ENQUANTO  PAREN_E  Expr  PAREN_D  EXECUTE Comando                 	{ 	$$ = makeNode(if_while, numLinha, $3, $6, NULL); }
  | Bloco                                                             	{ 	$$ = $1; }
;

Expr:
  AssignExpr                                                          	{	$$ = $1; }
;

AssignExpr:
    CondExpr                                                          	{ 	$$ = $1; }
  | LValueExpr IGUAL AssignExpr                                       	{ 	$$ = makeNode(assignment, numLinha, $1, $3, NULL); }
;

CondExpr:
    OrExpr                                                            	{ 	$$ = $1; }
  | OrExpr INTERROGACAO Expr DOISPONTOS CondExpr                      	{ 	$$ = makeNodeTernary(if_while, numLinha, $1, $3, $5, NULL); }
;

OrExpr:
    OrExpr OU AndExpr                                                 	{ 	$$ = makeNode(logical_operator, numLinha, $1, $3, NULL); }
  | AndExpr                                                           	{ 	$$ = $1; }
;

AndExpr:
    AndExpr E EqExpr                                                  	{ 	$$ = makeNode(logical_operator, numLinha, $1, $3, NULL); }
  | EqExpr                                                            	{ 	$$ = $1; }
;

EqExpr:
    EqExpr IGUALIGUAL DesigExpr                                       	{ 	$$ = makeNode(relational_operator, numLinha, $1, $3, NULL); }
  | EqExpr EXCLAMACAO IGUAL DesigExpr                                 	{ 	$$ = makeNode(relational_operator, numLinha, $1, $4, NULL); }
  | DesigExpr                                                         	{ 	$$ = $1; }
;

DesigExpr:
    DesigExpr MENOR AddExpr                                           	{ 	$$ = makeNode(relational_operator, numLinha, $1, $3, NULL); }
  | DesigExpr MAIOR AddExpr                                           	{ 	$$ = makeNode(relational_operator, numLinha, $1, $3, NULL); }
  | DesigExpr MAIORIGUAL AddExpr                                      	{ 	$$ = makeNode(relational_operator, numLinha, $1, $3, NULL); }
  | DesigExpr MENORIGUAL AddExpr                                      	{ 	$$ = makeNode(relational_operator, numLinha, $1, $3, NULL); }
  | AddExpr                                                           	{ 	$$ = $1; } 
;

AddExpr:
    AddExpr MAIS MulExpr                                              	{ 	$$ = makeNode(arithmetic_operator, numLinha, $1, $3, NULL); }
  | AddExpr MENOS MulExpr                                             	{ 	$$ = makeNode(arithmetic_operator, numLinha, $1, $3, NULL); }
  | MulExpr                                                           	{ 	$$ = $1; }
;

MulExpr:
    MulExpr VEZES UnExpr                                              	{ 	$$ = makeNode(arithmetic_operator, numLinha, $1, $3, NULL); }
  | MulExpr DIVIDIDO UnExpr                                           	{ 	$$ = makeNode(arithmetic_operator, numLinha, $1, $3, NULL); }
  | MulExpr RESTO UnExpr                                              	{ 	$$ = makeNode(arithmetic_operator, numLinha, $1, $3, NULL); }
  | UnExpr                                                            	{ 	$$ = $1; }
;

UnExpr:
    MENOS PrimExpr                                                    	{ 	$$ = makeNode(arithmetic_operator, numLinha, $2, NULL, NULL); }
  | EXCLAMACAO PrimExpr                                               	{ 	$$ = makeNode(logical_operator, numLinha, $2, NULL, NULL); }
  | PrimExpr                                                          	{ 	$$ = $1; }
;

LValueExpr:
    ID COLCH_E Expr COLCH_D                                           	{ 	$$ = makeNode(single, numLinha, NULL, NULL, $1); }
  | ID                                                                	{ 	$$ = makeNode(any, numLinha, NULL, NULL, $1); }
;

PrimExpr:
    ID PAREN_E ListExpr PAREN_D                                       	{ 	$$ = makeNode(invocation, numLinha, $3, NULL, $1); }
  | ID PAREN_E PAREN_D                                                	{ 	$$ = makeNode(invocation, numLinha, NULL, NULL, $1); }
  | ID COLCH_E Expr COLCH_D                                           	{ 	$$ = makeNode(single, numLinha, NULL, NULL, $1); }
  | ID                                                                	{ 	$$ = makeNode(any, numLinha, NULL, NULL, NULL); }
  | CONSCAR                                                           	{ 	$$ = makeNode(character, numLinha, NULL, NULL, NULL); }
  | CONSINT                                                           	{ 	$$ = makeNode(integer, numLinha, NULL, NULL, NULL); }
  | PAREN_E Expr PAREN_D                                              	{ 	$$ = $2; }
;

ListExpr:
    AssignExpr                                                        	{ 	$$ = makeNode(parameter_list, numLinha, $1, NULL, NULL); }
  | ListExpr VIRGULA  AssignExpr                                      	{ 	$$ = makeNode(parameter_list, numLinha, $3, NULL, NULL); }
;
%% /* Secao Epilogo*/   

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