/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:16:03 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/24 15:25:34 by chanhuil         ###   ########.fr       */
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

					send_to_socket(csocket, "localhost 001 chanhuil :Welcome to the Internet Relay Network chanhuil!chanhuil@localhost");
					send_to_socket(csocket, "localhost 002 chanhuil :Your host is servername, running version working-in-progress");
					send_to_socket(csocket, "localhost 003 chanhuil :This server was created Christmas");
					send_to_socket(csocket, "localhost 004 chanhuil :localhost working-in-progress o o");
					send_to_socket(csocket, ":chanhuil!chanhuil@localhost NICK chanhuil");
				}
				for (unsigned long i=1;i<_c.size() + 1;i++)
				{
					if (fds[i].revents & (POLLIN | POLLPRI))
					{
						/** 512 = 510 + '\r''\n'
						*/
						char buf[1024];
						int rret;

						memset(buf, 0,1024);
						rret = recv(fds[i].fd, buf, 1024, 0);
						if (rret == 0)
						{
							std::cout << fds[i].fd << " - disconnected!\n";
							close(_c[i - 1].get_fd());
							_c.erase(_c.begin() + i - 1);
							break;
						}
						std::cout << fds[i].fd << " :\n" << buf;

						




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
