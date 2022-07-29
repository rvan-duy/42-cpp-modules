#ifndef MODULE_00_CONTACT_HPP
#define MODULE_00_CONTACT_HPP

#include <string>

class Contact {
 public:
  // Default constructor
  Contact();

  // Getters
  std::string getFirstName();
  std::string getLastName();
  std::string getNickname();
  std::string getPhonenumber();

  // Setters
  void setFirstName(const std::string firstname);
  void setLastName(const std::string lastname);
  void setNickname(const std::string nickname);
  void setPhonenumber(const std::string phonenumber);
  void setSecret(const std::string secret);

 private:
  // Internal variables
  std::string firstname;    // Name of the contact
  std::string lastname;     // Lastname of the contact
  std::string nickname;     // Nickname of the contact
  std::string phonenumber;  // Phone number of the contact
  std::string secret;       // Secret of the contact
};

#endif  // MODULE_00_CONTACT_HPP
