#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <set>

#include "easyfind.hpp"

// TODO: proper printing of containers

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

    std::cout << "Looking for 20" << std::endl;
    std::deque::iterator it = ::easyfind(mydeque, 20);
    std::cout << "Found " << *it << std::endl;
  }

  // Testing list
  {
    std::list<int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);

    std::cout << "mylist contains:";
    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "Looking for 20" << std::endl;
    ::easyfind(mylist, 20);
  }

  // Testing vector
  {
    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "Looking for 20" << std::endl;
    ::easyfind(myvector, 20);
  }

  // Testing out_of_range
  {
    std::vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "Looking for 40" << std::endl;
    try {
      ::easyfind(myvector, 40);
    } catch (std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }
}
