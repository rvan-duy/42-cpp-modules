#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  const Animal* meta = new Animal();
  const Animal* j    = new Dog();
  const Animal* i    = new Cat();

  std::cout << "Type of Animal class: (" << meta->getType() << ")" << std::endl;
  std::cout << "Type of Dog class: (" << j->getType() << ")" << std::endl;
  std::cout << "Type of Cat class: (" << i->getType() << ")" << std::endl;

  meta->makeSound();
  j->makeSound();
  i->makeSound();

  delete meta;
  delete j;
  delete i;

  return EXIT_SUCCESS;
}
