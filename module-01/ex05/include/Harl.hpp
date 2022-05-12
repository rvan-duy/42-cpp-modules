#ifndef MODULE_01_HARL_HPP
#define MODULE_01_HARL_HPP

#include <iostream>
#include <string>

class Harl {
 public:
  typedef void (Harl::*complainFunctions)() const;

  Harl();
  ~Harl();

  void complain(std::string& level);

 private:
  complainFunctions functions[4];

  void              debug() const;
  void              info() const;
  void              warning() const;
  void              error() const;
};

#endif  // MODULE_01_HARL_HPP
