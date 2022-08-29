/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:16:03 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/29 17:40:21 by chanhuil         ###   ########.fr       */
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

#include "Client.hpp"
#include "Parser.hpp"
#include "Channel.hpp"

class Server
{
private:
	int 					_ssocket;
	struct sockaddr_in		_address;
	std::string				_password;
	int						_g;

	std::vector<Client>		_c;
	std::vector<Channel>	_ch;

	std::string GiveName()
	{
		return ("Guest" + std::to_string(_g++));
	}

	Client& GetClientByFd(int fd)
	{
		for (std::vector<Client>::iterator it = _c.begin();it != _c.end(); it++)
		{
			if (it->_fd == fd)
			{
				return (*it);
			}
		}
		throw std::logic_error("Couldn't find a Client");
	}

	std::string toLowerStr(const std::string & input)
	{
		std::string ret = input;
		for (size_t i = 0; i < ret.size(); ++i)
		{
			ret[i] = std::tolower(ret[i]);
		}
		return ret;
	}

	Client& GetClientByNick(const std::string & input)
	{
		std::string temp_input = toLowerStr(input);
		std::vector<Client>::iterator it = _c.begin();
		for (; it != _c.end(); ++it)
		{
			std::string temp_nick = toLowerStr(it->_nick);
			if (temp_input == temp_nick)
				return *it;
		}
		throw std::logic_error("No Client Found");
		return *it;
	}

	Channel& GetChannelByName(const std::string & name)
	{
		std::vector<Channel>::iterator it = _ch.begin();
		for (; it != _ch.end(); ++it)
		{
			if (name == it->get_name())
				return *it;
		}
		throw std::logic_error("No Channel Found");
		return *it;
	}

	bool isUniqueNick(const std::string & input)
	{
		try
		{
			GetClientByNick(input);
			return false;
		}
		catch (const std::exception & e)
		{
			return true;
		}
	}

	struct pollfd *getfds(int s, std::vector<Client> c)
	{
		struct pollfd *temp = new struct pollfd[c.size() + 1];
		temp[0].fd = s;
		temp[0].events = POLLIN | POLLPRI;
		temp[0].revents = 0;

		for (unsigned long i=1;i<c.size() + 1;i++)
		{
			temp[i].fd = c[i-1]._fd;
			temp[i].events = POLLIN | POLLPRI;
			temp[i].revents = 0;
		}
		return temp;
	}

	void send_to_socket(int fd, std::string str)
	{
		send(fd, str.c_str(), str.length(), 0);
		send(fd, "\n", 1, 0);
	}

	std::vector<std::string> GetMSG(std::vector<std::pair<std::string,int> > v)
	{
		std::vector<std::string> temp;
		for (size_t i=0;i<v.size();i++)
		{
			temp.push_back(v.at(i).first);
		}
		return temp;
	}

