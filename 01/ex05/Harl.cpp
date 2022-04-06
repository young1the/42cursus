#include "Harl.hpp"

Harl::Harl()
{
	fptr[DEBUG] = &Harl::debug;
	fptr[INFO] = &Harl::info;
	fptr[WARNING] = &Harl::warning;
	fptr[ERROR] = &Harl::error;
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
	(this->*(fptr[i]))();
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!";
	std::cout << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!";
	std::cout << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
