#ifndef MODULE_04_BRAIN_HPP
#define MODULE_04_BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
 public:
  Brain();                               // Default constructor
  ~Brain();                              // Destructor
  Brain(const Brain &brain);             // Copy Constructor
  Brain &operator=(const Brain &brain);  // Copy assignment operator

 private:
  std::string ideas[100];
};

#endif  // MODULE_04_BRAIN_HPP
