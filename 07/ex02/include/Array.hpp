#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <iostream>

template <typename T>
class Array
{
	public:
		Array(unsigned int n = 0);
		~Array();
		Array(const Array& original);
		Array&			operator= (const Array& right);
		T&				operator[](unsigned int idx);
		unsigned int	size() const;
	private:
		T*				_Array;
		unsigned int	_Size;
};

template<typename T>
Array<T>::Array(unsigned int n) : _Array(new T[n]()), _Size(n)
{
}

template <typename T>
Array<T>::Array(const Array& original) : Array<T>::Array(original.size())
{
}

template <typename T>
Array<T>::~Array()
{
	delete [] _Array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& right)
{
	_Size = right.size();
	delete [] _Array;
	_Array = new T[_Size];
	for (unsigned int idx = 0; idx < _Size; idx++)
		_Array[idx] = right._Array[idx];
	return *this;
}

template <typename T>
T&			Array<T>::operator[](unsigned int idx)
{
	if (_Size == 0 || (idx > _Size - 1))
		throw std::exception();
	return _Array[idx];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _Size;
}

#endif
