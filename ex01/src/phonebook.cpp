#include "phonebook.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <iomanip>
#include <string.h>

PhoneBook::PhoneBook() : head_idx(0), NbAdd(0), size(8)
{
}

std::string	PhoneBook::get_input(std::string item, int width)
{
	std::string	input;

	input = "";
	while (input.empty())
	{
		std::cout << CYAN << std::setw(width) << item << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
			throw std::exception();
	}
	return input;
}

void	PhoneBook::add()
{
	if (NbAdd >= size)
		head_idx = ++head_idx % size;
	int idx = NbAdd % size;
	contacts[idx].setFirstName(get_input(FNAME+COLON, 15));
	contacts[idx].setLastName(get_input(LNAME+COLON, 15));
	contacts[idx].setNickName(get_input(NNAME+COLON, 15));
	contacts[idx].setPhoneNumber(get_input(PNUM+COLON, 15));
	contacts[idx].setDarkestSecret(get_input(DSECRET+COLON, 15));
	NbAdd++;
	if (NbAdd >= INT_MAX)
		throw std::exception();
}

void	PhoneBook::display_tenw(std::string content, std::string separate)
{
	if (content.size() > 10)
		content.replace(9, 1, ".");
	std::cout << std::setw(10) << content.substr(0, 10) << separate;
}

void	PhoneBook::display_oneline(int order)
{
	int idx = (head_idx + (order - 1)) % size;
	if(idx < NbAdd)
	{
		std::cout << MAGENTA << order << COLON;
		display_tenw(contacts[idx].getFirstName(), "|");
		display_tenw(contacts[idx].getLastName(), "|");
		display_tenw(contacts[idx].getNickName(), "|");
		display_tenw(contacts[idx].getPhoneNumber(), "|");
		display_tenw(contacts[idx].getDarkestSecret(), "");
		std::cout << RESET << std::endl;
	}
}

void	PhoneBook::display_detail(int order)
{
	int idx = (head_idx + (order - 1)) % size;
	if (idx < NbAdd)
	{
		std::cout
		<< YELLOW
		<< "+--------------+" << std::endl
		<< "first name     : " << contacts[idx].getFirstName() << std::endl
		<< "last name      : " << contacts[idx].getLastName() << std::endl
		<< "nick name      : " << contacts[idx].getNickName() << std::endl
		<< "phone number   : " << contacts[idx].getPhoneNumber() << std::endl
		<< "darkest secret : " << contacts[idx].getDarkestSecret() << std::endl
		<< "+--------------+" << std::endl
		<< RESET;
	}
	else
		std::cout << RED << "empty" << RESET << std::endl;
}

void	PhoneBook::search()
{
	int order;

	if (NbAdd)
	{
		for (order = 1; order <= size; order++)
			display_oneline(order);
		std::string	order_input = get_input("order see more >", 10);
		order = order_input.at(0) - '0';
		if (order_input.size() == 1 &&  1 <= order && order <= size)
			display_detail(order);
		else
			std::cout << "invalid order" << std::endl;
	}
	else
		std::cout << RED << "phonebook is empty" << RESET << std::endl;
}

void	PhoneBook::reception()
{
	try
	{
		while (true)
		{
			std::string input = get_input(">", 1);
			if (input == "EXIT")
				break ;
			else if (input == "ADD")
				add();
			else if (input == "SEARCH")
				search();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error" << RESET << std::endl;
	}
}
