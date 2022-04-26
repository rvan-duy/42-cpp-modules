#include "PhoneBook.hpp"

int main() {

	PhoneBook   book;
    Contact     new_contact1("John");
	Contact     new_contact2("Jane");
	Contact     new_contact3("Jack");
	Contact     new_contact4("Jill");
	Contact     new_contact5("Joe");
	Contact     new_contact6("Jenny");
	Contact     new_contact7("Jules");
	Contact     new_contact8("Julia");
	Contact		new_contact9("Julie");
	Contact		new_contact10("Julius");


	book.addContact(new_contact1);
	book.addContact(new_contact2);
	book.addContact(new_contact3);
	book.addContact(new_contact4);
	book.addContact(new_contact5);
	book.addContact(new_contact6);
	book.addContact(new_contact7);
	book.addContact(new_contact8);
	book.printContacts();
	
	std::cout << "----------------------------" << std::endl;
	book.addContact(new_contact9);
	book.printContacts();

	std::cout << "----------------------------" << std::endl;
	book.addContact(new_contact10);
	book.printContacts();

	return EXIT_SUCCESS;
}
