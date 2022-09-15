#ifndef MODULE_05_SHRUBBERYCREATIONFORM_HPP
#define MODULE_05_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm(const std::string& target);                     // Constructor with target
  ~ShrubberyCreationForm();                                             // Destructor
  ShrubberyCreationForm(const ShrubberyCreationForm& form);             // Copy constructor
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);  // Copy assignment operator

  // Methods
  void execute(Bureaucrat const& executor) const;

 private:
  std::string target;

  ShrubberyCreationForm();  // Default constructor
};

#endif  // MODULE_05_SHRUBBERYCREATIONFORM_HPP
