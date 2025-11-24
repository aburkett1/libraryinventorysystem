#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include "Item.h"

class Magazine : public Item {
public:
    // Constructors
    Magazine();
    Magazine(string title, string description, string edition);

    // Getters
    string getEdition() const;
    string getTitle() const;

    // Setters
    void setEdition(const string& edition);
    void setTitle(const string& title);

    // Overloaded Operators
    friend ostream& operator<<(ostream& out, const Magazine& magazine);

private:
    string edition;
    string title;
};

#endif