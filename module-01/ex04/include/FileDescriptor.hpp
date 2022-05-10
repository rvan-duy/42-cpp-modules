#include <cerrno>    // errno
#include <cstring>   // strerror
#include <fstream>   // fstream
#include <iostream>  // cout

class FileDescriptor {
 public:
  FileDescriptor(const std::string& path);
  ~FileDescriptor();

 private:
  const std::string& _path;
  std::fstream       _fs;
};
