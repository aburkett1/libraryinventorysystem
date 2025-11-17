#ifndef BOOK_H_
#define BOOK_H_

#include "Item.h"

class Book : public Item {
public:
    Book();

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getCopyrightDate() const {
        return copyrightDate;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    void setAuthor(const string& author) {
        this->author = author;
    }

    void setCopyrightDate(const string& copyrightDate) {
        this->copyrightDate = copyrightDate;
    }

    friend ostream& operator<<(ostream& out, const Book& obj);

private:
    string title;
    string author;
    string copyrightDate;
};

#endif