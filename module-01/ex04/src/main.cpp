#include "Replacer.hpp"

enum program_params { file_name = 1, s1 = 2, s2 = 3 };

int main(int argc, char *argv[]) {
  if (argc == 4) {
    File     src(argv[file_name]);
    Replacer replacer(src, argv[s1], argv[s2]);

    if (replacer.fillBuffer() == false) {
      return EXIT_FAILURE;
    }
    replacer.replaceBuffer();
  } else
    std::cout << "Usage:" << std::endl << argv[0] << " <file_name> <s1> <s2>" << std::endl;
  return EXIT_SUCCESS;
}
