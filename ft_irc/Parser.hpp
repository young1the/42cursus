#ifndef PARSER_HPP
#define PARSER_HPP

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

    void initVector(const std::string & str);

    void setType();

public:

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
        TRAILING = 3,
        END,
    };

    Parser(const std::string & str);

    Parser(const std::string & str, const char & delimeter);

    Parser(const std::string & str, const std::string & delimeter);

    ~Parser();
 
    const Vector & getVector();

    void printVector() const;

	std::string getCommand();

	std::vector<std::string> getParams();

	std::string getTrail();

    static bool checkStr(const std::string & str, int (*f)(int));

    static int isChstring(int c);
};

#endif