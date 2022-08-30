/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:16:03 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/30 17:27:10 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string>
#include <arpa/inet.h>
#include <exception>
#include <vector>
#include <poll.h>
#include <unistd.h>
#include <algorithm>
#include <fcntl.h>

#include "Client.hpp"
#include "Parser.hpp"
#include "Channel.hpp"

class Channel;

class Server
{
private:
	int 					_ssocket;
	struct sockaddr_in		_address;
	std::string				_password;
	int						_g;

	std::vector<Client>		_c;
	std::vector<Channel>	_ch;

	std::string GiveName();

	Client& GetClientByFd(int fd);

	std::string toLowerStr(const std::string & input);

	Client& GetClientByNick(const std::string & input);

	Channel& GetChannelByName(const std::string & name);

	bool isUniqueNick(const std::string & input);

	struct pollfd *getfds(int s, std::vector<Client> c);

	void send_to_socket(int fd, std::string str);

	std::vector<std::string> GetMSG(std::vector<std::pair<std::string,int> > v);

	void printParser(Parser p);
	
public:

    enum COMMANDS
    {
        PASS = 0,
        NICK,
        USER,
        JOIN,
        PART,
        PRIVMSG,
        PING,
        QUIT,
        KICK,
        TOPIC,
		NOTICE,
    };

	int getCommandType(std::string command);

	Server(const std::string & port, const std::string & password);

	void initialize();

	void loop();

	void handleMSG(std::vector<std::string> msgs, Client & c);

	int doPass(Parser & par, Client & c);

	void doNick(Parser & par, Client & c);

	int doUser(Parser & par, Client & c);

	void doJoin(Parser & par, Client & c);

	void doPart(Parser & par, Client & c);

	void doPrivmsg(Parser & par, Client & c);

	void doPing(Parser & par, Client & c);

	void doQuit(Parser & par, Client & c);

	void doKick(Parser & par, Client & c);

	void doTopic(Parser & par, Client & c);

	void doNotice(Parser & par, Client & c);

	~Server();

}; // class end

#endif