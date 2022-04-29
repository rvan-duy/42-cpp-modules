#include "PhoneBook.hpp"

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
		
		if (user_input_string == "ADD") { phonebook.addContact(std::cin); }
		if (user_input_string == "SEARCH") { execute_search_command(phonebook); }
		if (user_input_string == "EXIT") { break; }
	}

	return EXIT_SUCCESS;
}
