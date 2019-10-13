# .y files
Y_SOURCE= ./source/cafezinho.y
 
# .l files
L_SOURCE= ./source/cafezinho.l

#Makefile Cafezinho

all: objFolder cafezinho

cafezinho: cafezinho.tab.c lex.yy.c
	@ gcc -o cafezinho cafezinho.tab.c lex.yy.c -w
	@ mv cafezinho.tab.c lex.yy.c cafezinho.tab.h objects

cafezinho.tab.c: $(Y_SOURCE)
	@ bison -d $(Y_SOURCE)

lex.yy.c: $(L_SOURCE)
	@ flex $(L_SOURCE)

objFolder:
	@ mkdir -p objects