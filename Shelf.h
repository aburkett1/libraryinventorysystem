#ifndef SHELF_H_
#define SHELF_H_

#include "Item.h"

static const int MAX_COMPARTMENT_SIZE = 15;

class Shelf {
public:
    Shelf();

    Item*& operator[](int index) {
        return compartments[index];
    }
    
    Item* operator[](int index) const {
        return compartments[index];
    }
private:
    Item* compartments[MAX_COMPARTMENT_SIZE];
};

#endif