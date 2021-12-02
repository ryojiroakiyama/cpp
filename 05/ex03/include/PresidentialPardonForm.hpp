#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm( std::string targe = "target less" );
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm& original );
		PresidentialPardonForm&	operator= ( const PresidentialPardonForm& right );
		virtual void			action() const;
	private:
		static const int		ToSignGrade;
		static const int		ToExecuteGrade;
};

std::ostream&	operator<<( std::ostream& os, const PresidentialPardonForm& right );

#endif
