#include <string>
#include <iostream>

enum PseudoLiterals
{
	Inf,
	Nan,
	END
};

std::string _PseudoLiterals[2] = {"inf", "nan"};

void parse(const std::string & str, int & type)
{
	for (int i(0); i < str.size(); ++i)
	{
		if (str.find(_PseudoLiterals[0]));
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "! ARGUMENT ERROR !" << std::endl;
		return 1;
	}
	std::string str = argv[1];
}