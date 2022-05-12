#ifndef MODULE_01_FILE_HPP
#define MODULE_01_FILE_HPP

#include <cerrno>    // errno
#include <cstring>   // strerror string
#include <fstream>   // fstream
#include <iostream>  // cout

class File {
 public:
  File();
  File(const char* path);
  ~File();

  std::string getPath() const;

 private:
  const std::string path;
};

#endif  // MODULE_01_FILE_HPP
