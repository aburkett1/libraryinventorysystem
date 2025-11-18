#include "Shelf.h"

Shelf::~Shelf() {
    
}

Item*& Shelf::operator[](int index) {
    return compartments[index]->getItem();
}
    
Item* Shelf::operator[](int index) const {
    return compartments[index]->getItem();
}