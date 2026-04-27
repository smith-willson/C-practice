#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ===================== CLASS BOOK =====================
class Book {
private:
    string title;
    int pages;

public:
    // Parametrized Constructor with Exception Handling
    Book(string t = "", int p = 0) {
        if (t.empty()) {
            throw invalid_argument("Title cannot be empty!");
        }
        if (p <= 0) {
            throw invalid_argument("Pages must be greater than 0!");
        }
        title = t;
        pages = p;
    }

    // Getters
    string getTitle() { return title; }
    int getPages()    { return pages; }

    // Setters
    void setTitle(string t) {
        if (t.empty()) throw invalid_argument("Title cannot be empty!");
        title = t;
    }
    void setPages(int p) {
        if (p <= 0) throw invalid_argument("Pages must be greater than 0!");
        pages = p;
    }

    void displayBook() {
        cout << "  Title : " << title << endl;
        cout << "  Pages : " << pages << endl;
    }
};

// ===================== CLASS LIBRARIAN =====================
class Librarian {
private:
    string name;

public:
    Librarian(string n) {
        name = n;
    }

    // Getter & Setter
    string getName() { return name; }
    void setName(string n) { name = n; }

    void displayLibrarian() {
        cout << "Librarian Name: " << name << endl;
    }
};

// ===================== CLASS LIBRARY =====================
class Library {
private:
    Book books[5];        // COMPOSITION — Book is PART of Library
    Librarian* librarian; // REFERENCE POINTER — Aggregation
    int bookCount;

public:
    Library(Librarian* lib) : librarian(lib), bookCount(0),
        books{Book("Placeholder",1), Book("Placeholder",1),
              Book("Placeholder",1), Book("Placeholder",1),
              Book("Placeholder",1)} {
    }

    void addBook(Book b) {
        if (bookCount >= 5) {
            cout << "Library is full! Cannot add more books." << endl;
            return;
        }
        books[bookCount] = b;
        bookCount++;
        cout << "Book added successfully!" << endl;
    }

    void displayLibrary() {
        cout << "\n===== LIBRARY SYSTEM =====" << endl;
        librarian->displayLibrarian();
        cout << "\nBooks in Library (" << bookCount << "):" << endl;
        for (int i = 0; i < bookCount; i++) {
            cout << "Book " << i + 1 << ":" << endl;
            books[i].displayBook();
        }
        cout << "==========================" << endl;
    }
};

// ===================== MAIN =====================
int main() {
    // Create Librarian
    Librarian lib("Mr. Ahmed");

    // Create Library (passing librarian by pointer)
    Library myLibrary(&lib);

    // Add books with exception handling
    try {
        Book b1("C++ Programming", 450);
        myLibrary.addBook(b1);

        Book b2("Data Structures", 380);
        myLibrary.addBook(b2);

        Book b3("OOP Concepts", 290);
        myLibrary.addBook(b3);

        // Testing exception — empty title
        Book b4("", 100);
        myLibrary.addBook(b4);
    }
    catch (invalid_argument& e) {
        cout << "Invalid Input Error: " << e.what() << endl;
    }
    catch (logic_error& e) {
        cout << "Logic Error: " << e.what() << endl;
    }

    // Display everything
    myLibrary.displayLibrary();

    return 0;
}