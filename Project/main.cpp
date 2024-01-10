// main.cpp
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>



#include "Person.h"
#include "Book.h" 
#include "Member.h"
#include "Librarian.h"
#include "LibraryFunctions.h"

int main() {
  const int MAX_BOOKS = 300;
  Book books[MAX_BOOKS];
  int numBooks = 0;

  std::string filename;
  std::cout << "Enter the filename: ";
  std::cin >> filename;

  // Check if the filename is valid
  if (filename.empty()) {
    std::cout << "Error: Invalid file. Exiting...\n";
    return 1; // Indicate an error to the calling environment
  }

  // Attempt to read books from the CSV file
  bool fileOpenedSuccessfully =
      readBooksFromCSV(filename, books, numBooks, MAX_BOOKS);

  // Inform the user whether the file was opened successfully
  if (!fileOpenedSuccessfully) {
    std::cout << "Warning: Unable to open the CSV file. The program will "
                 "continue, but book data may not be available.\n";
  }

  Librarian librarian(678, "John Doe", "Library St", "john@example.com", 50000,
                      "librarian", "library123");

  int mainChoice;
  int staffID;
  std::string password;
  bool loggedIn = false;

  do {
    if (!loggedIn) {
      std::cout << "\nLogin as Librarian\n";
      std::cout << "Enter staff ID: ";

      // Verify that the input is a number
      while (!(std::cin >> staffID)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid staff ID: ";
      }

      std::cout << "Enter password: ";
      std::cin >> password;

      if (librarian.validateCredentials(staffID, password)) {
        std::cout << "Login successful!\n";
        loggedIn = true;
      } else {
        std::cout << "Invalid staff ID or password. Please try again.\n";
      }
    } else {
      std::cout << "\nLibrary Management System\n";
      std::cout << "1. Add Member\n";
      std::cout << "2. Display Member\n";
      std::cout << "3. Display Books from: " << filename << "\n";
      std::cout << "4. Exit\n";
      std::cout << "Enter your choice (1-4): ";

      if (std::cin >> mainChoice) {
        switch (mainChoice) {
        case 1: {
          Member newMember;
          librarian.addMember(newMember);
        } break;
        case 2: {
          int memberID;
          std::cout << "Enter Member ID: ";
          std::cin >> memberID;

          Member *existingMember = librarian.findMemberByID(memberID);
          if (existingMember != nullptr) {
            int memberChoice;
            do {
              std::cout << "\nMember Menu [" << existingMember->name << "]\n";
              std::cout << "1. Issue Book\n";
              std::cout << "2. Return Book\n";
              std::cout << "3. Display Borrowed Books\n";
              std::cout << "4. Display Member Details\n";
              std::cout << "5. Back\n";
              std::cout << "Enter your choice (1-5): ";

              if (std::cin >> memberChoice) {
                switch (memberChoice) {
                case 1: {
                  int bookIDToIssue;
                  std::cout << "Enter Book ID to issue: ";
                  std::cin >> bookIDToIssue;

                  std::string bookName =
                      getBookNameByID(bookIDToIssue, books, numBooks);
                  if (!bookName.empty()) {
                    librarian.issueBook(existingMember, bookIDToIssue);

                    // Display details after issuing the book
                    std::cout
                        << "\nThank you for borrowing the book: " << bookName
                        << "\n";
                  } else {
                    std::cout
                        << "Error: Book not found. Book issuance failed.\n";
                  }
                } break;

                case 2:
                  int bookIDToReturn;
                  std::cout << "Enter Book ID to return: ";
                  std::cin >> bookIDToReturn;

                  librarian.returnBook(existingMember, bookIDToReturn);
                  break;

                case 3:
                  librarian.displayBorrowedBooks(existingMember);
                  break;

                case 4:
                  librarian.displayMemberDetails(existingMember);
                  break;

                case 5:
                  std::cout << "Returning to the main menu.\n";
                  break;

                default:
                  std::cout << "Invalid choice. Please enter a number between "
                               "1 and 5.\n";
                  break;
                }
              } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "Invalid input. Please enter a number between 1 "
                             "and 5.\n";
              }

            } while (memberChoice != 5);
          } else {
            std::cout << "Member not found.\n";
          }
        } break;
        case 3: {
          // Read books only when the user chooses to display them
          readBooksFromCSV(filename, books, numBooks, MAX_BOOKS);

          if (numBooks > 0) {
            std::cout << "-------------------------\n";

            // Display all books
            std::cout << "\nDisplaying All Books:\n";
            for (int i = 0; i < numBooks; ++i) {
              std::cout << books[i].getBookID() << ". "
                        << books[i].getBookName() << " by "
                        << books[i].getAuthorFirstName() << " "
                        << books[i].getAuthorLastName() << "\n";
            }
            std::cout << "-------------------------\n";
          } else {
            std::cout << "No books to display.\n";
          }

          std::cout << "\nReturning to the main menu.\n";
        } break;
        case 4:
          std::cout << "Exiting Library Management System. Closing...\n";
          break;

        default:
          std::cout
              << "Invalid choice. Please enter a number between 1 and 4.\n";
          break;
        }
      } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
      }
    }
  } while (mainChoice != 4);

  return 0;
}
