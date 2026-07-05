#include "Show.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<set>
#include<cctype>

constexpr int LINE_WIDTH=15;

Show::Show():showId(0),movieId(0),showTime(""),ticketPrice(0){}

Show::Show(int showId, int movieId, const std::string &showTime, int ticketPrice):showId(showId),movieId(movieId),showTime(showTime),ticketPrice(ticketPrice){}

int Show::getShowId() const{
    return showId;
}

int Show::getMovieId() const{
    return movieId;
}

std::string Show::getShowTime() const{
    return showTime;
}

int Show::getTicketPrice() const{
    return ticketPrice;
}

bool Show::bookSeat(const std::string &seat){
    if(bookedSeats.count(seat)==1)return false;
    bookedSeats.insert(seat);
    return true;
}

bool Show::cancelSeat(const std::string &seat){
    if(bookedSeats.count(seat)==0)return false;
    bookedSeats.erase(seat);
    return true;
}

bool Show::isSeatBooked(const std::string &seat) const{
    if(bookedSeats.count(seat)==1)return true;
    else return false;
}

void Show::displayShow() const{
    std::cout<<std::string(20,'-')<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Show ID"<<": "<<showId<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Movie ID"<<": "<<movieId<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Time"<<": "<<showTime<<'\n';
    std::cout<<std::left<<std::setw(LINE_WIDTH)<<"Ticket Price"<<": "<<ticketPrice<<'\n';
    std::cout<<std::string(20,'-')<<'\n';
}

void Show::displaySeatLayout() const{
    constexpr int ROWS = 6;
    constexpr int COLS = 8;
    std::cout << "\n";
    std::cout << "================== SCREEN ==================\n\n";
    // Column numbers
    std::cout << "     ";
    for (int col = 1; col <= COLS; col++)
    {
        std::cout << std::setw(4) << col;
    }
    std::cout << "\n\n";
    // Seat layout
    for (char row = 'A'; row < 'A' + ROWS; row++){
        std::cout << row << "    ";
        for (int col = 1; col <= COLS; col++){
            std::string seat;
            seat += row;
            seat += std::to_string(col);
            if (bookedSeats.find(seat) != bookedSeats.end())
                std::cout << "[X] ";
            else
                std::cout << "[ ] ";
        }
        std::cout << '\n';
    }
    std::cout << "\n============================================\n";
    std::cout << "[ ] Available    [X] Booked\n\n";
}

bool Show::isValidSeat(const std::string& seat) const{
    if(seat.length()<2)return false;
    char row=std::toupper(seat[0]);
    int col=std::stoi(seat.substr(1));
    if(row<'A'||row>'F')return false;
    if(col<1||col>8)return false;
    for (size_t i = 1; i < seat.length(); i++){
        if (!std::isdigit(seat[i])){
            return false;
        }
    }
    return true;
}

