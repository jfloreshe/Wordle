#include "../include/UI/symbol.hpp"
#include <iostream>
using namespace UI;

Symbol::Symbol():Symbol(L' '){}

Symbol::Symbol(wchar_t symbol)
{
    _symbol = symbol;
    _state = UNUSED;
}

void Symbol::print()
{
    switch (_state)
    {
    case UNUSED:
        std::wcout << L' ' << _symbol << L' ';
        break;
    case NOT_IN_WORD:
        std::wcout << L'>' << _symbol << L'<';
        break;
    case RIGHT_POSITION:
        std::wcout << L'=' << _symbol << L'=';
        break;
    case INCORRECT_POSITION:
        std::wcout << L'<' << _symbol << L'>';
        break;
    default:
        break;
    }    
}
void Symbol::setState(SymbolState newState)
{
    _state = newState;
}
void Symbol::setSymbol(wchar_t symbol)
{
    _symbol = symbol;
}