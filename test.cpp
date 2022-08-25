#include "Parser.hpp"

int main()
{
    // std::string str1 = "Hello World Young";
    // std::string str2 = ":Hello World Young";
    std::string str1 = ":Hello World Young,Il :hello uni";
    std::string deli = "\r\n";
    std::string str = "CAP LS\r\nhello\r\n\r\nmy";

    // std::string str1 = "::        ";
    try
    {
        Parser p1(str,deli);
        p1.printVector();
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}