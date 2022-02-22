#ifndef DATA_FETCHER_HPP
#define DATA_FETCHER_HPP
#include <locale>
namespace DATA
{

class Fetcher
{
private:
    int _size;
public:
    Fetcher(int size):_size{size}{setlocale(LC_ALL, "");}
    ~Fetcher(){}
    void fetchDataFromUrl(){}
    void generatePalabras5();
};
}
#endif