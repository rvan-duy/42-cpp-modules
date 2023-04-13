#ifndef MODULE_09_RPN_HPP
#define MODULE_09_RPN_HPP

#include <iostream>
#include <stack>

enum Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE };

class RPN {
 public:
  RPN();
  ~RPN();

  void addNumber(double number);
  void calculate(Operation operation);
  void printStack();

 private:
  std::stack<double> _numberStack;
};

#endif  // MODULE_09_RPN_HPP
