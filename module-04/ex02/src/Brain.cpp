#include "Brain.hpp"

Brain::Brain() { std::cout << "-> (Brain) Default constructor is called" << std::endl; };

Brain::~Brain() { std::cout << "-> (Brain) Destructor is called" << std::endl; };

Brain::Brain(const Brain &brain) {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = brain.ideas[i];
  }

  std::cout << "-> (Brain) Copy assignment constructor is called" << std::endl;
};

Brain &Brain::operator=(const Brain &brain) {
  for (int i = 0; i < 100; i++) {
    this->ideas[i] = brain.ideas[i];
  }

  std::cout << "-> (Brain) Copy assignment constructor is called" << std::endl;
  return *this;
};
