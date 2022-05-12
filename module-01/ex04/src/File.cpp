#include "File.hpp"

File::File(){};
File::File(const char* path) : path(path){};
File::~File(){};

std::string File::getPath() const { return path; }
