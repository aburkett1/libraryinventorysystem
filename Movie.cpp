#include "Movie.h"

Movie::Movie() {
    title = "";
    director = "";
    mainActors = nullptr;
}

Movie::Movie(string name, string description, int id, string title, string director, vector<string> *mainActors):
Item(name, description, id) {
    this->title = title;
    this->director = director;
    this->mainActors = mainActors;
}

string Movie::getTitle() const {
    return title;
}

string Movie::getDirector() const {
    return director;
}

vector<string> Movie::getMainActors() const {
    return *mainActors;
}

void Movie::setTitle(const string& title) {
    this->title = title;
}

void Movie::setDirector(const string& director) {
    this->director = director;
}

void Movie::setMainActors(vector<string> *mainActors) {
    this->mainActors = mainActors;
}

ostream& operator<<(ostream& out, const Movie& obj) {

    return out;
}
