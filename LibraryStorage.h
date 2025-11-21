#ifndef LIBRARYSTORAGE_H_
#define LIBRARYSTORAGE_H_

#include "Shelf.h"

class LibraryStorage {
private:
    vector<Shelf*> storage;

public:
    LibraryStorage() {};
    ~LibraryStorage();

    void addItem(Item* newItem, int shelfLocation, int compartmentLocation);
    void addShelves(int amount);
    void checkOut(int shelf, int compartment, string name, string dueDate);
    void checkIn(int shelfIndex, int compartmentIndex);
    void printCheckedIn();
    void printCheckedOut();
    void swapItems(int item1Shelf, int item1Compartment, int item2Shelf, int item2Compartment);

    Shelf& operator[](int index);
    Shelf& operator[](int index) const;
};

#endif