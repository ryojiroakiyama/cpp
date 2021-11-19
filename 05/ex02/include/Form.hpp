#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form( std::string name = "nameless", int sgrade = 150, int egrade = 1, std::string target = "target less" );
		~Form();
		Form( const Form& original );
		Form&				operator= ( const Form& right );
		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getisSigned() const;
		int					getSigneGrade() const;
		int					getExecuteGrade() const;
		void				beSigned( const Bureaucrat& b);
		void				beExcuted( const Bureaucrat& b) const;
		virtual void		execute( Bureaucrat const & executor ) const = 0;
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
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const _NOEXCEPT;
		};
	private:
		const std::string	_Name;
		bool				_isSigned;
		const int			_SignGrade;
		const int			_ExecuteGrade;
		const std::string	_Target;
};

std::ostream&	operator<<( std::ostream& os, const Form& right );

#endif
