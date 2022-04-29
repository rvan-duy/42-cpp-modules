#include "PhoneBook.hpp"

// Getters
std::size_t PhoneBook::getAmountOfContactsStored() { return this->_amount_of_contacts_stored; }
Contact		PhoneBook::getContact(std::size_t index) { return this->_contacts[index]; }

// Methods
void 		PhoneBook::addContact(std::__1::istream &iostream)
{
	enum E_ADD_CONTACT_FIELD {
		FIRSTNAME,
		LASTNAME,
		NICKNAME,
		PHONENUMBER,
		SECRET
	};

	std::string user_input[5]; // Temporary array to store user input

	// Getting user input
	std::cout << "Firstname: ";
	std::getline(iostream, user_input[FIRSTNAME]);
	std::cout << "Lastname: ";
	std::getline(iostream, user_input[LASTNAME]);
	std::cout << "Nickname: ";
	std::getline(iostream, user_input[NICKNAME]);
	std::cout << "Phone number: ";
	std::getline(iostream, user_input[PHONENUMBER]);
	std::cout << "Secret: ";
	std::getline(iostream, user_input[SECRET]);

	// Adding contact to the phonebook
	if (_amount_of_contacts_stored < MAX_CONTACTS)
	{
		_contacts[_amount_of_contacts_stored].setFirstName(user_input[FIRSTNAME]);
		_contacts[_amount_of_contacts_stored].setLastName(user_input[LASTNAME]);
		_contacts[_amount_of_contacts_stored].setNickname(user_input[NICKNAME]);
		_contacts[_amount_of_contacts_stored].setPhonenumber(user_input[PHONENUMBER]);
		_contacts[_amount_of_contacts_stored].setSecret(user_input[SECRET]);
		_amount_of_contacts_stored++;
	}
	else
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++) {
			_contacts[i] = _contacts[i + 1];
		}
		_contacts[MAX_CONTACTS - 1].setFirstName(user_input[FIRSTNAME]);
		_contacts[MAX_CONTACTS - 1].setLastName(user_input[LASTNAME]);
		_contacts[MAX_CONTACTS - 1].setNickname(user_input[NICKNAME]);
		_contacts[MAX_CONTACTS - 1].setPhonenumber(user_input[PHONENUMBER]);
		_contacts[MAX_CONTACTS - 1].setSecret(user_input[SECRET]);
	}

}
void 		PhoneBook::printContacts(void) {
	for (std::size_t i = 0; i < _amount_of_contacts_stored; i++) {
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << _cut_string(_contacts[i].getFirstName()) << "|";
		std::cout << _cut_string(_contacts[i].getLastName()) << "|";
		std::cout << _cut_string(_contacts[i].getNickname()) << "|";
		std::cout << _cut_string(_contacts[i].getPhonenumber()) << "|";
		std::cout << std::setw(0);
		std::cout << std::endl;
	}
}

// Internal methods
std::string	PhoneBook::_cut_string(std::string str)
{
	const std::size_t	str_size = str.size();
	std::string 		new_str = str.substr(0, 10);
	
	if (str_size > 10)
		new_str[9] = '.';
	
	return new_str;
}
