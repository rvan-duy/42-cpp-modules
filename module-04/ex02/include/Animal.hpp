#ifndef MODULE_04_AANIMAL_HPP
#define MODULE_04_AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
 public:
  AAnimal();                                  // Default constructor
  virtual ~AAnimal();                         // Destructor
  AAnimal(const AAnimal &animal);             // Copy Constructor
  AAnimal &operator=(const AAnimal &animal);  // Copy assignment operator

  // Getters
  const std::string &getType() const;

  // Methods
  virtual void makeSound() const = 0;

 protected:
  std::string type;
};

#endif  // MODULE_04_AANIMAL_HPP
