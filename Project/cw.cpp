#include <iostream>
#include <string>

struct Book {
    int id;
    std::string name;
    std::string author;
    std::string type;
    int page_count;
    bool is_borrowed;
    time_t due_date;
};

struct Member {
    int id;
    std::string name;
    Book borrowed_books[10]; // Assuming a member can borrow up to 10 books
    int num_borrowed_books;
};

class Library {
private:
    Member members[100]; // Assuming up to 100 members
    Book books[100];     // Assuming up to 100 books
    int numMembers;
    int numBooks;

    time_t getCurrentTime() {
        return time(0); // Remove the std:: prefix
    }

public:
    Library() : numMembers(0), numBooks(0) {}

    void addMember(const std::string& name) {
        members[numMembers].id = numMembers + 1;
        members[numMembers].name = name;
        members[numMembers].num_borrowed_books = 0;
        numMembers++;

        std::cout << "Member added successfully. Member ID: " << members[numMembers - 1].id << "\n";
    }

    void addBook(const Book& book) {
        if (numBooks < 100) {
            books[numBooks++] = book;
            std::cout << "Book added successfully. Book ID: " << book.id << "\n";
        } else {
            std::cout << "Cannot add more books. Library is full.\n";
        }
    }

    int getNumBooks() const {
        return numBooks;
    }

    void displayAllBooks() const {
        std::cout << "Available Books:\n";
        for (int i = 0; i < numBooks; ++i) {
            if (!books[i].is_borrowed) {
                std::cout << "ID: " << books[i].id << " | Name: " << books[i].name << " | Author: " << books[i].author << "\n";
            }
        }
    }

    void issueBook(int memberId, int bookId) {
        for (int i = 0; i < numMembers; ++i) {
            if (members[i].id == memberId) {
                for (int j = 0; j < numBooks; ++j) {
                    if (books[j].id == bookId && !books[j].is_borrowed) {
                        books[j].is_borrowed = true;
                        books[j].due_date = getCurrentTime() + 3 * 24 * 60 * 60; // 3 days in seconds
                        members[i].borrowed_books[members[i].num_borrowed_books++] = books[j];

                        std::cout << "Book issued successfully. Due date: " << asctime(localtime(&books[j].due_date)); // Remove the std:: prefix
                        return;
                    }
                }
                std::cout << "Book not found or already borrowed.\n";
                return;
            }
        }
        std::cout << "Member not found.\n";
    }

    void returnBook(int memberId, int bookId) {
        for (int i = 0; i < numMembers; ++i) {
            if (members[i].id == memberId) {
                for (int j = 0; j < members[i].num_borrowed_books; ++j) {
                    if (members[i].borrowed_books[j].id == bookId) {
                        members[i].borrowed_books[j].is_borrowed = false;

                        time_t currentTime = getCurrentTime();
                        if (members[i].borrowed_books[j].due_date < currentTime) {
                            int daysOverdue = (currentTime - members[i].borrowed_books[j].due_date) / (24 * 60 * 60);
                            int fine = daysOverdue * 1; // £1 per day overdue
                            std::cout << "Book returned successfully. Overdue fine: £" << fine << "\n";
                        } else {
                            std::cout << "Book returned successfully.\n";
                        }

                        // Remove the book from the member's borrowed_books array
                        for (int k = j; k < members[i].num_borrowed_books - 1; ++k) {
                            members[i].borrowed_books[k] = members[i].borrowed_books[k + 1];
                        }
                        members[i].num_borrowed_books--;

                        return;
                    }
                }
                std::cout << "Book not found or not borrowed by this member.\n";
                return;
            }
        }
        std::cout << "Member not found.\n";
    }

    void displayBooksBorrowedByMember(int memberId) const {
        for (int i = 0; i < numMembers; ++i) {
            if (members[i].id == memberId) {
                if (members[i].num_borrowed_books == 0) {
                    std::cout << "No books borrowed by this member.\n";
                } else {
                    std::cout << "Books borrowed by Member ID " << memberId << ":\n";
                    for (int j = 0; j < members[i].num_borrowed_books; ++j) {
                        std::cout << "ID: " << members[i].borrowed_books[j].id << " | Name: " << members[i].borrowed_books[j].name << " | Due Date: " << asctime(localtime(&members[i].borrowed_books[j].due_date)); // Remove the std:: prefix
                    }
                }
                return;
            }
        }
        std::cout << "Member not found.\n";
    }
};

int main() {
    Library library;

    // Sample usage
    library.addMember("John Doe");

    Book book1 = {1, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Science Fiction", 224, false, 0};
    Book book2 = {2, "1984", "George Orwell", "Satire", 328, false, 0};

    library.addBook(book1);
    library.addBook(book2);

    library.displayAllBooks();

    library.issueBook(1, 1);

    library.displayBooksBorrowedByMember(1);

    library.returnBook(1, 1);

    return 0;
}
