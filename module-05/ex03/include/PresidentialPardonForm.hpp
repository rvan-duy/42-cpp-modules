#ifndef MODULE_05_PRESIDENTIALPARDONFORM_HPP
#define MODULE_05_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm(const std::string& target);                      // Constructor with target
  ~PresidentialPardonForm();                                              // Destructor
  PresidentialPardonForm(const PresidentialPardonForm& form);             // Copy constructor
  PresidentialPardonForm& operator=(const PresidentialPardonForm& form);  // Copy assignment operator

  // Methods
  void execute(Bureaucrat const& executor) const;

 private:
  std::string target;

  PresidentialPardonForm();  // Default constructor
};

#endif  // MODULE_05_PRESIDENTIALPARDONFORM_HPP
