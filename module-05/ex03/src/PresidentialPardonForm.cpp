#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : Form(form) { *this = form; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
  if (this == &form) return *this;
  form_signed = form.form_signed;
  target      = form.target;
  return *this;
}

// Methods

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  beExecuted(executor);  // throws exception if form cannot be executed
  std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
