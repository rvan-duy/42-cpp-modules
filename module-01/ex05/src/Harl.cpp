#include "Harl.hpp"

Harl::Harl() {
  functions[0] = &Harl::debug;
  functions[1] = &Harl::info;
  functions[2] = &Harl::warning;
  functions[3] = &Harl::error;
};
Harl::~Harl(){};

void Harl::complain(std::string& level) {
  const static std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
      if (level == levels[i])
        (this->*functions[i])();
  }
}

void Harl::debug() const {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
            << std::endl;
}
void Harl::info() const {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you "
               "did, I wouldn’t be asking for more!"
            << std::endl;
}
void Harl::warning() const {
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
               "working here since last month."
            << std::endl;
}
void Harl::error() const { std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; }
