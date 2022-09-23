#ifndef CPP_MODULE_07_ITER_HPP
#define CPP_MODULE_07_ITER_HPP

#include <cstddef>

template <class T>
void iter(T* arr, std::size_t len, void (*f)(T const&)) {
  for (std::size_t i = 0; i < len; i++) {
    f(arr[i]);
  }
}

#endif  // CPP_MODULE_07_ITER_HPP
