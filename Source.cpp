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
    testAccessCompartmentByBracket();

    testAddItemMethod();
    testAddItemToFilledLocation();
    testAddItemToOutOfBounds();

    testCheckInMethod();
    testCheckInItemThatsNotCheckedOut();

    testCheckOutMethod();
    testCheckOutItemThatsNotCheckedIn();

    testPrintCheckedInMethod();
    testPrintCheckedOutMethod();

    testSwapItemAndItem();
    testSwapItemAndNothing();
    testSwapNothingAndNothing();
    testSwapItemAndCheckedOut();
    testSwapCheckedOutAndCheckedOut();

    return 0;
} // end of main()
// =============================================================================