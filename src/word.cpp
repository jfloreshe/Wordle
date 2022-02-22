#include "../include/UI/word.hpp"
#include <iostream>
using namespace UI;

void Word::setSymbols(){
    for(auto symbol: _word){
        _symbols.push_back(new Symbol {symbol});
    }
}

Word::Word(int size){
    _size = size;
    for(int i = 0; i < _size; ++i)
        _word += ' ';
    setSymbols();
}

Word::Word(int size, std::wstring word){
    _size = size;
    _word = word;
    if(word.size() != _size)
        throw ("size is wrong");
    setSymbols();
}

Word::~Word(){
    for(auto& symbol: _symbols)
        delete symbol;
}

void Word::printSingleDelimiter(wchar_t delimiter){

    std::wcout << delimiter;    
    for(int i = 0; i < _size; ++i){
        _symbols[i] -> print();
        std::wcout << delimiter;
    }
}
void Word::printCompleteDelimiter(wchar_t firstDelimiter, wchar_t secondDelimiter){
    for(int i = 0; i < _size; ++i){
        std::wcout << firstDelimiter;
        _symbols[i] -> print();
        std::wcout << secondDelimiter;
    }
}
void Word::linkSymbolsToDictionary(std::map<wchar_t, Symbol*>* dictionary){
    for(auto& symbol: _symbols){
        (*dictionary)[symbol->getSymbol()] = symbol;
    }
}
int Word::getTotalDelimiters(int typeDelimiter){
    switch(typeDelimiter)
    {
        case 1:
            return _size + 1;
            break;
        case 2:
            return _size * 2;
            break;
        default:
            return 0;
            break;
    }
}

