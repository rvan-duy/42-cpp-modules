#include "PhoneBook.hpp"

int main(void) {

	PhoneBook	phonebook;
	std::string user_input_string;

	while (true)
	{
		std::cout << "Type a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, user_input_string);
		
		if (user_input_string == "ADD") { phonebook.addContact(std::cin); }
		if (user_input_string == "SEARCH") { phonebook.searchContact(std::cin); }
		if (user_input_string == "EXIT") { break; }
	}

	return EXIT_SUCCESS;
}
