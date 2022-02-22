#ifndef UI_WORD_HPP
#define UI_WORD_HPP
#include "./utilitarios.hpp"
#include "./symbol.hpp"
#include <string>
#include <vector>
#include <map>
namespace UI
{
class Word
{
private:
    std::wstring _word;
    int _size;
    std::vector<Symbol*> _symbols; 
    void setSymbols();
    void updateSymbols();
public:
    Word(int size);
    Word(int size, std::wstring word);
    ~Word();
    void setWord(std::wstring word);
    void printSingleDelimiter(wchar_t delimiter);
    void printCompleteDelimiter(wchar_t firstDelimiter, wchar_t secondDelimiter);
    void linkSymbolsToDictionary(std::map<wchar_t, Symbol*>* symbols);
    int getSize(){return _size;}
    int getTotalDelimiters(int typeDelimiter);
    bool evaluate (std::wstring word, std::map<wchar_t,UI::Symbol*>* keys);
};
}
#endif