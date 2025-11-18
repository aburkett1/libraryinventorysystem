#include "Compartment.h"

Compartment::~Compartment() {
    delete item;
}

/********************************************************
    MARK: GETTERS
********************************************************/
Item*& Compartment::getItem() {
    return item;
}

Item* Compartment::getItem() const {
    return item;
}

string Compartment::getPerson() const {
    return person;
}

string Compartment::getDueDate() const {
    return dueDate;
}

/********************************************************
    MARK: SETTERS
********************************************************/
void Compartment::setPerson(const string& person) {
    this->person = person;
}

void Compartment::setDueDate(const string& dueDate) {
    this->dueDate = dueDate;
}