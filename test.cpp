#include "Parser.hpp"

int main()
{
    // std::string str1 = "Hello World Young";
    // std::string str2 = ":Hello World Young";
    std::string str1 = ":Hello Wor1ld Young :hello uni";
    std::string str2 = "   CAP,LS   ";

    // std::string str1 = "::        ";
    try
    {
        Parser p1(str1);
        p1.printVector();
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}