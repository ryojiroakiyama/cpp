#include "span.hpp"
#include <iostream>

span::span(const unsigned int content_size) : content_size_(content_size)
{
}

span::~span()
{
}

span::span(span const &other) : content_size_(other.content_size_)
{
	*this = other;
}

span &span::operator=(span const &other)
{
	if (this != &other)
	{
		this->content_size_ = other.content_size_;
		this->container_ = other.container_;
	}
	return *this;
}

bool span::addNumber(const int num)
{
	typedef std::pair<span::ContainerType::iterator, bool> InsertResultType;

	if (this->container_.size() < this->content_size_) {
		InsertResultType result = this->container_.insert(num);
		return result.second;
	} else {
		throw span::OutRange();
	}
}

span::ContainerType::const_iterator span::getIterBegin() const
{
	return this->container_.begin();
}

span::ContainerType::const_iterator span::getIterEnd() const
{
	return this->container_.end();
}

std::ostream &operator<<(std::ostream &os, span const &span)
{
	os << "[";

	span::ContainerType::const_iterator itEnd = span.getIterEnd();
	for (span::ContainerType::const_iterator it = span.getIterBegin(); it != itEnd; it++)
		os << " " << *it;

	os << " ]";
	return os;
}
