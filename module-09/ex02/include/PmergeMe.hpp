#ifndef CPP_MODULE_09_PMERGEME_HPP
#define CPP_MODULE_09_PMERGEME_HPP

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#define THRESHOLD 1
#define num std::size_t

/*
 * PmergeMe is a class that takes a vector of integers as a parameter and stores
 * them in a CONTAINER_ONE and a CONTAINER_TWO. It then sorts the CONTAINER_ONE
 * and CONTAINER_TWO using merge insort.
 */

class PmergeMe {
 public:
  PmergeMe(const std::vector<int> &numbers);
  ~PmergeMe();

  std::chrono::microseconds sortVector();
  std::chrono::microseconds sortList();
  void printVector();
  void printList();

 private:
  std::vector<int> _vectorNumbers;
  std::list<int> _listNumbers;

  void vector_merge(num left, num middle, num right);
  void vector_mergeSort(num left, num right);

  void list_merge(num left, num middle, num right);
  void list_mergeSort(num left, num right);
};

#endif  // CPP_MODULE_09_PMERGEME_HPP
