#ifndef APP_GAME_HPP
#define APP_GAME_HPP

#include "../UI/board.hpp"
#include "../UI/symbol.hpp"
#include "../UI/word.hpp"
#include "../UI/utilitarios.hpp"
#include "../DATA/fetcher.hpp"
#include "../DATA/serializer.hpp"
#include <iostream>
#include <map>
#include <set>
namespace WORDLE
{
enum State{RUNNING, IDLE};

class Game
{
private:
    int _tries;
    int _wordSize;
    State _state;
    std::wstring _dailyWord;
    std::wstring _errorMessage;
    std::map<wchar_t,UI::Symbol*> _keyBoardKeys;
    std::set<std::wstring> dictionary;
    UI::Board* _wordBoard;
    UI::Board* _keyBoard;
    UI::Languages _language;
    void setLanguage(UI::Languages language);
    void normalize(std::wstring& word);
    void normalizeUTF8(std::wstring& word);
    void initDictionary();
    void readFile(const char* filename);
    bool isInDictionary(std::wstring& word);
    bool validate(std::wstring& word);
    bool verifySymbols(std::wstring& word);
public:
    Game(UI::Languages language, int tries, int wordSize);
    ~Game();
    void run();
    void display();
};
}
#endif