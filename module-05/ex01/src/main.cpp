#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  // TEST 1 - bureaucrat has a high enough grade
  {
    Bureaucrat bureaucrat("Gerrit", 5);
    Form       form("Formulier", 10, 1);

    std::cout << form;
    bureaucrat.signForm(form);
    std::cout << form;
  }

  std::cout << std::endl;

  // TEST 2 - bureaucrat does not have a high enough grade
  {
    Bureaucrat bureaucrat("Gerrit", 20);
    Form       form("Formulier", 10, 1);

    std::cout << form;
    bureaucrat.signForm(form);
    std::cout << form;
  }

  return EXIT_SUCCESS;
}
