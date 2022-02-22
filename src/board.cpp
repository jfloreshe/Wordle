#include "../include/UI/board.hpp"
#include <iostream>
#include <locale.h>
using namespace UI;

Board::Board(int rows, int columns){
    _rows = rows;
    _columns = columns;
}

Board::~Board(){
    for(auto& v: words){
        delete v;
    }
}

void Board::print(){
    int totalDelimiters = _columns + 1;
    int totalColumns = _columns*3 + totalDelimiters;//3 = ratio columns - symbol 25-20  5%2
    for(auto& word: words){
        int wordTotalDelimiter = word -> getSize() + 1;
        int sideSize = (totalColumns - (word->getSize()*3 + wordTotalDelimiter))/2;
        for(int i = 0; i < sideSize; ++i)
            std::cout << ' ';
        word->printSingleDelimiter('|');
        std::cout<<std::endl;
    }
}

void KeyBoard::print(){
    int totalDelimiters = _columns*2;
    int totalColumns = _columns*3 + totalDelimiters;
    for(auto& word: words){
        int wordTotalDelimiter = word -> getSize()*2;
        int sideSize = (totalColumns - (word->getSize()*3 + wordTotalDelimiter))/2;
        for(int i = 0; i < sideSize; ++i)
            std::cout << ' ';
        word->printCompleteDelimiter('[',']');
        std::cout<<std::endl;
    }
}

void Board::update(){

}

KeyBoardSpanish::KeyBoardSpanish(){
    _rows = 3;
    _columns = 10;
    addWord("QWERTYUIOP");
    addWord("ASDFGHJKLÑ");
    addWord(7,"ZXCVBNM");
}