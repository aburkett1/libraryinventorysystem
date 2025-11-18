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

Item*& Shelf::operator[](int index) {
    return compartments[index]->getItem();
}
    
Item* Shelf::operator[](int index) const {
    return compartments[index]->getItem();
}