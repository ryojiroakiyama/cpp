#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <ostream>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		~Bureaucrat();
		Bureaucrat( const Bureaucrat& src );
		std::string	getName() const;
		int			getGrade() const;
		void		Upgrade();
		void		Downgrade();
		//Bureaucrat&				operator= ( const Bureaucrat& right );
		//bool				operator> ( const Bureaucrat& right ) const;
		//bool				operator< ( const Bureaucrat& right ) const;
		//bool				operator>=( const Bureaucrat& right ) const;
		//bool				operator<=( const Bureaucrat& right ) const;
		//bool				operator==( const Bureaucrat& right ) const;
		//bool				operator!=( const Bureaucrat& right ) const;
		//Bureaucrat				operator+ ( const Bureaucrat& right ) const;
		//Bureaucrat				operator- ( const Bureaucrat& right ) const;
		//Bureaucrat				operator* ( const Bureaucrat& right ) const;
		//Bureaucrat				operator/ ( const Bureaucrat& right ) const;
		//Bureaucrat&				operator++();
		//Bureaucrat				operator++(int);
	private:
		std::string	_Name;
		int			_Grade;
};

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& bure );

#endif
