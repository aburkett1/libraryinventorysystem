#include "LibraryStorage.h"

LibraryStorage::~LibraryStorage() {
    for (Shelf* shelf : storage) {
        delete shelf;
    }
}

void LibraryStorage::addItem(Item* newItem, int shelfLocation, int compartmentLocation) {
    (*this)[shelfLocation][compartmentLocation]->setItem(newItem);
}

void LibraryStorage::checkOut(int shelfIndex, int compartmentIndex, string name, string dueDate) {

    //Check range of the compartments and shelves
    Compartment* compartment = shelves.at(shelfIndex)->compartments.at(compartmentIndex);

    //Check if compartment has item
    if (compartment->getItem == nullptr)
    {
        throw runtime_error("No item in compartment exist.");
    }

    //Check if item is already checked out
    if (!compartment->getPerson().empty())
    {
        throw runtime_error("Item already checked out.");
    }

    // Check out item
    compartment->setPerson(name);
    compartment->setDueDate(dueDate);
}

void LibraryStorage::checkIn(int shelfIndex, int compartmentIndex) {

    // Get the compartment at the given location
    Compartment* compartment = shelves.at(shelfIndex)->compartments.at(compartmentIndex);

    // Make sure there is actually an item in this compartment
    if (compartment->getItem() == nullptr)
    {
        throw std::runtime_error("No item in compartment exists.");
    }

    // Make sure this item is currently checked out
    if (compartment->getPerson().empty())
    {
        throw std::runtime_error("Item is not currently checked out.");
    }

    // "Check in" the item: clear borrower name and due date
    compartment->setPerson("");
    compartment->setDueDate("");
}

void LibraryStorage::printCheckedIn() {

}

void LibraryStorage::printCheckedOut() {

}

void LibraryStorage::swapItems(int item1Shelf, int item1Compartment, int item2Shelf, int item2Compartment) {
    // Skip swap if either compartment is empty
    if ((*this)[item1Shelf][item1Compartment]->isEmpty() || (*this)[item2Shelf][item2Compartment]->isEmpty()) {
        // Throw Exception
    }

    // Skip swap if either compartment is checked out
    if (!(*this)[item1Shelf][item1Compartment]->isCheckedIn() || !(*this)[item2Shelf][item2Compartment]->isCheckedIn()) {
        // Throw Exception
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