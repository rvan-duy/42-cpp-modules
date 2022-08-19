#ifndef MODULE_04_ANIMAL_HPP
#define MODULE_04_ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
 public:
  Animal();                                 // Default constructor
  virtual ~Animal();                        // Destructor
  Animal(const Animal &animal);             // Copy Constructor
  Animal &operator=(const Animal &animal);  // Copy assignment operator

  // Getters
  const std::string &getType() const;

  // Methods
  virtual void makeSound() const;

 protected:
  std::string type;
};

#endif  // MODULE_04_ANIMAL_HPP
