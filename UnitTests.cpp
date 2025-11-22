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
    try {
        LibraryStorage lib;
        lib.addShelves(2);

        int occupiedShelf = 0;
        int occupiedComp = 0;

        Item* first = new Book("fake title","fake Desc","fake auth","fake date");
        lib.addItem(first, occupiedShelf, occupiedComp);

        Item* second = new Book("fake title2","fake Desc2","fake auth2", "fake date2");
        lib.addItem(second, occupiedShelf, occupiedComp);

        cout << "testAddItemToFilledLocation: FAIL (second add did not throw error)\n";
    }
    catch (const logic_error& e) {
        if (string(e.what()) == "This compartment already has an item")
        {
            cout << "testAddItemToFilledLocation: PASS" << endl;
        }
        else
        {
            cout << "testAddItemToFilledLocation: FAIL (wrong exception: \""
             << e.what() << "\" is not \"This compartment already has an item\"" << ")" << endl;
        }
    }
}

void testAddItemToOutOfBounds() {
    try {
        LibraryStorage lib;
        lib.addShelves(2);

        Item* newItem = new Book("oob book", "oob desc", "oob auth","oob date");
        
        int oobShelf = 1000;
        int oobComp = 1000;

        lib.addItem(newItem, oobShelf, oobComp);


        cout <<"testAddItemToOutOfBounds: FAIL (no exception thrown)\n";

    }
    catch (const out_of_range& e){
        if (string(e.what()).substr(0, 14) == "Invalid Index:")
        {
            cout << "testAddItemToOutOfBounds: PASS" << endl;
        }
        else
        {
            cout << "testAddItemToOutOfBounds: FAIL (wrong exception: \""
             << e.what() << "\" is not \"Invalid Index:\"" << ")" << endl;
        }
    }
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
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(2);

    //Create string for a Movie item
    vector<string>* a = new vector<string>{"Test Actor", "Test Actress"};

    // Create Items
    Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");
    Movie* testMovie = new Movie("Test Title", "Test Description", "Test Director", a);
    Magazine* testMagazine = new Magazine("Test Title", "Test Description", "Test Edition");

    // Add Items
    library.addItem(testBook, 0, 5);
    library.addItem(testMovie, 1, 12);
    library.addItem(testMagazine, 0, 14);

    //Check out Item(s)
    library.checkOut(1, 12, "John Doe", "02/03/2026");

    //test printCheckedIn
    library.printCheckedIn();
}

void testPrintCheckedOutMethod() {
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(2);

    //Create string for a Movie item
    vector<string>* a = new vector<string>{"Test Actor", "Test Actress"};

    // Create Items
    Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");
    Movie* testMovie = new Movie("Test Title", "Test Description", "Test Director", a);
    Magazine* testMagazine = new Magazine("Test Title", "Test Description", "Test Edition");

    // Add Items
    library.addItem(testBook, 0, 5);
    library.addItem(testMovie, 1, 12);
    library.addItem(testMagazine, 0, 14);

    //Check out Item(s)
    library.checkOut(0, 5, "James Buck", "05/06/2026");
    library.checkOut(0, 14, "Jane Fawn", "07/02/2026");

    //test printCheckedIn
    library.printCheckedOut();
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

        // If we get here, no exception was thrown -> FAIL
        cout << "testSwapItemAndNothing: FAIL (no exception thrown)" << endl;
    }
    catch (const logic_error& ex1) {
        if (string(ex1.what()) == "\n[Error]: Swap Failed. One or more compartments are empty.\n") {
            cout << "testSwapItemAndNothing: PASS" << endl;
        } else {
            cout << "testSwapItemAndNothing: FAIL (wrong exception: \""
                 << ex1.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are empty.\"" << ")" << endl;
        }
    }
    catch (const exception& ex2) {
        cout << "testSwapItemAndNothing: FAIL (wrong exception: \""
             << ex2.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are empty.\"" << ")" << endl;
    }
}

void testSwapNothingAndNothing() {
    try {
        // Create Library
        LibraryStorage library;
        library.addShelves(2);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // If we get here, no exception was thrown -> FAIL
        cout << "testSwapNothingAndNothing: FAIL (no exception thrown)" << endl;
    }
    catch (const logic_error& ex1) {
        if (string(ex1.what()) == "\n[Error]: Swap Failed. One or more compartments are empty.\n") {
            cout << "testSwapNothingAndNothing: PASS" << endl;
        } else {
            cout << "testSwapNothingAndNothing: FAIL (wrong exception: \""
                 << ex1.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are empty.\"" << ")" << endl;
        }
    }
    catch (const exception& ex2) {
        cout << "testSwapNothingAndNothing: FAIL (wrong exception: \""
             << ex2.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are empty.\"" << ")" << endl;
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

        // Checkout item
        library.checkOut(1, 1, "Test Person", "Test Date");

        // Swap Items
        library.swapItems(0, 0, 1, 1);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // If we get here, no exception was thrown -> FAIL
        cout << "testSwapItemAndCheckedOut: FAIL (no exception thrown)" << endl;
    }
    catch (const logic_error& ex1) {
        if (string(ex1.what()) == "\n[Error]: Swap Failed. One or more compartments are checked out.\n") {
            cout << "testSwapItemAndCheckedOut: PASS" << endl;
        } else {
            cout << "testSwapItemAndCheckedOut: FAIL (wrong exception: \""
                 << ex1.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are checked out.\"" << ")" << endl;
        }
    }
    catch (const exception& ex2) {
        cout << "testSwapItemAndCheckedOut: FAIL (wrong exception: \""
             << ex2.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are checked out.\"" << ")" << endl;
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

        // Checkout items
        library.checkOut(0, 0, "Test Person 0", "Test Date 0");
        library.checkOut(1, 1, "Test Person 1", "Test Date 1");

        // Swap Items
        library.swapItems(0, 0, 1, 1);

        // Attempt Swap - Should throw std::logic_error
        library.swapItems(0, 0, 1, 1);

        // If we get here, no exception was thrown -> FAIL
        cout << "testSwapCheckedOutAndCheckedOut: FAIL (no exception thrown)" << endl;
    }
    catch (const logic_error& ex1) {
        if (string(ex1.what()) == "\n[Error]: Swap Failed. One or more compartments are checked out.\n") {
            cout << "testSwapCheckedOutAndCheckedOut: PASS" << endl;
        } else {
            cout << "testSwapCheckedOutAndCheckedOut: FAIL (wrong exception: \""
                 << ex1.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are checked out.\"" << ")" << endl;
        }
    }
    catch (const exception& ex2) {
        cout << "testSwapCheckedOutAndCheckedOut: FAIL (wrong exception: \""
             << ex2.what() << "\" is not \"[Error]: Swap Failed. One or more compartments are checked out.\"" << ")" << endl;
    }
}
