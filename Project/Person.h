// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
  std::string name;
  std::string address;
  std::string email;

public:
    // Getter methods
  std::string getName() const { return name; }

  std::string getAddress() const { return address; }

  std::string getEmail() const { return email; }

  // Setter methods
  void setName(const std::string &_name) { name = _name; }

  void setAddress(const std::string &_address) { address = _address; }

  void setEmail(const std::string &_email) { email = _email; }
};

#endif // PERSON_H
