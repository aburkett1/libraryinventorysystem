#include "Item.h"

// =============================================================================
// MARK: Constructors
// =============================================================================

Item::Item() {
    description = "";
    id = nextId++;
}

Item::Item(string description) {
    this->description = description;
    this->id = nextId++;
}

// =============================================================================
// MARK: Getters
// =============================================================================

string Item::getDescription() const {
    return description;
}

int Item::getId() const {
    return id;
}

// =============================================================================
// MARK: Setters
// =============================================================================

void Item::setDescription(const string& description) {
    this->description = description;
}

// =============================================================================
// MARK: Overloaded Operators
// =============================================================================

bool Item::operator==(Item& other) {
    return id == other.id ? true : false;
}