#ifndef CPP_MODULE_00_CONTACT_H
#define CPP_MODULE_00_CONTACT_H

#include <string>

class Contact {

	private:

		// Internal variables
		std::string _firstname;		// Name of the contact
		std::string	_lastname;		// Lastname of the contact
		std::string _nickname;		// Nickname of the contact
		std::string _phonenumber;	// Phone number of the contact
		std::string _secret;		// Secret of the contact

	public:

		// Default constructor
		Contact();
		
		// Getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhonenumber();

		// Setters
		void setFirstName(std::string firstname);
		void setLastName(std::string lastname);
		void setNickname(std::string nickname);
		void setPhonenumber(std::string phonenumber);
		void setSecret(std::string secret);

};

#endif //CPP_MODULE_00_CONTACT_H
