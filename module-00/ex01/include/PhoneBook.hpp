#ifndef CPP_MODULE_00_PHONEBOOK_H
#define CPP_MODULE_00_PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {

	public:
		
		// Default constructor
		PhoneBook() {
			_amount_of_contacts_stored = 0;
		}

		// Getters
		std::size_t	getAmountOfContactsStored();
		Contact 	getContact(std::size_t index);

		// Methods
		void addContact(std::istream &iostream);
		void searchContact(std::istream &iostream);


	private:

		#define MAX_CONTACTS 8
		
		// Internal variables
		std::size_t _amount_of_contacts_stored;		// Amount of contacts stored in the phonebook
		Contact 	_contacts[MAX_CONTACTS];		// Array of contacts

		// Internal methods
		std::string _cutString(std::string str);
		void		_printContacts(void);

};

#endif //CPP_MODULE_00_PHONEBOOK_H
