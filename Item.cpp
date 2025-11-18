#include "Item.h"

Item::Item() {
    name = "";
    description = "";
    id = 0;
}

Item::Item(string name, string description, int id) {
    this->name = name;
    this->description = description;
    this->id = id;
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

void Item::setId(int id) {
    this->id = id;
}

ostream& operator<<(ostream& out, const Item& obj) {

    return out;
}