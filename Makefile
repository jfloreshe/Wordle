rm:
	rm *.o
all:
	g++ -c ./src/board.cpp
	g++ -c ./src/symbol.cpp
	g++ -c ./src/word.cpp
	g++ -c ./src/wordle.cpp
	g++ -o main board.o symbol.o word.o wordle.o main.cpp
	make rm	
	clear
	./main