#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm( std::string targe = "target less" );
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm& original );
		RobotomyRequestForm&	operator= ( const RobotomyRequestForm& right );
		virtual void			execute(Bureaucrat const & executor) const;
	private:
		static const int		ToSignGrade;
		static const int		ToExecuteGrade;
};

std::ostream&	operator<<( std::ostream& os, const RobotomyRequestForm& right );

#endif
