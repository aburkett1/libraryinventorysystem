#ifndef BOOK_H_
#define BOOK_H_

#include "Item.h"

class Book : public Item {
public:
    Book();
    Book(string name, string description, string title, string author, string copyrightDate);

    string getTitle() const;
    string getAuthor() const;
    string getCopyrightDate() const;

    virtual void setTitle(const string& title);
    void setAuthor(const string& author);
    void setCopyrightDate(const string& copyrightDate);

    friend ostream& operator<<(ostream& out, const Book& obj);

private:
    string title;
    string author;
    string copyrightDate;
};

#endif