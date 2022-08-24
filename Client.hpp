/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:52:12 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/24 14:26:23 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Client
{
private:
	std::string	_name;
	int			_fd;
	
public:
	Client()
		: _name("Anonymous"), _fd(-1)
	{}
	Client(int fd)
		: _name("Anonymous"), _fd(fd)
	{}

	void clientout()
	{
		std::cout << _fd << ": Welcome!" << std::endl;
	}

	int get_fd()
	{
		return _fd;
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