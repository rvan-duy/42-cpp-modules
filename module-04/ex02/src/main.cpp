#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

int  main(void) {
   AAnimal* animals[10];

  //  AAnimal * animal = new AAnimal(); // << this gives an error because its abstract!

   for (int i = 0; i < 10; i++) {
     if (i % 2 == 0)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

   for (int i = 0; i < 10; i++) {
     delete animals[i];
  }

   return EXIT_SUCCESS;
}
