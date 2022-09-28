/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:13:00 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/29 16:34:28 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "config.h"

void sighandler(int sig)
{
	if (sig == SIGINT)
	{
		std::cout << "\n";
		exit(0);
	}
}

int main(int argc, char** argv)
{
	if (argc > 3)
	{
		std::cout << "usage: ./ft_irc [port] [password]\n";
		return (1);
	}
	std::string port = DEFAULT_PORT;
	std::string pass = "";
	if (argc >= 2)
		port = argv[1];
	if (argc == 3)
		pass = argv[2];
	try
	{
		Server s(port, pass);
		s.initialize();
		s.loop();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}