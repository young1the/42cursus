#include "Parser.hpp"

void Parser::initVector(const std::string & str)
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

void Parser::setType()
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

Parser::Parser(const std::string & str)
{
    initVector(str);
    setType();
}

Parser::Parser(const std::string & str, const char & delimeter)
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

Parser::Parser(const std::string & str, const std::string & delimeter)
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

Parser::~Parser(){}
 
const Parser::Vector & Parser::getVector() {return _v;}

void Parser::printVector() const
{
    for (size_t i = 0; i < _v.size(); ++i)
    {
        std::cout <<"|"<< _v[i].first<<"|" << " : " << _v[i].second << std::endl;
    }
}

std::string Parser::getCommand()
{
	for (size_t i = 0; i < _v.size(); ++i)
	{
		if (_v[i].second == COMMAND)
			return _v[i].first;
	}
	return "";
}

std::vector<std::string> Parser::getParams()
{
	std::vector<std::string> p;
	for (size_t i = 0; i < _v.size(); ++i)
	{
		if (_v[i].second == PARAMS)
			p.push_back(_v[i].first);
	}
	return p;
}
	
std::string Parser::getTrail()
{
	for (size_t i = 0; i < _v.size(); ++i)
	{
		if (_v[i].second == TRAILING)
			return _v[i].first;
	}
	return "";
}

bool Parser::checkStr(const std::string & str, int (*f)(int))
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!f(str[i]))
            return false;
    }
    return true;
}

int Parser::isChstring(int c)
{
    // 7: Bell, 0: NUL
    if (c == ' ' || c == '\r' || c == '\n' || c == ',' || c == 7 || c == 0)
        return false;
    return true;
}