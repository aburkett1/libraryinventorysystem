#include "Compartment.h"

Item*& Compartment::getItem() {
    return item;
}

Item* Compartment::getItem() const {
    return item;
}