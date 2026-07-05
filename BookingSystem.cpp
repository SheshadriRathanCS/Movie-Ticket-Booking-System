#include "BookingSystem.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<algorithm>

BookingSystem::BookingSystem(): nextBookingId(1001){
    loadMovies();
    loadShows();
    loadBookings();
}

Movie* BookingSystem::findMovie(int movieId){
    for(auto& movie : movies){
        if(movie.getMovieId()==movieId)return &movie;
    }
    return nullptr;
}

Show* BookingSystem::findShow(int showId){
    for(auto& show : shows){
        if(show.getShowId()==showId)return &show;
    }
    return nullptr;
}

Booking* BookingSystem::findBooking(int bookingId){
    for(auto& booking : bookings){
        if(booking.getBookingId()==bookingId)return &booking;
    }
    return nullptr;
}

void BookingSystem::loadMovies(){
    std::ifstream file("movies.txt");
    if(!file){
        std::cout<<"Unable to open movies.txt\n";
        return ;
    }
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);
        std::string id;
        std::string title;
        std::string genre;
        std::string duration;
        std::getline(ss,id,'|');
        std::getline(ss,title,'|');
        std::getline(ss,genre,'|');
        std::getline(ss,duration);
        int movieId=std::stoi(id);
        int movieDuration=std::stoi(duration);
        movies.emplace_back(movieId,title,genre,movieDuration);
    }
    std::cout << movies.size() << " movies loaded.\n";
}

void BookingSystem::loadShows(){
    std::ifstream file("shows.txt");
    if(!file){
        std::cout<<"Unable to open shows.txt \n";
        return ;
    }
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);
        std::string id;
        std::string mId;
        std::string time;
        std::string price;
        std::getline(ss,id,'|');
        std::getline(ss,mId,'|');
        std::getline(ss,time,'|');
        std::getline(ss,price);
        int showId=std::stoi(id);
        int movieId=std::stoi(mId);
        int ticketPrice=std::stoi(price);
        shows.emplace_back(showId,movieId,time,ticketPrice);
    }
    std::cout << shows.size() << " shows loaded.\n";
}

void BookingSystem::loadBookings(){
    std::ifstream file("bookings.txt");
    if(!file){
        std::cout<<"Unable to open bookings.txt\n";
        return ;
    }
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);
        std::string id;
        std::string sId;
        std::string seats;
        std::string amount;
        std::getline(ss,id,'|');
        std::getline(ss,sId,'|');
        std::getline(ss,seats,'|');
        std::getline(ss,amount);
        int bookingId=std::stoi(id);
        if(bookingId>=nextBookingId)nextBookingId=bookingId+1;
        int showId=std::stoi(sId);
        int totalAmount=std::stoi(amount);
        std::vector<std::string> bookedSeats;
        std::stringstream seatStream(seats);
        std::string seat;
        while(std::getline(seatStream,seat,','))bookedSeats.push_back(seat);
        bookings.emplace_back(bookingId,showId,bookedSeats,totalAmount);
        Show* show = findShow(showId);
        if (show != nullptr){
            for (const auto& seat : bookedSeats){
                show->bookSeat(seat);
            }
        }
    }
    std::cout << bookings.size() << " bookings loaded.\n";
}

void BookingSystem::displayMovies() const{
    if(movies.empty()){
        std::cout<<"No movies to display . \n";
        return ;
    }
    std::cout<<'\n'<<std::string(10,'=')<<" MOVIES "<<std::string(10,'=')<<'\n';
    std::cout<<'\n';
    for(const auto& movie : movies){
        movie.displayMovie();
        std::cout<<'\n';
    }
}

void BookingSystem::displayShows() const{
    if(shows.empty()){
        std::cout<<"No shows to display .\n";
        return ;
    }
    std::cout<<'\n'<<std::string(10,'=')<<" SHOWS "<<std::string(10,'=')<<'\n';
    std::cout<<'\n';
    for(const auto& show:shows){
        show.displayShow();
        std::cout<<'\n';
    }
}

void BookingSystem::displayBookings() const{
    if(bookings.empty()){
        std::cout<<"No bookings to display .\n";
        return ;
    }
    std::cout<<'\n'<<std::string(10,'=')<<" BOOKINGS "<<std::string(10,'=')<<'\n';
    std::cout<<'\n';
    for(const auto& booking : bookings){
        booking.displayBooking();
        std::cout<<'\n';
    }
}

void BookingSystem::saveMovies(){
    std::ofstream file("movies.txt");
    if(!file){
        std::cout<<"Unable to open movies.txt \n";
        return ;
    }
    for(const auto& movie : movies){
        file<<movie.getMovieId()<<'|'<<movie.getTitle()<<'|'<<movie.getGenre()<<'|'<<movie.getDuration()<<'\n';
    }
}

