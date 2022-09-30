#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

static void printMutantStack(MutantStack<int>& stack) {
  for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main() {
  // Testing MutantStack
  {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "MutantStack:" << std::endl;
    printMutantStack(mstack);

    // Testing copy constructor of MutantStack
    {
      MutantStack<int> mstack2(mstack);

      std::cout << "MutantStack2:" << std::endl;
      printMutantStack(mstack2);
    }

    // Testing assignment operator of MutantStack
    {
      MutantStack<int> mstack3;
      mstack3 = mstack;

      std::cout << "MutantStack3:" << std::endl;
      printMutantStack(mstack3);
    }

    // Testing if MutantStack is a stack
    std::cout << "MutantStack is a stack:" << std::endl;
    std::stack<int> s(mstack);
    std::cout << std::boolalpha << !s.empty() << std::endl;

    // Testing top() method
    std::cout << "MutantStack top():" << std::endl;
    std::cout << mstack.top() << std::endl;

    // Testing size() method
    std::cout << "MutantStack size():" << std::endl;
    std::cout << mstack.size() << std::endl;
  }

  std::cout << "----------------" << std::endl;

  // Do the same but with std::list
  {
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it  = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      it++;
    }

    std::cout << "List back():" << std::endl;
    std::cout << mstack.back() << std::endl;

    std::cout << "List size():" << std::endl;
    std::cout << mstack.size() << std::endl;
  }

  std::cout << "----------------" << std::endl;

  // Do the same but with std::vector
  {
    std::vector<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::vector<int>::iterator it  = mstack.begin();
    std::vector<int>::iterator ite = mstack.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      it++;
    }

    std::cout << "Vector back():" << std::endl;
    std::cout << mstack.back() << std::endl;

    std::cout << "Vector size():" << std::endl;
    std::cout << mstack.size() << std::endl;
  }

  return 0;
}
