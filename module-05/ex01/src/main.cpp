#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  
  // TEST 1 - bureaucrat has a high enough grade
  {
    Bureaucrat bureaucrat("Gerrit", 5);
    Form       form("Formulier", 10, 1);

    bureaucrat.signForm(form);
  }

  // TEST 2 - bureaucrat does not have a high enough grade
  {
    Bureaucrat bureaucrat("Gerrit", 20);
    Form       form("Formulier", 10, 1);

    bureaucrat.signForm(form);
  }



  return EXIT_SUCCESS;
};
