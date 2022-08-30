/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:29:31 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/30 15:25:08 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <vector>
#include <sys/socket.h>
#include <utility>

#include "Client.hpp"

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
	std::string _topic;
	// int _type;

	bool is_joined(Client c);

	bool is_op(Client c);

	void send_to_socket(int fd, std::string str);
	
public:

	Channel(std::string name, Client& first);

	~Channel();

	void send_to_other_client(Client sender, std::string msg);

	const std::string& get_name() const;

	std::vector<std::string> get_users();

	void addUser(Client& c);

	void removeUser(Client& c);

	std::string kick(Client oper, Client usr);

	std::string setTopic(Client oper, std::string t);

	std::string getTopic();

};

#endif