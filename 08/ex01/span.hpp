#ifndef SPAN_HPP
#define SPAN_HPP

#include <ostream>
#include <set>

#define _NOEXCEPT throw()


class Span
{
	public:
		typedef int ContentType;
		typedef std::set<ContentType> ContainerType;
		Span(const unsigned int content_size);
		~Span();
		Span(Span const &other);
		Span &operator=(Span const &other);

		template <typename Iterator>
		Iterator addNumber(Iterator begin, Iterator end);

		bool addNumber(const int num);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		unsigned int getCapacity() const;
		ContainerType::const_iterator getIterBegin() const;
		ContainerType::const_iterator getIterEnd() const;

		class OutRange : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT {
					return "Full of content";
				}
		};
		class NoSpan : public std::exception {
			public:
				virtual const char *what() const _NOEXCEPT {
					return "Emtpy or too few content";
				}
		};

	private:
		Span();
		ContainerType container_;
		unsigned int capacity_;
};

template <typename Iterator>
Iterator Span::addNumber(Iterator itbegin, Iterator itend)
{
	Iterator it = itbegin;
	while (it != itend)
	{
		if (this->container_.size() < this->capacity_)
		{
			bool is_inserted = (this->container_.insert(*it)).second;
			if (!is_inserted)
				break;
		}
		else
		{
			throw Span::OutRange();
		}
		it++;
	}
	return it;
}

std::ostream &operator<<(std::ostream &os, Span const &Span);

#endif /* SPAN_HPP */
