#include "span.hpp"

span::span(const unsigned int content_size) : content_size_(content_size)
{
}

span::~span()
{
}

span::span(span const &other) : span::span(other.content_size_)
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
