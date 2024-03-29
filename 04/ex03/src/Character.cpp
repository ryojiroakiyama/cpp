#include "Character.hpp"
#include "AMateria.hpp"

// construcor, destructor
Character::Character() : _Name("default")
{
	std::cout	<< "Character default constructor"
				<< std::endl;
	for (int i = 0; i < MNUM; i++)
		_Materia[i] = 0;
}

Character::Character( const std::string& name ) : _Name(name)
{
	std::cout	<< "Character constructor"
				<< std::endl;
	for (int i = 0; i < MNUM; i++)
		_Materia[i] = 0;
}

Character::Character( const Character& original )
{
	std::cout	<< "Character copy constructor"
				<< std::endl;
	*this = original;
}

Character::~Character()
{
	std::cout	<< "Character default destructor"
				<< std::endl;
	for (int i = 0; i < MNUM; i++)
	{
		if (_Materia[i])
			delete _Materia[i];
	}
}

// oprator overload
Character&			Character::operator= ( const Character& right )
{
	for (int i = 0; i < MNUM; i++)
	{
		if (right._Materia[i])
			_Materia[i] = right._Materia[i]->clone();
	}
	return *this;
}

// function
std::string const&	Character::getName() const
{
	return _Name;
}

void				Character::equip(AMateria* NewMateria)
{
	int	insert_idx = -1;
	for (int i = 0; NewMateria && i < MNUM; i++)
	{
		if (!_Materia[i] && insert_idx == -1)
			insert_idx = i;
		if (_Materia[i] == NewMateria)
		{
			insert_idx = -1;
			break ;
		}
	}
	if (0 <= insert_idx)
		_Materia[insert_idx] = NewMateria;
}

void				Character::unequip(int idx)
{
	if (idx < MNUM)
		_Materia[idx] = 0;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < MNUM && _Materia[idx])
		_Materia[idx]->use(target);
}
