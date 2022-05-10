#include "File.hpp"

File::File(const char* path, const std::ios_base::openmode& mode) : path(path) {
  fs.open(path, mode);
  if (fs.is_open() == false) {
    is_open = false;
    std::cout << path << ": " << strerror(errno) << std::endl;
  } else
    is_open = true;
}
File::~File() { fs.close(); }

const std::string File::getPath() { return path; }
bool              File::checkIfOpen() { return is_open; }
