#ifndef UI_SYMBOL_HPP
#define UI_SYMBOL_HPP
#include "./utilitarios.hpp"
#include <string>
namespace UI
{
class Symbol
{
    private:
        wchar_t _symbol;
        SymbolState _state;
    public:
        Symbol();
        Symbol(wchar_t symbol);
        virtual void print();
        void setState(SymbolState newState);
        void setSymbol(wchar_t symbol);
        SymbolState getState(){return _state;}
        wchar_t getSymbol(){return _symbol;}
};
//herencia para simbolo con color
}
#endif