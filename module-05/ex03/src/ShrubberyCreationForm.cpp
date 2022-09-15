#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form::Form("ShrubberyCreationForm", 145, 137), target(target + "_shrubbery") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : Form(form) {
  target = form.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
  if (this != &form) {
    Form::operator=(form);
    target = form.target;
  }
  return *this;
}

// Methods

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  beExecuted(executor);  // throws exception if form cannot be executed
  std::ofstream ofs(target.c_str(), std::ofstream::out);
  ofs << "                      ___" << std::endl
      << "                _,-'\"\"   \"\"\"\"`--." << std::endl
      << "             ,-'          __,,-- \\" << std::endl
      << "           ,'    __,--\"\"\"\"dF   .  )" << std::endl
      << "          /   .-\"Hb_,--\"\"dF   .  /" << std::endl
      << "        ,'       _Hb ___dF\"-._,-'" << std::endl
      << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl
      << "     (     ,-'                . `." << std::endl
      << "      `._,'     _   _        .    ;" << std::endl
      << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl
      << "       \\    ,'\"Hb.-'HH`-.dHF\"" << std::endl
      << "        `--'   \"Hb  HH  dF\"" << std::endl
      << "                \"Hb HH dF" << std::endl
      << "                 \"HbHHdF" << std::endl
      << "                  |HHHF" << std::endl
      << "                  |HHH|" << std::endl
      << "                  |HHH|" << std::endl
      << "                  |HHH|" << std::endl
      << "                  |HHH|" << std::endl
      << "                  dHHHb" << std::endl
      << "                .dFd|bHb.               o" << std::endl
      << "      o       .dHFdH|HbTHb.          o /" << std::endl
      << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__ |   Y" << std::endl
      << "##########################################" << std::endl;
  ofs.close();
}
