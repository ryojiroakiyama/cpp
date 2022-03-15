#ifndef SPAN_HPP
#define SPAN_HPP

#include <ostream>
#include <set>

typedef std::set<int> IntSet;

class span
{
public:
	span(const unsigned int content_size);
	~span();
	span(span const &other);
	span &operator=(span const &other);

private:
	span();
	IntSet container_;
	unsigned int content_size_;
};

std::ostream &operator<<(std::ostream &os, span const &span);

#endif /* SPAN_HPP */
