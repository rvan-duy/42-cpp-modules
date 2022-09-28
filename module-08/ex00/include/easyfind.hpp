#ifndef CPP_MODULE_08_EASYFIND_HPP
#define CPP_MODULE_08_EASYFIND_HPP

#include <iterator>
#include <stdexcept>

template <class T>
typename T::iterator easyfind(T container, int element) {
  for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
    if (*it == element) return it;
  }
  throw std::invalid_argument("Element is not in container");
}

#endif  // CPP_MODULE_08_EASYFIND_HPP
