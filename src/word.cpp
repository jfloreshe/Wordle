#include "../include/UI/word.hpp"
#include <iostream>
using namespace UI;

void Word::setSymbols(){
    for(auto symbol: _word){
        _symbols.push_back(new Symbol {symbol});
    }
}

void Word::updateSymbols(){
    for(int i = 0; i < _size; ++ i){
        _symbols[i]->setSymbol(_word[i]);
    }
}

Word::Word(int size){
    _size = size;
    _word = L" ";
    for(int i = 0; i < _size; ++i)
        _word += L' ';
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

void Word::setWord(std::wstring word){
    _word = word;
    updateSymbols();
}

bool Word::evaluate (std::wstring word, std::map<wchar_t,UI::Symbol*>* keys ){
    std::map<wchar_t, int> wordPositions;
    int pos = 0;
    for(wchar_t s: word){
        wordPositions[s] = pos++;
    }
    int matches = 0;
    for(int i = 0; i < _size; ++i){
        auto it = wordPositions.find(_word[i]);
        if (it == wordPositions.end()){
            _symbols[i] -> setState(NOT_IN_WORD);
            (*keys)[_word[i]]->setState(NOT_IN_WORD);
            continue;
        }
        if (it->second == i){
            _symbols[i] -> setState(RIGHT_POSITION);
            (*keys)[_word[i]]->setState(RIGHT_POSITION);
            if(++matches == _size)
                return true;
        }
        else{
            _symbols[i] -> setState(INCORRECT_POSITION);
            (*keys)[_word[i]]->setState(INCORRECT_POSITION);
        }        
    }
    return false;
}

void Word::printSingleDelimiter(wchar_t delimiter){

    std::wcout << delimiter;    
    for(int i = 0; i < _size; ++i){
        _symbols[i] -> print();
        std::wcout << delimiter;
    }
    std::wcout << std::endl;
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

