#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SMNUM 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource( const MateriaSource& orginal );
		virtual ~MateriaSource();
		MateriaSource&		operator= ( const MateriaSource& right );
		virtual void		learnMateria( AMateria* );
		virtual AMateria*	createMateria( std::string const & type );
	private:
		AMateria*			_SrcMateria[SMNUM];
};

#endif
