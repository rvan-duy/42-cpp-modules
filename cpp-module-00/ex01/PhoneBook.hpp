#ifndef CPP_MODULE_00_PHONEBOOK_H
#define CPP_MODULE_00_PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {

	private:
		std::size_t _amount_of_contacts_stored;	// Amount of contacts stored in the phonebook
		Contact 	_contacts[MAX_CONTACTS];		// Array of contacts

	public:

		// Constructor
		PhoneBook() {
			_amount_of_contacts_stored = 0;
		}

		// Getters
		std::size_t	getAmountOfContactsStored();
		Contact 	getContact(std::size_t index);

		void addContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret);
		void printContacts(void);

};

#endif //CPP_MODULE_00_PHONEBOOK_H
