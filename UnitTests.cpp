#include "UnitTests.h"

void testAccessCompartmentByBracket() {
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(2);

    // Test Type Match
    if (typeid(library[0][2]) == typeid(Compartment*))
    {
        cout << "testAccessCompartmentByBracket: PASS" << endl;
    }
    else
    {
        cout << "testAccessCompartmentByBracket: FAIL" << endl;
    }
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
    if (*testBook == *bookAtLocation)
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
    // Create Library
    LibraryStorage library;
    library.addShelves(2);

    // Create Items
    Book* testBook = new Book("Book Title", "Book Description ", "Book Author ", "01/01/2001");
    Magazine* testMag = new Magazine("Mag Title", "Mag Description", "Mag Edition");

    // Add Items
    library.addItem(testBook, 0, 0);
    library.addItem(testMag, 1, 1);

    // Swap Items
    library.swapItems(0, 0, 1, 1);

    // Access items at locations
    Item* itemAtLocation00 = library[0][0]->getItem();
    Item* itemAtLocation11 = library[1][1]->getItem();

    // Test if swap was successful
    cout << "testSwapItemAndItem: ";
    cout << (*testBook == *itemAtLocation11 && *testMag == *itemAtLocation00 ? "PASS" : "FAIL");
    cout << endl;
}

void testSwapItemAndNothing() {
    try {
        // Create Library
        LibraryStorage library;
        library.addShelves(2);

        // Create Items
        Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");

        // Add Item
        library.addItem(testBook, 0, 0);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // Test fails if swap goes through
        cout << "testSwapItemAndNothing: FAIL" << endl;
    }
    catch (const logic_error&) {
        cout << "testSwapItemAndNothing: PASS" << endl;
    }
}

void testSwapNothingAndNothing() {
    try {
        // Create Library
        LibraryStorage library;
        library.addShelves(2);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // Test fails if swap goes through
        cout << "testSwapNothingAndNothing: FAIL" << endl;
    }
    catch (const logic_error&) {
        cout << "testSwapNothingAndNothing: PASS" << endl;
    }
}

void testSwapItemAndCheckedOut() {
    try {
        // Create Library
        LibraryStorage library;
        library.addShelves(2);

        // Create Items
        Book* testBook = new Book("Book Title", "Book Description ", "Book Author ", "01/01/2001");
        Magazine* testMag = new Magazine("Mag Title", "Mag Description", "Mag Edition");

        // Add Items
        library.addItem(testBook, 0, 0);
        library.addItem(testMag, 1, 1);

        // MARK: PLACEHOLDER
        //       FOR CHECKOUT LOGIC
        library[1][1]->setPerson("Test Person 1");
        library[1][1]->setDueDate("Test Date 1");

        // Swap Items
        library.swapItems(0, 0, 1, 1);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // Test fails if swap goes through
        cout << "testSwapItemAndCheckedOut: FAIL" << endl;
    }
    catch (const logic_error&) {
        cout << "testSwapItemAndCheckedOut: PASS" << endl;
    }
}

void testSwapCheckedOutAndCheckedOut() {
    try {
        // Create Library
        LibraryStorage library;
        library.addShelves(2);

        // Create Items
        Book* testBook = new Book("Book Title", "Book Description ", "Book Author ", "01/01/2001");
        Magazine* testMag = new Magazine("Mag Title", "Mag Description", "Mag Edition");

        // Add Items
        library.addItem(testBook, 0, 0);
        library.addItem(testMag, 1, 1);

        // MARK: PLACEHOLDER
        //       FOR CHECKOUT LOGIC
        library[0][0]->setPerson("Test Person 0");
        library[0][0]->setDueDate("Test Date 0");
        library[1][1]->setPerson("Test Person 1");
        library[1][1]->setDueDate("Test Date 1");

        // Swap Items
        library.swapItems(0, 0, 1, 1);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // Test fails if swap goes through
        cout << "testSwapCheckedOutAndCheckedOut: FAIL" << endl;
    }
    catch (const logic_error&) {
        cout << "testSwapCheckedOutAndCheckedOut: PASS" << endl;
    }
}