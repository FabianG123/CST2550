//tests.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Librarian.h"
#include "LibraryFunctions.h"
#include "Member.h"
#include "Book.h"
#include "Person.h"

TEST_CASE("Invalid CSV file handling", "[LibraryFunctions]") {
    const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS];
    int numBooks = 0;

    SECTION("Attempt to open non-existent file") {
        std::string invalidCsvFile = "nonexistent_file.csv";
        bool result = readBooksFromCSV(invalidCsvFile, books, numBooks, MAX_BOOKS);

        REQUIRE_FALSE(result);  // The file should not be opened successfully
        REQUIRE(numBooks == 0);  // No books should be read
    }

  
}
