#include "RPN.hpp"

int main(int argc, char **argv) {
  // Program takes inverted Polish mathematical expression as an argument
  RPN rpn;

  rpn.addNumber(2);
  rpn.addNumber(3);
  rpn.calculate(Operation::ADD);

}
