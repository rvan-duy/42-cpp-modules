#include "Contact.hpp"

// Default constructor
Contact::Contact() {}

// Getters
std::string Contact::getFirstName() { return this->firstname; }
std::string Contact::getLastName() { return this->lastname; }
std::string Contact::getNickname() { return this->nickname; }
std::string Contact::getPhonenumber() { return this->phonenumber; }

// Setters
void Contact::setFirstName(const std::string firstname) { this->firstname = firstname; }
void Contact::setLastName(const std::string lastname) { this->lastname = lastname; }
void Contact::setNickname(const std::string nickname) { this->nickname = nickname; }
void Contact::setPhonenumber(const std::string phonenumber) { this->phonenumber = phonenumber; }
void Contact::setSecret(const std::string secret) { this->secret = secret; }
