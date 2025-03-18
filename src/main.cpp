#include "Bookshop.h"
#include "Utils.h"

using namespace std;

int main() {
    bookShopHeader();

    Bookshop shop;
    int choice;
    char x;

    while (true) {
        shop.controlPanel();
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: shop.addBook(); break;
            case 2: shop.showBooks(); break;
            case 3: shop.checkBook(); break;
            case 4: shop.updateBook(); break;
            case 5: shop.deleteBook(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice! Try again.\n";
        }
    }

    return 0;
}
