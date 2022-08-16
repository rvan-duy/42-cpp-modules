#ifndef MODULE_05_BUREAUCRAT_HHP
#define MODULE_05_BUREAUCRAT_HHP

#include <exception>
#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
 public:
  Bureaucrat();                                          // Default constructor
  Bureaucrat(const std::string& name, const int grade);  // Constructor with name and grade
  ~Bureaucrat();                                         // Destructor
  Bureaucrat(const Bureaucrat& bureaucrat);              // Copy constructor
  Bureaucrat& operator=(const Bureaucrat& bureaucrat);   // Copy assignment operator

  // Getters
  std::string getName() const;
  int         getGrade() const;

  // Methods
  void incrementGrade(const int amount = 1);
  void decrementGrade(const int amount = 1);
  void signForm(Form& form);

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw() { return "Grade too low"; }
  };

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw() { return "Grade too high"; }
  };

 private:
  const std::string name;
  int               grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif  // MODULE_05_BUREAUCRAT_HPP