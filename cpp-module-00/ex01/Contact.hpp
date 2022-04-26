#ifndef CPP_MODULE_00_CONTACT_H
#define CPP_MODULE_00_CONTACT_H

#include <string>

class Contact {

	public:

		// Default constructor
		Contact();

		// Constructor
		Contact(std::string name);
		
		// Getter
		std::string getName();

	private:
		std::string _name;
};

#endif //CPP_MODULE_00_CONTACT_H
