#include "../include/DATA/serializer.hpp"
#include "../include/nlohman/json.hpp"
#include <iostream>
#include <map>
#include <codecvt> 
#include <locale> 

using json = nlohmann::json;
using namespace DATA;

std::string Serializer::toUtf8(std::wstring & ws){
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    return utf8_conv.to_bytes(ws);
}

std::string Serializer::formatDigit(int number){
    std::string digitFormated = "";
    if(number >= 0 && number <10)
        digitFormated = "0";
    digitFormated += std::to_string(number);
    return digitFormated;
}

void Serializer::SerializeByDate(std::set<std::wstring> dataBase, int year){
    std::vector<int> meses = {31,28,31,30,31,30,31,31,30,31,30,31};
    json wordByDate;
    for(int i = 0 ; i < 12; i++){
        for(int j = 1; j<= meses[i]; j++ ){
            int max = dataBase.size();
            int random = rand() % max;
            auto it = dataBase.begin();
            for(int i = 0; i < random; ++i){
                ++it;
            }
            std::string date = formatDigit(year) +"-"+ formatDigit(i) +"-"+formatDigit(j); 
            std::wstring word = *it;
            std::string utfWord = toUtf8(word);
            wordByDate[date] = utfWord;
            dataBase.erase(it);
        }
    }
    std::cout << wordByDate;
}