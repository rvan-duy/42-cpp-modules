#ifndef CPP_MODULE_07_TEMPLATES_HPP
#define CPP_MODULE_07_TEMPLATES_HPP

// Good practice is to use T as name for the template parameter

template <class T>
void swap(T &a, T &b) {
  T tmp = a;
  a     = b;
  b     = tmp;
}

template <class T>
T min(T a, T b) {
  return (a < b) ? a : b;
}

template <class T>
T max(T a, T b) {
  return (a > b) ? a : b;
}

#endif  // CPP_MODULE_07_TEMPLATES_HPP
