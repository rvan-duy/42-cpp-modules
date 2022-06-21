#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

void leaks() { system("leaks -q i_dont_want_to_set_the_world_on_fire"); };

int  main(void) {
   atexit(leaks);
   Animal* animals[10];

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
