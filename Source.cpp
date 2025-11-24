#include "Book.h"
#include "Magazine.h"
#include "Movie.h"
#include "LibraryStorage.h"
#include "Shelf.h"
#include "UnitTests.h"

void showCasePrintCheckedInMethod();
void showCasePrintCheckedOutMethod();

// =============================================================================
// MARK: Main
// =============================================================================

int main()
{
    // =============================================================================
    // MARK: Print Unit Tests
    // =============================================================================

    cout << "================================" << endl;
    cout << "Unit Tests" << endl;
    cout << "================================" << endl;
    cout << endl << endl;

    cout << "Access Compartment" << endl;
    cout << "--------------------------------" << endl;
    testAccessCompartmentByBracket();
    cout << endl << endl;

    cout << "Add Item" << endl;
    cout << "--------------------------------" << endl;
    testAddItemMethod();
    testAddItemToFilledLocation();
    testAddItemToOutOfBounds();
    cout << endl << endl;

    cout << "Check In Item" << endl;
    cout << "--------------------------------" << endl;
    testCheckInMethod();
    testCheckInItemThatsNotCheckedOut();
    cout << endl << endl;

    cout << "Check Out Item" << endl;
    cout << "--------------------------------" << endl;
    testCheckOutMethod();
    testCheckOutItemThatsNotCheckedIn();
    cout << endl << endl;

    cout << "Swap Item" << endl;
    cout << "--------------------------------" << endl;
    testSwapItemAndItem();
    testSwapItemAndNothing();
    testSwapNothingAndNothing();
    testSwapItemAndCheckedOut();
    testSwapCheckedOutAndCheckedOut();
    cout << endl << endl;

    
    // =============================================================================
    // MARK: Show that the print methods work.
    // =============================================================================

    // Print items that are checked in.
    showCasePrintCheckedInMethod();
    cout << endl << endl;

    // Print items that are checked out.
    showCasePrintCheckedOutMethod();
    cout << endl << endl;

    return 0;
} // end of main()
// =============================================================================

// =============================================================================
// MARK: Showcase Methods
// =============================================================================

void showCasePrintCheckedInMethod() {
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

void showCasePrintCheckedOutMethod() {
    // Create Library
    LibraryStorage library = LibraryStorage();
    library.addShelves(2);

    //Create string for a Movie item
    vector<string>* actorsList = new vector<string>{"Test Actor", "Test Actress"};

    // Create Items
    Book* testBook = new Book("Test Title", "Test Description", "Test Author", "01/01/2025");
    Movie* testMovie = new Movie("Test Title", "Test Description", "Test Director", actorsList);
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