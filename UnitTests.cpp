#include "UnitTests.h"

void testAccessItemByBracket() {

}

void testAddItemByBracket() {

}


void testAddItemMethod() {
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(2);

    // Create Item
    Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");

    // Add Item
    library.addItem(testBook, 0, 5);

    // Access item at location
    Book* bookAtLocation = dynamic_cast<Book*>(library[0][5]->getItem());

    // Test to see if item is there.
    if (testBook == bookAtLocation)
    {
        cout << "testAddItemMethod: PASS" << endl;
    }
    else
    {
        cout << "testAddItemMethod: FAIL" << endl;
    }
}

void testAddItemToFilledLocation() {

}

void testAddItemToOutOfBounds() {

}


void testCheckInMethod() {

}

void testCheckInItemThatsNotCheckedOut() {

}


void testCheckOutMethod() {

}

void testCheckOutItemThatsNotCheckedIn() {

}


void testPrintCheckedInMethod() {

}

void testPrintCheckedOutMethod() {

}


void testSwapItemAndItem() {

}

void testSwapItemAndNothing() {

}

void testSwapNothingAndNothing() {

}
