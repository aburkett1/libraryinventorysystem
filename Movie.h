#ifndef MOVIE_H_
#define MOVIE_H_

#include "Item.h"
#include <vector>

class Movie : public Item {
public:
    // Constructors
    Movie();
    Movie(string title, string description, string director, vector<string> *mainActors);

    // Getters
    string getTitle() const;
    string getDirector() const;
    vector<string> getMainActors() const;

    // Setters
    void setTitle(const string& title);
    void setDirector(const string& director);
    void setMainActors(vector<string> *mainActors);

    // Overloaded Operators
    friend ostream& operator<<(ostream& out, const Movie& movie);

private:
    string title;
    string director;
    vector<string> *mainActors;
};

#endif