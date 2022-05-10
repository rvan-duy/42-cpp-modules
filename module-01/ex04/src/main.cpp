#include "Replacer.hpp"

enum program_params { file_name = 1, s1 = 2, s2 = 3 };

int main(int argc, char *argv[]) {
  if (argc == 4) {
    File src(argv[file_name]);
    if (src.checkIfOpen() == false) return EXIT_FAILURE;
    Replacer replacer(src, argv[s1], argv[s2]);
    replacer.openDstFile();
  } else
    std::cout << "Usage:" << std::endl << argv[0] << " <file_name> <s1> <s2>" << std::endl;
  return EXIT_SUCCESS;
}
