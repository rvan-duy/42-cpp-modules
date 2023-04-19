#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &numbers) {
  for (std::vector<int>::const_iterator it = numbers.begin();
       it != numbers.end(); it++) {
    _listNumbers.push_back(*it);
    _vectorNumbers.push_back(*it);
  }
}

PmergeMe::~PmergeMe() {}

void PmergeMe::vector_merge(num left, num middle, num right) {
  num sizeLeftVector = middle - left + 1;
  num sizeRightVector = right - middle;

  std::vector<int> leftVector;
  std::vector<int> rightVector;

  for (num i = 0; i < sizeLeftVector; i++) {
    leftVector.push_back(_vectorNumbers[left + i]);
  }
  for (num j = 0; j < sizeRightVector; j++) {
    rightVector.push_back(_vectorNumbers[middle + 1 + j]);
  }

  // index of leftVector, rightVector and _vectorNumbers
  num i = 0, j = 0, k = left;

  while (i < sizeLeftVector && j < sizeRightVector) {  // merge
    if (leftVector[i] <= rightVector[j]) {
      _vectorNumbers[k] = leftVector[i];
      i++;
    } else {
      _vectorNumbers[k] = rightVector[j];
      j++;
    }
    k++;
  }

  while (i < sizeLeftVector) {  // if leftVector is bigger
    _vectorNumbers[k] = leftVector[i];
    i++;
    k++;
  }

  while (j < sizeRightVector) {  // if rightVector is bigger
    _vectorNumbers[k] = rightVector[j];
    j++;
    k++;
  }
}

void PmergeMe::vector_mergeSort(num left, num right) {
  if (left < right) {
    num middle = (left + right) / 2;
    vector_mergeSort(left, middle);
    vector_mergeSort(middle + 1, right);
    vector_merge(left, middle, right);
  }
}

long PmergeMe::sortVector() {
  long start = getTimestamp();

  if (_vectorNumbers.size() <= THRESHOLD) {
    // insert sort
    for (num i = 1; i < _vectorNumbers.size(); i++) {
      num j = i;
      while (j > 0 && _vectorNumbers[j - 1] > _vectorNumbers[j]) {
        std::swap(_vectorNumbers[j - 1], _vectorNumbers[j]);
        j--;
      }
    }
  } else {
    // merge sort
    num left = 0;
    num right = _vectorNumbers.size() - 1;
    vector_mergeSort(left, right);
  }

  long end = getTimestamp();
  return end - start;
}

void PmergeMe::list_merge(num left, num middle, num right) {
  num sizeLeftList = middle - left + 1;
  num sizeRightList = right - middle;

  std::list<int> leftList;
  std::list<int> rightList;

  for (num i = 0; i < sizeLeftList; i++) {
    std::list<int>::iterator it = _listNumbers.begin();
    std::advance(it, left + i);
    leftList.push_back(*it);
  }
  for (num j = 0; j < sizeRightList; j++) {
    std::list<int>::iterator it = _listNumbers.begin();
    std::advance(it, middle + 1 + j);
    rightList.push_back(*it);
  }

  std::list<int>::iterator itLeft = leftList.begin();
  std::list<int>::iterator itRight = rightList.begin();
  std::list<int>::iterator it = _listNumbers.begin();
  std::advance(it, left);

  while (itLeft != leftList.end() && itRight != rightList.end()) {
    if (*itLeft <= *itRight) {
      *it = *itLeft;
      itLeft++;
    } else {
      *it = *itRight;
      itRight++;
    }
    it++;
  }

  while (itLeft != leftList.end()) {
    *it = *itLeft;
    itLeft++;
    it++;
  }

  while (itRight != rightList.end()) {
    *it = *itRight;
    itRight++;
    it++;
  }
}

void PmergeMe::list_mergeSort(num left, num right) {
  if (left < right) {
    num middle = (left + right) / 2;
    list_mergeSort(left, middle);
    list_mergeSort(middle + 1, right);
    list_merge(left, middle, right);
  }
}

long PmergeMe::sortList() {
  long start = getTimestamp();

  if (_listNumbers.size() <= THRESHOLD) {
    // insert sort
    for (std::list<int>::iterator it = _listNumbers.begin();
         it != _listNumbers.end(); it++) {
      std::list<int>::iterator it2 = it;
      while (it2 != _listNumbers.begin() &&
             *std::prev(it2) > *it2) {  // if prev is bigger
        std::swap(*std::prev(it2), *it2);
        it2--;
      }
    }
  } else {
    // merge sort
    num left = 0;
    num right = _listNumbers.size() - 1;
    list_mergeSort(left, right);
  }

  long end = getTimestamp();
  return end - start;
}

void PmergeMe::printVector() {
  for (std::vector<int>::const_iterator it = _vectorNumbers.begin();
       it != _vectorNumbers.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printList() {
  for (std::list<int>::const_iterator it = _listNumbers.begin();
       it != _listNumbers.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

long PmergeMe::getTimestamp() const {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * (int)1e6 + tv.tv_usec;
}
