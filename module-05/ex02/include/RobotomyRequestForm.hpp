#ifndef MODULE_05_ROBOTOMYREQUESTFORM_HPP
#define MODULE_05_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm(const std::string& target);                   // Constructor with target
  ~RobotomyRequestForm();                                           // Destructor
  RobotomyRequestForm(const RobotomyRequestForm& form);             // Copy constructor
  RobotomyRequestForm& operator=(const RobotomyRequestForm& form);  // Copy assignment operator

  // Methods
  void execute(Bureaucrat const& executor) const;

 private:
  std::string target;

  RobotomyRequestForm();  // Default constructor
};

#endif  // MODULE_05_ROBOTOMYREQUESTFORM_HPP
