#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150){};
Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name(name), grade(grade){};
Bureaucrat::~Bureaucrat(){};
Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade){};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
  grade = bureaucrat.grade;
  return *this;
};

// Getters

const std::string Bureaucrat::getName() const { return name; };
int               Bureaucrat::getGrade() const { return grade; };

// Methods

void Bureaucrat::incrementGrade(const int amount) {
  if (grade - amount > 150) throw Bureaucrat::GradeTooLowException();
  if (grade - amount < 1) throw Bureaucrat::GradeTooHighException();
  grade -= amount;
};

void Bureaucrat::decrementGrade(const int amount) {
  if (grade + amount > 150) throw Bureaucrat::GradeTooLowException();
  if (grade + amount < 1) throw Bureaucrat::GradeTooHighException();
  grade += amount;
};

// << overload

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName();
  out << ", bureaucrat grade ";
  out << bureaucrat.getGrade();
  return out;
};
