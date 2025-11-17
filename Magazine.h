#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include "Item.h"

class Magazine : public Item {
public:
    Magazine();

    string getEdition() const {
        return edition;
    }

    string getTitle() const {
        return title;
    }

    void setEdition(const string& edition) {
        this->edition = edition;
    }

    void setTitle(const string& title) {
        this->title = title;
    }


    friend ostream& operator<<(ostream& out, const Magazine& obj);
private:
    string edition;
    string title;
};

#endif