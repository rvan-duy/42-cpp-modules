#include <cstdlib>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// TODO: Rework copy constructors
//        Add more tests with bureaucrats

int main(void) {
  {
    Intern someRandomIntern;
    Form*  rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    Bureaucrat bureaucrat("z", 1);

    rrf->execute(bureaucrat);

  }

  return EXIT_SUCCESS;
};
