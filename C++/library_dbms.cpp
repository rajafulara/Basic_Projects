#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Book class definition
class Book {
private:
    string title;
    string author;
    int pages;
public:
    // Constructor
    Book(string title, string author, int pages) {
        this->title = title;
        this->author = author;
        this->pages = pages;
    }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPages() const { return pages; }
};

// Library class definition
class Library {
private:
    vector<Book> books;
public:
    // Function to add a new book
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    // Function to remove a book by title
    void removeBook(const string& title) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) {
            return b.getTitle() == title;
        });

        if (it != books.end()) {
            books.erase(it);
            cout << "Book '" << title << "' removed successfully.\n";
        } else {
            cout << "Book '" << title << "' not found in the library.\n";
        }
    }

    // Function to search for a book by title
    void searchBook(const string& title) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) {
            return b.getTitle() == title;
        });

        if (it != books.end()) {
            cout << "Book found:\n";
            cout << "Title: " << it->getTitle() << endl;
            cout << "Author: " << it->getAuthor() << endl;
            cout << "Pages: " << it->getPages() << endl;
        } else {
            cout << "Book '" << title << "' not found in the library.\n";
        }
    }
};

int main() {
    Library library;

    // Adding some initial books
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 180);
    Book book2("To Kill a Mockingbird", "Harper Lee", 281);
    library.addBook(book1);
    library.addBook(book2);

    int choice;
    string title;

    do {
        // Menu
        cout << "\nLibrary Management System\n";
        cout << "1. Add a Book\n";
        cout << "2. Remove a Book\n";
        cout << "3. Search for a Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string author;
                int pages;
                cout << "Enter book title: ";
                cin.ignore(); // Clear input buffer
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter number of pages: ";
                cin >> pages;
                Book newBook(title, author, pages);
                library.addBook(newBook);
                break;
            }
            case 2:
                cout << "Enter book title to remove: ";
                cin.ignore(); // Clear input buffer
                getline(cin, title);
                library.removeBook(title);
                break;
            case 3:
                cout << "Enter book title to search: ";
                cin.ignore(); // Clear input buffer
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
