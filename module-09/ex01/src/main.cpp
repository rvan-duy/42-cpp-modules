#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc == 2) {
    RPN rpn;
    const std::string input = argv[1];
    for (std::string::const_iterator it = input.begin(); it != input.end();
         it++) {
      if (std::isdigit(*it)) {
        rpn.addNumber(*it - '0');
        continue;
      }
      switch (*it) {
        case '+':
          rpn.calculate(ADD);
          break;
        case '-':
          rpn.calculate(SUBTRACT);
          break;
        case '*':
          rpn.calculate(MULTIPLY);
          break;
        case '/':
          rpn.calculate(DIVIDE);
          break;
        case ' ':
          break;
        default:
          std::cout << "Error" << std::endl;
          return 1;
      }
    }
    rpn.printStack();
  } else {
    std::cout << "Error" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
