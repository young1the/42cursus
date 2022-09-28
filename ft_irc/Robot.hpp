#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <stdlib.h>
#include <time.h>

#include "Client.hpp"
#include "Parser.hpp"

class Robot : public Client
{
private:
	int _called;
public:
	Robot(std::string name);
	
	~Robot();

	std::string rollDice(int space);

	std::string Count();

	std::string RSP();

	std::string Help();

	std::string doRoboticThing(std::string user, std::string trail);
};

#endif