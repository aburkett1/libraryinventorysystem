#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    copyrightDate = "";
}

Book::Book(string title, string description, string author, string copyrightDate):
Item(description) {
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

ostream& operator<<(ostream& out, const Book& book) {
    // Variables
    const int colWidth = 16;

    // Output
    out << left;
    out << setw(colWidth) << "ID: " << book.id << endl;
    out << setw(colWidth) << "Title: " << book.title << endl;
    out << setw(colWidth) << "Author: " << book.author << endl;
    out << setw(colWidth) << "Copyright Date: " << book.copyrightDate << endl << endl;
    out << setw(colWidth) << "Description: " << endl
        << book.description << endl;
    out << right;

    return out;
}