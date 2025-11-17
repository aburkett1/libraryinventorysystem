#ifndef MOVIE_H_
#define MOVIE_H_

#include "Item.h"
#include <vector>

class Movie : public Item {
public:
    Movie();

    string getTitle() const {
        return title;
    }

    string getDirector() const {
        return director;
    }

    vector<string> getMainActors() const {
        return *mainActors;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    void setDirector(const string& director) {
        this->director = director;
    }

    void setMainActors(vector<string> *mainActors) {
        this->mainActors = mainActors;
    }

    friend ostream& operator<<(ostream& out, const Movie& obj);

private:
    string title;
    string director;
    vector<string> *mainActors;
};

#endif