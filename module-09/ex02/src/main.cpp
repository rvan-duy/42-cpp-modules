#include "PmergeMe.hpp"

std::vector<int> parseAndErrorCheckArgv(int argc, char **argv) {
  std::vector<int> numbers;
  try {
    for (int i = 1; i < argc; i++) {
      std::stringstream ss(argv[i]);
      long number;
      while (ss >> number) {
        if (ss.fail() || number < 0 || number > INT_MAX) {
          throw std::invalid_argument("invalid argument");
        }
        numbers.push_back(number);
      }
    }
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
  return numbers;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
    return EXIT_FAILURE;
  }

  {
    std::vector<int> numbers = parseAndErrorCheckArgv(argc, argv);
    PmergeMe pmergeMe(numbers);

    std::cout << "Before: ";
    pmergeMe.printVector();

    long duration = pmergeMe.sortVector();

    std::cout << "After:  ";
    pmergeMe.printVector();

    std::cout << "Time to process range of " << numbers.size()
              << " elements with std::vector: " << duration << " microseconds"
              << std::endl;

    duration = pmergeMe.sortList();

    std::cout << "Time to process range of " << numbers.size()
              << " elements with std::list: " << duration << " microseconds"
              << std::endl;
  }

  return EXIT_SUCCESS;
}
