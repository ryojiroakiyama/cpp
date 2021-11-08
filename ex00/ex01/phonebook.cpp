#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : head_idx(0), last_idx(0), size(8)
{
}

std::string	PhoneBook::get_input(std::string item)
{
	std::string	input;

	std::cout << std::setw(15) << item << " : ";
	std::getline(std::cin, input);
	return input;
}

void	PhoneBook::add()
{
	contacts[last_idx].setFirstName(get_input(FNAME));
	contacts[last_idx].setLastName(get_input(LNAME));
	contacts[last_idx].setNickName(get_input(NNAME));
	contacts[last_idx].setPhoneNumber(get_input(PNUM));
	contacts[last_idx].setDarkestSecret(get_input(DSECRET));
	last_idx++;
	if (last_idx == size)
		last_idx = 0;
}

void	PhoneBook::search()
{
	std::cout << "+--------------+" << std::endl;
	std::cout << "first name     : " << contacts[head_idx].getFirstName() << std::endl;
	std::cout << "last name      : " << contacts[head_idx].getLastName() << std::endl;
	std::cout << "nick name      : " << contacts[head_idx].getNickName() << std::endl;
	std::cout << "phone number   : " << contacts[head_idx].getPhoneNumber() << std::endl;
	std::cout << "darkest secret : " << contacts[head_idx].getDarkestSecret() << std::endl;
	std::cout << "+--------------+" << std::endl;
}

void	PhoneBook::reception()
{
	std::string	input;

	while (true)
	{
		std::cout << ">";
		std::getline(std::cin, input);
		if (!std::cin || input == "EXIT")
			break ;
		else if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
	}
}
