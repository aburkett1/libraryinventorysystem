#ifndef LIBRARYSTORAGE_H_
#define LIBRARYSTORAGE_H_

#include "Shelf.h"
#include "Item.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

class LibraryStorage {
public:
    void addItem(Item* newItem, int shelfLocation, int compartmentLocation);
    void checkOut(string name, string dueDate);
    void checkIn(Item* returnItem);
    void swapItems(int item1Shelf, int item1Compartment, int item2Shelf, int item2Compartment);

    Shelf*& operator[](int index) {
        return storage[index];
    }

    Shelf* operator[](int index) const {
        return storage[index];
    }

private:
    vector<Shelf*> storage;
    vector<Item*> checkedOutItems;

};

#endif