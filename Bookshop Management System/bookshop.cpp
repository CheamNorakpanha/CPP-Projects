#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPages: " << pages << endl;
    }

    void modifyPages(int newPages) {
        pages = newPages;
    }
};

class Bookshop {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        int pages;

        cout << "\nEnter book title: ";
        cin >> title;

        cout << "Enter author name: ";
        cin >> author;

        cout << "Enter number of pages: ";
        cin >> pages;

        books.push_back(Book(title, author, pages));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
        } else {
            cout << "\nList of Books:\n";
            for (const auto& book : books) {
                book.display();
                cout << "-------------------\n";
            }
        }
    }

    void modifyBookPages() {
        string title;
        int newPages;

        cout << "\nEnter the title of the book you want to modify: ";
        cin >> title;

        for (auto& book : books) {
            if (book.title == title) {
                cout << "Enter the new number of pages: ";
                cin >> newPages;

                book.modifyPages(newPages);
                cout << "Book modified successfully!\n";
                return;
            }
        }

        cout << "Book not found!\n";
    }

    void removeBook() {
        string title;

        cout << "\nEnter the title of the book you want to remove: ";
        cin >> title;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Book removed successfully!\n";
                return;
            }
        }

        cout << "Book not found!\n";
    }
};

int main() {
    Bookshop bookshop;
    int choice;

    do {
        cout << "\nBookshop Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Modify Book Pages\n";
        cout << "4. Remove Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookshop.addBook();
                break;
            case 2:
                bookshop.displayBooks();
                break;
            case 3:
                bookshop.modifyBookPages();
                break;
            case 4:
                bookshop.removeBook();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
