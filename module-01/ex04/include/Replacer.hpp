#ifndef MODULE_01_REPLACER_HPP
#define MODULE_01_REPLACER_HPP

#include "File.hpp"

class Replacer {
 public:
  #define newline buffer.size() - 1
  enum status { success, failure };

  Replacer();
  Replacer(File& src, const char* s1, const char* s2);
  ~Replacer();

  status fillBuffer();
  void   replaceBuffer();
  status writeBufferToPath();

 private:
  File        src;
  std::string dst_path;
  std::string buffer;
  const char* s1;
  const char* s2;
};

#endif  // MODULE_01_REPLACER_HPP
