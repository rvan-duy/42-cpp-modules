#include "Contact.hpp"

Contact::Contact() { }

std::string Contact::getFirstName() { return this->_firstname; }
std::string Contact::getLastName() { return this->_lastname; }
std::string Contact::getNickname() { return this->_nickname; }
std::string Contact::getPhonenumber() { return this->_phonenumber; }

void Contact::setFirstName(std::string firstname) { this->_firstname = firstname; }
void Contact::setLastName(std::string lastname) { this->_lastname = lastname; }
void Contact::setNickname(std::string nickname) { this->_nickname = nickname; }
void Contact::setPhonenumber(std::string phonenumber) { this->_phonenumber = phonenumber; }
void Contact::setSecret(std::string secret) { this->_secret = secret; }
