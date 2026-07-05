#ifndef BOOKING_H
#define BOOKING_H

#include<string>
#include<vector>

class Booking{
private:
    int bookingId;
    int showId;
    std::vector<std::string> seats;
    int totalAmount;
public:
    Booking();
    Booking(int bookingId, int showId, const std::vector<std::string> &seats, int totalAmount);
    int getBookingId() const;
    int getShowId() const;
    const std::vector<std::string>& getSeats() const;
    int getTotalAmount() const;
    void displayBooking() const;
};


#endif