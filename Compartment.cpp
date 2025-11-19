#include "Compartment.h"

Compartment::Compartment() {
    item = nullptr;
    person = "";
    dueDate = "";
}

Compartment::Compartment(const Compartment& other) {
    this->item = other.item;
    this->person = other.person;
    this->dueDate = other.dueDate;
}

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

bool Compartment::empty() const {
    return item == nullptr;
}

/********************************************************
    MARK: SETTERS
********************************************************/
void Compartment::setItem(Item*& item) {
    this->item = item;
}

void Compartment::setPerson(const string& person) {
    this->person = person;
}

void Compartment::setDueDate(const string& dueDate) {
    this->dueDate = dueDate;
}

/********************************************************
    MARK: OPERATORS
********************************************************/
Compartment& Compartment::operator=(const Compartment& rightside) {
    if (this != &rightside) {
        this->item = rightside.item;
        this->person = rightside.person;
        this->dueDate = rightside.dueDate;
    }
    
    return *this;
}