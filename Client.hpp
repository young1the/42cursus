/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:52:12 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/29 16:10:45 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLINET_HPP
#define CLINET_HPP

#include <iostream>

class Client
{

public:

	/** nickname having a maximum length of nine (9) characters */
	std::string _nick;
	std::string	_name;
	int			_fd;
	std::string _mode;
	std::string _temp;
	bool		_regist;

	Client();

	Client(int fd);

	~Client();

	std::string get_prefix();

	bool operator==(const Client& c);

	bool operator!=(const Client& c);

};

#endif