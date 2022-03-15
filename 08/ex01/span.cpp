#include "span.hpp"
#include <iostream>
#include <algorithm>

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

void span::addNumber(const int num)
{
	if (this->container_.size() < this->content_size_)
		this->container_.insert(num);
	else
		throw span::OutRange();
}

IntSet::const_iterator span::getIterBegin() const
{
	return this->container_.begin();
}

IntSet::const_iterator span::getIterEnd() const
{
	return this->container_.end();
}

static void PutInt(int i)
{
	std::cout << " " << i;
}

std::ostream &operator<<(std::ostream &os, span const &span)
{
	os << "[";
	std::for_each(span.getIterBegin(), span.getIterEnd(), PutInt);
	os << " ]";
	return os;
}
//std::string span::LineUpContent() const
//{
//	std::string line_up;
//	IntSet::const_iterator it_end;

//	for (IntSet::const_iterator it = this->container_.begin(); it != it_end; it++)
//		line_up += std::to_string(*it);
//	return line_up;
//}
