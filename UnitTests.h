#ifndef UNITTESTS_H_
#define UNITTESTS_H_

#include <iostream>
#include "LibraryStorage.h"
using namespace std;

void testAccessItemByBracket();
void testAddItemByBracket();

void testAddItemMethod();
void testAddItemToFilledLocation();
void testAddItemToOutOfBounds();

void testCheckInMethod();
void testCheckInItemThatsNotCheckedOut();

void testCheckOutMethod();
void testCheckOutItemThatsNotCheckedIn();

void testPrintCheckedInMethod();
void testPrintCheckedOutMethod();

void testSwapItemAndItem();
void testSwapItemAndNothing();
void testSwapNothingAndNothing();

#endif