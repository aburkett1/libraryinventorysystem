#ifndef SHELF_H_
#define SHELF_H_

#include "Item.h"

class Shelf {
private:
    static const int MAX_COMPARTMENT_SIZE = 15;

public:
    Item* compartments[MAX_COMPARTMENT_SIZE];

    Shelf() {};

    Item*& operator[](int index) {
        return compartments[index];
    }
    
    Item* operator[](int index) const {
        return compartments[index];
    }

};

#endif