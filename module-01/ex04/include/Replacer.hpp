#ifndef MODULE_01_REPLACER_HPP
#define MODULE_01_REPLACER_HPP

#include "File.hpp"

class Replacer {
 public:
  Replacer(File& src, const char* s1, const char* s2);

  bool openDstFile();

 private:
  File        src;
  File        dst;
  std::string buffer;
  const char* s1;
  const char* s2;
};

#endif  // MODULE_01_REPLACER_HPP
