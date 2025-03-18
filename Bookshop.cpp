#include "Bookshop.h"
#include "Utils.h"
#include <cstdlib>
#include <windows.h>

using namespace std;

// Display Control Panel
void Bookshop::controlPanel() {
    system("cls");
    system("color 3");
    cout << "\n\n\t\t\t\tCONTROL PANEL";
    cout << "\n\n1. Add Book";
    cout << "\n2. Display Books";
    cout << "\n3. Search Book";
    cout << "\n4. Update Book";
    cout << "\n5. Delete Book";
    cout << "\n6. Exit\n";
}

// Function to add a new book to the system
void Bookshop::addBook() {
    system("cls");
    system("color 4");

    fstream file;
    int no_copy;
    string b_name, a_name, b_id;

    cout << "\n\n\t\t\t\tADD BOOKS";
    cout << "\n\nBook ID: ";
    cin >> b_id;
    cout << "Book Name: ";
    cin >> b_name;
    cout << "Author Name: ";
    cin >> a_name;
    cout << "Number of Copies: ";
    cin >> no_copy;

    file.open("books.txt", ios::app);
    file << b_id << " " << b_name << " " << a_name << " " << no_copy << "\n";
    file.close();
}

// Function to display all books
void Bookshop::showBooks() {
    system("cls");
    system("color 5");

    fstream file;
    int no_copy;
    string b_name, b_id, a_name;
// this is comments for better
    cout << "\n\n\t\t\t\tAll BOOKS\n\n";
    file.open("books.txt", ios::in);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    cout << "Book ID\tBook Name\tAuthor\tCopies\n";
    while (file >> b_id >> b_name >> a_name >> no_copy) {
        cout << b_id << "\t" << b_name << "\t" << a_name << "\t" << no_copy << "\n";
    }

    file.close();
}

// Function to check book details
void Bookshop::checkBook() {
    system("cls");
    system("color 6");

    fstream file;
    int no_copy;
    string b_id, b_name, a_name, search_id;
    bool found = false;

    cout << "\n\nEnter Book ID to search: ";
    cin >> search_id;

    file.open("books.txt", ios::in);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    while (file >> b_id >> b_name >> a_name >> no_copy) {
        if (b_id == search_id) {
            cout << "\nBook Found!\n";
            cout << "Book ID: " << b_id << "\nName: " << b_name << "\nAuthor: " << a_name << "\nCopies: " << no_copy << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nBook ID not found.\n";
    }

    file.close();
}

// Function to update book details
void Bookshop::updateBook() {
    system("cls");
    system("color 2");

    fstream file, tempFile;
    string b_id, b_name, a_name, search_id, new_name, new_author;
    int no_copy, new_copies;
    bool found = false;

    cout << "\n\nEnter Book ID to update: ";
    cin >> search_id;

    file.open("books.txt", ios::in);
    tempFile.open("temp.txt", ios::out);

    if (!file || !tempFile) {
        cout << "Error opening file!\n";
        return;
    }

    while (file >> b_id >> b_name >> a_name >> no_copy) {
        if (b_id == search_id) {
            cout << "\nEnter new details:\n";
            cout << "New Book Name: ";
            cin >> new_name;
            cout << "New Author Name: ";
            cin >> new_author;
            cout << "New Number of Copies: ";
            cin >> new_copies;
            tempFile << b_id << " " << new_name << " " << new_author << " " << new_copies << "\n";
            found = true;
        } else {
            tempFile << b_id << " " << b_name << " " << a_name << " " << no_copy << "\n";
        }
    }

    file.close();
    tempFile.close();
    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (found)
        cout << "\nBook updated successfully.\n";
    else
        cout << "\nBook ID not found.\n";
}

// Function to delete a book
void Bookshop::deleteBook() {
    system("cls");
    system("color 6");

    fstream file, tempFile;
    string b_id, b_name, a_name, search_id;
    int no_copy;
    bool found = false;

    cout << "\n\nEnter Book ID to delete: ";
    cin >> search_id;

    file.open("books.txt", ios::in);
    tempFile.open("temp.txt", ios::out);

    if (!file || !tempFile) {
        cout << "Error opening file!\n";
        return;
    }

    while (file >> b_id >> b_name >> a_name >> no_copy) {
        if (b_id == search_id) {
            cout << "\nBook deleted successfully.\n";
            found = true;
        } else {
            tempFile << b_id << " " << b_name << " " << a_name << " " << no_copy << "\n";
        }
    }

    file.close();
    tempFile.close();
    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (!found)
        cout << "\nBook ID not found.\n";
}
