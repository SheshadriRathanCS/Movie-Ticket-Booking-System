#include "Movie.h"
#include<iostream>
#include<iomanip>
#include<string>

constexpr int LINE_WIDTH=10;

Movie::Movie():movieId(0),title(""),genre(""),duration(0){}

Movie::Movie(int movieId, const std::string &title, const std::string &genre, int duration):movieId(movieId),title(title),genre(genre),duration(duration){}

int Movie::getMovieId() const{
    return movieId;
}

std::string Movie::getTitle() const{
    return title;
}

std::string Movie::getGenre() const{
    return genre;
}

int Movie::getDuration() const{
    return duration;
}

void Movie::displayMovie() const{
    std::cout<<std::string(20,'-')<<std::endl;
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Movie ID"<<": "<<movieId<<std::endl;
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Title"<<": "<<title<<std::endl;
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Genre"<<": "<<genre<<std::endl;
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Duration"<<": "<<duration<<" mins"<<std::endl;
    std::cout<<std::string(20,'-')<<std::endl;
}