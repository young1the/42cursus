#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <exception>
#include <cctype>

class Parser
{

private:

    typedef std::vector< std::pair<std::string, int> >   Vector;
    
    Vector _v;

    void initVector(const std::string & str)
    {
        unsigned long prev_index = 0;
        unsigned long deli_index = str.find(' ');
        while (deli_index != std::string::npos)
        {
            std::string substring = str.substr(prev_index, deli_index - prev_index);
            if (substring != "")
                _v.push_back(std::make_pair(substring, NONE));
            prev_index = deli_index + 1;
            if (str[prev_index] == ':')
            {
                _v.push_back(std::make_pair(str.substr(prev_index), NONE));
                return ;
            }
            deli_index = str.find(' ', prev_index);
        }
        std::string substring = str.substr(prev_index, deli_index - prev_index);
        if (substring != "")
            _v.push_back(std::make_pair(substring, NONE));
    }

    void setType()
    {
        size_t i = 0;
        if (_v.empty())
            throw std::logic_error("Wrong Format!");
        if (_v[i].first[0] == ':')
        {
            _v[i++].second = PREFIX;
        }
        _v[i++].second = COMMAND;
        for (; i < _v.size(); ++i)
        {
            if (_v[i].first[0] == ':')
            {
                _v[i].second = TRAILING;
                return ;
            }
            _v[i].second = PARAMS;
        }
    }

    void checkVector()
    {
        // for (size_t i = 0; i < _v.size(); ++i)
        // {
        //     switch (_v[i].second)
        //     {
        //         case PREFIX:
        //             _v[i].first.erase(_v[i].first.begin());
        //             if(!checkStr(_v[i].first, isChstring))
        //             {
        //                 std::string errmsg = _v[i].first + " : Wrong Format!!";
        //                 throw std::logic_error(errmsg.c_str());
        //             }
        //             break ;
        //         case TRAILING:
        //             _v[i].first.erase(_v[i].first.begin());
        //             break ;
        //         default:
        //             if(!checkStr(_v[i].first, isChstring))
        //             {
        //                 std::string errmsg = _v[i].first + " : Wrong Format!!";
        //                 throw std::logic_error(errmsg.c_str());
        //             }
        //     }
        // }
    }

public:
    
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
        TRAILING = 3,
        END,
    };

    Parser(const std::string & str)
    {
        initVector(str);
        setType();
        checkVector();
    }

    Parser(const std::string & str, const char & delimeter)
    {
        unsigned long prev_index = 0;
        unsigned long deli_index = str.find(delimeter);
        while (deli_index != std::string::npos)
        {
            std::string substring = str.substr(prev_index, deli_index - prev_index);
            if (substring != "")
                _v.push_back(std::make_pair(substring, NONE));
            prev_index = deli_index + 1;
            deli_index = str.find(delimeter, prev_index);
        }
        std::string substring = str.substr(prev_index, deli_index - prev_index);
        if (substring != "")
            _v.push_back(std::make_pair(substring, NONE));
    }

    Parser(const std::string & str, const std::string & delimeter)
    {
        unsigned long prev_index = 0;
        unsigned long deli_index = str.find(delimeter);
        unsigned long deli_len = delimeter.size();
        while (deli_index != std::string::npos)
        {
            std::string substring = str.substr(prev_index, deli_index - prev_index);
            if (substring != "")
                _v.push_back(std::make_pair(substring, NONE));
            prev_index = deli_index + deli_len;
            deli_index = str.find(delimeter, prev_index);
        }
        std::string substring = str.substr(prev_index, deli_index - prev_index);
        if (substring != "")
            _v.push_back(std::make_pair(substring, NONE));
    }

    ~Parser();
 
    const Vector & getVector() {return _v;}

    void printVector() const
    {
        for (size_t i = 0; i < _v.size(); ++i)
        {
            std::cout <<"|"<< _v[i].first<<"|" << " : " << _v[i].second << std::endl;
        }
    }

	std::string getCommand()
	{
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (_v[i].second == COMMAND)
				return _v[i].first;
		}
		return "";
	}

	std::vector<std::string> getParams()
	{
		std::vector<std::string> p;
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (_v[i].second == PARAMS)
				p.push_back(_v[i].first);
		}
		return p;
	}

	std::string getTrail()
	{
		for (size_t i = 0; i < _v.size(); ++i)
		{
			if (_v[i].second == TRAILING)
				return _v[i].first;
		}
		return "";
	}

    static bool checkStr(const std::string & str, int (*f)(int))
    {
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (!f(str[i]))
                return false;
        }
        return true;
    }

    static int isChstring(int c)
    {
        // 7: Bell, 0: NUL
        if (c == ' ' || c == '\r' || c == '\n' || c == ',' || c == 7 || c == 0)
            return false;
        return true;
    }

};

Parser::~Parser()
{
}
