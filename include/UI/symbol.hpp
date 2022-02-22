#ifndef UI_SYMBOL_HPP
#define UI_SYMBOL_HPP
#include "./utilitarios.hpp"
#include <string>
namespace UI
{
class Symbol
{
    private:
        char _symbol;
        SymbolState _state;
    public:
        Symbol();
        Symbol(char symbol);
        virtual void print();
        void setState(SymbolState newState);
        void setSymbol(char symbol);
        SymbolState getState(){return _state;}
        char getSymbol(){return _symbol;}
};
//herencia para simbolo con color
}
#endif