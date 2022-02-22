#include "./include/APP/wordle.hpp"
#include <iostream>
#include <string>
#include <locale>

int main(){
    // WORDLE::Game* app = new WORDLE::Game {UI::Languages::SPANISH, 6, 5};
    // app -> display();
    // delete app;
    //app.display();
    setlocale(LC_ALL, "");
    std::wcout << "ñá";
    std::wstring test = L"hola ñeraáéíóú";
    std::wcout << test;
    for (auto i: test)
        std::wcout << i << std::endl;
    
}