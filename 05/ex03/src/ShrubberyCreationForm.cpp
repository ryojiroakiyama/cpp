#include "ShrubberyCreationForm.hpp"
#include <fstream>

const int	ShrubberyCreationForm::ToSignGrade = 145;
const int	ShrubberyCreationForm::ToExecuteGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: Form("ShrubberyCreationForm", ToSignGrade, ToExecuteGrade, target)
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
: Form(original.getName(), ToSignGrade, ToExecuteGrade, original.getTarget())
{
	std::cout	<< "ShrubberyCreationForm copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& right )
{
	(void)right;
	return *this;
}

// method
void	ShrubberyCreationForm::action() const
{
	std::ofstream	outstream(getTarget() + std::string("_shrubbery"));
	if (outstream.fail())
		throw FailOpenFile();
	outstream	<< "                                                         .\n"
				<< "                                              .         ;  \n"
				<< "                 .              .              ;%     ;;   \n"
				<< "                   ,           ,                :;%  %;   \n"
				<< "                    :         ;                   :;%;'     .,   \n"
				<< "           ,.        %;     %;            ;        %;'    ,;\n"
				<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
				<< "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
				<< "                `%;.     ;%;     %;'         `;%%;.%;'\n"
				<< "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
				<< "                    `:%;.  :;bd%;          %;@%;'\n"
				<< "                      `@%:.  :;%.         ;@@%;'   \n"
				<< "                        `@%.  `;@%.      ;@@%;         \n"
				<< "                          `@%%. `@%%    ;@@%;        \n"
				<< "                            ;@%. :@%%  %@@%;   \n";
}

const char*	ShrubberyCreationForm::FailOpenFile::what() const _NOEXCEPT
{
	return "fail to open file";
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
		<< ", target "
		<< "<" << right.getTarget() << ">"
		<< ".";
	return os;
}
