#ifndef CPP_MODULE_08_MUTANTSTACK_HPP
#define CPP_MODULE_08_MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() : std::stack<T>() {}
  MutantStack(const MutantStack& other) : std::stack<T>(other) {}
  MutantStack& operator=(const MutantStack& other) {
    if (this != &other) {
      std::stack<T>::operator=(other);
    }
    return *this;
  }
  ~MutantStack() {}

  typedef typename std::deque<T>::iterator iterator;
  
  // Methods
  iterator    begin() { return this->c.begin(); }
  iterator    end() { return this->c.end(); }
};

#endif  // CPP_MODULE_08_MUTANTSTACK_HPP
