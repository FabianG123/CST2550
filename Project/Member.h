// Member.h
#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <chrono>

class Member {
private:
  static int lastAssignedID;
  int memberID;
  std::chrono::system_clock::time_point lastIssueTimestamp;

public:
  // Additional attributes
  std::string name;
  std::string address;
  std::string email;
  int bookID;
  int borrowedBookID; // Store the ID of the borrowed book
  std::chrono::system_clock::time_point issueTimestamp; // Store issue timestamp

  // Constructor for manual creation
  Member(const std::string &_name, const std::string &_address,
         const std::string &_email)
      : memberID(generateRandomID()), name(_name), address(_address),
        email(_email), bookID(0), borrowedBookID(0) {}

  // Constructor for random creation
  Member() : memberID(generateRandomID()), bookID(0), borrowedBookID(0) {}

  // Member functions
  int getMemberID() const { return memberID; }

  void setBooksBorrowed(int _bookID);
  void displayDetails() const;

  void setLastIssueTimestamp() {
    lastIssueTimestamp = std::chrono::system_clock::now();
  }

private:
  // Function to generate a random ID
  static int generateRandomID();
};

#endif // MEMBER_H
