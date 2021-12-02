#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern : public Form
{
	public:
		Intern( std::string targe = "target less" );
		~Intern();
		Intern( const Intern& original );
		Intern&	operator= ( const Intern& right );
		virtual void			action() const;
	private:
		static const int		ToSignGrade;
		static const int		ToExecuteGrade;
};

std::ostream&	operator<<( std::ostream& os, const Intern& right );

#endif
