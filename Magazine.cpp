#include "Magazine.h"

Magazine::Magazine() {
    edition = "";
    title = "";
}

Magazine::Magazine(string name, string description, int id, string edition, string title):
Item(name, description, id) {
    this->edition = edition;
    this->title = title;
}

string Magazine::getEdition() const {
    return edition;
}

string Magazine::getTitle() const {
    return title;
}

void Magazine::setEdition(const string& edition) {
    this->edition = edition;
}

void Magazine::setTitle(const string& title) {
    this->title = title;
}


ostream& operator<<(ostream& out, const Magazine& obj) {

    return out;
}