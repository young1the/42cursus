#include "Harl.hpp"

Harl::Harl()
{
	fptr[DEBUG] = debug;
	fptr[INFO] = info;
	fptr[WARNING] = warning;
	fptr[ERROR] = error;
	levels[DEBUG] = "DEBUG";
	levels[INFO] = "INFO";
	levels[WARNING] = "WARNING";
	levels[ERROR] = "ERROR";
}

Harl::~Harl()
{
}

void	Harl::complain( std::string level )
{
	int		i(0);

	while (level != levels[i] && i < END)
		i++;
	switch (i)
	{
	case END :
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	default:
			for(;i<END;++i)
			{
				(this->*(fptr[i]))();
				std::cout << std::endl;
			}
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. " << std::endl;
	std::cout << "I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl;
	std::cout << "You didn't put enough bacon in my burger! " << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
