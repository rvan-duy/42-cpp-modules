#include "PhoneBook.hpp"

static void execute_add_command(PhoneBook &phonebook)
{
	std::string user_input[5];

	std::cout << "Adding a user to the phonebook" << std::endl;
	std::cout << "Firstname: ";
	std::getline(std::cin, user_input[0]);
	std::cout << "Lastname: ";
	std::getline(std::cin, user_input[1]);
	std::cout << "Nickname: ";
	std::getline(std::cin, user_input[2]);
	std::cout << "Phone number: ";
	std::getline(std::cin, user_input[3]);
	std::cout << "Secret: ";
	std::getline(std::cin, user_input[4]);

	phonebook.addContact(Contact(user_input[0], user_input[1], user_input[2], user_input[3], user_input[4]));
}

static void execute_search_command(PhoneBook &phonebook)
{
	phonebook.printContacts();
}

int main(void) {

	PhoneBook	phonebook;
	std::string user_input;

	while (true)
	{
		std::cout << "Type a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, user_input);
		
		if (user_input == "ADD") { execute_add_command(phonebook); }
		if (user_input == "SEARCH") { execute_search_command(phonebook); }
		if (user_input == "EXIT") { break; }
	}

	return EXIT_SUCCESS;
}
