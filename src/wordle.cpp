#include "../include/APP/wordle.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <codecvt>
#include <vector>

using namespace WORDLE;

Game::Game(UI::Languages language, int tries, int wordSize){
     _errorMessage = L"";
    _tries = tries;
    _wordSize = wordSize;
    _state = IDLE;
    setlocale(LC_ALL, "");
    setLanguage(language);
    _wordBoard = new UI::Board(tries,wordSize);
    std::wstring word = L"";
    for(int j = 0; j < wordSize; ++j){
        word += L' ';
    }
    for(int i = 0; i < tries; ++i){
        _wordBoard -> addWord(word);
    }
    initDictionary();
}

void Game::readFile(const char* filename){
    std::wifstream wif(filename);
    std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
    wif.imbue(loc);
    std::wstring word;
    do{
        getline(wif, word);
        if(word.size() < 5)
            continue;
        normalize(word);
        normalizeUTF8(word);
        dictionary.insert(word);
    }while(!wif.eof());
    wif.close();
}
void Game::initDictionary(){
    DATA::Fetcher fetcher {365};
    fetcher.generatePalabras5();
    readFile("./resources/palabras5.txt");
    int max = dictionary.size();
    int random = rand() % max;
    auto it = dictionary.begin();
    for(int i = 0; i < random; ++i){
        ++it;
    }
    _dailyWord = *it;
    /*DATA::Serializer jsonSerializer{};
    jsonSerializer.SerializeByDate(dictionary, 2021);*/
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

void Game::normalizeUTF8(std::wstring& word){
    std::wstring spanishLowerCaseTilde = L"áéíóúäëïöü";
    std::wstring spanishUppperCaseTilde = L"ÁÉÍÓÚÄËÏÖÜ";
    for(auto& symbol: word){
        for(auto& lowerSymbol: spanishLowerCaseTilde){
            if(symbol == lowerSymbol)
                symbol -= 32;
        }
        if(symbol == L'Á' || symbol == L'Ä')
            symbol = L'A';
        if(symbol == L'É' || symbol == L'Ë')
            symbol = L'E';
        if(symbol == L'Í' || symbol == L'Ï')
            symbol = L'I';
        if(symbol == L'Ó' || symbol == L'Ö')
            symbol = L'O';
        if(symbol == L'Ú' || symbol == L'Ü')
            symbol = L'U';
    }
}

void Game::normalize(std::wstring& word){
    std::wstring charsToTrim = L" ";
    std::wstring spanishLowerCase = L"abcdefghijklmnopqrstuvwxyzñ";

    std::wstring wordNormalized = word.erase(word.find_last_not_of(charsToTrim) + 1);
    word = wordNormalized.erase(0, wordNormalized.find_first_not_of(charsToTrim));
    for(auto& symbol: word){
        for(auto& spanishSymbol: spanishLowerCase){
            if(symbol == spanishSymbol)
                symbol -= 32;
        }
    }
}

bool Game::verifySymbols(std::wstring& word){
    std::wstring spanishUpperCase = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÑ";
    for(auto& symbol: word){
        bool found = false;
        for(auto& spanishSymbol: spanishUpperCase){
            if(symbol == spanishSymbol){
                found = true;
                break;
            }
        }
        if(!found)
            return false;
    }
    return true;
}

bool Game::isInDictionary(std::wstring& word){
    auto it = dictionary.find(word);
    if(it != dictionary.end())
        return true;
    return false;
}

bool Game::validate(std::wstring& word){
    normalize(word);
    if (word.size() != _wordSize){
        _errorMessage = L"Wrong size of word\n";
         return false;
    }
    if (!verifySymbols(word)){
        _errorMessage = L"Wrong symbols in your word\n";
         return false;
    }
    if (!isInDictionary(word)){
        _errorMessage = L"Your word does not match any of our database\n";
         return false;
    }
    _errorMessage = L"";
    return true;
}


void Game::display(){

    std::wcout<<_errorMessage;
    _wordBoard -> print();
    std::wcout << std::endl << std::endl;
    _keyBoard -> print();
    std::wcout << std::endl << std::endl;
}
void Game::run(){
    _state = RUNNING;
    int currentTry = 0;
    std::wstring word;
    while(_state == RUNNING){
        system("clear");
        std::wcout << _dailyWord << std::endl;
        display();
        std::wcin >> word;
        //If word is correct return currentTry + 1, else keeps in the same try
        if(!validate(word)){
            std::wcout<<L"Palabra ingresada incorrecta"<<std::endl;
            continue;
        }
        _wordBoard -> setWord(word, currentTry);
        bool finalResult = _wordBoard -> tryWord(_dailyWord, currentTry, &_keyBoardKeys);
        if(finalResult){
            _errorMessage = L"You Won\n";
            _state = IDLE;
            continue;
        }
        if(++currentTry == _tries){
            _errorMessage = L"You Lost\n";
            _state = IDLE;
        }
    }
    
    system("clear");
    display();
}