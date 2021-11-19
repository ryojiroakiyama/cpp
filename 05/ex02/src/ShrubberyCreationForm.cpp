#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: Form("ShrubberyCreationForm", 145, 137), _Target(target)
{
	std::cout	<< "ShrubberyCreationForm constructor"
				<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout	<< "ShrubberyCreationForm default destructor"
				<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& original )
: Form("ShrubberyCreationForm", 145, 137), _Target(original._Target)
{
	std::cout	<< "ShrubberyCreationForm copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& right )
{
	_isSigned = right._isSigned;
	return *this;
}

// external function
std::ostream&	operator<<( std::ostream& os, const ShrubberyCreationForm& right )
{
	os	<< "<" << right.getName() << ">"
		<< ", is signed or not "
		<< "<" << right.getisSigned() << ">"
		<< ", sign grade "
		<< "<" << right.getSigneGrade() << ">"
		<< ", execute grade "
		<< "<" << right.getExecuteGrade() << ">"
		<< ".";
	return os;
}
