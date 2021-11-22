#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& x, T& y)
{
	std::cout	<< "(swap)";
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T		min(T x, T y)
{
	std::cout	<< "(min)";
	if (x < y)
		return x;
	return y;
}

template <typename T>
T		max(T x, T y)
{
	std::cout	<< "(max)";
	if (x > y)
		return x;
	return y;
}

template <typename T>
T		ryojiro(T x, T y)
{
	std::cout	<< "(ryojiro)";
	if (x < y)
		return x;
	return y;
}

#endif
