#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator Iter;
		typedef typename std::stack<T>::container_type::const_iterator ConstIter;
		MutantStack() {}
		~MutantStack() {}
		MutantStack(MutantStack const &other);
		MutantStack &operator=(MutantStack const &other);
		Iter begin();
		ConstIter begin() const;

};

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other)
{
	*this = other;
}

#include <iostream>
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other)
{
	if (this != &other)
	{
		this->c = other.c; /* c: container */
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::Iter MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::ConstIter MutantStack<T>::begin() const
{
	return this->c.begin();
}

#endif /* MUTANTSTACK_HPP */
