#include "span.hpp"

span::span()
{
}

span::~span()
{
}

span::span(span const &other)
{
	*this = other;
}

span &span::operator=(span const &other)
{
	if (this != &other)
	{
	}
	return *this;
}
