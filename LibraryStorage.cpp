#include "LibraryStorage.h"

LibraryStorage::~LibraryStorage() {

}

void LibraryStorage::addItem(Item* newItem, int shelfLocation, int compartmentLocation) {
    (*this)[shelfLocation][compartmentLocation] = newItem;
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