#include <cstdlib>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  {
    Intern someRandomIntern;
    Form*  rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  }

  return EXIT_SUCCESS;
};
