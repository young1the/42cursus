#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "# ERROR!\n# Usage : ";
		std::cout << "./sed-is-for-loser <filename> <oldstring> <newstring>" << std::endl;
		return (0);
	}

	std::ifstream filein(argv[1]);
	if (!filein)
	{
		std::cerr << "CANNOT FOUND \""<< argv[1] << '\"' << std::endl;
		return (0);
	}

	std::string filestring;
	std::string buffer;
	while (std::getline(filein, buffer))
	{
		filestring += buffer;
		filestring += '\n';
	}

	std::string old_string(argv[2]);
	std::string new_string(argv[3]);
	std::string::size_type position;
	while ((position = filestring.find(old_string)) != std::string::npos)
	{
		position = filestring.find(old_string);
		filestring.erase(position, old_string.size());
		filestring.insert(position, new_string);
	}

	std::ofstream fileout(std::string(argv[1]) + std::string(".replace"));
	fileout << filestring;
}
