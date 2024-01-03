#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
    // Getter methods
    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }

    std::string getEmail() const {
        return email;
    }

    // Setter methods
    void setName(const std::string& _name) {
        name = _name;
    }

    void setAddress(const std::string& _address) {
        address = _address;
    }

    void setEmail(const std::string& _email) {
        email = _email;
    }
};

class Librarian {
private:
    int staffID;
    int salary;

public:
    // Additional attributes
    std::string name;
    std::string address;
    std::string email;
    int memberID;  // 

    // Constructor
    Librarian(int _staffID, const std::string& _name, const std::string& _address, const std::string& _email, int _salary)
        : staffID(_staffID), name(_name), address(_address), email(_email), salary(_salary) {
        
    }

    // Member functions
    void addMember() {
        // Implementation to add a member
        std::cout << "Member added." << std::endl;
    }

    void issueBook(int _memberID, int bookID) {
        // Implementation to issue a book to an individual member
        memberID = _memberID;
        std::cout << "Book issued to member." << std::endl;
    }

    void returnBook(int _memberID, int bookID) {
        // Implementation to return a book from an individual member
        memberID = 0; 
        std::cout << "Book returned by member." << std::endl;
    }

    void displayBorrowedBooks(int _memberID) {
        // Implementation to display all books borrowed by an individual member
        std::cout << "Displaying books borrowed by member." << std::endl;
    }

    void calcFine(int _memberID) {
        // Implementation to calculate a fine for an individual member
        std::cout << "Fine calculated for member." << std::endl;
    }

    // Getter and Setter for staffID
    int getStaffID() const {
        return staffID;
    }

    void setStaffID(int _staffID) {
        staffID = _staffID;
    }

    // Getter and Setter for salary
    int getSalary() const {
        return salary;
    }

    void setSalary(int _salary) {
        salary = _salary;
    }
};

class Member {
private:
    int memberID;

public:
    // Additional attributes
    std::string name;
    std::string address;
    std::string email;
    int bookID; 

    // Constructor
    Member(int _memberID, const std::string& _name, const std::string& _address, const std::string& _email)
        : memberID(_memberID), name(_name), address(_address), email(_email) {
        
    }

    // Member functions
    int getMemberID() const {
        return memberID;
    }

    void setBooksBorrowed(int _bookID) {
        // Implementation to set books borrowed by a member
        bookID = _bookID;
        std::cout << "Book borrowed by member." << std::endl;
    }
};

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    // Remove Date and borrower attributes

public:
    // Constructor
    Book(int _bookID, const std::string& _bookName, const std::string& _authorFirstName, const std::string& _authorLastName)
        : bookID(_bookID), bookName(_bookName), authorFirstName(_authorFirstName), authorLastName(_authorLastName) {
        // Additional initialization if needed
    }

    // Getter methods
    int getBookID() const {
        return bookID;
    }

    std::string getBookName() const {
        return bookName;
    }

    std::string getAuthorFirstName() const {
        return authorFirstName;
    }

    std::string getAuthorLastName() const {
        return authorLastName;
    }

    // Member functions
    void returnBook() {
        // Implementation to return a book
        std::cout << "Book returned." << std::endl;
    }

    void borrowBook(Member* _borrower) {
        // Implementation to borrow a book by a member
        std::cout << "Book borrowed by " << _borrower->name << "." << std::endl;
    }
};

int main() { 
  // Main code, usage of the classes
}
