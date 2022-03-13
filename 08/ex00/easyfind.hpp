#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::const_iterator	easyfind(const T& x, const int target)
{
    typename T::const_iterator itEnd = x.end();
    for (typename T::const_iterator it = x.begin(); it != itEnd; ++it) {
		if (*it == target)
			return it;
    }
	return itEnd;
}

#endif
