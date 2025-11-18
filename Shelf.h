#ifndef SHELF_H_
#define SHELF_H_

#include "Compartment.h"

class Shelf {
private:
    static const int MAX_COMPARTMENT_SIZE = 15;

public:
    Compartment* compartments[MAX_COMPARTMENT_SIZE];

    Shelf() {};
    ~Shelf();

    Item*& operator[](int index) {
        return compartments[index]->getItem();
    }
    
    Item* operator[](int index) const {
        return compartments[index]->getItem();
    }

};

#endif