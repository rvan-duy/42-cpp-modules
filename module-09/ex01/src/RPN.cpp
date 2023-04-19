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
  if (_numberStack.empty() || _numberStack.size() > 1) {
    std::cout << "Error" << std::endl;
    return;
  }
  std::cout << _numberStack.top() << std::endl;
}
