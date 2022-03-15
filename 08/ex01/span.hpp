#ifndef SPAN_HPP
#define SPAN_HPP

#include <ostream>
#include <set>

#define _NOEXCEPT throw()

typedef std::set<int> IntSet;

class span
{
public:
	span(const unsigned int content_size);
	~span();
	span(span const &other);
	span &operator=(span const &other);
	//std::string LineUpContent() const;
	void addNumber(const int num);
	IntSet::const_iterator getIterBegin() const;
	IntSet::const_iterator getIterEnd() const;
	class OutRange : public std::exception
	{
		public:
			virtual const char *what() const _NOEXCEPT {
				return "Contents is full";
			}
	};

private:
	span();
	IntSet container_;
	unsigned int content_size_;
};

std::ostream &operator<<(std::ostream &os, span const &span);

#endif /* SPAN_HPP */
