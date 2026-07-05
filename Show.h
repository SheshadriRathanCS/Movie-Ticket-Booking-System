#ifndef SHOW_H
#define SHOW_H

#include<string>
#include<set>

class Show{
private:
    int showId;
    int movieId;
    std::string showTime;
    int ticketPrice;
    std::set<std::string> bookedSeats;
public:
    Show();
    Show(int showId, int movieId, const std::string &showTime, int ticketPrice);
    int getShowId() const;
    int getMovieId() const;
    std::string getShowTime() const;
    int getTicketPrice() const;
    bool bookSeat(const std::string &seat);
    bool cancelSeat(const std::string &seat);
    bool isSeatBooked(const std::string &seat) const;
    void displayShow() const;
    void displaySeatLayout() const;
    bool isValidSeat(const std::string& seat) const;
};

#endif