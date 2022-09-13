#include "Brain.hpp"

Brain::Brain() {
  std::cout << "-> (Brain) Default constructor is called" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = "Amazing idea";
  }
}

Brain::~Brain() {
  std::cout << "-> (Brain) Destructor is called" << std::endl;
}

Brain::Brain(const Brain &brain) {
  std::cout << "-> (Brain) Copy constructor is called" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = brain.ideas[i];
  }
}

Brain &Brain::operator=(const Brain &brain) {
  std::cout << "-> (Brain) Copy assignment operator overload is called" << std::endl;
  if (this != &brain) {
    for (int i = 0; i < 100; i++) {
      ideas[i] = brain.ideas[i];
    }
  }
  return *this;
}
