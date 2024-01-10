// LibraryFunctions.h
#ifndef LIBRARY_FUNCTIONS_H
#define LIBRARY_FUNCTIONS_H

#include <string>
#include "Book.h"

// Function declarations
bool readBooksFromCSV(const std::string &filename, Book books[], int &numBooks, const int MAX_BOOKS);
std::string getBookNameByID(int bookID, const Book books[], int numBooks);

#endif // LIBRARY_FUNCTIONS_H
