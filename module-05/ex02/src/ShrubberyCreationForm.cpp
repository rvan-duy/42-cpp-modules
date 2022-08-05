#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form::Form("ShrubberyCreationForm", 145, 137), target(target + "_shrubbery"){};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
    : Form::Form(form), target(form.target){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
  form_signed = form.form_signed;
  target      = form.target;
  return *this;
};

// Methods

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  beExecuted(executor);  // throws exception if form cannot be executed
  std::ofstream ofs(target.c_str(), std::ofstream::out);
  ofs << R"(                      ___
                _,-'""   """"`--.
             ,-'          __,,-- \
           ,'    __,--""""dF      )
          /   .-"Hb_,--""dF      /
        ,'       _Hb ___dF"-._,-'
      ,'      _,-""""   ""--..__
     (     ,-'                  `.
      `._,'     _   _             ;
       ,'     ,' `-'Hb-.___..._,-'
       \    ,'"Hb.-'HH`-.dHF"
        `--'   "Hb  HH  dF"
                "Hb HH dF
                 "HbHHdF
                  |HHHF
                  |HHH|
                  |HHH|
                  |HHH|
                  |HHH|
                  dHHHb
                .dFd|bHb.               o
      o       .dHFdH|HbTHb.          o /
\  Y  |  \__,dHHFdHH|HHhoHHb.__Krogg  Y
##########################################)"
      << std::endl;
  ofs.close();
};
