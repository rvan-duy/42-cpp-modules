#include "AMateria.hpp"

AMateria::AMateria() : type("") {
  std::cout << "-> (AMateria) Default constructor for AMateria is called" << std::endl;
};

AMateria::AMateria(std::string const& type) : type(type) {
  this->type = type;
  std::cout << "-> (AMateria) Constructor with name for AMateria is called" << std::endl;
};

AMateria::~AMateria() { std::cout << "-> (AMateria) Destructor for AMateria is called" << std::endl; };

// Nothing is copied
AMateria::AMateria(const AMateria& material) {
  std::cout << "-> (AMateria) Copy constructor for AMateria is called" << std::endl;
};

// Nothing is copied
AMateria::AMateria& operator=(const AMateria& materia) {
  std::cout << "(AMateria) Copy assignment operator for AMateria is called" << std::endl;
  return *this;
};

std::string const* AMateria::getType() const { return this->type; };

void AMateria::use(ICharacter& target) { std::err << "If this shows, something goes horribly wrong" << std::endl; };
