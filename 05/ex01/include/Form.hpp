#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form( std::string name = "nameless", int sgrade = 150, int egrade = 1);
		~Form();
		Form( const Form& original );
		Form&				operator= ( const Form& right );
		const std::string&	getName() const;
		bool				getisSigned() const;
		int					getSigneGrade() const;
		int					getExecuteGrade() const;
		void				beSigned( const Bureaucrat& b);
	private:
		const std::string	_Name;
		bool				_isSigned;
		const int			_SignGrade;
		const int			_ExecuteGrade;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const _NOEXCEPT;
		};
};

std::ostream&	operator<<( std::ostream& os, const Form& bure );

#endif
