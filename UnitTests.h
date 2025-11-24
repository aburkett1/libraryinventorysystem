#ifndef UNITTESTS_H_
#define UNITTESTS_H_

#include <iostream>
#include <typeinfo>
#include "LibraryStorage.h"
using namespace std;

// Access Tests
void testAccessCompartmentByBracket();

// Add Item Tests
void testAddItemMethod();
void testAddItemToFilledLocation();
void testAddItemToOutOfBounds();

// Check In Tests
void testCheckInMethod();
void testCheckInItemThatsNotCheckedOut();

// Check Out Tests
void testCheckOutMethod();
void testCheckOutItemThatsNotCheckedIn();

// Swap Item Tests
void testSwapItemAndItem();
void testSwapItemAndNothing();
void testSwapNothingAndNothing();
void testSwapItemAndCheckedOut();
void testSwapCheckedOutAndCheckedOut();

#endif