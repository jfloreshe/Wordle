#ifndef APP_GAME_HPP
#define APP_GAME_HPP

#include "../UI/board.hpp"
#include "../UI/symbol.hpp"
#include "../UI/word.hpp"
#include "../UI/utilitarios.hpp"
#include <iostream>
#include <map>
namespace WORDLE
{
class Game
{
private:
    std::map<char,UI::Symbol*> _keyBoardKeys;
    UI::Board* _wordBoard;
    UI::Board* _keyBoard;
    UI::Languages _language;
    void setLanguage(UI::Languages language);
public:
    Game(UI::Languages language, int tries, int wordSize);
    ~Game();
    void display();
};
}
#endif