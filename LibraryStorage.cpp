#include "LibraryStorage.h"

LibraryStorage::~LibraryStorage() {

}

void LibraryStorage::addItem(Item* newItem, int shelfLocation, int compartmentLocation) {
    (*this)[shelfLocation][compartmentLocation] = newItem;
}

void LibraryStorage::checkOut(string name, string dueDate) {

}

void LibraryStorage::checkIn(Item* returnItem) {

}

void LibraryStorage::printCheckedIn() {

}

void LibraryStorage::printCheckedOut() {

}

// Check for two items existing
// Should not swap if there is only one item
// Should not swap if there are no items
void LibraryStorage::swapItems(int item1Shelf, int item1Compartment, int item2Shelf, int item2Compartment) {

}

void LibraryStorage::addShelves(int amount) {
    for (int i = 0; i < amount; i++)
    {
        Shelf* shelf = new Shelf();
        storage.push_back(shelf);
    }
}