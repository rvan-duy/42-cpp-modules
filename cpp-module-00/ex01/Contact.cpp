#include "Contact.hpp"

Contact::Contact() { }

Contact::Contact(std::string name) : _name(name) { }

std::string Contact::getName() { return this->_name; }
