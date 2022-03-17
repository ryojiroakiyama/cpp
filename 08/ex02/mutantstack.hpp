#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class mutantstack : public std::stack<T>
{
	public:
		mutantstack();
		~mutantstack();
		mutantstack(mutantstack const &other);
		mutantstack &operator=(mutantstack const &other);
};

template <typename T>
mutantstack<T>::mutantstack() {}

template <typename T>
mutantstack<T>::~mutantstack() {}

template <typename T>
mutantstack<T>::mutantstack(mutantstack<T> const &other)
{
	*this = other;
}

template <typename T>
mutantstack<T> &mutantstack<T>::operator=(mutantstack<T> const &other)
{
	if (this != &other)
	{
		// mutant's specific copy treatment
	}
	return *this;
}

#endif /* MUTANTSTACK_HPP */
