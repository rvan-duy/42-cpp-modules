#include "Harl.hpp"

Harl::Harl() {
  functions[0] = &Harl::debug;
  functions[1] = &Harl::info;
  functions[2] = &Harl::warning;
  functions[3] = &Harl::error;
  levels[0]    = "DEBUG";
  levels[1]    = "INFO";
  levels[2]    = "WARNING";
  levels[3]    = "ERROR";
};
Harl::~Harl(){};

bool Harl::checkValidInput(const std::string& input, int& argc) const {
  if (argc == 2) {
    for (int i = 0; i < 4; i++) {
      if (input == levels[i]) return true;
    }
  }
  return false;
};
void Harl::complain(const std::string& input) const {
  for (int i = findIndexOfInput(input); i < 4; i++) {
    (this->*functions[i])();
    std::cout << std::endl;
  }
}

void Harl::debug() const {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
            << std::endl;
}
void Harl::info() const {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you "
               "did, I wouldn’t be asking for more!"
            << std::endl;
}
void Harl::warning() const {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
               "working here since last month."
            << std::endl;
}
void Harl::error() const { 
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; }
std::size_t Harl::findIndexOfInput(const std::string& input) const {
  for (int i = 0; i < 4; i++) {
    if (input == levels[i]) return i;
  }
  return 0;
};