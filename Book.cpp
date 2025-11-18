#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    copyrightDate = "";
}

Book::Book(string name, string description, string title, string author, string copyrightDate):
Item(name, description) {
    this->title = title;
    this->author = author;
    this->copyrightDate = copyrightDate;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getCopyrightDate() const {
    return copyrightDate;
}

void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setCopyrightDate(const string& copyrightDate) {
    this->copyrightDate = copyrightDate;
}

ostream& operator<<(ostream& out, const Book& obj) {

    return out;
}