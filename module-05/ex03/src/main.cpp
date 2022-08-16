#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// TODO: Rework copy constructors

int main(void) {
  {
    Intern     someRandomIntern;
    Form*      rrf;
    Bureaucrat bureaucrat("Ben", 1);
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    
    if (rrf != NULL) {
      bureaucrat.signForm(*rrf);
      bureaucrat.executeForm(*rrf);
    }
  }

  {
    Intern     someRandomIntern;
    Form*      rrf;
    Bureaucrat bureaucrat("Ben", 1);
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

    if (rrf != NULL) {
      bureaucrat.signForm(*rrf);
      bureaucrat.executeForm(*rrf);
    }
  }

  {
    Intern     someRandomIntern;
    Form*      rrf;
    Bureaucrat bureaucrat("Ben", 1);
    rrf = someRandomIntern.makeForm("presidential position", "Bender");

    if (rrf != NULL) {
      bureaucrat.signForm(*rrf);
      bureaucrat.executeForm(*rrf);
    }
  }

  {
    Intern     someRandomIntern;
    Form*      rrf;
    Bureaucrat bureaucrat("Ben", 1);
    rrf = someRandomIntern.makeForm("HOI", "Bender");

    if (rrf != NULL) {
      bureaucrat.signForm(*rrf);
      bureaucrat.executeForm(*rrf);
    }
  }

  return EXIT_SUCCESS;
};
