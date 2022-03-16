#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define _NOEXCEPT throw()
class NotFound : public std::exception
{
	public:
		virtual const char *what() const _NOEXCEPT {
			return "No element found";
		}
};

template <typename T>
typename T::iterator		easyfind(T& container, const int target)
{
	typename T::iterator result = std::find(container.begin(), container.end(), target);
	if (result == container.end()) {
		throw NotFound();
	} else {
		return result;
	}
}

template <typename T>
typename T::const_iterator	easyfind(const T& container, const int target)
{
	typename T::const_iterator result = std::find(container.begin(), container.end(), target);
	if (result == container.end()) {
		throw NotFound();
	} else {
		return result;
	}
}

#endif
