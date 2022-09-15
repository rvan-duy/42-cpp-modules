#include "Form.hpp"

Form::Form() : name(""), form_signed(false), grade_required_to_sign(10), grade_required_to_execute(1) {}

Form::Form(const std::string& name, const int grade_required_to_sign, const int grade_required_to_execute)
    : name(name),
      form_signed(false),
      grade_required_to_sign(grade_required_to_sign),
      grade_required_to_execute(grade_required_to_execute) {}

Form::~Form() {}

Form::Form(const Form& form)
    : name(form.name),
      grade_required_to_sign(form.grade_required_to_sign),
      grade_required_to_execute(form.grade_required_to_execute) {
  form_signed = form.form_signed;
}

Form& Form::operator=(const Form& form) {
  if (this != &form) {
    form_signed = form.form_signed;
  }
  return *this;
}

// Getters

const std::string& Form::getName() const {
  return name;
}

bool Form::getFormSigned() const {
  return form_signed;
}

int Form::getGradeRequiredToSign() const {
  return grade_required_to_sign;
}

int Form::getGradeRequiredToExecute() const {
  return grade_required_to_execute;
}

// Methods

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > grade_required_to_sign) {
    throw Form::GradeTooLowException();
  }
  form_signed = true;
  return;
}

// << overload

std::ostream& operator<<(std::ostream& out, const Form& form) {
  out << std::boolalpha;
  out << "form: (name:" << form.getName() << " ";
  out << "signed:" << form.getFormSigned() << " ";
  out << "grade_required_to_sign:" << form.getGradeRequiredToSign() << " ";
  out << "grade_required_to_execute:" << form.getGradeRequiredToExecute();
  out << ")" << std::endl;
  return out;
}
