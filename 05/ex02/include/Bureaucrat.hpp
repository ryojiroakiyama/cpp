#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <ostream>
#include <iostream>
#define _NOEXCEPT throw()

class Form;

class Bureaucrat
{
	public:
		Bureaucrat( std::string name = "nameless", int grade = 150);
		~Bureaucrat();
		Bureaucrat( const Bureaucrat& original);
		Bureaucrat&			operator= ( const Bureaucrat& right );
		std::string	const&	getName() const;
		int					getGrade() const;
		void				Upgrade();
		void				Downgrade();
		void				signForm( Form& f);
		static const int	_HighestGrade;
		static const int	_LowestGrade;
	private:
		std::string	const	_Name;
		int					_Grade;
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

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& bure );

#endif
