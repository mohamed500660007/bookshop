#include "Utils.h"
#include <iostream>
#include <windows.h>

using namespace std;

void bookShopHeader() {
    system("color 3");
    string title = "Book Shop Management System";
    for (char c : title) {
        cout << c;
        Sleep(100);
    }
    cout << endl;
}
