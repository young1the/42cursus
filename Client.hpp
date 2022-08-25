/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:52:12 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/25 15:17:06 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Client
{
private:
	/** nickname having a maximum length of nine (9) characters */
	std::string _nick;
	std::string	_name;
	int			_fd;
	std::string _mode;
	
public:
	std::string _temp;

	Client()
		: _nick("Anonymous"), _name("Anonymous"), _fd(-1), _mode(""), _temp("")
	{}
	Client(int fd)
		: _nick("Anonymous"), _name("Anonymous"), _fd(fd), _mode(""), _temp("")
	{}

	void clientout()
	{
		std::cout << _fd << ": Welcome!" << std::endl;
	}

	int get_fd()
	{
		return _fd;
	}

	std::string get_prefix()
	{
		return _nick + "!" + _name + "@localhost";
	}

	
	

	bool operator==(const Client& c)
	{
		return (_fd == c._fd);
	}

	bool operator!=(const Client& c)
	{
		return !(*this == c);
	}
};