// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>

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

#endif // BOOK_H
