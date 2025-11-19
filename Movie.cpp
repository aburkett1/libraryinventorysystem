#include "Movie.h"

Movie::Movie() {
    title = "";
    director = "";
    mainActors = nullptr;
}

Movie::Movie(string title, string description, string director, vector<string> *mainActors):
Item(description) {
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

ostream& operator<<(ostream& out, const Movie& movie) {
    // Variables
    const int colWidth = 10;

    // Output
    out << left;
    out << setw(colWidth) << "ID: " << movie.id << endl;
    out << setw(colWidth) << "Title: " << movie.title << endl;
    out << setw(colWidth) << "Director: " << movie.director << endl << endl;
    out << setw(colWidth) << "Main Actors: " << endl;

    for (string actor : *(movie.mainActors))
    {
        cout << actor << endl;
    }
    out << endl;

    out << setw(colWidth) << "Description: " << endl
        << movie.description << endl;

    out << right;
    
    return out;
}
