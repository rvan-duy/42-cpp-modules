#include "File.hpp"

// You should instead create the ifstream only when you need it, inside the method that needs it,
// and let it be destroyed when the method exits.
// It should not be a part of the object because it has no need to persist with the object.

File::File(){};
File::File(const char* path) : path(path){};
File::~File(){};

std::string File::getPath() const { return path; }
