#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include "Item.h"

class Magazine : public Item {
public:
    Magazine();
    Magazine(string name, string description, int id, string edition, string title);

    string getEdition() const;
    string getTitle() const;

    void setEdition(const string& edition);
    void setTitle(const string& title);

    friend ostream& operator<<(ostream& out, const Magazine& obj);

private:
    string edition;
    string title;
};

#endif