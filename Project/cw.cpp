#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

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

class Member;

class Librarian {
private:
  int staffID;
  int salary;
  std::vector<Member> members;
  std::string username;                                 // Added username
  std::string password;                                 // Added password
  std::chrono::system_clock::time_point issueTimestamp; // Added timestamp

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
  bool validateCredentials(int providedStaffID,
                           const std::string &providedPassword) const {
    return (providedStaffID == staffID && providedPassword == password);
  }
};

class Member {
private:
  static int
      lastAssignedID; // Static variable to keep track of the last assigned ID
  int memberID;
  std::chrono::system_clock::time_point lastIssueTimestamp; // Added timestamp

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
  static int generateRandomID() {
    // You can customize the range of random IDs as needed
    return lastAssignedID + 1 + rand() % 1000;
  }
};

int Member::lastAssignedID = 100;

class Book {
private:
  int bookID;
  std::string bookName;
  int pageCount;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;

public:
  Book() = default; // Default constructor
  Book(int _bookID, const std::string &_bookName, int _pageCount,
       const std::string &_authorFirstName, const std::string &_authorLastName,
       const std::string &_bookType)
      : bookID(_bookID), bookName(_bookName), pageCount(_pageCount),
        authorFirstName(_authorFirstName), authorLastName(_authorLastName),
        bookType(_bookType) {}

  int getBookID() const { return bookID; }

  std::string getBookName() const { return bookName; }

  int getPageCount() const { return pageCount; }

  std::string getAuthorFirstName() const { return authorFirstName; }

  std::string getAuthorLastName() const { return authorLastName; }

  std::string getBookType() const { return bookType; }
};

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

// Function to read books from a CSV file
bool readBooksFromCSV(const std::string &filename, Book books[], int &numBooks,
                      const int MAX_BOOKS) {
  std::ifstream file(filename);
  if (file.is_open()) {
    int count = 0; // Variable to count the number of books read
    std::string line;

    // Discard the header line
    std::getline(file, line);

    while (file.good() && numBooks < MAX_BOOKS && count < 300 &&
           std::getline(file, line)) {
      std::stringstream ss(line);

      int bookID;
      std::string bookName;
      int pageCount;
      std::string authorFirstName;
      std::string authorLastName;
      std::string bookType;

      char comma; // to read and discard the commas
      ss >> bookID >> comma;

      // Use std::getline to read strings with spaces
      std::getline(ss, bookName, ',');
      ss >> pageCount >> comma;
      std::getline(ss, authorFirstName, ',');
      std::getline(ss, authorLastName, ',');
      std::getline(ss, bookType, ',');

      // Debug output
      std::cout << "Read from file: " << bookID << ", " << bookName << ", "
                << pageCount << ", " << authorFirstName << ", "
                << authorLastName << ", " << bookType << std::endl;

      // Create Book object and store it in the array
      books[numBooks++] = {bookID,          bookName,       pageCount,
                           authorFirstName, authorLastName, bookType};

      count++;
    }
    file.close();
    std::cout << "File successfully opened: " << filename << std::endl;
    return true;
  } else {
    std::cout << "Error opening file: " << filename << std::endl;
    return false;
  }
}

// Function to get the book name based on book ID
std::string getBookNameByID(int bookID, const Book books[], int numBooks) {
  for (int i = 0; i < numBooks; ++i) {
    if (books[i].getBookID() == bookID) {
      return books[i].getBookName();
    }
  }
  return ""; // Return an empty string if book ID is not found
}

int main() {
  const int MAX_BOOKS = 300;
  Book books[MAX_BOOKS];
  int numBooks = 0;

  std::string filename;
  std::cout << "Enter the filename. Make sure it is saved in the same folder as this program: ";
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
