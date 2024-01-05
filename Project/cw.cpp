#include <fstream>
#include <iostream>
#include <random>
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

class Member;

class Librarian {
private:
  int staffID;
  int salary;
  std::string username; // Added username
  std::string password; // Added password

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
  void issueBook(Member &member, int bookID);
  void returnBook(Member &member, int bookID);
  void displayBorrowedBooks(const Member &member);
  void calcFine(const Member &member);
  void displayMemberDetails(const Member &member) const;

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

public:
  // Additional attributes
  std::string name;
  std::string address;
  std::string email;
  int bookID;

  // Constructor for manual creation
  Member(const std::string &_name, const std::string &_address,
         const std::string &_email)
      : memberID(generateRandomID()), name(_name), address(_address),
        email(_email), bookID(0) {}

  // Constructor for random creation
  Member() : memberID(generateRandomID()), bookID(0) {}

  // Member functions
  int getMemberID() const { return memberID; }

  void setBooksBorrowed(int _bookID);
  void displayDetails() const;

private:
  // Function to generate a random ID
  static int generateRandomID() {
    // You can customize the range of random IDs as needed
    return lastAssignedID + 1 + rand() % 1000;
  }
};

int Member::lastAssignedID = 100; // Set to 100 or any desired starting value

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
  std::cout << "Member added:\n";
  displayMemberDetails(member);
}

void Librarian::issueBook(Member &member, int bookID) {
  // Implementation to issue a book to an individual member
  // Set due date (3 days from the date of issue)
  // Assume today's date as the issue date
  // For simplicity, due date is set to 3 days later
  std::cout << "Book issued to " << member.name
            << ". Due date: 3 days from today.\n";

  // Set the book as borrowed by the member
  member.setBooksBorrowed(bookID);
}

void Librarian::returnBook(Member &member, int bookID) {
  // Implementation to return a book from an individual member
  // Assume today's date as the return date
  // For simplicity, fine calculation is not implemented here
  member.setBooksBorrowed(0);
  std::cout << "Book returned by member.\n";
}

void Librarian::displayBorrowedBooks(const Member &member) {
  // Implementation to display all books borrowed by an individual member
  std::cout << "Displaying books borrowed by member:\n";
  if (member.bookID != 0) {
    // Assuming book details can be retrieved by bookID
    std::cout << "Book ID: " << member.bookID << "\n";
    // Display other book details as needed
  } else {
    std::cout << "No books borrowed by the member.\n";
  }
}

void Librarian::calcFine(const Member &member) {
  // Implementation to calculate a fine for an individual member
  // For simplicity, fine calculation is not implemented here
  std::cout << "Fine calculated for member.\n";
}

// Helper function to display member details
void Librarian::displayMemberDetails(const Member &member) const {
  std::cout << "Member ID: " << member.getMemberID() << "\n";
  std::cout << "Name: " << member.name << "\n";
  std::cout << "Address: " << member.address << "\n";
  std::cout << "Email: " << member.email << "\n";
  std::cout << "-------------------------\n";
}

void Member::setBooksBorrowed(int _bookID) {
  // Implementation to set books borrowed by a member
  bookID = _bookID;
  std::cout << "Book borrowed by member.\n";
}

void Member::displayDetails() const {
  std::cout << "Member ID: " << getMemberID() << "\n";
  std::cout << "Name: " << name << "\n";
  std::cout << "Address: " << address << "\n";
  std::cout << "Email: " << email << "\n";
  std::cout << "-------------------------\n";
}

// Function to read books from a CSV file
void readBooksFromCSV(const std::string &filename, Book books[],
                      int &numBooks) {
  std::ifstream file(filename);
  if (file.is_open()) {
    while (file.good()) {
      int bookID;
      std::string bookName;
      int pageCount;
      std::string authorFirstName;
      std::string authorLastName;
      std::string bookType;

      // Assuming the CSV format is:
      // ID,Name,PageCount,AuthorFirstName,AuthorLastName,Type
      char comma; // to read and discard the commas
      file >> bookID >> comma;
      std::getline(file, bookName, ',');
      file >> pageCount >> comma;
      std::getline(file, authorFirstName, ',');
      std::getline(file, authorLastName, ',');
      std::getline(file, bookType, '\n');

      // Create Book object and store it in the array
      books[numBooks++] = {bookID,          bookName,       pageCount,
                           authorFirstName, authorLastName, bookType};
    }
    file.close();
  } else {
    std::cout << "Error opening file: " << filename << std::endl;
  }
}
int main() {
  const int MAX_BOOKS = 168;
  Book books[MAX_BOOKS];
  int numBooks = 0;

  readBooksFromCSV("./files/books.csv", books, numBooks);

  Librarian librarian(678, "John Doe", "Library St", "john@example.com", 50000,
                      "librarian", "iLoveLibraries");

  int mainChoice;
  int staffID;
  std::string password;
  bool loggedIn = false;

  do {
    if (!loggedIn) {
      std::cout << "\nLogin as Librarian\n";
      std::cout << "Enter staff ID: ";
      std::cin >> staffID;
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
      std::cout << "3. Exit\n";
      std::cout << "Enter your choice (1-3): ";

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

          Member existingMember;
          if (existingMember.getMemberID() == memberID) {
            int memberChoice;
            do {
              std::cout << "\nMember Menu\n";
              std::cout << "1. Issue Book\n";
              std::cout << "2. Return Book\n";
              std::cout << "3. Display Borrowed Books\n";
              std::cout << "4. Calculate Fine\n";
              std::cout << "5. Display Member Details\n";
              std::cout << "6. Back\n";
              std::cout << "Enter your choice (1-6): ";

              if (std::cin >> memberChoice) {
                switch (memberChoice) {
                case 1:
                  int bookID;
                  std::cout << "Enter Book ID to issue: ";
                  std::cin >> bookID;
                  librarian.issueBook(existingMember, bookID);
                  break;

                case 2:
                  if (existingMember.bookID != 0) {
                    librarian.returnBook(existingMember, existingMember.bookID);
                  } else {
                    std::cout << "No books to return. Member has not borrowed "
                                 "any books.\n";
                  }
                  break;

                case 3:
                  librarian.displayBorrowedBooks(existingMember);
                  break;

                case 4:
                  librarian.calcFine(existingMember);
                  break;

                case 5:
                  librarian.displayMemberDetails(existingMember);
                  break;

                case 6:
                  std::cout << "Returning to the main menu.\n";
                  break;

                default:
                  std::cout << "Invalid choice. Please enter a number between "
                               "1 and 6.\n";
                  break;
                }
              } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "Invalid input. Please enter a number between 1 "
                             "and 6.\n";
              }

            } while (memberChoice != 6);
          } else {
            std::cout << "Member not found.\n";
          }
        } break;
        case 3:
          std::cout << "Exiting Library Management System. Closing...\n";
          break;
        default:
          std::cout
              << "Invalid choice. Please enter a number between 1 and 3.\n";
          break;
        }
      } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
      }
    }
  } while (mainChoice != 3);

  return 0;
}
