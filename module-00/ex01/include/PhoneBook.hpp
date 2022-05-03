#ifndef MODULE_00_PHONEBOOK_HPP
#define MODULE_00_PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
	public:
		// Default constructor
		PhoneBook();

		// Getters
		std::size_t	getAmountOfContactsStored();
		Contact 	getContact(const std::size_t index);

		// Methods
		void addContact(std::istream &istream);
		void searchContact(std::istream &istream);

	private:
		#define MAX_CONTACTS 8
		
		// Internal variables
		std::size_t _amount_of_contacts_stored;		// Amount of contacts stored in the phonebook
		Contact 	_contacts[MAX_CONTACTS];		// Array of contacts

		// Internal methods
		std::string _cutString(const std::string str);
		void		_printContacts(void);
};

#endif // MODULE_00_PHONEBOOK_HPP
