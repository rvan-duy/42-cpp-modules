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

	phonebook.addContact(user_input[0], user_input[1], user_input[2], user_input[3], user_input[4]);
}

// Displays a list of contacts in a list of 4 columns
// Then, prompts the user to select a contact to display
static void execute_search_command(PhoneBook &phonebook)
{
	std::string	user_input_string;
	int 		user_input_index;

	// Print contact list
	phonebook.printContacts();

	// Read user input
	std::cout << "Select the index of a contact to display: ";
	std::getline(std::cin, user_input_string);
	user_input_index = atoi(user_input_string.c_str());

	// Error check input
	if (user_input_index < 0 || (std::size_t) user_input_index >= phonebook.getAmountOfContactsStored())
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}

	// Search for index in the phonebook
	for (std::size_t i = 0; i < phonebook.getAmountOfContactsStored(); i++)
	{
		if (i == (std::size_t) user_input_index)
		{
			std::cout << "Firstname: " << phonebook.getContact(i).getFirstName() << std::endl;
			std::cout << "Lastname: " << phonebook.getContact(i).getLastName() << std::endl;
			std::cout << "Nickname: " << phonebook.getContact(i).getNickname() << std::endl;
			std::cout << "Phone number: " << phonebook.getContact(i).getPhonenumber() << std::endl;
		}
	}

	return;
}

int main(void) {

	PhoneBook	phonebook;
	std::string user_input_string;

	while (true)
	{
		std::cout << "Type a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, user_input_string);
		
		if (user_input_string == "ADD") { execute_add_command(phonebook); }
		if (user_input_string == "SEARCH") { execute_search_command(phonebook); }
		if (user_input_string == "EXIT") { break; }
	}

	return EXIT_SUCCESS;
}
