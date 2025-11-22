#include "LibraryStorage.h"

LibraryStorage::~LibraryStorage() {
    for (Shelf* shelf : storage) {
        delete shelf;
    }
}

void LibraryStorage::addItem(Item* newItem, int shelfLocation, int compartmentLocation) {
    try
    {
        //if there is an item already at this location throw an error
        if((*this)[shelfLocation][compartmentLocation]->isEmpty())
        {
            //add the item at the empty compartment
            (*this)[shelfLocation][compartmentLocation]->setItem(newItem);
        }
        else{
            //throw the error to be caught by the caller and handled
            throw logic_error("This compartment already has an item");
        }
    }
    //catch the out_of_range error thrown to the overloaded [] operator
    catch (out_of_range& e)
    {        
    	//re-throw so that the caller can catch and handle it
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
  //loop through storage
  cout << "========Checked in Items========\n";
  cout << "--------------------------------" << "\n";
  for (int s = 0; s < storage.size(); s++){
    auto shelf = storage[s];

    for (int c = 0; c < 15; c++){
      //loop through each compartment
      auto compartment = (*shelf)[c];
          //if checkedin = compartment has an item and is checked in then print
      if (compartment && compartment->getItem() && compartment->isCheckedIn()){
          cout << "Shelf: " << setw(2) << s << "  |  Compartment: "<< setw(2) << c << endl;
          cout << *compartment;
          cout << "--------------------------------" << "\n\n";
        }
      }
  }
  cout << "================================\n\n";
}

void LibraryStorage::printCheckedOut() {
  //loop through storage
  cout << "========Checked out Items=======\n"; 
  cout << "--------------------------------" << "\n";
  for (int s = 0; s < storage.size(); s++){
    auto shelf = storage[s];

    for (int c = 0; c < 15; c++){
      auto compartment = (*shelf)[c];
          //if compartment has an item and is not checked in print 
      if (compartment && compartment->getItem() && !compartment->isCheckedIn()){
          cout << *compartment;
          cout << "--------------------------------" << "\n";
        }
      }
  }
  cout << "================================\n\n";
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
