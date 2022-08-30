#include "Client.hpp"

Client::Client()
: _nick("Anonymous"), _name("Anonymous"), _fd(-1), _mode(""), _temp(""), _regist(false) {}

Client::Client(int fd)
: _nick("Anonymous"), _name("Anonymous"), _fd(fd), _mode(""), _temp(""), _regist(false) {}

Client::~Client(){}
	
std::string Client::get_prefix()
{
	return ":" + _nick + "!" + _name + "@localhost";
}

bool Client::operator == (const Client& c)
{
	return (_fd == c._fd);
}

bool Client::operator != (const Client& c)
{
	return !(*this == c);
}
