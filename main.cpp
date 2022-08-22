/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:13:00 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/22 16:10:00 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

// void sighandler;

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "usage: ./ft_irc [port] [password]";
		return (1);
	}
	Server s(argv[1], argv[2]);
	s.initialize();
	s.loop();
}