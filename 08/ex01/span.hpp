#ifndef SPAN_HPP
#define SPAN_HPP

#include <ostream>
#include <set>

#define _NOEXCEPT throw()


class span
{
	public:
		typedef std::set<int> ContainerType;
		span(const unsigned int content_size);
		~span();
		span(span const &other);
		span &operator=(span const &other);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		bool addNumber(const int num);
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
		span();
		ContainerType container_;
		unsigned int content_size_;
};

std::ostream &operator<<(std::ostream &os, span const &span);

#endif /* SPAN_HPP */