void BookingSystem::saveShows(){
    std::ofstream file("shows.txt");
    if(!file){
        std::cout<<"Unable to open shows.txt \n";
        return;
    }
    for(const auto& show : shows){
        file<<show.getShowId()<<'|'<<show.getMovieId()<<'|'<<show.getShowTime()<<'|'<<show.getTicketPrice()<<'\n';
    }
}

void BookingSystem::saveBookings(){
    std::ofstream file("bookings.txt");
    if(!file){
        std::cout<<"Unable to open bookings.txt \n";
        return ;
    }
    for(const auto& booking : bookings){
        file<<booking.getBookingId()<<'|'<<booking.getShowId()<<'|';
        const auto& seats=booking.getSeats();
        for (size_t i = 0; i < seats.size(); i++){
            file << seats[i];
            if (i != seats.size() - 1) file << ",";
        }
        file<<'|'<<booking.getTotalAmount()<<'\n';
    }
}

void BookingSystem::displayShowsByMovie(int movieId) const{
    if(shows.empty()){
        std::cout<<"No shows to display \n";
        return ;
    }
    bool count=false;
    std::cout<<'\n'<<std::string(10,'=')<<" AVAILABLE SHOWS "<<std::string(10,'=')<<'\n';
    for(const auto& show : shows){
        if(show.getMovieId()==movieId){
            show.displayShow();
            std::cout<<'\n';
            count=true;
        }
    }
    if(!count)std::cout<<"No shows for this movie .\n";
}

void BookingSystem::bookTicket(){
    displayMovies();
    int movieId;
    std::cout<<"\nEnter Movie ID : ";
    std::cin>>movieId;
    Movie* movie=findMovie(movieId);
    if(movie==nullptr){
        std::cout<<"Invalid Movie ID. \n";
        return;
    }
    displayShowsByMovie(movieId);
    int showId;
    std::cout<<"\nEnter Show ID : ";
    std::cin>>showId;
    Show* show=findShow(showId);
    if(show==nullptr){
        std::cout<<"Invalid Show ID. \n";
        return ;
    }
    if(show->getMovieId()!=movieId){
        std::cout<<"Given Show ID do not belong to the selected movie . \n";
        return ;
    }
    show->displaySeatLayout();
    int numSeats;
    std::cout<<"\nEnter the number of seats : ";
    std::cin>>numSeats;
    if(numSeats<=0||numSeats>48){
        std::cout<<"Invalid Number Of Seats.\n";
        return ;
    }
    std::vector<std::string> selectedSeats;
    for(int i=0;i<numSeats;i++){
        std::string seat;
        std::cout<<"Enter seat "<<i+1<<": ";
        std::cin>>seat;
        if(!show->isValidSeat(seat)){
            std::cout<<"Invalid Seat Number.\n";
            return ;
        }
        if(std::find(selectedSeats.begin(),selectedSeats.end(),seat)!=selectedSeats.end()){
            std::cout<<"Seat entered twice.\n";
            return;
        }
        if(show->isSeatBooked(seat)){
            std::cout<<seat<<" is already booked .\n";
            return;
        }
        selectedSeats.push_back(seat);
    }
    for(const auto& seat: selectedSeats){
        show->bookSeat(seat);
    }
    int totalAmount=numSeats*show->getTicketPrice();
    Booking booking(nextBookingId++,showId,selectedSeats,totalAmount);
    bookings.push_back(booking);
    saveBookings();
    constexpr int WIDTH = 15;
    std::cout<<std::string(30,'=')<<'\n';
    std::cout<<" BOOKING DETAILS \n";
    std::cout<<std::string(30,'=')<<'\n';
    std::cout << std::left << std::setw(WIDTH) << "Booking ID"   << ": " << nextBookingId-1 << '\n';
    std::cout << std::left << std::setw(WIDTH) << "Movie"        << ": " << movie->getTitle() << '\n';
    std::cout << std::left << std::setw(WIDTH) << "Show ID"      << ": " << show->getShowId() << '\n';
    std::cout << std::left << std::setw(WIDTH) << "Show Time"    << ": " << show->getShowTime() << '\n';
    std::cout << std::left << std::setw(WIDTH) << "Seats" << ": ";
    for (const auto& seat : selectedSeats){
        std::cout << seat << " ";
    }
    std::cout << '\n';
    std::cout << std::left << std::setw(WIDTH) << "Total Amount" << ": " << totalAmount << '\n';
    std::cout<<std::string(30,'=')<<'\n';
}


