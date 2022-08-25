/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:16:03 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/25 15:26:12 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "Client.hpp"
#include "Parser.hpp"

class Server
{
private:
	int 				_ssocket;
	struct sockaddr_in	_address;
	std::string			_password;

	std::vector<Client> _c;


	Client& GetClientByFd(int fd)
	{
		for (std::vector<Client>::iterator it = _c.begin();it != _c.end(); it++)
		{
			if (it->get_fd() == fd)
			{
				return (*it);
			}
		}
		throw std::logic_error("Couldn't find a Client");
	}

	struct pollfd *getfds(int s, std::vector<Client> c)
	{
		struct pollfd *temp = new struct pollfd[c.size() + 1];
		temp[0].fd = s;
		temp[0].events = POLLIN | POLLPRI;
		temp[0].revents = 0;

		for (unsigned long i=1;i<c.size() + 1;i++)
		{
			temp[i].fd = c[i-1].get_fd();
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
	
public:
	Server(const std::string & port, const std::string & password)
	: _password(password)
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
							close(_c[i - 1].get_fd());
							_c.erase(_c.begin() + i - 1);
							break;
						}
						std::cout << csocket << " :\n" << buf;

						GetClientByFd(csocket)._temp += std::string(buf);
						
						if (!strchr(GetClientByFd(csocket)._temp.c_str(), '\n'))
						{
							continue;
						}

						std::string msg = GetClientByFd(csocket)._temp.erase(GetClientByFd(csocket)._temp.length() - 1);
						GetClientByFd(csocket)._temp = "";
						Parser par(msg);
						
						std::cout << "Command was : |" << par.getCommand() << "|\n";
						std::cout << "Param 1 was : |" << par.getParams()[0] << "|\n";

						if (par.getCommand() == "CAP" && par.getParams()[0].substr(0, 2) == "LS")
						{
							send_to_socket(csocket, "CAP * LS :");
							send_to_socket(csocket, ":irc.example.com 001 chanhuil :Welcome to the Internet Relay Network, chanhuil");
							send_to_socket(csocket, ":irc.example.com 002 chanhuil :Your host is irc.example.com, running version working-in-progress");
							send_to_socket(csocket, ":irc.example.com 003 chanhuil :This server was created in Christmas");
							send_to_socket(csocket, ":irc.example.com 004 chanhuil :irc.example.com working-in-progress o o");
							send_to_socket(csocket, ":irc.example.com 372 chanhuil :-   _____  __     .__                ");
							send_to_socket(csocket, ":irc.example.com 372 chanhuil :- _/ ____\\/  |_   |__|______   ____  ");
							send_to_socket(csocket, ":irc.example.com 372 chanhuil :- \\   __\\\\   __\\  |  \\_  __ \\_/ ___\\ ");
							send_to_socket(csocket, ":irc.example.com 372 chanhuil :-  |  |   |  |    |  ||  | \\/\\  \\___ ");
							send_to_socket(csocket, ":irc.example.com 372 chanhuil :-  |__|   |__|____|__||__|    \\___  >");
							send_to_socket(csocket, ":irc.example.com 372 chanhuil :-           /_____/               \\/ ");
							send_to_socket(csocket, ":irc.example.com 376 chanhuil :- Welcome!");

						}
						// else if (Parser(msg, " ").getVector()[0] == "PING")
						else if (par.getCommand() == "PING")
						{
							send_to_socket(csocket, "PONG " + par.getParams()[0]);
						}

						// for (int j=0;j<_c.size();j++)
						// {
						// 	std::stringstream ss;
						// 	ss << _c[i - 1].get_fd();
						// 	std::string num;
						// 	ss >> num;
						// 	std::string temp(num + ": " + buf + "\n");
							
						// 	if (i - 1 != j)
						// 		send(_c[j].get_fd(), temp.c_str(), temp.length(), 0);
						// }
					}
				}
			}
			delete[] fds;
		}
	}
};
