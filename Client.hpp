/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:52:12 by chanhuil          #+#    #+#             */
/*   Updated: 2022/08/22 15:46:05 by chanhuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Client
{
private:
	/* data */
	int _fd;
public:
	Client(int fd):_fd(fd){}
	void clientout(){
		std::cout << _fd << ": Welcome!" << std::endl;
	}
	int getfd()
	{
		return _fd;
	}
};