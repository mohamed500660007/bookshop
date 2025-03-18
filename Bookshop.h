#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include <iostream>
#include <fstream>
#include <string>

class Bookshop {
public:
    void controlPanel();
    void addBook();
    void showBooks();
    void checkBook();
    void updateBook();
    void deleteBook();
};

#endif // BOOKSHOP_H
