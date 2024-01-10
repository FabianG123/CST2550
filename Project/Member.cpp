// Member.cpp
#include "Member.h"
#include <iostream>
#include <chrono>

int Member::lastAssignedID = 100;

// Implementation of the static member function
int Member::generateRandomID() {
    // You can customize the range of random IDs as needed
    return lastAssignedID + 1 + rand() % 1000;
}

void Member::setBooksBorrowed(int _bookID) {
    // Implementation to set books borrowed by a member
    bookID = _bookID;
}

void Member::displayDetails() const {
    std::cout << "Member ID: " << getMemberID() << "\n";
    std::cout << "-------------------------\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Email: " << email << "\n";
    if (borrowedBookID != 0) {
        std::cout << "Borrowed Book ID: " << borrowedBookID << "\n";
    }
    std::cout << "-------------------------\n";
}
