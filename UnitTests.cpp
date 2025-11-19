#include "UnitTests.h"

void testAccessItemByBracket() {

}

void testAddItemByBracket() {

}


void testAddItemMethod() {
    // Test Phrase
    string testPhrase = "Book for testing testAddItemMethod";
    
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(2);

    // Create Item
    Book* testBook = new Book("Test Name", testPhrase, "Test Title", "Test Author", "01/01/2025");

    // Add Item
    library.addItem(testBook, 0, 5);

    // Test to see if item is there.
    if (library[0][5]->getItem()->getDescription() == testPhrase)
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
