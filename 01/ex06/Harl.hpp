#pragma once
#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>

class Harl {

private:

	enum	eLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		END,
	};

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	void		(Harl::*fptr[END])(void);
	std::string	levels[END];

public:

	Harl();
	~Harl();
	void	complain(std::string level);

};

#endif
