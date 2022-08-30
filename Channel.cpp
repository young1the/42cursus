#include "Channel.hpp"

Channel::Channel(std::string name, Client& first)
	: _name(name), _topic("")
{
	_c.push_back(first);
	_op.push_back(first);
}

Channel::~Channel(){}

const std::string& Channel::get_name() const
{
	return _name;
}

std::string Channel::setTopic(Client oper, std::string t)
{
	if (!is_joined(oper))
	{
		return "442";
	}
	if (!is_op(oper))
	{
		return "482";
	}
	_topic = t;
	return "";
}

std::string Channel::getTopic()
{
	return _topic;
}

bool Channel::is_joined(Client c)
{
	std::vector<Client>::iterator temp = find(_c.begin(), _c.end(), c);
	if (temp == _c.end())
		return false;
	return true;
}

bool Channel::is_op(Client c)
{
	std::vector<Client>::iterator temp = find(_op.begin(), _op.end(), c);
	if (temp == _op.end())
		return false;
	return true;
}

void Channel::send_to_socket(int fd, std::string str)
{
	send(fd, str.c_str(), str.length(), 0);
	send(fd, "\n", 1, 0);
}

void Channel::send_to_other_client(Client sender, std::string msg)
{
	for (std::vector<Client>::iterator it=_c.begin();it!=_c.end();it++)
	{
		if (*it != sender)
		{
			send_to_socket(it->_fd, msg);
		}
	}
}

void Channel::addUser(Client& c)
{
	_c.push_back(c);
}

void Channel::removeUser(Client& c)
{
	_c.erase(find(_c.begin(), _c.end(), c));
}

std::string Channel::kick(Client oper, Client usr)
{
	if (!is_joined(oper))
	{
		return "442";
	}
	if (!is_op(oper))
	{
		return "482";
	}
	if (!is_joined(usr))
	{
		return "441";
	}
	_c.erase(find(_c.begin(), _c.end(), usr));
	return "";
}
