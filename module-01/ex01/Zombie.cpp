#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() {}

// Constructor
Zombie::Zombie(const std::string name) : _name(name) {}

// Destructor
Zombie::~Zombie() { std::cout << "Zombie " << this->_name << " died of starvation." << std::endl; }

// Getters
std::string Zombie::getName(void) const { return this->_name; }

// Setters
void Zombie::setName(std::string name) { this->_name = name; }

// Methods
void Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
