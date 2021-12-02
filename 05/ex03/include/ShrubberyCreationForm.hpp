#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm( std::string targe = "target less" );
		~ShrubberyCreationForm();
		ShrubberyCreationForm( const ShrubberyCreationForm& original );
		ShrubberyCreationForm&	operator= ( const ShrubberyCreationForm& right );
		virtual void			action() const;
	private:
		static const int		ToSignGrade;
		static const int		ToExecuteGrade;
		class FailOpenFile : public std::exception
		{
			public:
				virtual const char *what() const _NOEXCEPT;
		};
};

std::ostream&	operator<<( std::ostream& os, const ShrubberyCreationForm& right );

#endif
