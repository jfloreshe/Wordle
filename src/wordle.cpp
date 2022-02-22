#include "../include/APP/wordle.hpp"
#include <string>
#include <vector>
using namespace WORDLE;

Game::Game(UI::Languages language, int tries, int wordSize){
    setlocale(LC_ALL, "");
    setLanguage(language);
    _wordBoard = new UI::Board(tries,wordSize);
    std::wstring word = "";
    for(int j = 0; j < wordSize; ++j){
        word += ' ';
    }
    for(int i = 0; i < tries; ++i){
        _wordBoard -> addWord(word);
    }
}

void Game::setLanguage(UI::Languages language){
    delete _keyBoard;
    switch (language)
    {
    case UI::Languages::SPANISH:
        _keyBoard = new UI::KeyBoardSpanish {};
        break;
    default:
        throw ("Language not implemented");
        break;
    }
    std::vector<UI::Word*>* keyBoardWords = _keyBoard -> getWords();
    for(auto word: *keyBoardWords){
        word -> linkSymbolsToDictionary(&_keyBoardKeys);
    }
}

Game::~Game(){
    delete _wordBoard;
    delete _keyBoard;
}
void Game::display(){
    _wordBoard -> print();
    std::wcout << std::endl;
    _keyBoard -> print();
}