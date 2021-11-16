#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Materia.hpp"

// constructor, destructor
MateriaSource::MateriaSource() {}
MateriaSource::~MateriaSource() {}
MateriaSource::MateriaSource( const MateriaSource& original) { *this = original; }

// oprator overload
MateriaSource&	MateriaSource::operator=( const MateriaSource& right )
{
	/* */
	return *this;
}

void			MateriaSource::learnMateria( AMateria* materia )
{
	
}