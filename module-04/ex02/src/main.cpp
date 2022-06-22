#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

void leaks() { system("leaks -q abstract_class"); };

int  main(void) {
   atexit(leaks);
   Animal* animals[10];

   // Animal animal; << this gives an error because its abstract!

   for (int i = 0; i < 10; i++) {
     if (i % 2 == 0)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  };

   for (int i = 0; i < 10; i++) {
     delete animals[i];
  };

   return EXIT_SUCCESS;
};
