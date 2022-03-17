#include "mutantstack.hpp"

template <typename T>
mutantstack<T>::mutantstack()
{
}

template <typename T>
mutantstack<T>::~mutantstack()
{
}

template <typename T>
mutantstack<T>::mutantstack(mutantstack const &other)
{
	*this = other;
}

template <typename T>
mutantstack<T> &mutantstack<T>::operator=(mutantstack<T> const &other)
{
	if (this != &other)
	{
	}
	return *this;
}
