#ifndef CPP_MODULE_08_SPAN_HPP
#define CPP_MODULE_08_SPAN_HPP

#include <cstddef>
#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
 public:
  Span();                             // Default constructor
  Span(std::size_t n);                // Constructor with size
  ~Span();                            // Destructor
  Span(const Span& span);             // Copy constructor
  Span& operator=(const Span& span);  // Copy assignment operator

  // Methods
  void addNumber(int number);
  void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
  int  shortestSpan();
  int  longestSpan();

 private:
  // Attributes
  std::vector<int>  number_storage;
  const std::size_t max_size;
};

#endif  // CPP_MODULE_08_SPAN_HPP
