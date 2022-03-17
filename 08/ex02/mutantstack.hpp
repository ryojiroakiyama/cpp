#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <list>

template <typename T>
class mutantstack
{
	public:
		mutantstack();
		~mutantstack();
		mutantstack(mutantstack const &other);
		mutantstack &operator=(mutantstack const &other);

	private:
		std::list<T> container;
};

#endif /* MUTANTSTACK_HPP */
