#include "LibraryStorage.h"

LibraryStorage::~LibraryStorage() {
    for (Shelf* shelf : storage) {
        delete shelf;
    }
}

void LibraryStorage::addItem(Item* newItem, int shelfLocation, int compartmentLocation) {
    try
    {
        (*this)[shelfLocation][compartmentLocation]->setItem(newItem);
    }
    catch (out_of_range& e)
    {        
        throw;
    }
}

void LibraryStorage::checkOut(int shelfIndex, int compartmentIndex, string name, string dueDate) {
    try
    {
        //Check range of the compartments and shelves
        Compartment* compartment = (*this)[shelfIndex][compartmentIndex];

        //Check if compartment has item
        if (compartment->getItem() == nullptr)
        {
            throw runtime_error("No item in compartment exist.");
        }

        //Check if item is already checked out
        if (!compartment->isCheckedIn())
        {
            throw runtime_error("Item already checked out.");
        }

        // Check out item
        compartment->setPerson(name);
        compartment->setDueDate(dueDate);
    }
    catch(const exception& e)
    {
        throw;
    }
}

void LibraryStorage::checkIn(int shelfIndex, int compartmentIndex) {
    try
    {
        // Get the compartment at the given location
        Compartment* compartment = (*this)[shelfIndex][compartmentIndex];

        // Make sure there is actually an item in this compartment
        if (compartment->getItem() == nullptr)
        {
            throw runtime_error("No item in compartment exists.");
        }

        // Make sure this item is currently checked out
        if (compartment->isCheckedIn())
        {
            throw runtime_error("Item is not currently checked out.");
        }

        // "Check in" the item: clear borrower name and due date
        compartment->setPerson("");
        compartment->setDueDate("");
    }
    catch(const exception& e)
    {
        throw;
    }
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
    if (index < 0 || index >= storage.size())
    {
        throw out_of_range("Invalid Index: " + to_string(index) + " is not 0 <= index < " + to_string(storage.size()));
    }
    return *storage[index];
}

Shelf& LibraryStorage::operator[](int index) const {
    if (index < 0 || index >= storage.size())
    {
        throw out_of_range("Invalid Index: " + to_string(index) + " is not 0 <= index < " + to_string(storage.size()));
    }
    return *storage[index];
}