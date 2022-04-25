#include "Intern.hpp"

int main()
{
	try
	{
		Intern tern;
		Form *rform;
		Form *wform;
		rform = tern.makeForm("Robotomy Request", "Bender");
		std::cout << *rform << std::endl;
		Bureaucrat bu("young", 1);
		bu.signForm(*rform);
		bu.executeForm(*rform);
		delete rform;
		wform = tern.makeForm("Robot Rock Request", "Bender");
		bu.signForm(*wform);
		bu.executeForm(*wform);
		// delete rform;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}