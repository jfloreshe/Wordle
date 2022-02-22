#ifndef UI_BOARD_HPP
#define UI_BOARD_HPP
#include "./utilitarios.hpp"
#include "./word.hpp"
#include <vector>

namespace UI
{
class Board
{
protected:
    int _rows;
    int _columns;
    std::vector<Word*> words;
    void update();

public:
    Board(){}
    Board(int rows, int columns);
    ~Board();
    void addWord(std::wstring word){words.push_back(new Word{_columns, word});}
    void addWord(int size, std::wstring word){words.push_back(new Word{size,word});}
    std::vector<Word*>* getWords(){return &words;}
    virtual void print();
};

class KeyBoard: public Board
{
public:
    KeyBoard(){}
    KeyBoard(int rows, int columns):Board(rows, columns){}
    void print();
};

class KeyBoardSpanish: public KeyBoard
{
public:
    KeyBoardSpanish();
    void print(){KeyBoard::print();}
};
}
#endif