#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    Item();
    Item(string description);
    virtual ~Item() {}

    string getDescription() const;
    int getId() const;

    void setDescription(const string& description);
    virtual void setTitle(const string& title) = 0;

protected:
    string description;
    int id;
    inline static int nextId = 0;
};

#endif