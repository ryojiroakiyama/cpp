#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		void		setFirstName(const std::string str);
		void		setLastName(const std::string str);
		void		setNickName(const std::string str);
		void		setPhoneNumber(const std::string str);
		void		setDarkestSecret(const std::string str);
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif
