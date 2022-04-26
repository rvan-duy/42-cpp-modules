#include "Contact.hpp"

Contact::Contact() { }

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret) 
        : _firstname(firstname), _lastname(lastname), _nickname(nickname), _phonenumber(phonenumber), _secret(secret) { }

// Getters
std::string Contact::getFirstName() { return this->_firstname; }
std::string Contact::getLastName() { return this->_lastname; }
std::string Contact::getNickname() { return this->_nickname; }
std::string Contact::getPhonenumber() { return this->_phonenumber; }
std::string Contact::getSecret() { return this->_secret; }
