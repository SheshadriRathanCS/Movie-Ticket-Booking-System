#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "Movie.h"
#include "Show.h"
#include "Booking.h"
#include<vector>

class BookingSystem{
private:
    std::vector<Movie> movies;
    std::vector<Show> shows;
    std::vector<Booking> bookings;
    int nextBookingId;
public:
    BookingSystem();
    void loadMovies();
    void loadShows();
    void loadBookings();
    void saveMovies();
    void saveShows();
    void saveBookings();
    void displayMovies() const;
    void displayShows() const;
    void displayBookings() const;
    void displayShowsByMovie(int movieId) const;
    void bookTicket();
    Movie* findMovie(int movieId);
    Show* findShow(int showId);
    Booking* findBooking(int bookingId);
};

#endif