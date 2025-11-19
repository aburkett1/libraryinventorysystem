#ifndef SHELF_H_
#define SHELF_H_

#include "Compartment.h"

class Shelf {
private:
    static const int MAX_COMPARTMENT_SIZE = 15;
    Compartment* compartments[MAX_COMPARTMENT_SIZE];

public:
    Shelf();
    ~Shelf();

    Compartment*& operator[](int index);
    Compartment* operator[](int index) const;
};

#endif