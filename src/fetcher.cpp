#include "../include/DATA/fetcher.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <codecvt>
#include <iostream>
#include <set>
#include<cstdlib>

using namespace DATA;

void Fetcher::generatePalabras5(){
    srand(time(0));
    //read data into a set
    std::set<std::wstring> dataBase;
    std::wifstream wif("./resources/listado-general.txt");
    std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
    wif.imbue(loc);
    std::wstring word;
    do{
        getline(wif, word);
        if (word.size() == 5)
            dataBase.insert(word);
    }while(!wif.eof());
    wif.close();
    //redude the data to 365 words
    while(dataBase.size() > _size){
         int max = dataBase.size() - 1;
         int random = rand() % max;
         auto it = dataBase.begin();
         for(int i = 0; i < random; ++i){
             ++it;
         }
         dataBase.erase(it);
    }

    //send data to file palabras5
    std::wofstream wof("./resources/palabras5.txt", std::ios::out);
    wof.imbue(loc);
    for(auto it = dataBase.begin(); it != dataBase.end(); ++it){
        wof << (*it) << "\n";
    }
    wof.close();
}
