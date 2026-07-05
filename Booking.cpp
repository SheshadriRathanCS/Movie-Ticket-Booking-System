#include "Booking.h"
#include<iostream>
#include<iomanip>

constexpr int LINE_WIDTH=15;

Booking::Booking():bookingId(0),showId(0),seats(),totalAmount(0){}

Booking::Booking(int bookingId, int showId, const std::vector<std::string> &seats, int totalAmount):bookingId(bookingId),showId(showId),seats(seats),totalAmount(totalAmount){}

int Booking::getBookingId() const{
    return bookingId;
}

int Booking::getShowId() const{
    return showId;
}

const std::vector<std::string>& Booking::getSeats() const{
    return seats;
}

int Booking::getTotalAmount() const{
    return totalAmount;
}

void Booking::displayBooking() const{
    std::cout<<std::string(20,'-')<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Booking ID"<<": "<<bookingId<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Show ID"<<": "<<showId<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Seats"<<": ";
    for(const auto& it : seats)std::cout<<it<<" ";
    std::cout<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Total Amount"<<": "<<totalAmount<<'\n';
    std::cout<<std::string(20,'-')<<'\n';
}
