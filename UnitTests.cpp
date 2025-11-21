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
    // Test Phrase
    string testPhrase = "Book for testing testAddItemMethod";

    try{
        //Create Library
        LibraryStorage library = LibraryStorage();
        library.addShelves(1);

        // Creating Item
        Book* testBook = new Book("Test Name", testPhrase, "Test Title", "Test Author", "01/01/2025");

        // Add Item
        library.addItem(testBook, 0,0);

        // Check Out an Item
        library.checkOut(0, 0, "John", "11/11/2025");

        //Check Item In
        library.checkIn(testBook);

        // Validate person and due date
        string person = library[0][0].getPerson();
        string due = library[0][0].getDueDate();

        if (person == "" && due == "")
        {
            cout << "testCheckInMethod: PASS" << endl;
        }
        else
        {
            cout << "testCheckInMethod: FAIL" << endl;
        }
    }
    catch(const exception& e){
        cout << "testCheckInMethod: FAIL (expecetion: " << e.what() << ")" << endl;
    }
}

void testCheckInItemThatsNotCheckedOut() {
    // Test Phrase
    string testPhrase = "Book for testing testAddItemMethod";

    try{
        //Create Library
        LibraryStorage library = LibraryStorage();
        library.addShelves(1);

        // Creating Item
        Book* testBook = new Book("Test Name", testPhrase, "Test Title", "Test Author", "01/01/2025");
        library.addItem(testBook, 0, 0);

        // Call checkIn
        library.checkIn(testBook);

        // Get Compartment Info
        string person = library[0][0].getPerson();
        string due = library[0][0].getDueDate();


        if (person == "" && due == "")
        {
            cout << "testCheckInItemThatsNotCheckedOut: PASS" << endl;
        }
        else
        {
            cout << "testCheckInItemThatsNotCheckedOut: FAIL" << endl;
        }
    }
    catch(const exception& e){
        cout << "testCheckInItemThatsNotCheckedOut: FAIL (exception: " << e.what() << ")" << endl;
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
        cout << "testCheckOutItemThatsNotCheckedIn: PASS" << endl;
    }
    catch (const exception& e) {
        cout << "testCheckOutItemThatsNotCheckedIn: FAIL (wrong exception: "
             << e.what() << ")" << endl;
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
