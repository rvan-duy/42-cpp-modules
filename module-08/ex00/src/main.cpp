#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>

#include "easyfind.hpp"

int main() {
  // Testing deque
  {
    std::deque<int> mydeque;
    mydeque.push_back(10);
    mydeque.push_back(20);
    mydeque.push_back(30);

    std::cout << "mydeque contains:";
    for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it) std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "Looking for 20 in mydeque..." << std::endl;
    try {
      std::deque<int>::iterator it = easyfind(mydeque, 20);
      std::cout << *it << " was found" << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    // This should throw an exception
    std::cout << "Looking for 40 in mydeque..." << std::endl;
    try {
      std::deque<int>::iterator it = easyfind(mydeque, 40);
      std::cout << *it << " was found" << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;

  // Testing list
  {
    std::list<int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);

    std::cout << "mylist contains:";
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "Looking for 20 in mylist..." << std::endl;
    try {
      std::list<int>::iterator it = easyfind(mylist, 20);
      std::cout << *it << " was found" << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    // This should throw an exception
    std::cout << "Looking for 40 in mylist..." << std::endl;
    try {
      std::list<int>::iterator it = easyfind(mylist, 40);
      std::cout << *it << " was found" << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;

  // Testing vector
  {
    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "Looking for 20 in myvector..." << std::endl;
    try {
      std::vector<int>::iterator it = easyfind(myvector, 20);
      std::cout << *it << " was found" << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    // This should throw an exception
    std::cout << "Looking for 40 in myvector..." << std::endl;
    try {
      std::vector<int>::iterator it = easyfind(myvector, 40);
      std::cout << *it << " was found" << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}
