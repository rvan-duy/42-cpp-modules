#ifndef MODULE_04_ANIMAL_HPP
#define MODULE_04_ANIMAL_HPP

#include <iostream>
#include <string>

#include "Brain.hpp"

class Animal {
 public:
  Animal();                                 // Default constructor
  virtual ~Animal();                        // Destructor
  Animal(const Animal &animal);             // Copy Constructor
  Animal &operator=(const Animal &animal);  // Copy assignment operator

  // Getters
  std::string getType() const;

  // Methods
  virtual void makeSound() const = 0;       // Because makeSound() is not implemented inside the Animal class, it is an abstract class

 protected:
  std::string type;
  Brain      *brain;
};

#endif  // MODULE_04_ANIMAL_HPP
