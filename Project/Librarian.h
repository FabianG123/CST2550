// Librarian.h
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <vector>
#include <iostream>
#include <chrono>
#include "Member.h"

class Librarian {
private:
  int staffID;
  int salary;
  std::vector<Member> members;
  std::string username;
  std::string password;
  std::chrono::system_clock::time_point issueTimestamp;

public:
    // Additional attributes
  std::string name;
  std::string address;
  std::string email;
  int memberID;

  // Constructor with username and password
  Librarian(int _staffID, const std::string &_name, const std::string &_address,
            const std::string &_email, int _salary,
            const std::string &_username, const std::string &_password)
      : staffID(_staffID), salary(_salary), username(_username),
        password(_password), name(_name), address(_address), email(_email) {}

  // Member functions
  void addMember(Member &member);
  // Function to issue a book to an individual member
  void issueBook(Member *member, int bookID);
  // Function to return a book from an individual member
  void returnBook(Member *member, int bookID);
  void displayBorrowedBooks(const Member *member);
  void displayMemberDetails(const Member *member) const;

  // Function to add a member to the vector
  void addMember(const Member &member);
  // Function to find a member by ID in the vector
  Member *findMemberByID(int memberID);

  // Getter and Setter for staffID
  int getStaffID() const { return staffID; }

  void setStaffID(int _staffID) { staffID = _staffID; }

  // Getter and Setter for salary
  int getSalary() const { return salary; }

  void setSalary(int _salary) { salary = _salary; }

  // Function to check if provided credentials are correct
  bool validateCredentials(int providedStaffID, const std::string &providedPassword);

};

#endif // LIBRARIAN_H
