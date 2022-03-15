#ifndef TEST_HPP
#define TEST_HPP

#include "span.hpp"

void TestError();
void TestNormal();
void SpanInfo(span& s);
void ExceptionAddNumber(span& s, const unsigned int addNum);
void ExceptionShortestSpan(span& s);
void ExeptionLongestSpan(span& s);
#endif
