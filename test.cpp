#include "Parser.hpp"

int main()
{
    std::string str = "Hello World Young";
    Parser p(str, ' ');
    p.printV();
    std::cout << p.getVector()[0] << std::endl;;
}