#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"

#define FNAME static_cast<std::string>("first name")
#define LNAME static_cast<std::string>("last name")
#define NNAME static_cast<std::string>("nick name")
#define PNUM static_cast<std::string>("phone number")
#define DSECRET static_cast<std::string>("darkest secret")
#define COLON static_cast<std::string>(" : ")

class PhoneBook
{
	private:
		Contact 	contacts[8];
		int			head_idx;
		int			last_idx;
		int			size;
		std::string	get_input(std::string item, int width);
		void		display_tenw(std::string content, std::string separate);
		void		display_oneline(int order);
		void		display_detail(int order);
	public:
		PhoneBook();
		void		add();
		void		search();
		void		reception();
};

#endif
