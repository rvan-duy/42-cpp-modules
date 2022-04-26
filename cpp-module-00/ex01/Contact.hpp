#ifndef CPP_MODULE_00_CONTACT_H
#define CPP_MODULE_00_CONTACT_H

#include <string>

class Contact {

	private:
		std::string _firstname;		// Name of the contact
		std::string	_lastname;		// Lastname of the contact
		std::string _nickname;		// Nickname of the contact
		std::string _phonenumber;	// Phone number of the contact
		std::string _secret;		// Secret of the contact

	public:

		// Default constructor
		Contact();

		// Constructor
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret);
		
		// Getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhonenumber();
		std::string getSecret();

};

#endif //CPP_MODULE_00_CONTACT_H
