all: objFolder cafezinho

cafezinho: cafezinho_parser.o cafezinho_lexer.o
	@ cd source && gcc cafezinho_parser.o cafezinho_lexer.o -o cafezinho -w
	@ cd source && mv *.c *.o cafezinho_parser.h ./objects
	@ cd source && mv cafezinho ../
	@ cd source && mv objects ../

cafezinho_parser.o: cafezinho_parser.c
	@ cd source && gcc -c cafezinho_parser.c -o cafezinho_parser.o

cafezinho_parser.c:  source/cafezinho_parser.y
	@ cd source && bison -d -o cafezinho_parser.c cafezinho_parser.y
	
cafezinho_lexer.o: source/cafezinho_lexer.c
	@ cd source && gcc -c cafezinho_lexer.c -o cafezinho_lexer.o

cafezinho_lexer.c: source/cafezinho_lexer.l
	@ cd source && flex -o cafezinho_lexer.c cafezinho_lexer.l

objFolder:
	@ rm -rf objects
	@ cd source && mkdir -p objects

