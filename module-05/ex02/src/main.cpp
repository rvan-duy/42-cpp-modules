#include <cstdlib>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
  std::cout << "TEST 1 - bureaucrat has a high enough grade to sign and execute ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 1);
    ShrubberyCreationForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 2 - bureaucrat has a high enough grade to sign but not execute ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 140);
    ShrubberyCreationForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 3 - bureaucrat does not have an high enough grade to execute nor sign ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 149);
    ShrubberyCreationForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 4 - bureaucrat does not sign form and cannot execute ShrubberyCreationForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 149);
    ShrubberyCreationForm form("form");

    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 5 - bureaucrat has a high enough grade to sign and execute RobotomyRequestForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 1);
    RobotomyRequestForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 6 - bureaucrat has a high enough grade to sign but not execute RobotomyRequestForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 70);
    RobotomyRequestForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 7 - bureaucrat does not have an high enough grade to execute nor sign RobotomyRequestForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 149);
    RobotomyRequestForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 8 - bureaucrat has a high enough grade to sign and execute PresidentialPardonForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 1);
    PresidentialPardonForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 9 - bureaucrat has a high enough grade to sign but not execute PresidentialPardonForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 10);
    PresidentialPardonForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  std::cout << "TEST 10 - bureaucrat does not have an high enough grade to execute nor sign PresidentialPardonForm" << std::endl;
  {
    Bureaucrat bureaucrat("Gerrit", 149);
    PresidentialPardonForm form("form");

    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
