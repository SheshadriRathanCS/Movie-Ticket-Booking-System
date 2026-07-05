#include<iostream>
#include "BookingSystem.h"

int main(){
    BookingSystem system;
    int choice;
    do{
        std::cout<<'\n';
        std::cout<<std::string(28,'=')<<'\n';
        std::cout<<" MOVIE TICKET BOOKING SYSTEM \n";
        std::cout<<std::string(28,'=')<<'\n';
        std::cout<<"1.Display Movies\n";
        std::cout<<"2.Display Shows\n";
        std::cout<<"3.Book Ticket\n";
        std::cout<<"4.Display Bookings\n";
        std::cout<<"5.Exit\n";
        std::cout<<std::string(28,'=')<<'\n';
        std::cout<<"Enter your choice : \n";
        std::cin>>choice;
        switch(choice){
            case 1:
            {
                system.displayMovies();
                break;
            }
            case 2:
            {
                system.displayShows();
                break;
            }
            case 3:
            {
                system.bookTicket();
                break;
            }
            case 4:
            {
                system.displayBookings();
                break;
            }
            case 5:
            {
                std::cout<<"\nThank you for using Ticket Booking System!\n";
                break;
            }
            default:
            {
                std::cout<<"\nInvalid Choice! Please try again.\n";
            }
        }
    }while(choice!=5);
    return 0;
}