#include "FileDescriptor.hpp"

FileDescriptor::FileDescriptor(const std::string& path) : _path(path) {
  _fs.open(_path);
  if (_fs.is_open() == false) {
    std::cout << _path << ": " << strerror(errno) << std::endl;
  }
}
FileDescriptor::~FileDescriptor() {
    _fs.close();
};
