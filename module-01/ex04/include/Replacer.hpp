#ifndef MODULE_01_REPLACER_HPP
#define MODULE_01_REPLACER_HPP

#include "File.hpp"

class Replacer {
 public:
  Replacer();
  Replacer(File& src, const char* s1, const char* s2);
  ~Replacer();

  bool fillBuffer();
  void replaceBuffer();

 private:
  File        src;
  std::string dst_path;
  std::string buffer;
  const char* s1;
  const char* s2;
};

#endif  // MODULE_01_REPLACER_HPP
