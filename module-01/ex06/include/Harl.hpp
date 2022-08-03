#ifndef MODULE_01_HARL_HPP
#define MODULE_01_HARL_HPP

#include <iostream>
#include <string>

class Harl {
 public:
  Harl();
  ~Harl();

  void complain(const std::string& input) const;

 private:
  std::string levels[4];

  void        debug() const;
  void        info() const;
  void        warning() const;
  void        error() const;
  std::size_t findIndexOfInput(const std::string& input) const;
};

#endif  // MODULE_01_HARL_HPP
