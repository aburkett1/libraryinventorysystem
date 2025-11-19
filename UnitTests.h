#ifndef UNITTESTS_H_
#define UNITTESTS_H_

#include <iostream>
#include <typeinfo>
#include "LibraryStorage.h"
using namespace std;

void testAccessCompartmentByBracket();

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