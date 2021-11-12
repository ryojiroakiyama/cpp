#include "ClapTrap.cpp"

CrapTrap::CrapTrap() : _Name("player1"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{ std::cout << "default constructor" << std::endl; }
CrapTrap::CrapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{ std::cout << "second constructor" << std::endl; }
CrapTrap::~CrapTrap() { std::cout << "destructor" << std::endl; }
CrapTrap::CrapTrap( const CrapTrap& original ) { *this = original; }

Fixed&	Fixed::operator= ( const Fixed& right )
{
	_Name 			= right.getName();
	_HitPoints 		= right.getHitPoints();
	_EnergyPoints 	= right.getEnergyPoints();
	_AttackDamage 	= right.getAttackDamage();
	return *this;
}
