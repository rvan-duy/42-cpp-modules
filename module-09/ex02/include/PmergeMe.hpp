#ifndef CPP_MODULE_09_PMERGEME_HPP
#define CPP_MODULE_09_PMERGEME_HPP

#include <sys/time.h>

#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#define THRESHOLD 5
#define num std::size_t

class PmergeMe {
 public:
  PmergeMe(const std::vector<int> &numbers);
  ~PmergeMe();

  long sortVector();
  long sortList();
  void printVector();
  void printList();

 private:
  std::vector<int> _vectorNumbers;
  std::list<int> _listNumbers;

  void vector_merge(num left, num middle, num right);
  void vector_mergeSort(num left, num right);

  void list_merge(num left, num middle, num right);
  void list_mergeSort(num left, num right);

  long getTimestamp() const;
};

#endif  // CPP_MODULE_09_PMERGEME_HPP
