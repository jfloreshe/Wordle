#include "../include/UI/symbol.hpp"
#include <iostream>
using namespace UI;

Symbol::Symbol():Symbol(' '){}

Symbol::Symbol(char symbol)
{
    _symbol = symbol;
    _state = UNUSED;
}

void Symbol::print()
{
    switch (_state)
    {
    case UNUSED:
        std::cout <<' ' << _symbol <<' ';
        break;
    case NOT_IN_WORD:
        std::cout <<'>' << _symbol <<'<';
        break;
    case RIGHT_POSITION:
        std::cout <<'=' << _symbol <<'=';
        break;
    case INCORRECT_POSITION:
        std::cout <<'<' << _symbol <<'>';
        break;
    default:
        break;
    }    
}
void Symbol::setState(SymbolState newState)
{
    _state = newState;
}
void Symbol::setSymbol(char symbol)
{
    _symbol = symbol;
}