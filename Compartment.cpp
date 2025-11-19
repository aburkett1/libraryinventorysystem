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

bool Compartment::isEmpty() const {
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
        out << setw(colWidth) << "ID: " << book->getId() << endl;
        out << setw(colWidth) << "Title: " << book->getTitle() << endl;
    }
    else if (magazine)
    {
        out << setw(colWidth) << "ID: " << magazine->getId() << endl;
        out << setw(colWidth) << "Title: " << magazine->getTitle() << endl;
    }
    else if (movie)
    {
        out << setw(colWidth) << "ID: " << movie->getId() << endl;
        out << setw(colWidth) << "Title: " << movie->getTitle() << endl;
    }

    out << endl;

    if (compartment.getPerson() != "")
    {
        out << "Item checked out by " << compartment.getPerson() << ".\n";
        out << "Due Date: " << compartment.getDueDate() << ".\n";
    }
    else
    {
        out << "Item checked in.\n";
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