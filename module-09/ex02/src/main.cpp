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

    std::chrono::microseconds duration = pmergeMe.sortVector();

    std::cout << "After: ";
    pmergeMe.printVector();

    std::cout << "Time to process range of " << numbers.size()
              << " elements with std::vector: " << duration.count()
              << " microseconds" << std::endl;

    std::cout << "Before: ";
    pmergeMe.printList();

    duration = pmergeMe.sortList();

    std::cout << "After: ";
    pmergeMe.printList();

    std::cout << "Time to process range of " << numbers.size()
              << " elements with std::list: " << duration.count()
              << " microseconds" << std::endl;
  }

  return EXIT_SUCCESS;
}
