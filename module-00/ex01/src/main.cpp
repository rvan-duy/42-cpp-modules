#include "PhoneBook.hpp"

int main(void) {
  PhoneBook   phonebook;
  std::string user_input_string;

  std::cout << "Type a command (ADD, SEARCH, EXIT): ";
  while (std::getline(std::cin, user_input_string)) {
    if (user_input_string == "ADD") {
      phonebook.addContact(std::cin);
    } else if (user_input_string == "SEARCH") {
      phonebook.searchContact(std::cin);
    } else if (user_input_string == "EXIT") {
      break;
    }
    std::cout << "Type a command (ADD, SEARCH, EXIT): ";
  }
  return EXIT_SUCCESS;
}
