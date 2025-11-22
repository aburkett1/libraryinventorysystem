#include "Book.h"
#include "Magazine.h"
#include "Movie.h"
#include "LibraryStorage.h"
#include "Shelf.h"
#include "UnitTests.h"

// ==== main ===================================================================
//
// =============================================================================
int main()
{
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

    
    testPrintCheckedInMethod();
    cout << endl << endl;

    testPrintCheckedOutMethod();
    cout << endl << endl;

    return 0;
} // end of main()
// =============================================================================