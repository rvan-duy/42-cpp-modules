#ifndef CPP_MODULE_00_PHONEBOOK_H
#define CPP_MODULE_00_PHONEBOOK_H

#include <string>
#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 8
#define NO_OLDEST_CONTACT -1

class PhoneBook {

	private:
		std::size_t amount_of_contacts_stored;
		int			oldest_contact;
		Contact 	contacts[8];

	public:

		// Constructor
		PhoneBook() {
			amount_of_contacts_stored = 0;
			oldest_contact = NO_OLDEST_CONTACT;
		}

		void addContact(Contact new_contact);
		void printContacts();

};


#endif //CPP_MODULE_00_PHONEBOOK_H
