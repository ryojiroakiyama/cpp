#include "test.hpp"
#include "span.hpp"
#include <iostream>

void SpanInfo(span& s)
{
	std::cout	<< "span"
				<< "  "
				<< "capacity: " << s.getCapacity()
				<< "  "
				<< "content: "  << s
				<< std::endl;
}
