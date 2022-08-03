#include "Zombie.hpp"

// Constructor
Zombie::Zombie(const std::string name) : _name(name) {}

// Destructor
Zombie::~Zombie() { std::cout << "Zombie " << this->_name << " died of starvation." << std::endl; }

// Methods
void Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
