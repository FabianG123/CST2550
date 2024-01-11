CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic
TESTS = tests.cpp
CATCH_INCLUDE = catch.hpp

program: main.cpp Librarian.o Member.o Book.o LibraryFunctions.o
	$(CXX) $(CXXFLAGS) -o program main.cpp Librarian.o Member.o Book.o LibraryFunctions.o

tests: $(TESTS) Librarian.o Member.o Book.o LibraryFunctions.o
	$(CXX) $(CXXFLAGS) -o tests $(TESTS) Librarian.o Member.o Book.o LibraryFunctions.o -I $(CATCH_INCLUDE)

Librarian.o: Librarian.cpp Librarian.h Member.h Book.h LibraryFunctions.h
	$(CXX) $(CXXFLAGS) -c Librarian.cpp

Member.o: Member.cpp Member.h Book.h LibraryFunctions.h
	$(CXX) $(CXXFLAGS) -c Member.cpp

Book.o: Book.cpp Book.h
	$(CXX) $(CXXFLAGS) -c Book.cpp

LibraryFunctions.o: LibraryFunctions.cpp LibraryFunctions.h Librarian.h
	$(CXX) $(CXXFLAGS) -c LibraryFunctions.cpp

clean:
	rm -f *.o
	rm -f program
	rm -f tests
