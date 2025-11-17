#include "Item.h"

Item::Item() {
    name = "";
    description = "";
    id = 0;
    person = "";
    dueDate = "";
}

Item::Item(string name, string description, int id) {
    this->name = name;
    this->description = description;
    this->id = id;
    this->person = "";
    this->dueDate = "";
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

string Item::getPerson() const {
    return person;
}

string Item::getDueDate() const {
    return dueDate;
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

void Item::setPerson(const string& person) {
    this->person = person;
}

void Item::setDueDate(const string& dueDate) {
    this->dueDate = dueDate;
}


ostream& operator<<(ostream& out, const Item& obj) {

    return out;
}