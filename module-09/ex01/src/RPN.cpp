#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::addNumber(double number) { _numberStack.push(number); }

void RPN::calculate(Operation operation) {
  double result1 = _numberStack.top();
  _numberStack.pop();

  double result2 = _numberStack.top();
  _numberStack.pop();

  switch (operation) {
    case ADD:
      _numberStack.push(result2 + result1);
      break;
    case SUBTRACT:
      _numberStack.push(result2 - result1);
      break;
    case MULTIPLY:
      _numberStack.push(result2 * result1);
      break;
    case DIVIDE:
      _numberStack.push(result2 / result1);
      break;
  }
}

void RPN::printStack() {
  std::stack<double> tmp = _numberStack;
  while (!tmp.empty()) {
    std::cout << tmp.top() << std::endl;
    tmp.pop();
  }
}
