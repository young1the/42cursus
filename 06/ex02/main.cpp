#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	unsigned int type = std::rand() % 3;
	Base * ret = NULL;
	switch (type)
	{
	case 0:
		ret = new A; break;
	case 1:
		ret = new B; break;
	case 2:
		ret = new C; break;
	}
	return ret;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this is C" << std::endl;
}

bool castRefA(Base& p)
{
	try
	{
		p = dynamic_cast<A&>(p);
		return true;
	}
	catch (std::bad_cast)
	{
		return false;
	}
}

bool castRefB(Base& p)
{
	try
	{
		p = dynamic_cast<B&>(p);
		return true;
	}
	catch (std::bad_cast)
	{
		return false;
	}
}

bool castRefC(Base& p)
{
	try
	{
		p = dynamic_cast<C&>(p);
		return true;
	}
	catch (std::bad_cast)
	{
		return false;
	}
}

void	identify(Base& p)
{
	if (castRefA(p))
		std::cout << "this is A" << std::endl;
	else if (castRefB(p))
		std::cout << "this is B" << std::endl;
	else if (castRefC(p))
		std::cout << "this is C" << std::endl;
}

int main()
{
	Base *ptr;
	ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
}