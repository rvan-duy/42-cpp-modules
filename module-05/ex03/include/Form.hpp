#ifndef MODULE_05_FORM_HPP
#define MODULE_05_FORM_HPP

#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
  Form();  // Default constructor
  Form(const std::string& name, const int grade_required_to_sign,
       const int grade_required_to_execute);  // Constructor with variables
  ~Form();                                    // Destructor
  Form(const Form& form);                     // Copy constructor
  Form& operator=(const Form& form);          // Copy assignment operator

  // Getters
  const std::string& getName() const;
  bool               getFormSigned() const;
  int                getGradeRequiredToSign() const;
  int                getGradeRequiredToExecute() const;

  // Methods
  void         beSigned(const Bureaucrat& bureaucrat);
  void         beExecuted(const Bureaucrat& bureaucrat) const;
  virtual void execute(Bureaucrat const& executor) const = 0;  // pure virtual
  //                                ^ is the same as const Bureaucrat const &

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw() { return "grade is too low"; }
  };

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw() { return "grade is too high"; }
  };

  class FormNotSignedException : public std::exception {
   public:
    const char* what() const throw() { return "form is not signed"; }
  };

 protected:
  const std::string name;
  bool              form_signed;
  const int         grade_required_to_sign;
  const int         grade_required_to_execute;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif  // MODULE_05_FORM_HPP
