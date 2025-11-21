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
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(1);

    // Create Item
    Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");

    // Add Item
    library.addItem(testBook, 0, 0);

    try
    {
        // Check Out an Item
        library.checkOut(0, 0, "John", "11/11/2025");

        // Check Item In
        library.checkIn(0, 0);

        // Validate person and due date
        if (library[0][0]->isCheckedIn())
        {
            cout << "testCheckInMethod: PASS" << endl;
        }
        else
        {
            cout << "testCheckInMethod: FAIL" << endl;
        }
    }
    catch(const exception& e)
    {
        cout << "testCheckInMethod: FAIL (expecetion: " << e.what() << ")" << endl;
    }
}

void testCheckInItemThatsNotCheckedOut() {
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(1);

    // Create Item
    Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");

    // Add Item
    library.addItem(testBook, 0, 0);

    try
    {
        // Check Item In
        library.checkIn(0, 0);
    }
    catch(const runtime_error& e)
    {
        if (string(e.what()) == "Item is not currently checked out.")
        {
            cout << "testCheckInItemThatsNotCheckedOut: PASS" << endl;
        }
        else
        {
            cout << "testCheckInItemThatsNotCheckedOut: FAIL (wrong exception: \""
             << e.what() << "\" is not \"Item is not currently checked out.\"" << ")" << endl;
        }
    }
    catch(const exception& e)
    {
        cout << "testCheckInItemThatsNotCheckedOut: FAIL (wrong exception: \""
             << e.what() << "\" is not \"Item is not currently checked out.\"" << ")" << endl;
    }
}

void testCheckOutMethod() {
    try {
        // Create Library
        LibraryStorage library = LibraryStorage();
        library.addShelves(1);

        // Create Item
        Book* testBook = new Book("Test Title", "Test Description",
                                  "Test Author", "01/01/2025");

        // Add Item to shelf 0, compartment 0
        library.addItem(testBook, 0, 0);

        // Check out item
        string borrower = "John";
        string dueDate = "02/01/2025";
        library.checkOut(0, 0, borrower, dueDate);

        // Get the compartment where the book lives
        Compartment* comp = library[0][0];

        // Verify state
        if ((comp->getItem() == testBook) &&
            (comp->getPerson() == borrower) &&
            (comp->getDueDate() == dueDate)) {
            cout << "testCheckOutMethod: PASS" << endl;
        } else {
            cout << "testCheckOutMethod: FAIL" << endl;
        }
    }
    catch (const exception& e) {
        cout << "testCheckOutMethod: FAIL (exception: " << e.what() << ")" << endl;
    }
}

void testCheckOutItemThatsNotCheckedIn() {
    try {
        // Create Library
        LibraryStorage library = LibraryStorage();
        library.addShelves(1);

        // Create Item
        Book* testBook = new Book("Test Title", "Test Description",
                                  "Test Author", "01/01/2025");

        // Add Item to shelf 0, compartment 0
        library.addItem(testBook, 0, 0);

        // First checkout should succeed
        library.checkOut(0, 0, "John", "02/01/2025");

        // Second checkout of the same compartment should throw
        library.checkOut(0, 0, "Jane", "03/01/2025");

        // If we get here, no exception was thrown -> FAIL
        cout << "testCheckOutItemThatsNotCheckedIn: FAIL (no exception thrown)" << endl;
    }
    catch (const runtime_error& e) {
        // We expect "Item already checked out."
        if (string(e.what()) == "Item already checked out.")
        {
            cout << "testCheckOutItemThatsNotCheckedIn: PASS" << endl;
        }
        else
        {
            cout << "testCheckOutItemThatsNotCheckedIn: FAIL (wrong exception: \""
             << e.what() << "\" is not \"Item already checked out.\"" << ")" << endl;
        }
    }
    catch (const exception& e) {
        cout << "testCheckOutItemThatsNotCheckedIn: FAIL (wrong exception: \""
             << e.what() << "\" is not \"Item already checked out.\"" << ")" << endl;
    }
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
