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
    return compartments[index];
}
    
Compartment* Shelf::operator[](int index) const {
    return compartments[index];
}