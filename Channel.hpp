/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:29:31 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/29 14:04:49 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Server.hpp"
#include <utility>

class Channel
{
private:
	/** Channels names are strings (beginning with a '&' or '#' character) of length up to 200 characters.
	the only restriction on a channel name is that it may not contain any spaces (' '), a control G (^G or ASCII 7), 
	or a comma (',' which is used as a list item separator by the protocol). */
	std::string _name;
	std::vector<Client> _c;
	std::vector<Client> _op; // chop, chanop : KICK, MODE, INVITE, TOPIC
	std::pair<Client, std::string> message;
	// int _type;

	bool is_op(Client c)
	{
		std::vector<Client>::iterator temp = find(_op.begin(), _op.end(), c);
		if (temp == _op.end())
			return false;
		return true;
	}

	void send_to_socket(int fd, std::string str)
	{
		send(fd, str.c_str(), str.length(), 0);
		send(fd, "\n", 1, 0);
	}
	
public:

	Channel(std::string name, Client& first)
		: _name(name)
	{
		_c.push_back(first);
		_op.push_back(first);
	}
	~Channel(){}

	void send_to_other_client(Client sender, std::string msg)
	{
		for (std::vector<Client>::iterator it=_c.begin();it!=_c.end();it++)
		{
			if (*it != sender)
			{
				send_to_socket(it->_fd, msg);
			}
		}
	}

	const std::string& get_name() const
	{
		return _name;
	}

	void addUser(Client& c)
	{
		_c.push_back(c);
	}

	void removeUser(Client& c)
	{
		_c.erase(find(_c.begin(), _c.end(), c));
	}

	// void kick(Client oper, Client usr)
	// {
	// 	if (is_op(oper))
	// 	{
	// 		msg;
	// 		return ;
	// 	}
	// 	previllege
	// 	_c.find(usr).erase();
	// 	send(usr, asdasd);
	// }
};

#endif