#include "PhoneBook.hpp"

std::size_t PhoneBook::getAmountOfContactsStored() { return this->_amount_of_contacts_stored; }
Contact		PhoneBook::getContact(std::size_t index) { return this->_contacts[index]; }

void PhoneBook::addContact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret)
{
	if (_amount_of_contacts_stored < MAX_CONTACTS)
	{
		_contacts[_amount_of_contacts_stored].setFirstName(firstname);
		_contacts[_amount_of_contacts_stored].setLastName(lastname);
		_contacts[_amount_of_contacts_stored].setNickname(nickname);
		_contacts[_amount_of_contacts_stored].setPhonenumber(phonenumber);
		_contacts[_amount_of_contacts_stored].setSecret(secret);
		_amount_of_contacts_stored++;
	}
	else
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++) {
			_contacts[i] = _contacts[i + 1];
		}
		_contacts[MAX_CONTACTS - 1].setFirstName(firstname);
		_contacts[MAX_CONTACTS - 1].setLastName(lastname);
		_contacts[MAX_CONTACTS - 1].setNickname(nickname);
		_contacts[MAX_CONTACTS - 1].setPhonenumber(phonenumber);
		_contacts[MAX_CONTACTS - 1].setSecret(secret);
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
	for (std::size_t i = 0; i < _amount_of_contacts_stored; i++) {
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << cut_string(_contacts[i].getFirstName()) << "|";
		std::cout << cut_string(_contacts[i].getLastName()) << "|";
		std::cout << cut_string(_contacts[i].getNickname()) << "|";
		std::cout << cut_string(_contacts[i].getPhonenumber()) << "|";
		std::cout << std::setw(0);
		std::cout << std::endl;
	}
}
