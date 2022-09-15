#ifndef MODULE_05_INTERN_HPP
#define MODULE_05_INTERN_HPP

#include <string>

#include "Form.hpp"

class Intern {
 public:
  Intern();                                 // Default constructor
  ~Intern();                                // Destructor
  Intern(const Intern& intern);             // Copy constructor
  Intern& operator=(const Intern& intern);  // Copy assignment operator

  // Methods
  Form* makeForm(const std::string& name, const std::string& target);

 private:
    enum forms_e {
        SHRUBBERY_CREATION,
        ROBOTOMY_REQUEST,
        PRESIDENTIAL_POSITION
    };
};

#endif  // MODULE_05_INTERN_HPP
