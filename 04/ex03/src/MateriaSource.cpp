#include "MateriaSource.hpp"

// constructor, destructor
MateriaSource::MateriaSource()
{
	std::cout	<< "MateriaSource default constructor"
				<< std::endl;
	for (int i = 0; i < SMNUM; i++)
		_SrcMateria[i] = 0;
}

MateriaSource::MateriaSource( const MateriaSource& original )
{
	std::cout	<< "MateriaSource copy constructor"
				<< std::endl;
	*this = original;
}

MateriaSource::~MateriaSource()
{
	std::cout	<< "MateriaSource default destructor"
				<< std::endl;
	for (int i = 0; i < SMNUM; i++)
	{
		if (_SrcMateria[i])
			delete _SrcMateria[i];
	}
}

// oprator overload
MateriaSource&	MateriaSource::operator= ( const MateriaSource& right )
{
	for (int i = 0; i < SMNUM; i++)
	{
		if (right._SrcMateria[i])
			_SrcMateria[i] = right._SrcMateria[i]->clone();
	}
	return *this;
}

// fucntion
void			MateriaSource::learnMateria(AMateria* NewMateria)
{
	int	insert_idx = -1;
	for (int i = 0; NewMateria && i < SMNUM; i++)
	{
		if (!_SrcMateria[i] && insert_idx == -1)
			insert_idx = i;
		if (_SrcMateria[i] == NewMateria)
		{
			insert_idx = -1;
			break ;
		}
	}
	if (0 <= insert_idx)
		_SrcMateria[insert_idx] = NewMateria;
}

AMateria*		MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < SMNUM; i++)
	{
		if (_SrcMateria[i] && _SrcMateria[i]->getType() == type)
			return _SrcMateria[i]->clone();
	}
	return 0;
}
