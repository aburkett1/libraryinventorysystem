#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    Item();
    Item(string name, string description, int id);

    string getName() const;
    string getDescription() const;
    int getId() const;

    void setName(const string& name);
    void setDescription(const string& description);
    void setId(int id);

    virtual void setTitle(const string& title) = 0;

    friend ostream& operator<<(ostream& out, const Item& obj);

protected:
    string name;
    string description;
    int id;
};

#endif