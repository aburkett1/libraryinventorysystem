#include "LibraryStorage.h"

LibraryStorage::~LibraryStorage() {
    for (Shelf* shelf : storage) {
        delete shelf;
    }
}

void LibraryStorage::addItem(Item* newItem, int shelfLocation, int compartmentLocation) {
    (*this)[shelfLocation][compartmentLocation]->setItem(newItem);
}

void LibraryStorage::checkOut(string name, string dueDate) {

}

void LibraryStorage::checkIn(Item* returnItem) {

}

void LibraryStorage::printCheckedIn() {

}

void LibraryStorage::printCheckedOut() {

}

void LibraryStorage::swapItems(int item1Shelf, int item1Compartment, int item2Shelf, int item2Compartment) {
    if ((*this)[item1Shelf][item1Compartment]->isEmpty() || (*this)[item2Shelf][item2Compartment]->isEmpty()) {
        throw std::logic_error("\n[Error]: Swap Failed. One or more compartments are empty.\n");
    }

    if (!(*this)[item1Shelf][item1Compartment]->isCheckedIn() || !(*this)[item2Shelf][item2Compartment]->isCheckedIn()) {
        throw std::logic_error("\n[Error]: Swap Failed. One or more compartments are checked out.\n");
    }

    // Swap compartment pointers
    Compartment* temp = (*this)[item1Shelf][item1Compartment];
    (*this)[item1Shelf][item1Compartment] = (*this)[item2Shelf][item2Compartment];
    (*this)[item2Shelf][item2Compartment] = temp;
}

void LibraryStorage::addShelves(int amount) {
    for (int i = 0; i < amount; i++)
    {
        Shelf* shelf = new Shelf();
        storage.push_back(shelf);
    }
}

Shelf& LibraryStorage::operator[](int index) {
    return *storage[index];
}

Shelf& LibraryStorage::operator[](int index) const {
    return *storage[index];
}