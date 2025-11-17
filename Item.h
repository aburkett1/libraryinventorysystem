#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>
using namespace std;

class Item {
public:
    Item();

    string getName() const {
        return name;
    }

    string getDescription() const {
        return description;
    }

    int getId() const {
        return id;
    }

    string getPerson() const {
        return person;
    }

    string getDueDate() const {
        return dueDate;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setDescription(const string& description) {
        this->description = description;
    }

    void setId(int id) {
        this->id = id;
    }

    void setPerson(const string& person) {
        this->person = person;
    }

    void setDueDate(const string& dueDate) {
        this->dueDate = dueDate;
    }

    virtual void setTitle() = 0;

    friend ostream& operator<<(ostream& out, const Item& obj);

protected:
    string name;
    string description;
    int id;
    string person;
    string dueDate;
};

#endif