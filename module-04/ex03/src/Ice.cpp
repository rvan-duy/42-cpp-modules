#include "Ice.hpp"

Ice::Ice() {
  this->type = "ice";
  std::cout << "-> (Ice) Default constructor for Ice is called" << std::endl;
};

Ice::~Ice() { std::cout << "-> (Ice) Destructor for Ice is called" << std::endl; };

Ice::Ice(const Ice &ice) {
  this->type = ice.type;
  std::cout << "-> (Ice) Copy constructor for Ice is called" << std::endl;
};

Ice &Ice::operator=(const Ice &ice) {
  this->type = ice.type;
  std::cout << "(Ice) Copy assignment operator for Ice is called" << std::endl;
  return *this;
};

// Clones the ice and returns it
Ice *Ice::clone() {
  Ice new_ice;

  return &new_ice;
};

// probably replace with getname func
void Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl; };
