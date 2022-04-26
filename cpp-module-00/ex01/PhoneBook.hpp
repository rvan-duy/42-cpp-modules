#ifndef CPP_MODULE_00_PHONEBOOK_H
#define CPP_MODULE_00_PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {

	private:
		std::size_t amount_of_contacts_stored;	// Amount of contacts stored in the phonebook
		Contact 	contacts[8];				// Array of contacts

	public:

		// Constructor
		PhoneBook() {
			amount_of_contacts_stored = 0;
		}

		void addContact(Contact new_contact);
		void printContacts();

};


#endif //CPP_MODULE_00_PHONEBOOK_H
