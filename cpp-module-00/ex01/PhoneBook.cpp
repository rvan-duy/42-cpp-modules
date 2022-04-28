#include "PhoneBook.hpp"

std::size_t PhoneBook::getAmountOfContactsStored() { return this->amount_of_contacts_stored; }
Contact		PhoneBook::getContact(std::size_t index) { return this->contacts[index]; }

void PhoneBook::addContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret)
{
	if (amount_of_contacts_stored < MAX_CONTACTS)
	{
		contacts[amount_of_contacts_stored].setFirstName(firstname);
		contacts[amount_of_contacts_stored].setLastName(lastname);
		contacts[amount_of_contacts_stored].setNickname(nickname);
		contacts[amount_of_contacts_stored].setPhonenumber(phonenumber);
		contacts[amount_of_contacts_stored].setSecret(secret);
		amount_of_contacts_stored++;
	}
	else
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[MAX_CONTACTS - 1].setFirstName(firstname);
		contacts[MAX_CONTACTS - 1].setLastName(lastname);
		contacts[MAX_CONTACTS - 1].setNickname(nickname);
		contacts[MAX_CONTACTS - 1].setPhonenumber(phonenumber);
		contacts[MAX_CONTACTS - 1].setSecret(secret);
	}
}

static std::string cut_string(std::string str)
{
	const std::size_t	str_size = str.size();
	std::string 		new_str = str.substr(0, 10);
	
	if (str_size > 10)
		new_str[9] = '.';
	
	return new_str;
}

void PhoneBook::printContacts(void) {
	for (std::size_t i = 0; i < amount_of_contacts_stored; i++) {
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << cut_string(contacts[i].getFirstName()) << "|";
		std::cout << cut_string(contacts[i].getLastName()) << "|";
		std::cout << cut_string(contacts[i].getNickname()) << "|";
		std::cout << cut_string(contacts[i].getPhonenumber()) << "|";
		std::cout << std::setw(0);
		std::cout << std::endl;
	}
}
