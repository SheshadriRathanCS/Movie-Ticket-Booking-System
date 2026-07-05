#ifndef MOVIE_H
#define MOVIE_H

#include<string>

class Movie{
private:
    int movieId;
    std::string title;
    std::string genre;
    int duration;
public:
    Movie();
    Movie(int movieId , const std::string &title , const std::string &genre , int duration);
    int getMovieId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getDuration() const;
    void displayMovie() const;
};

#endif
