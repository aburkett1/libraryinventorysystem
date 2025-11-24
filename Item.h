#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <iomanip>
using namespace std;

class Item {
public:
    // Constructors
    Item();
    Item(string description);
    virtual ~Item() {}

    // Getters
    string getDescription() const;
    int getId() const;

    // Setters
    void setDescription(const string& description);
    virtual void setTitle(const string& title) = 0;

    // Overloaded Operators
    bool operator==(Item& other);

protected:
    string description;
    int id;
    inline static int nextId = 0;
};

#endif