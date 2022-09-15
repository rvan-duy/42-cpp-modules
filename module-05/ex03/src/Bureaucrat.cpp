#include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name(name), grade(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name) {
  grade = bureaucrat.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
  if (this != &bureaucrat) {
    grade = bureaucrat.grade;
  }
  return *this;
}

// Getters

const std::string& Bureaucrat::getName() const {
  return name;
}

int Bureaucrat::getGrade() const {
  return grade;
}

// Methods

void Bureaucrat::incrementGrade(const int amount) {
  if (grade - amount > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  if (grade - amount < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  grade -= amount;
}

void Bureaucrat::decrementGrade(const int amount) {
  if (grade + amount > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  if (grade + amount < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  grade += amount;
}

void Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
  } catch (std::exception& exception) {
    std::cout << name << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
    return;
  }
  std::cout << name << " signed " << form.getName() << std::endl;
  return;
}

void Bureaucrat::executeForm(Form const& form) {
  try {
    form.execute(*this);
  } catch (const std::exception& exception) {
    std::cout << name << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
    return;
  }
  std::cout << name << " executed " << form.getName() << std::endl;
  return;
}

// << overload

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
  out << bureaucrat.getName();
  out << ", bureaucrat grade ";
  out << bureaucrat.getGrade();
  return out;
}
