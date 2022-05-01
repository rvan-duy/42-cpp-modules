#include "Contact.hpp"

// Default constructor
Contact::Contact() { }

// Getters
std::string Contact::getFirstName() { return this->_firstname; }
std::string Contact::getLastName() { return this->_lastname; }
std::string Contact::getNickname() { return this->_nickname; }
std::string Contact::getPhonenumber() { return this->_phonenumber; }

// Setters
void Contact::setFirstName(const std::string firstname) { this->_firstname = firstname; }
void Contact::setLastName(const std::string lastname) { this->_lastname = lastname; }
void Contact::setNickname(const std::string nickname) { this->_nickname = nickname; }
void Contact::setPhonenumber(const std::string phonenumber) { this->_phonenumber = phonenumber; }
void Contact::setSecret(const std::string secret) { this->_secret = secret; }
