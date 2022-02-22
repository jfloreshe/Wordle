#ifndef DATA_SERIALIZER_HPP
#define DATA_SERIALIZER_HPP
#include <string>
#include <set>

namespace DATA
{
class Serializer{
private:

public:
    Serializer(){}
    ~Serializer(){}
    void SerializeByDate(std::set<std::wstring> dataBase, int year);
    std::string toUtf8(std::wstring & ws);
    std::string formatDigit(int number);
};
}
#endif