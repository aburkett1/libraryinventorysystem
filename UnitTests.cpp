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