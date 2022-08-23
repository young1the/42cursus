/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:29:31 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/22 17:08:04 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int _type;

	bool is_op(Client c)
	{
		std::vector<Client>::iterator temp = find(_op.begin(), _op.end(), c);
		if (temp == _op.end())
			return false;
		return true;
	}
	
public:

	Channel(Client first)
		: message(std::pair<Client, std::string>())
	{
		_op.push_back(first);
	}
	~Channel();

	void send_to_other_client(Client sender, std::string msg);
	void kick(Client oper, Client usr)
	{
		// if (is_op(oper))
		// {
		// 	msg;
		// 	return ;
		// }
		// previllege
		// _c.find(usr).erase();
		// send(usr, asdasd);
	}
};
