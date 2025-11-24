#ifndef COMPARTMENT_H_
#define COMPARTMENT_H_

#include "Item.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

class Compartment {
public:
    // Constructors
    Compartment();
    Compartment(const Compartment& other);
    ~Compartment();

    // Getters
    Item*& getItem();
    Item* getItem() const;
    string getPerson() const;
    string getDueDate() const;
    bool isEmpty() const;
    bool isCheckedIn() const;

    // Setters
    void setItem(Item*& item);
    void setPerson(const string& person);
    void setDueDate(const string& dueDate);

    // Overloaded Operators
    friend ostream& operator<<(ostream& out, const Compartment& compartment);
    Compartment& operator=(const Compartment& rightside);

protected:
    Item *item;
    string person;
    string dueDate;
};

#endif