#include "RobotomyRequestForm.hpp"

#include <cstdlib>  // srand rand

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : Form(form) {
  target = form.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
  if (this != &form) {
    Form::operator=(form);
    target = form.target;
  }
  return *this;
}

// Methods

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  beExecuted(executor);  // throws exception if form cannot be executed

  // generate seed and a random number (0 or 1)
  std::cout << "* drilling noises *" << std::endl;
  std::srand(time(0));
  int random_number = std::rand() % 2;

  if (random_number == 0)
    std::cout << target << " has been robotomized!" << std::endl;
  else
    std::cout << "Robotomy has failed.." << std::endl;
}
