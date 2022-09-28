
#include "Robot.hpp"

Robot::Robot(std::string name) :_called(0)
{
	_nick = name;
	_name = name;
	_fd = -1;
	_regist = true;
}
	
Robot::~Robot()
{}

std::string Robot::rollDice(int space)
{
	srand(time(NULL));
	return "Rolled a " + std::to_string((rand() % space) + 1);
}

std::string Robot::Count()
{
	return "I have done " + std::to_string(_called) + " tasks";
}

std::string Robot::RSP()
{
	srand(time(NULL));
	int ret = rand() % 3;
	if (ret == 0)
		return "You Win, Human";
	else if (ret == 1)
		return "We Draw, Human";
	else
		return "You Lose, Human";
}

std::string Robot::Help()
{
	return "Usage : !dice, !rock, !scissors, !paper !count";
}

std::string Robot::doRoboticThing(std::string user, std::string trail)
{
	Parser p(trail, " ");
	std::string botm = ": " + user + " - ";
	
	if (_called >= 10)
	{
		botm += "ughh... ";
	}
	if (p._v[0].first == ":!dice")
		botm += rollDice(6);
	else if (p._v[0].first == ":!rock" 
		|| p._v[0].first == ":!scissors"
		|| p._v[0].first == ":!paper")
		botm += RSP();
	else if (p._v[0].first == ":!help")
		botm += Help();
	else if (p._v[0].first == ":!count")
		botm += Count();
	else
		botm += "Not a valid command! type \"!help\"";
	_called++;
	return botm;
}