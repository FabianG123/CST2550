#include <iostream>
#include <string>

class Member;

class Librarian {
private:
  int staffID;
  int salary;

public:
  // Additional attributes
  std::string name;
  std::string address;
  std::string email;
  int memberID;

  // Constructor
  Librarian(int _staffID, const std::string &_name, const std::string &_address,
            const std::string &_email, int _salary)
      : staffID(_staffID), salary(_salary), name(_name), address(_address),
        email(_email) {}

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
  Member(int _memberID, const std::string &_name, const std::string &_address,
         const std::string &_email)
      : memberID(_memberID), name(_name), address(_address), email(_email) {}

  // Member functions
  int getMemberID() const { return memberID; }

  void setBooksBorrowed(int _bookID);
};

class Book {
private:
  int bookID;
  std::string bookName;
  int pageCount;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;

public:
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
  std::cout << "Book issued to member. Due date: 3 days from today.\n";
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

int main() {
  // Created an array of Book objects with the provided details
  Book books[] = {
      {1, "A Daughter of the Snows", 199, "Jack", "n", "Guide"},
      {2, "The Near East: 10,000 Years of History", 298, "Isaac", "Asimov",
       "Journals"},
      {3, "The Cocoon: A Rest-Cure Comedy", 90, "Ruth", "Stuart", "Diaries"},
      {4, "The Freakshow Murders", 321, "Frederic", "Brown", "Drama"},
      {5, "Pharaohs, Fellahs and Explorers", 367, "Amelia B.", "Edwards",
       "Guide"},
      {6, "Hard Times", 293, "Charles", "Dickens", "Science fiction"},
      {7, "A Modern Instance", 222, "William Dean", "Howells", "Diaries"},
      {8, "The Real Mother Goose", 88, "Mother", "Goose", "Science fiction"},
      {9, "A Thousand Miles Up the Nile", 110, "Amelia B.", "Edwards", "Art"},
      {10, "Children of Blood and Bone", 137, "Titus", "Lucretius", "Journals"},
      {11, "A pushcart at the curb", 95, "John", "DosPassos",
       "Science fiction"},
      {12, "The Desert and the Sown", 126, "Mary Hallock", "Foote", "Diaries"},
      {13, "Three Soldiers", 223, "John", "DosPassos", "History"},
      {14, "The End of Eternity", 168, "Isaac", "Asimov", "Science fiction"},
      {15, "Annie Kilburn", 291, "William Dean", "Howells", "Diaries"},
      {16, "A Touch of Sun and Other Stories", 141, "Mary Hallock", "Foote",
       "Guide"},
      {17, "Show Boat", 151, "Edna", "Ferber", "Art"},
      {18, "The Call of the Wild", 362, "Jack", "London", "Art"},
      {19, "My Mark Twain", 339, "William Dean", "Howells", "Guide"},
      {20, "Broken Ties", 134, "Rabindranath", "Tagore", "Romance"},
      {21, "Short Stories From American History", 305, "Albert", "Blaisdell",
       "Health"},
      {22, "Mrs Rosie and the Priest", 104, "Givoanni", "Boccaccio",
       "Biographies"},
      {23, "So Big", 209, "Edna", "Ferber", "Drama"},
      {24, "Monsieur Maurice", 92, "Amelia B.", "Edwards", "Health"},
      {25, "The Master of Ballantrae", 236, "Robert Louis", "Stevenson",
       "Journals"},
      {26, "The Unlived Life of Little Mary Ellen", 99, "Ruth", "Stuart",
       "Mystery"},
      {27, "Mouse - The Last Train", 184, "Frederic", "Brown", "Biographies"},
      {28, "Edith Bonham", 122, "Mary Hallock", "Foote", "Horror"},
      {29, "Maybe Mother Goose", 161, "Mother", "Goose", "Biographies"},
      {30, "The Noble Gases", 321, "Isaac", "Asimov", "Romance"},
      {31, "Rainy Week", 98, "Eleanor Hallowell", "Abbott", "Horror"},
      {32, "A Hazard of New Fortunes", 144, "William Dean", "Howells",
       "Action and Adventure"},
      {33, "A Plot for Murder", 108, "Frederic", "Brown", "Journals"},
      {34, "Nature", 357, "Ralph Waldo", "Emerson", "Health"},
      {35, "Hickory Dickory Dock", 326, "Mother", "Goose", "Mystery"},
      {36, "Big Fat Hen", 232, "Mother", "Goose", "Diaries"},
      {37, "The Lone Star Ranger", 328, "Zane", "Grey", "Guide"},
      {38, "The Great Fire of London", 252, "Samuel", "Pepys", "Guide"},
      {39, "White Nights", 265, "Fyodor", "Dostoevsky", "Biographies"},
      {40, "In a Glass Darkly", 173, "Joseph Sheridan", "LeFanu", "Guide"},
      {41, "Fanny herself", 248, "Edna", "Ferber", "Diaries"},
      {42, "Loaded", 273, "Frederic", "Brown", "Action and Adventure"},
      {43, "A Foregone Conclusion", 121, "William Dean", "Howells", "Fantasy"},
      {44, "The Hill of Dreams", 175, "Arthur", "Machen", "Mystery"},
      {45, "Adventure", 217, "Jack", "London", "Health"},
      {46, "A Tagore Reader", 285, "Rabindranath", "Tagore",
       "Action and Adventure"},
      {47, "A Tale of Two Cities", 331, "Charles", "Dickens", "Journals"},
      {48, "Dombey and Son", 344, "Charles", "Dickens", "Biographies"},
      {49, "Famous Women", 273, "Givoanni", "Boccaccio", "Science fiction"},
      {50, "Rejection, The Ruling Spirit", 358, "Ellis", "Butler", "Satire"},
      {51, "Little Dorrit", 314, "Charles", "Dickens", "Journals"},
      {52, "The Four-Fifteen Express", 201, "Amelia B.", "Edwards", "Satire"},
      {53, "Fairy Prince and Other Stories", 306, "Eleanor Hallowell", "Abbott",
       "Fantasy"},
      {54, "Ten Tales from the Decameron", 183, "Givoanni", "Boccaccio",
       "Romance"},
      {55, "The Double", 372, "Fyodor", "Dostoevsky", "Science"},
      {56, "A Flight Of Swans", 115, "Rabindranath", "Tagore", "Health"},
      {57, "The Phantom Coach", 243, "Amelia B.", "Edwards", "Science"},
      {58, "The Game", 209, "Jack", "London", "Diaries"},
      {59, "Rico and Wiseli", 309, "Johanna", "Spyri", "Health"},
      {60, "The Shorter Pepys", 276, "Samuel", "Pepys", "Romance"},
      {61, "My Life Had Stood a Loaded Gun", 278, "Emily", "Dickinson",
       "Diaries"},
      {62, "A Tagore Testament", 268, "Rabindranath", "Tagore", "Fantasy"},
      {63, "The Cruise of the Dazzler", 140, "Jack", "London", "Diaries"},
      {64, "To the Lighthouse", 90, "Virginia", "Woolf", "Satire"},
      {65, "The Terror", 293, "Arthur", "Machen", "Art"},
      {66, "The Sick-a-Bed Lady", 369, "Eleanor Hallowell", "Abbott", "Guide"},
      {67, "Christmas Every Day", 98, "William Dean", "Howells", "Journals"},
      {68, "The home-maker", 316, "Dorothy", "Canfield", "Biographies"},
      {69, "The Ground-Swell", 193, "Mary Hallock", "Foote", "Diaries"},
      {70, "A Sleep and a Forgetting", 360, "William Dean", "Howells",
       "Satire"},
      {71, "Nicholas Nickleby", 219, "Charles", "Dickens", "Science fiction"},
      {72, "The Whole Family: A Novel by Twelve Authors", 149, "William Dean",
       "Howells", "Mystery"},
      {73, "Middlemarch", 288, "George", "Eliot", "Comics"},
      {74, "Life of Dante", 156, "Givoanni", "Boccaccio", "Biographies"},
      {75, "Short Stories From English History", 189, "Albert", "Blaisdell",
       "Satire"},
      {76, "Little Eve Edgarton", 306, "Eleanor Hallowell", "Abbott",
       "Romance"},
      {77, "The Kingdom of the Sun", 189, "Isaac", "Asimov", "Guide"},
      {78, "Indian Summer", 107, "William Dean", "Howells", "Biographies"},
      {79, "Mrs Dalloway", 321, "Virginia", "Woolf", "Romance"},
      {80, "Demons", 232, "Fyodor", "Dostoevsky", "Fantasy"},
      {81, "The Last Trail", 116, "Zane", "Grey", "Biographies"},
      {82, "The Fredric Brown Megapack", 324, "Frederic", "Brown", "History"},
      {83, "The Decameron: Selected Tales", 337, "Givoanni", "Boccaccio",
       "Science"},
      {84, "Th bent twig", 367, "Dorothy", "Canfield", "Drama"},
      {85, "Things near and far", 199, "Arthur", "Machen", "Mystery"},
      {86, "The Story of Salome", 316, "Amelia B.", "Edwards", "Comics"},
      {87, "The Destruction of Our Children", 104, "Ellis", "Butler", "Guide"},
      {88, "Collected Stories", 295, "Rabindranath", "Tagore",
       "Action and Adventure"},
      {89, "The House of the Dead", 209, "Fyodor", "Dostoevsky", "Satire"},
      {90, "Sonny: A Christmas Guest", 186, "Ruth", "Stuart", "Mystery"},
      {91, "Amores", 297, "Publius", "Ovid", "Diaries"},
      {92, "Chaturanga", 218, "Rabindranath", "Tagore", "Diaries"},
      {93, "Little Eve Edgarton", 247, "Eleanor Hallowell", "Abbott",
       "Biographies"},
      {94, "Chitra", 122, "Rabindranath", "Tagore", "Guide"},
      {95, "The Iron Heel", 81, "Jack", "London", "Fantasy"},
      {96, "Self Reliance", 137, "Ralph Waldo", "Emerson", "Art"},
      {97, "The Great God Pan And The Hill Of Dreams", 158, "Arthur", "Machen",
       "Romance"},
      {98, "The White People and Other Weird Stories", 100, "Arthur", "Machen",
       "Fantasy"},
      {99, "The Diary of Samuel Pepys: A Selection", 271, "Samuel", "Pepys",
       "Drama"},
      {100, "The Rise of Silas Lapham", 314, "William Dean", "Howells",
       "Satire"},
      {101, "The Mystery of Edwin Drood", 340, "Charles", "Dickens", "Diaries"},
      {102, "In Exile and Other Stories", 140, "Mary Hallock", "Foote",
       "Comics"},
      {103, "Bleak House", 130, "Charles", "Dickens", "Art"},
      {104, "U.S.A Trilogy", 118, "John", "DosPassos", "Science fiction"},
      {105, "A Comedy of Masks", 237, "Ernest", "Dowson", "Journals"},
      {106, "Barnaby Rudge", 380, "Charles", "Dickens", "Diaries"},
      {107, "Heroic Deeds of American Sailors", 243, "Albert", "Blaisdell",
       "Science fiction"},
      {108, "A Bouquet", 309, "Ernest", "Dowson", "Art"},
      {109, "Editha", 155, "William Dean", "Howells", "Art"},
      {110, "Manhattan Transfer", 124, "John", "DosPassos", "Drama"},
      {111, "Fasti", 325, "Publius", "Ovid", "Horror"},
      {112, "Hearts of Three", 272, "Jack", "London", "Satire"},
      {113, "Speak, Memory", 154, "Vladimir", "Nabokov", "Fantasy"},
      {114, "Kidnapped", 334, "Robert Louis", "Stevenson", "Drama"},
      {115, "The Brothers Karamazov", 161, "Fyodor", "Dostoevsky", "Mystery"},
      {116, "Envelope Poems", 342, "Emily", "Dickinson", "Fantasy"},
      {117, "Selected Poems", 203, "Emily", "Dickinson", "Guide"},
      {118, "Gobolinks or Shadow Pictures for Young and Old", 332, "Ruth",
       "Stuart", "Romance"},
      {119, "The Decameron", 318, "Givoanni", "Boccaccio", "Diaries"},
      {120, "The Cock and Anchor", 133, "Joseph Sheridan", "LeFanu",
       "Science fiction"},
      {121, "Adrian Rome", 259, "Ernest", "Dowson", "Journals"},
      {122, "Words in Genesis", 217, "Isaac", "Asimov", "Science"},
      {123, "Stories of Ohio", 191, "William Dean", "Howells", "Romance"},
      {124, "Treasure Island", 308, "Robert Louis", "Stevenson",
       "Action and Adventure"},
      {125, "Uncle Silas", 118, "Joseph Sheridan", "LeFanu", "Science fiction"},
      {126, "The Idiot", 248, "Fyodor", "Dostoevsky", "Horror"},
      {127, "Inside The Atom", 176, "Isaac", "Asimov", "Action and Adventure"},
      {128, "The Story of Babette: A Little Creole Girl", 313, "Ruth", "Stuart",
       "Romance"},
      {129, "The Eternal Husband", 225, "Fyodor", "Dostoevsky", "Fantasy"},
      {130, "Heidi", 146, "Johanna", "Spyri", "Science"},
      {131, "The Concise Pepys", 303, "Samuel", "Pepys", "Journals"},
      {132, "Tales From Shakespeare", 121, "Albert", "Blaisdell", "Diaries"},
      {133, "Molly Make-Believe", 286, "Eleanor Hallowell", "Abbott",
       "Diaries"},
      {134, "Peace on Earth, Good Will to Dogs", 321, "Eleanor Hallowell",
       "Abbott", "Guide"},
      {135, "Miss Darkness", 360, "Frederic", "Brown", "Health"},
      {136, "Poor Folk", 202, "Fyodor", "Dostoevsky", "Horror"},
      {137, "Their Wedding Journey", 132, "William Dean", "Howells", "Art"},
      {138, "The Elegy of Lady Fiammetta", 157, "Givoanni", "Boccaccio",
       "Action and Adventure"},
      {139, "Art Of Tagore", 119, "Rabindranath", "Tagore", "History"},
      {140, "Chemistry and Human Health", 244, "Isaac", "Asimov", "Journals"},
      {141, "Realm of Numbers", 279, "Isaac", "Asimov", "Comics"},
      {142, "The Kempton-Wace Letters", 240, "Jack", "London", "Drama"},
      {143, "Crime and Punishment", 144, "Fyodor", "Dostoevsky", "Science"},
      {144, "Fairy Prince and Other Wonderful Stories", 219,
       "Eleanor Hallowell", "Abbott", "Science fiction"},
      {145, "Adam Bede", 303, "George", "Eliot", "Action and Adventure"},
      {146, "Madam Crowl's ghost", 344, "Joseph Sheridan", "LeFanu",
       "Journals"},
      {147, "Is Anyone There?", 178, "Isaac", "Asimov", "Biographies"},
      {148, "An Imperative Duty", 100, "William Dean", "Howells", "Mystery"},
      {149, "Adding a Dimension", 334, "Isaac", "Asimov", "Comics"},
      {150, "The Caves of Steel", 98, "Isaac", "Asimov", "Art"},
      {151, "Carmilla", 91, "Joseph Sheridan", "LeFanu", "Art"},
      {152, "1919", 105, "John", "DosPassos", "Science"},
      {153, "Pale Fire", 250, "Vladimir", "Nabokov", "Journals"},
      {154, "Martin Chuzzlewit", 315, "Charles", "Dickens", "Drama"},
      {155, "Understood Betsy", 130, "Dorothy", "Canfield", "Horror"},
      {156, "The White Linen Nurse", 369, "Eleanor Hallowell", "Abbott",
       "Journals"},
      {157, "A Writer's Diary", 164, "Fyodor", "Dostoevsky", "Science fiction"},
      {158, "Pnin", 233, "Vladimir", "Nabokov", "Biographies"},
      {159, "Honeymoon in Hell", 202, "Frederic", "Brown", "History"},
      {160, "The Black Arrow", 366, "Robert Louis", "Stevenson", "Diaries"},
      {161, "David Copperfield", 240, "Charles", "Dickens", "History"},
      {162, "Famous Ghost Stories", 152, "Amelia B.", "Edwards", "Drama"},
      {163, "Book Of Indian Braves", 117, "Kate Dickinson", "Sweetser",
       "Health"},
      {164, "Binodini", 306, "Rabindranath", "Tagore", "Health"},
      {165, "Holly And Pizen, And Other Stories", 220, "Ruth", "Stuart",
       "Science"},
      {166, "Lolita", 153, "Vladimir", "Nabokov", "Satire"},
      {167, "The Best Short Stories", 115, "Fyodor", "Dostoevsky", "Satire"},
      {168, "Cimarron", 101, "Edna", "Ferber", "Science"}};

  // Create a Librarian object
  Librarian librarian(101, "John Doe", "Library St", "john@example.com", 50000);

  // Create a Member object
  Member member(201, "Alice", "Wonderland", "alice@example.com");

  // Display the main menu
  int choice;
  do {
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. Add Member\n";
    std::cout << "2. Issue Book\n";
    std::cout << "3. Return Book\n";
    std::cout << "4. Display Borrowed Books\n";
    std::cout << "5. Calculate Fine\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice (1-6): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      librarian.addMember(member);
      break;
    case 2:
      int bookID;
      std::cout << "Enter Book ID to issue: ";
      std::cin >> bookID;
      librarian.issueBook(member, bookID);
      break;
    case 3:
      std::cout << "Enter Book ID to return: ";
      std::cin >> bookID;
      librarian.returnBook(member, bookID);
      break;
    case 4:
      librarian.displayBorrowedBooks(member);
      break;
    case 5:
      librarian.calcFine(member);
      break;
    case 6:
      std::cout << "Exiting Library Management System. Closing...\n";
      break;
    default:
      std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
      break;
    }
  } while (choice != 6);

  return 0;
}
