#include "PhoneBook.hpp"

// Default constructor
PhoneBook::PhoneBook() : _amount_of_contacts_stored(0) { }

// Getters
std::size_t PhoneBook::getAmountOfContactsStored() { return this->_amount_of_contacts_stored; }
Contact		PhoneBook::getContact(const std::size_t index) { return this->_contacts[index]; }

// Methods
void 		PhoneBook::addContact(std::istream &istream)
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
	std::getline(istream, user_input[FIRSTNAME]);
	std::cout << "Lastname: ";
	std::getline(istream, user_input[LASTNAME]);
	std::cout << "Nickname: ";
	std::getline(istream, user_input[NICKNAME]);
	std::cout << "Phone number: ";
	std::getline(istream, user_input[PHONENUMBER]);
	std::cout << "Secret: ";
	std::getline(istream, user_input[SECRET]);

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
void		PhoneBook::searchContact(std::istream &istream)
{
	std::string user_input;
	int			user_input_index;

	// Print contact list
	_printContacts();

	// Read user input
	std::cout << "Select the index of a contact to display: ";
	std::getline(istream, user_input);
	user_input_index = atoi(user_input.c_str());

	// Error handling
	if (user_input_index < 0 || (std::size_t) user_input_index >= _amount_of_contacts_stored)
	{
		std::cout << "Error: Invalid index" << std::endl;
		return ;
	}

	// Display contact
	for (std::size_t i = 0; i < getAmountOfContactsStored(); i++)
	{
		if (i == (std::size_t) user_input_index)
		{
			std::cout << "Firstname: " << getContact(i).getFirstName() << std::endl;
			std::cout << "Lastname: " << getContact(i).getLastName() << std::endl;
			std::cout << "Nickname: " << getContact(i).getNickname() << std::endl;
			std::cout << "Phone number: " << getContact(i).getPhonenumber() << std::endl;
		}
	}

}

// Internal methods
std::string	PhoneBook::_cutString(const std::string str)
{
	const std::size_t	str_size = str.size();
	std::string 		new_str = str.substr(0, 10);
	
	if (str_size > 10)
		new_str[9] = '.';
	
	return new_str;
}
void 		PhoneBook::_printContacts(void)
{
	for (std::size_t i = 0; i < _amount_of_contacts_stored; i++) {
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		std::cout << _cutString(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10);
		std::cout << _cutString(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10);
		std::cout << _cutString(_contacts[i].getNickname()) << "|";
		std::cout << std::setw(10);
		std::cout << _cutString(_contacts[i].getPhonenumber()) << "|";
		std::cout << std::endl;
	}
}
