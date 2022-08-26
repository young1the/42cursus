/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:16:03 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/25 16:54:49 by chanhuil         ###   ########.fr       */
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
			if (it->_fd == fd)
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
							close(_c[i - 1]._fd);
							_c.erase(_c.begin() + i - 1);
							break;
						}
						std::cout << csocket << " :\n" << buf;

						GetClientByFd(csocket)._temp += std::string(buf);
						
						if (!strstr(GetClientByFd(csocket)._temp.c_str(), "\n"))
						{
							continue;
						}

						std::vector<std::string> msgs = GetMSG(Parser(GetClientByFd(csocket)._temp, "\r\n").getVector());
						GetClientByFd(csocket)._temp = "";
						
						for (size_t i=0;i<msgs.size();i++)
						{
							Parser par(msgs[i]);

							// printParser(par);

							if (par.getCommand() == "CAP")
							{
								if (par.getParams()[0] == "LS")
								{
									send_to_socket(csocket, "CAP * LS :");
								}
								if (par.getParams()[0] == "END")
								{
									send_to_socket(csocket, ":localhost 001 chanhuil :Welcome to the ft_irc, chanhuil");
									send_to_socket(csocket, ":localhost 002 chanhuil :Your host is localhost, running version working-in-progress");
									send_to_socket(csocket, ":localhost 003 chanhuil :This server was created in Christmas");
									send_to_socket(csocket, ":localhost 004 chanhuil :localhost working-in-progress o o");
									send_to_socket(csocket, ":localhost 372 chanhuil :-   _____  __     .__                ");
									send_to_socket(csocket, ":localhost 372 chanhuil :- _/ ____\\/  |_   |__|______   ____  ");
									send_to_socket(csocket, ":localhost 372 chanhuil :- \\   __\\\\   __\\  |  \\_  __ \\_/ ___\\ ");
									send_to_socket(csocket, ":localhost 372 chanhuil :-  |  |   |  |    |  ||  | \\/\\  \\___ ");
									send_to_socket(csocket, ":localhost 372 chanhuil :-  |__|   |__|____|__||__|    \\___  >");
									send_to_socket(csocket, ":localhost 372 chanhuil :-           /_____/               \\/ ");
									send_to_socket(csocket, ":localhost 376 chanhuil :- Welcome!");
								}
							}
							else if (par.getCommand() == "PASS")
							{
							}
							else if (par.getCommand() == "NICK")
							{
								GetClientByFd(csocket)._name = par.getParams()[0];
							}
							else if (par.getCommand() == "USER")
							{
							}
							else if (par.getCommand() == "MODE")
							{
							}
							else if (par.getCommand() == "JOIN")
							{
								// If a JOIN is successful, the user receives a JOIN message as
								// confirmation and is then sent the channel's topic (using RPL_TOPIC) and
								// the list of users who are on the channel (using RPL_NAMREPLY), which
								// MUST include the user joining.
								send_to_socket(csocket, ":localhost JOIN #ft : chanhuil has joined " + par.getParams()[0]);
							}
							else if (par.getCommand() == "PART")
							{

							}
							else if (par.getCommand() == "PRIVMSG")
							{
							}
							else if (par.getCommand() == "PING")
							{
								send_to_socket(csocket, "PONG " + par.getParams()[0]);
							}
							else if (par.getCommand() == "QUIT")
							{
								// A client session is terminated with a quit message.  The server
   								// acknowledges this by sending an ERROR message to the client.
							}
						}
					}
				}
			}
			delete[] fds;
		}
	}
};
