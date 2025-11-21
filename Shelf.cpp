#include "Shelf.h"

Shelf::Shelf() {
    for (int i = 0; i < MAX_COMPARTMENT_SIZE; i++) {
        compartments[i] = new Compartment();
    }
}

Shelf::~Shelf() {
    for (int i = 0; i < MAX_COMPARTMENT_SIZE; i++) {
        delete compartments[i];
    }
}

Compartment*& Shelf::operator[](int index) {
    if (index < 0 || index >= MAX_COMPARTMENT_SIZE)
    {
        throw out_of_range("Invalid Index: " + to_string(index) + " is not 0 <= index < " + to_string(MAX_COMPARTMENT_SIZE));
    }
    return compartments[index];
}
    
Compartment* Shelf::operator[](int index) const {
    if (index < 0 || index >= MAX_COMPARTMENT_SIZE)
    {
        throw out_of_range("Invalid Index: " + to_string(index) + " is not 0 <= index < " + to_string(MAX_COMPARTMENT_SIZE));
    }
    return compartments[index];
}