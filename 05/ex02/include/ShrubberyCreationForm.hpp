#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm( std::string target = "target less");
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm& original );
		ShrubberyCreationForm&	operator= ( const ShrubberyCreationForm& right );
		virtual void			execute(Bureaucrat const & executor) const;
	private:
		const std::string		_Target;
};

std::ostream&	operator<<( std::ostream& os, const ShrubberyCreationForm& right );

#endif
