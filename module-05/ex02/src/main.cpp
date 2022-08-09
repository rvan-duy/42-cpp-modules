#include <cstdlib>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

  std::cout << "TEST 1 - bureaucrat has a high enough grade to sign and execute ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 1);
    ShrubberyCreationForm form("form");

    try {
      bureaucrat.signForm(form);
      form.execute(bureaucrat);
    } catch (const std::exception& exception) {
      std::cout << bureaucrat.getName() << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
    }
  }

  std::cout << "TEST 2 - bureaucrat has a high enough grade to sign but not execute ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 140);
    ShrubberyCreationForm form("form");

    try {
      bureaucrat.signForm(form);
      form.execute(bureaucrat);
    } catch (const std::exception& exception) {
      std::cout << bureaucrat.getName() << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
    }
  }

  std::cout << "TEST 3 - bureaucrat does not have an high enough grade to execute nor sign ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 149);
    ShrubberyCreationForm form("form");

    try {
      bureaucrat.signForm(form);
      form.execute(bureaucrat);
    } catch (const std::exception& exception) {
      std::cout << bureaucrat.getName() << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
    }
  }

  return EXIT_SUCCESS;
};
