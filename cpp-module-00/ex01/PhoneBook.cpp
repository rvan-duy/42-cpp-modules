#include "PhoneBook.hpp"

void PhoneBook::addContact(Contact new_contact)
{
	if (amount_of_contacts_stored < MAX_CONTACTS)
	{
		contacts[amount_of_contacts_stored] = new_contact;
		amount_of_contacts_stored++;
	}
	else
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[MAX_CONTACTS - 1] = new_contact;
	}
}

void PhoneBook::printContacts() {
	for (std::size_t i = 0; i < amount_of_contacts_stored; i++) {
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		std::cout << contacts[i].getFirstName() << "|";
		std::cout << std::setw(10);
		std::cout << contacts[i].getLastName() << "|";
		std::cout << std::setw(10);
		std::cout << contacts[i].getNickname() << "|";
		std::cout << std::endl;
	}
}
