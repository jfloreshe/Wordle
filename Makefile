rm:
	rm *.o
all:
	g++ -c ./src/board.cpp
	g++ -c ./src/symbol.cpp
	g++ -c ./src/word.cpp
	g++ -c ./src/wordle.cpp
	g++ -c ./src/fetcher.cpp
	g++ -c ./src/serializer.cpp
	g++ -o main board.o symbol.o word.o wordle.o fetcher.o serializer.o ./include/nlohman/json.hpp main.cpp
	make rm	
	clear
	./main