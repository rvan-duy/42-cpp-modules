#include "Replacer.hpp"

Replacer::Replacer(File& src, const char* s1, const char* s2) : this->src(src), this->s1(s1), this->s2(s2) {}

bool Replacer::openDstFile() {
  std::string dst_path = src.getPath() + std::string(".replace");
  std::cout << dst_path << std::endl;
}
