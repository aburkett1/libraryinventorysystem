#include "Item.h"

Item::Item() {
    description = "";
    id = nextId++;
}

Item::Item(string description) {
    this->description = description;
    this->id = nextId++;
}

string Item::getDescription() const {
    return description;
}

int Item::getId() const {
    return id;
}


void Item::setDescription(const string& description) {
    this->description = description;
}