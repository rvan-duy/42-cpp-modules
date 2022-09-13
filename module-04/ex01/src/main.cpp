#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "       Testing 5 dogs and 5 cats        " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Animal* animals[10];

    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0)
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++) {
      delete animals[i];
    }

    system("/usr/bin/leaks -q i_dont_want_to_set_the_world_on_fire");
  }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "            Testing deep copy           " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Cat cat1, cat3;

    std::cout << "Copy constructor" << std::endl;
    Cat cat2(cat1);

    std::cout << "Copy assignment operator" << std::endl;
    cat3 = cat1;

    std::cout << "address of cat1: " << &cat1 << std::endl;
    std::cout << "address of brain(cat1): " << cat1.getBrainPtr() << std::endl;
    std::cout << "address of cat2: " << &cat2 << std::endl;
    std::cout << "address of brain(cat2): " << cat2.getBrainPtr() << std::endl;
    std::cout << "address of cat3: " << &cat3 << std::endl;
    std::cout << "address of brain(cat3): " << cat3.getBrainPtr() << std::endl;
  }

  return EXIT_SUCCESS;
}
