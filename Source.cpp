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
    testAccessItemByBracket();
    testAddItemByBracket();

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

    return 0;
} // end of main()
// =============================================================================