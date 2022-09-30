#include "Span.hpp"

int main() {
  // Test from subject
  {
    Span sp = Span(5);

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  // Test with empty storage
  {
    Span sp = Span(5);

    try {
      std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    try {
      std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  // Test with a lot of numbers
  {
    Span sp = Span(10000);

    for (int i = 0; i < 10000; i++) {
      sp.addNumber(i);
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  
  // Test addNumbers()
  {
    Span sp = Span(5);

    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);
    sp.addNumbers(numbers.begin() + 1, numbers.end() - 1);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  // Test adding to many numbers with addNumbers()
  {
    Span sp = Span(5);

    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);
    numbers.push_back(11);
    try {
      sp.addNumbers(numbers.begin(), numbers.end());
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  // Test adding to many numbers with addNumber()
  {
    Span sp = Span(5);

    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);
    numbers.push_back(11);
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
      try {
        sp.addNumber(*it);
      } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
      }
    }
  }
}
