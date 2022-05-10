#include "FileDescriptor.hpp"

enum program_params { file_name = 1, s1 = 2, s2 = 3 };

int main(int argc, char *argv[]) {
  FileDescriptor fd(argv[file_name]);

  (void)argc;
}
