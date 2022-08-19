#ifndef MODULE_04_ANIMAL_HPP
#define MODULE_04_ANIMAL_HPP

#include <iostream>
#include <string>

// With the destructor being virtual you can destroy Derived object
// with a pointer to the Animal class

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
