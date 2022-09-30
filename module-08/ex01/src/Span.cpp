#include "Span.hpp"

// Default constructor

Span::Span() : max_size(10) {}

// Constructor with size

Span::Span(std::size_t n) : max_size(n) {}

// Destructor

Span::~Span() {}

// Copy constructor

Span::Span(const Span& span) : max_size(span.max_size) {
  number_storage = span.number_storage;
}

// Copy assignment operator

Span& Span::operator=(const Span& span) {
  if (this != &span) {
    number_storage = span.number_storage;
  }
  return *this;
}

// Methods

void Span::addNumber(int number) {
  number_storage.push_back(number);
  if (number_storage.size() > max_size) {
    throw std::invalid_argument("Number storage is full");
  }
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  number_storage.insert(number_storage.end(), begin, end);
  if (number_storage.size() > max_size) {
    throw std::invalid_argument("Number storage is full");
  }
}

int Span::shortestSpan() {
  if (number_storage.size() < 2) throw std::invalid_argument("Number storage is too small");

  // Sort the vector to make it easier to find the shortest span
  std::vector<int> sorted_vector = number_storage;
  sort(sorted_vector.begin(), sorted_vector.end());

  int shortest_span = sorted_vector[1] - sorted_vector[0];
  for (std::vector<int>::iterator it = sorted_vector.begin(); it != sorted_vector.end(); it++) {
    if (it + 1 != sorted_vector.end()) {
      int span = *(it + 1) - *it;
      if (span < shortest_span) shortest_span = span;
    }
  }
  return shortest_span;
}

int Span::longestSpan() {
  if (number_storage.size() < 2) throw std::invalid_argument("Number storage is too small");

  // Sort the vector to make it easier to find the longest span
  std::vector<int> sorted_vector = number_storage;
  sort(sorted_vector.begin(), sorted_vector.end());

  return sorted_vector[sorted_vector.size() - 1] - sorted_vector[0];
}
