#Makefile Cafezinho C++

all: objFolder cafezinho

cafezinho: cafezinho_parser.cpp cafezinho_lexer.cpp
	@ cd source && g++ main.cpp cafezinho_lexer.cpp cafezinho_parser.cpp -o cafezinho
	@ cd source && mv cafezinho_parser.cpp cafezinho_parser.h cafezinho_lexer.cpp ../objects
	@ cd source && mv cafezinho ../

cafezinho_parser.cpp:
	@ cd source && bison -o cafezinho_parser.cpp cafezinho.y

cafezinho_lexer.cpp: 
	@ cd source && flex -o cafezinho_lexer.cpp cafezinho.l

objFolder:
	@ mkdir -p objects


