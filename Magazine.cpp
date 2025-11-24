#include "Magazine.h"

// =============================================================================
// MARK: Constructors
// =============================================================================

Magazine::Magazine() {
    edition = "";
    title = "";
}

Magazine::Magazine(string title, string description, string edition):
Item(description) {
    this->edition = edition;
    this->title = title;
}

// =============================================================================
// MARK: Getters
// =============================================================================

string Magazine::getEdition() const {
    return edition;
}

string Magazine::getTitle() const {
    return title;
}

// =============================================================================
// MARK: Setters
// =============================================================================

void Magazine::setEdition(const string& edition) {
    this->edition = edition;
}

void Magazine::setTitle(const string& title) {
    this->title = title;
}

// =============================================================================
// MARK: Overloaded Operators
// =============================================================================

ostream& operator<<(ostream& out, const Magazine& magazine) {
    // Variables
    const int colWidth = 9;

    // Output
    out << left;
    out << setw(colWidth) << "ID: " << magazine.id << endl;
    out << setw(colWidth) << "Title: " << magazine.title << endl;
    out << setw(colWidth) << "Edition: " << magazine.edition << endl << endl;
    out << setw(colWidth) << "Description: " << endl
        << magazine.description << endl;
    out << right;
    
    return out;
}