#ifndef MODULE_09_RPN_HPP
#define MODULE_09_RPN_HPP

#include <stack>

enum class Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE };

class RPN {
 public:
  RPN();
  ~RPN();

  void addNumber(double number);
  double calculate(Operation operation);

 private:
  std::stack<double> _numberStack;
};

#endif  // MODULE_09_RPN_HPP
