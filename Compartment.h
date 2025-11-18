#ifndef COMPARTMENT_H_
#define COMPARTMENT_H_

#include "Item.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

class Compartment {
public:
    Compartment();
    ~Compartment();

    Item*& getItem();
    Item* getItem() const;
    string getPerson() const;
    string getDueDate() const;

    void setItem(const Item*& item);
    void setPerson(const string& person);
    void setDueDate(const string& dueDate);

    friend ostream& operator<<(ostream& out, const Item& obj);

protected:
    Item *item;
    string person;
    string dueDate;
};

#endif