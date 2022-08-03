#include "Replacer.hpp"

Replacer::Replacer(){};
Replacer::Replacer(File& src, const char* s1, const char* s2) : src(src), s1(s1), s2(s2) {
  dst_path = src.getPath() + std::string(".replace");
};
Replacer::~Replacer(){};

Replacer::status Replacer::fillBuffer() {
  std::string   line;
  std::ifstream ifs(src.getPath().c_str(), std::ifstream::in);

  if (ifs.is_open() == false) {
    std::cout << "error: " << src.getPath() << ": " << strerror(errno) << std::endl;
    return failure;
  }

  while (ifs.eof() == false) {
    std::getline(ifs, line);
    buffer += line + "\n";
  }
  buffer.erase(newline);

  ifs.close();
  return success;
};
void Replacer::replaceBuffer() {
  for (std::size_t found = buffer.find(s1, 0); found != std::string::npos;
       found             = buffer.find(s1, found + strlen(s2))) {
    buffer.erase(found, strlen(s1));
    buffer.insert(found, s2);
  }
};
Replacer::status Replacer::writeBufferToPath() {
  std::ofstream ofs(dst_path.c_str(), std::ofstream::out);

  if (ofs.is_open() == false) {
    std::cout << "error: " << dst_path << ": " << strerror(errno) << std::endl;
    return failure;
  }
  ofs << buffer;
  ofs.close();
  return success;
};
