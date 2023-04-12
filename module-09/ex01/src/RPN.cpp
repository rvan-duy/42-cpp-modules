#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::addNumber(double number) { _numberStack.push(number); }

double RPN::calculate(Operation operation) {
  double result = 0;
  double firstNumber = _numberStack.top();
  _numberStack.pop();
  double secondNumber = _numberStack.top();
  _numberStack.pop();

  switch (operation) {
    case Operation::ADD:
      result = firstNumber + secondNumber;
      break;
    case Operation::SUBTRACT:
      result = firstNumber - secondNumber;
      break;
    case Operation::MULTIPLY:
      result = firstNumber * secondNumber;
      break;
    case Operation::DIVIDE:
      result = firstNumber / secondNumber;
      break;
  }

  _numberStack.push(result);
  return result;
}
