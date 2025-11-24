#ifndef BOOK_H_
#define BOOK_H_

#include "Item.h"

class Book : public Item {
public:
    // Constructors
    Book();
    Book(string title, string description, string author, string copyrightDate);

    // Getters
    string getTitle() const;
    string getAuthor() const;
    string getCopyrightDate() const;

    // Setters
    virtual void setTitle(const string& title);
    void setAuthor(const string& author);
    void setCopyrightDate(const string& copyrightDate);

    // Overloaded Operators
    friend ostream& operator<<(ostream& out, const Book& book);

private:
    string title;
    string author;
    string copyrightDate;
};

#endif