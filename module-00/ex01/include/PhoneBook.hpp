#ifndef MODULE_00_PHONEBOOK_HPP
#define MODULE_00_PHONEBOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
 public:
  // Default constructor
  PhoneBook();

  // Getters
  std::size_t getAmountOfContactsStored();
  Contact     getContact(const std::size_t index);

  // Methods
  void addContact(std::istream &istream);
  void searchContact(std::istream &istream);

 private:
  // Internal variables
  std::size_t amount_of_contacts_stored;  // Amount of contacts stored in the phonebook
  Contact     contacts[MAX_CONTACTS];     // Array of contacts

  // Internal methods
  std::string cutString(const std::string str);
  void        printContacts(void);
};

#endif  // MODULE_00_PHONEBOOK_HPP
