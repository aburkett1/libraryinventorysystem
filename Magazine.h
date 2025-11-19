#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include "Item.h"

class Magazine : public Item {
public:
    Magazine();
    Magazine(string title, string description, string edition);

    string getEdition() const;
    string getTitle() const;

    void setEdition(const string& edition);
    void setTitle(const string& title);

    friend ostream& operator<<(ostream& out, const Magazine& magazine);

private:
    string edition;
    string title;
};

#endif