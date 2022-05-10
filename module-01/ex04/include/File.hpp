#ifndef MODULE_01_FILE_HPP
#define MODULE_01_FILE_HPP

#include <cerrno>    // errno
#include <cstring>   // strerror string
#include <fstream>   // fstream
#include <iostream>  // cout

class File {
 public:
  File(const char* path, const std::ios_base::openmode& mode = 24U);
  ~File();

  const std::string getPath();
  bool              checkIfOpen();

 private:
  const std::string path;
  std::fstream      fs;
  bool              is_open;
};

#endif  // MODULE_01_FILE_HPP
