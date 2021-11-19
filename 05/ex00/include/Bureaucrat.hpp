#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <ostream>
#include <iostream>
#define _NOEXCEPT throw()

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		~Bureaucrat();
		Bureaucrat( const Bureaucrat& src );
		std::string	const&	getName() const;
		int					getGrade() const;
		void				Upgrade();
		void				Downgrade();
		Bureaucrat&			operator= ( const Bureaucrat& right );
	private:
		std::string	const	_Name;
		int					_Grade;
		static const int	_HighestGrade;
		static const int	_LowestGrade;
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
