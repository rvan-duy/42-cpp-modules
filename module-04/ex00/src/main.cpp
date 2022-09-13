#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  Testing Animal, Cat and Dog classes   " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog    = new Dog();
    const Animal* cat    = new Cat();

    std::cout << "Type of animal is: (" << animal->getType() << ")" << std::endl;
    std::cout << "Type of dog is:    (" << dog->getType() << ")" << std::endl;
    std::cout << "Type of cat is:    (" << cat->getType() << ")" << std::endl;

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;
  }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  Testing copy constructor and operator " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Dog dog;
    Dog dog2(dog);
    Dog dog3 = dog;

    dog2.makeSound();
    dog3.makeSound();
 }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Testing WrongAnimal and WrongCat classes" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    const WrongAnimal* animal = new WrongAnimal();
    const WrongAnimal* cat    = new WrongCat();

    std::cout << "Type of animal is: (" << animal->getType() << ")" << std::endl;
    std::cout << "Type of cat is:    (" << cat->getType() << ")" << std::endl;

    animal->makeSound();
    cat->makeSound();

    delete animal;
    delete cat;
  }

  return EXIT_SUCCESS;
}
