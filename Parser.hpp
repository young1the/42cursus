#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>

class Parser
{

private:

    typedef std::vector< std::pair<std::string, int> >   Vector;
    
    Vector _v;

    /** <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
        <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
        <command>  ::= <letter> { <letter> } | <number> <number> <number>
        <SPACE>    ::= ' ' { ' ' }
        <params>   ::= <SPACE> [ ':' <trailing> | <middle> <params> ]
        <middle>   ::= <Any *non-empty* sequence of octets not including SPACE
                    or NUL or CR or LF, the first of which may not be ':'>
        <trailing> ::= <Any, possibly *empty*, sequence of octets not including
                        NUL or CR or LF>
        <crlf>     ::= CR LF */
    enum TYPE
    {
        NONE = -1,
        PREFIX = 0,
        COMMAND = 1,
        PARAMS = 2,
        END,
    };

    void initVector(const std::string & str)
    {
        unsigned long prev_index = 0;
        unsigned long deli_index = str.find(' ');
        while (deli_index != std::string::npos)
        {
            std::string substring = str.substr(prev_index, deli_index - prev_index);
            _v.push_back(std::make_pair(substring, NONE));
            prev_index = deli_index + 1;
            if (str[prev_index] == ':')
            {
                _v.push_back(std::make_pair(str.substr(prev_index), NONE));
                return ;
            }
            deli_index = str.find(' ', prev_index);
        }
        _v.push_back(std::make_pair(str.substr(prev_index, deli_index - prev_index), NONE));
    }

    void setType()
    {
        int i = 0;
        if (_v[i].first[0] == ':')
        {
            _v[i++].second = PREFIX;
        }
        _v[i++].second = COMMAND;
        for (; i < _v.size(); ++i)
        {
            _v[i].second = PARAMS;
        }
    }

public:
    
    Parser(const std::string & str)
    {
        initVector(str);
        setType();
    }

    ~Parser();
 
    const Vector & getVector() {return _v;}

    void printVector() const
    {
        for (int i = 0; i < _v.size(); ++i)
        {
            std::cout << _v[i].first << " : " << _v[i].second << std::endl;
        }
    }

};

Parser::~Parser()
{
}
