/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:13:00 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/26 14:29:02 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

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
	if (argc != 3)
	{
		std::cout << "usage: ./ft_irc [port] [password]\n";
		return (1);
	}
	Server s(argv[1], argv[2]);
	try
	{
		s.initialize();
		s.loop();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}