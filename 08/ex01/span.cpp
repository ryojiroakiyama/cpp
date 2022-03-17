#include "span.hpp"
#include <iostream>

// construct and destruct
Span::Span(const unsigned int content_size) : capacity_(content_size) {}
Span::~Span() {}

Span::Span(Span const &other) : capacity_(other.capacity_)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->capacity_ = other.capacity_;
		this->container_ = other.container_;
	}
	return *this;
}


// methods
bool Span::addNumber(const int num)
{
	typedef std::pair<Span::ContainerType::iterator, bool> InsertResultType;

	if (this->container_.size() < this->capacity_)
	{
		InsertResultType result = this->container_.insert(num);
		return result.second;
	}
	else
	{
		throw Span::OutRange();
	}
}

unsigned int Span::shortestSpan() const
{
	typedef Span::ContainerType::const_iterator Iterator;

	if (this->container_.size() < 2)
		throw Span::NoSpan();

	Iterator 		itBegin = this->container_.begin();
	Iterator		itEnd = this->container_.end();
	unsigned int	min_span = Span::longestSpan();
	unsigned int	prev_value = *(itBegin);
	for (Iterator it = ++itBegin; it != itEnd; it++)
	{
		unsigned int Span = *it - prev_value;
		if (Span < min_span)
			min_span = Span;
		prev_value = *it;
	}
	return min_span;
}

unsigned int Span::longestSpan() const
{
	if (this->container_.size() < 2)
		throw Span::NoSpan();

	unsigned int min_num = *(this->container_.begin());
	unsigned int max_num = *(--(this->container_.end()));
	return max_num - min_num;
}

unsigned int Span::getCapacity() const
{
	return this->capacity_;
}

Span::ContainerType::const_iterator Span::getIterBegin() const
{
	return this->container_.begin();
}

Span::ContainerType::const_iterator Span::getIterEnd() const
{
	return this->container_.end();
}


// funcs
std::ostream &operator<<(std::ostream &os, Span const &Span)
{
	typedef Span::ContainerType::const_iterator Iterator;

	os << "[";

	Iterator itEnd = Span.getIterEnd();
	for (Iterator it = Span.getIterBegin(); it != itEnd; it++)
		os << " " << *it;

	os << " ]";
	return os;
}
