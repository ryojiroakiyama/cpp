#include "span.hpp"
#include <iostream>

// construct and destruct
span::span(const unsigned int content_size) : capacity_(content_size) {}
span::~span() {}

span::span(span const &other) : capacity_(other.capacity_)
{
	*this = other;
}

span &span::operator=(span const &other)
{
	if (this != &other)
	{
		this->capacity_ = other.capacity_;
		this->container_ = other.container_;
	}
	return *this;
}


// methods
bool span::addNumber(const int num)
{
	typedef std::pair<span::ContainerType::iterator, bool> InsertResultType;

	if (this->container_.size() < this->capacity_)
	{
		InsertResultType result = this->container_.insert(num);
		return result.second;
	}
	else
	{
		throw span::OutRange();
	}
}

unsigned int span::shortestSpan() const
{
	typedef span::ContainerType::const_iterator Iterator;

	if (this->container_.size() < 2)
		throw span::NoSpan();

	Iterator 		itBegin = this->container_.begin();
	Iterator		itEnd = this->container_.end();
	unsigned int	min_span = span::longestSpan();
	unsigned int	prev_value = *(itBegin);
	for (Iterator it = ++itBegin; it != itEnd; it++)
	{
		unsigned int span = *it - prev_value;
		if (span < min_span)
			min_span = span;
		prev_value = *it;
	}
	return min_span;
}

unsigned int span::longestSpan() const
{
	if (this->container_.size() < 2)
		throw span::NoSpan();

	unsigned int min_num = *(this->container_.begin());
	unsigned int max_num = *(--(this->container_.end()));
	return max_num - min_num;
}

unsigned int span::getCapacity() const
{
	return this->capacity_;
}

span::ContainerType::const_iterator span::getIterBegin() const
{
	return this->container_.begin();
}

span::ContainerType::const_iterator span::getIterEnd() const
{
	return this->container_.end();
}


// funcs
std::ostream &operator<<(std::ostream &os, span const &span)
{
	typedef span::ContainerType::const_iterator Iterator;

	os << "[";

	Iterator itEnd = span.getIterEnd();
	for (Iterator it = span.getIterBegin(); it != itEnd; it++)
		os << " " << *it;

	os << " ]";
	return os;
}
