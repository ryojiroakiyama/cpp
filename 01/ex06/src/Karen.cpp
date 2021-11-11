#include "Karen.hpp"
#include "escape_sequence.hpp"

Karen::Karen()
{
	functions[0] = &Karen::non;
	functions[1] = &Karen::debug;
	functions[2] = &Karen::info;
	functions[3] = &Karen::warning;
	functions[4] = &Karen::error;
}

void	Karen::complain(std::string level)
{
	int	idx =	(level == "DEBUG") |
				(level == "INFO") * 2 |
				(level == "WARNING") * 3 |
				(level == "ERROR") * 4;
	(this->*functions[idx])();
}

void	Karen::non()
{
}

void	Karen::debug()
{
	std::cout	<< "I love to get extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I just love it!"
				<< std::endl;
}

void	Karen::info()
{
	std::cout	<< "I cannot believe adding extra bacon cost more money. "
				<< "You don’t put enough! "
				<< "If you did I would not have to ask for it!"
				<< std::endl;
}

void	Karen::warning()
{
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming here for years "
				<< "and you just started working here last month."
				<< std::endl;
}

void	Karen::error()
{
	std::cout	<< "This is unacceptable, I want to speak to the manager now."
				<< std::endl;
}
