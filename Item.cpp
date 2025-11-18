#include "Item.h"

Item::Item() {
    name = "";
    description = "";
    id = nextId++;
}

Item::Item(string name, string description) {
    this->name = name;
    this->description = description;
    this->id = nextId++;
}

string Item::getName() const {
    return name;
}

string Item::getDescription() const {
    return description;
}

int Item::getId() const {
    return id;
}

void Item::setName(const string& name) {
    this->name = name;
}

void Item::setDescription(const string& description) {
    this->description = description;
}

ostream& operator<<(ostream& out, const Item& obj) {

    return out;
}