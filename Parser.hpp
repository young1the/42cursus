#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Parser
{

private:

    std::vector<std::string> _v;

public:

    Parser(const std::string & str, const char & delimeter)
    {
        int prev_index = 0;
        int deli_index = str.find(delimeter);
        while (deli_index != std::string::npos)
        {
            std::string substring = str.substr(prev_index, deli_index - prev_index);
            _v.push_back(substring);
            prev_index = deli_index + 1;
            deli_index = str.find(delimeter, prev_index);
        }
        _v.push_back(str.substr(prev_index, deli_index - prev_index));
    }
    
    ~Parser();
 
    const std::vector<std::string> & getVector() {return _v;}
};

Parser::~Parser()
{
}
