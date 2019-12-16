#ifndef _TYPES_H
#define _TYPES_H

typedef enum{
    any,	
    block,
    single,
    unknown,
    integer,
    returns,
    if_while,
    program,
    character,
    statements,
    invocation,
    assignment,
    typeDeclProg,
    declarations,
    unknown_array,
    integer_array,
    variable_list,
    parameter_list,
    integer_method,
    character_array,
    character_method,
    logical_operator,
    arithmetic_operator,
    relational_operator
} TypesOperators;


//Definicao de um no da arvore abstrata.
typedef struct operador{
    TypesOperators typeOperator; // for, if, id, etc
    int line;
    char* lexema; // utilizado apenas em nos da especie Num para armazenar o lexa do numero
    struct operador* nodeTree1;
    struct operador* nodeTree2;
    struct operador* nodeTree3;
} NodeTree;

#endif