	void printParser(Parser p)
	{
							std::cout << "Command was : <" << p.getCommand() << ">\n";
							for (size_t i=0;i<p.getParams().size();i++)
							{
								std::cout << "Param " << i << " was : <" << p.getParams()[i] << ">\n";
							}
							std::cout << "Trail was : <" << p.getTrail() << ">\n";
	}
	
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
    };

	int getCommandType(std::string command)
	{
		if (command == "PASS")
		{
			return PASS;
		}
		if (command == "NICK")
		{
			return NICK;
		}
		if (command == "USER")
		{
			return USER;
		}
		if (command == "JOIN")
		{
			return JOIN;
		}
		if (command == "PART")
		{
			return PART;
		}
		if (command == "PRIVMSG")
		{
			return PRIVMSG;
		}
		if (command == "PING")
		{
			return PING;
		}
		if (command == "QUIT")
		{
			return QUIT;
		}
		if (command == "KICK")
		{
			return KICK;
		}
		if (command == "TOPIC")
		{
			return TOPIC;
		}
		return -1;
	}

	Server(const std::string & port, const std::string & password)
	: _password(password), _g(1)
	{
		std::stringstream ss;
		ss << port;
		int iport;
		ss >> iport;

		_address.sin_family = AF_INET;
		_address.sin_port = htons(iport);
		inet_pton(AF_INET, "127.0.0.1", &(_address.sin_addr));
	}

	void initialize()
	{
		if ((_ssocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			throw std::logic_error("creating socket failed");
		}

		if ((bind(_ssocket, (struct sockaddr*)&_address, sizeof(_address))) == -1)
		{
			throw std::logic_error("binding socket failed");
		}

		if ((listen(_ssocket, 20)) == -1)
		{
			throw std::logic_error("binding socket failed");
		}
	}

	void loop()
	{
		while (1)
		{
			int pret;
			struct pollfd *fds = getfds(_ssocket, _c);
			pret = poll(fds, _c.size() + 1, -1);

			if (pret == -1)
			{
				throw std::logic_error("poll failed");
			}
			else if (pret == 0)
			{
				// for (int i=0;i<_c.size();i++)
				// {
				// 	_c[i].clientout();
				// }
				std::cout << "timeout" << std::endl;
			}
			else
			{
				if (fds[0].revents & (POLLIN | POLLPRI))
				{
					struct sockaddr_in client;
					unsigned int client_size = sizeof(client);
					int csocket = accept(_ssocket, (struct sockaddr*)&client, &client_size);
					if (csocket == -1)
					{
						throw std::logic_error("connection failed");
					}
					_c.push_back(Client(csocket));
				}
				for (unsigned long i=1;i<_c.size() + 1;i++)
				{
					if (fds[i].revents & (POLLIN | POLLPRI))
					{
						/** 512 = 510 + '\r''\n'
						*/
						char buf[513];
						int rret;
						int csocket = fds[i].fd;

						memset(buf, 0, 513);
						rret = recv(csocket, buf, 513, 0);
						if (rret == 0)
						{
							std::cout << csocket << " - disconnected!\n";
							close(_c[i - 1]._fd);
							_c.erase(_c.begin() + i - 1);
							break;
						}
						std::cout << csocket << " :\n" << buf;

						try
						{
							Client &c = GetClientByFd(csocket);

							c._temp += std::string(buf);
							if (!strstr(c._temp.c_str(), "\n"))
							{
								continue;
							}
							std::vector<std::string> msgs = GetMSG(Parser(c._temp, "\r\n").getVector());
							c._temp = "";
							handleMSG(msgs, c);
						}
						catch(const std::exception& e)
						{
							std::cerr << e.what() << "\n";
							continue;
						}
					}
				}	// visiting fds
			}	// poll end
			delete[] fds;
		}
	}

	void handleMSG(std::vector<std::string> msgs, Client & c)
	{
		for (size_t i = 0; i < msgs.size(); ++i)
		{
			Parser par(msgs[i]);
			int ret = 0;

			switch (getCommandType(par.getCommand()))
			{
				case (PASS) : ret = doPass(par, c);
				break ;
				case (NICK) : doNick(par, c);
				break ;
				case (USER) : ret = doUser(par, c);
				break ;
				case (JOIN) : doJoin(par, c); // topic msg
				break ;
				case (PART) : doPart(par, c);
				break ;
				case (PRIVMSG) : doPrivmsg(par, c);
				break ;
				case (PING) : doPing(par, c);
				break ;
				case (QUIT) : doQuit(par, c);
				break ;
				case (KICK) : doKick(par, c);
				break ;
				case (TOPIC) : doTopic(par, c);
				break ;
			}
			if (ret != 0)
				return ;
		}
	}

	int doPass(Parser & par, Client & c)
	{
		if (par.getParams().size() < 1)
		{
			send_to_socket(c._fd, "461");
		}
		else if (_password == "" | par.getParams()[0] == _password)
		{
			c._regist = true;
		}
		else
		{
			send_to_socket(c._fd, "ERROR :Wrong Password!");
			close(c._fd);
			_c.erase(find(_c.begin(), _c.end(), c));
			return (1);
		}
		return (0);
	}

	void doNick(Parser & par, Client & c)
	{
		if (par.getParams().size() < 1)
		{
			// 431 ERR_NONICKNAMEGIVEN;
			send_to_socket(c._fd, "431");
		}
		//format
		else if (!isUniqueNick(par.getParams()[0]))
		{
			// 433 ERR_NICKNAMEINUSE;
			send_to_socket(c._fd, c.get_prefix() + " 433 NICK " + par.getParams()[0]);
		}
		else
		{
			send_to_socket(c._fd, ":" + c._nick + " NICK " + par.getParams()[0]);
			c._nick = par.getParams()[0];
		}
	}

	int doUser(Parser & par, Client & c)
	{
		c._name = par.getParams()[0];
		if (_password != "" && c._regist == false)
		{
			send_to_socket(c._fd, "ERROR :No password inputted");
			close(c._fd);
			_c.erase(find(_c.begin(), _c.end(), c));
			return (1);
		}
		send_to_socket(c._fd, c.get_prefix() + " 001 " + c._nick + " :Welcome to the ft_irc, " + c._nick);
		send_to_socket(c._fd, c.get_prefix() + " 002 " + c._nick + " :Your host is localhost, running version working-in-progress");
		send_to_socket(c._fd, c.get_prefix() + " 003 " + c._nick + " :This server was created in Feburary 30th");
		send_to_socket(c._fd, c.get_prefix() + " 004 " + c._nick + " :localhost working-in-progress o o");
		send_to_socket(c._fd, c.get_prefix() + " 372 " + c._nick + " :-   _____  __     .__                ");
		send_to_socket(c._fd, c.get_prefix() + " 372 " + c._nick + " :- _/ ____\\/  |_   |__|______   ____  ");
		send_to_socket(c._fd, c.get_prefix() + " 372 " + c._nick + " :- \\   __\\\\   __\\  |  \\_  __ \\_/ ___\\ ");
		send_to_socket(c._fd, c.get_prefix() + " 372 " + c._nick + " :-  |  |   |  |    |  ||  | \\/\\  \\___ ");
		send_to_socket(c._fd, c.get_prefix() + " 372 " + c._nick + " :-  |__|   |__|____|__||__|    \\___  >");
		send_to_socket(c._fd, c.get_prefix() + " 372 " + c._nick + " :-           /_____/               \\/ ");
		send_to_socket(c._fd, c.get_prefix() + " 376 " + c._nick + " :- Welcome!");
		return (0);
	}

	void doJoin(Parser & par, Client & c)
	{
		send_to_socket(c._fd, c.get_prefix() + " JOIN " + par.getParams()[0] + " :Someone has joined!");
		try
		{
			GetChannelByName(par.getParams()[0]).addUser(c);
		}
		catch(const std::exception& e)
		{
			_ch.push_back(Channel(par.getParams()[0], c));
		}
	}

	void doPart(Parser & par, Client & c)
	{
		send_to_socket(c._fd, c.get_prefix() + " PART " + par.getParams()[0]);
		GetChannelByName(par.getParams()[0]).removeUser(GetClientByFd(c._fd));
		// send_to_socket(c._fd, c.get_prefix() + " PART " + par.getParams()[0] + par.getTrail());

	}

	void doPrivmsg(Parser & par, Client & c)
	{
		if (par.getParams()[0][0] == '#' || par.getParams()[0][0] == '&')
			GetChannelByName(par.getParams()[0]).send_to_other_client(c, c.get_prefix() + " PRIVMSG " + GetChannelByName(par.getParams()[0]).get_name() + " " + par.getTrail());
		else
			send_to_socket(GetClientByNick(par.getParams()[0])._fd, c.get_prefix() + " PRIVMSG " + par.getParams()[0] + " " + par.getTrail());
	}

	void doPing(Parser & par, Client & c)
	{
		send_to_socket(c._fd, "PONG " + par.getParams()[0]);
	}

	void doQuit(Parser & par, Client & c)
	{
		(void)par;
		// A client session is terminated with a quit message.  The server
		// acknowledges this by sending an ERROR message to the client.
		close(c._fd);
		_c.erase(find(_c.begin(), _c.end(), c));
	}

	void doKick(Parser & par, Client & c)
	{
		if (par.getParams().size() < 2)
		{
			send_to_socket(c._fd, "461");
		}
		else
		{
			try
			{
				GetClientByNick(par.getParams()[1]);
			}
			catch(const std::exception& e)
			{
				send_to_socket(c._fd, "441");
			}			
			try
			{
				std::string err = GetChannelByName(par.getParams()[0]).kick(c, GetClientByNick(par.getParams()[1]));
				if (err != "")
				{
					send_to_socket(c._fd, err);
				}
				else
				{
					send_to_socket(c._fd, c.get_prefix() + " KICK " + par.getParams()[0] + " " + par.getParams()[1] + " :" + par.getTrail());
					send_to_socket(GetClientByNick(par.getParams()[1])._fd, c.get_prefix() + " KICK " + par.getParams()[0] + " " + par.getParams()[1] + " :" + par.getTrail());
				}
			}
			catch(const std::exception& e)
			{
				send_to_socket(c._fd, "403");
			}
		}
	}

	void doTopic(Parser & par, Client & c)
	{
		if (par.getParams().size() < 1)
		{
			send_to_socket(c._fd, "461");
		}
		else
		{
			try
			{
				if (par.getTrail() == "")
				{
					if (GetChannelByName(par.getParams()[0]).getTopic() == "")
						send_to_socket(c._fd, c.get_prefix() + " 331 " + par.getParams()[0] + " :No topic is set");
					else
						send_to_socket(c._fd, c.get_prefix() + " 332 " + par.getParams()[0] + " :" + GetChannelByName(par.getParams()[0]).getTopic());
				}
				else
				{
					std::string err = GetChannelByName(par.getParams()[0]).setTopic(c, par.getTrail());
					if (err != "")
					{
						send_to_socket(c._fd, err);
					}
					else
					{
						send_to_socket(c._fd, c.get_prefix() + " TOPIC " + par.getParams()[0] + " :" + par.getTrail());
						GetChannelByName(par.getParams()[0]).send_to_other_client(c, c.get_prefix() + " TOPIC " + par.getParams()[0] + " :" + par.getTrail());
					}
				}
			}
			catch(const std::exception& e)
			{
				send_to_socket(c._fd, "403");
			}
		}

	}

	~Server()
	{
		std::vector<Client>::iterator it = _c.begin();
		for (; it != _c.end(); ++it)
		{
			close(it->_fd);
		}
		close(_ssocket);
		std::cout << "Server Closed" << std::endl;
	}
}; // class end

#endif