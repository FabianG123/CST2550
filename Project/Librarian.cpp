// Librarian.cpp
#include "Librarian.h"


// Implementing member functions of Librarian and Member classes
void Librarian::addMember(Member &member) {
  // Implementation to add a member
  std::cout << "Enter member details:\n";
  std::cout << "Name: ";
  std::cin >> member.name;
  std::cout << "Address: ";
  std::cin >> member.address;
  std::cout << "Email: ";
  std::cin >> member.email;
  members.push_back(member);
  std::cout << "\n-------------------------\n";
  std::cout << "Member added:\n";
  displayMemberDetails(&member); // Pass the address of the member
}

Member *Librarian::findMemberByID(int memberID) {
  // Find the member with the specified ID in the vector
  for (auto &member : members) {
    if (member.getMemberID() == memberID) {
      return &member;
    }
  }
  return nullptr; // Member not found
}

// Function to issue a book to an individual member
void Librarian::issueBook(Member *member, int bookID) {
  if (member != nullptr) {
    // Set the issue timestamp to the current time
    issueTimestamp = std::chrono::system_clock::now();
    std::cout << "Book issued to " << member->name;
    // Set the book as borrowed by the member
    member->setBooksBorrowed(bookID);
  } else {
    std::cout << "Invalid member.\n";
  }
}

// Function to return a book from an individual member
void Librarian::returnBook(Member *member, int bookID) {
  if (member != nullptr) {
    if (member->bookID == bookID) {
      // Get the current time
      auto returnTimestamp = std::chrono::system_clock::now();
      // Calculated the difference in seconds between issue and return
      // timestamps
      auto timeDifference = std::chrono::duration_cast<std::chrono::seconds>(
          returnTimestamp - issueTimestamp);

      // Simulated 3 days as 180 seconds for testing
      // Value changes based on simulation, going to use 3 minutes as 3 days
      if (timeDifference.count() >= 180) {
        // Calculated fine in minutes
        int fineMinutes = (timeDifference.count() - 180) / 60; // £1 per minute
        int fineAmount = fineMinutes * 1;                      // £1 per minute

        std::cout << "Book returned after 3 days. Fine: £" << fineAmount
                  << "\n";
      } else {
        std::cout << "Book returned within 3 days. No fine.\n";
        std::cout << "Thank you for returning the book within 3 days!\n";
      }

      // Display the duration since borrowing the book
      std::cout << "Time since borrowing: "
                << timeDifference.count() / (60 * 60 * 24) << " days\n";

      member->setBooksBorrowed(0);
      std::cout << "Book returned by " << member->name << "\n";
    } else {
      std::cout << "You haven't borrowed the book with ID: " << bookID << "\n";
    }
  } else {
    std::cout << "Invalid member.\n";
  }
  std::cout << "\n-------------------------\n\n\n";
}

void Librarian::displayBorrowedBooks(const Member *member) {
  // Implementation to display all books borrowed by an individual member
  if (member != nullptr) {
    std::cout << "Displaying books borrowed by " << member->name << ":\n";
    if (member->bookID != 0) {
      // Book details can be retrieved by bookID
      std::cout << "Book ID: " << member->bookID << "\n";
    } else {
      std::cout << "No books borrowed by the member.\n";
    }
  } else {
    std::cout << "Invalid member.\n";
  }
}

// Helper function to display member details
void Librarian::displayMemberDetails(const Member *member) const {
  if (member != nullptr) {
    std::cout << "\nMember ID: " << member->getMemberID();
    std::cout << "\n-------------------------\n\n\n";
    std::cout << "\n-------------------------\n";
    std::cout << "Name: " << member->name << "\n";
    std::cout << "Address: " << member->address << "\n";
    std::cout << "Email: " << member->email << "\n";
    std::cout << "-------------------------\n\n";
  } else {
    std::cout << "Invalid member.\n";
  }
}

bool Librarian::validateCredentials(int providedStaffID, const std::string &providedPassword) {
    return (providedStaffID == staffID && providedPassword == password);
}

