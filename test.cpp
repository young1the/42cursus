#include "Parser.hpp"

int main()
{
    // std::string str1 = "Hello World Young";
    // std::string str2 = ":Hello World Young";
    std::string str1 = ":Hello World Young :hello uni";

    Parser p1(str1);
    p1.printVector();
}