#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"

#define FNAME "first name"
#define LNAME "last name"
#define NNAME "nick name"
#define PNUM "phone number"
#define DSECRET "darkest secret"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		head_idx;
		int		last_idx;
		int		size;
	public:
		PhoneBook();
		std::string	get_input(std::string item);
		void		add();
		void		search();
		void		reception();
};

#endif