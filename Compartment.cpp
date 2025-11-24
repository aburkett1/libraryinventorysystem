#include "Compartment.h"

// =============================================================================
// MARK: Constructors
// =============================================================================

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

// =============================================================================
// MARK: Getters
// =============================================================================

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

bool Compartment::isEmpty() const {
    return item == nullptr;
}

bool Compartment::isCheckedIn() const {
    return person.empty() && dueDate.empty();
}

// =============================================================================
// MARK: Setters
// =============================================================================

void Compartment::setItem(Item*& item) {
    this->item = item;
}

void Compartment::setPerson(const string& person) {
    this->person = person;
}

void Compartment::setDueDate(const string& dueDate) {
    this->dueDate = dueDate;
}

// =============================================================================
// MARK: Overloaded Operators
// =============================================================================

ostream& operator<<(ostream& out, const Compartment& compartment) {
    // Variables
    const int colWidth = 7;

    // Cast Item
    Item* item = compartment.getItem();
    Book* book = dynamic_cast<Book*>(item);
    Magazine* magazine = dynamic_cast<Magazine*>(item);
    Movie* movie = dynamic_cast<Movie*>(item);

    // Output
    out << left;

    if (book)
    {
        out << *book;
    }
    else if (magazine)
    {
        out << *magazine;
    }
    else if (movie)
    {
        out << *movie;
    }

    out << endl;

    if (!compartment.isCheckedIn())
    {
        out << "Item checked out by " << compartment.getPerson() << ".\n";
        out << "Due Date: " << compartment.getDueDate() << ".\n";
    }

    out << right;

    return out;
}

Compartment& Compartment::operator=(const Compartment& rightside) {
    if (this != &rightside) {
        this->item = rightside.item;
        this->person = rightside.person;
        this->dueDate = rightside.dueDate;
    }
    
    return *this;
}