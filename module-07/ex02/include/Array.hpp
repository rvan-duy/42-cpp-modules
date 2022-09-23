#ifndef CPP_MODULE_07_ARRAY_HPP
#define CPP_MODULE_07_ARRAY_HPP

#include <cstddef>

template <class T>
class Array {
 public:
  Array() : arr(new T[0]), arr_size(0){};                                       // Constructor
  Array(unsigned int n) : arr(new T[n]), arr_size(n){};                         // Constructor with size
  Array(const Array& cpy) : arr(new T[cpy.arr_size]), arr_size(cpy.arr_size) {  // Copy constructor
    for (unsigned int i = 0; i < arr_size; i++) {
      arr[i] = cpy.arr[i];
    }
  }
  ~Array() { delete[] arr; }  // Destructor

  T& operator[](unsigned int index) {
    if (index >= arr_size) {
      throw std::exception();
    }
    return arr[index];
  }

  // Methods
  unsigned int size() const { return arr_size; }

 private:
  T*           arr;
  unsigned int arr_size;
};

#endif  // CPP_MODULE_07_ARRAY_HPP
