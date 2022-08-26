#include "Server.hpp"

int main()
{
    // std::string str1 = "Hello World Young";
    // std::string str2 = ":Hello World Young";
    Server s("4442", "4442");
    Client c1;
    Client c2;
    c2._nick = std::string("Hello");
    s._c.push_back(c1);
    s._c.push_back(c2);
    std::cout << s.GetClientByNick("hello")._nick << std::endl;
    
    if (s.isUniqueNick("dd") == true)
    {
        std::cout << "is Unique" << std::endl;
    }
    else
        std::cout << "isn't unique" << std::endl;
}