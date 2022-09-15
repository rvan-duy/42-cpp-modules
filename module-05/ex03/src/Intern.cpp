#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& intern) {
  (void)intern;
}

Intern& Intern::operator=(const Intern& intern) {
  (void)intern;
  return *this;
}

Form* Intern::makeForm(const std::string& name, const std::string& target) {
  std::string arr[3] =
  { std::string("shrubbery creation"),
    std::string("robotomy request"),
    std::string("presidential position") };

  for (std::size_t index = 0; index < 3; index++) {
    if (arr[index] == name) {
      switch (index) {
        case SHRUBBERY_CREATION:
          return new ShrubberyCreationForm(target);
        case ROBOTOMY_REQUEST:
          return new RobotomyRequestForm(target);
        case PRESIDENTIAL_POSITION:
          return new PresidentialPardonForm(target);
      }
    }
  }

  std::cout << "Form doesn't exist" << std::endl;
  return NULL;
}
