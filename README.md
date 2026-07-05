# Movie Ticket Booking System

A console-based **Movie Ticket Booking System** built using **C++**, **Object-Oriented Programming (OOP)**, **STL**, and **File Handling**.

The application allows users to browse available movies and shows, view a theatre-style seat layout, book tickets, and store booking information persistently using text files.

---

## Features

* Display available movies
* Display movie shows and timings
* Interactive theatre seat layout
* Book multiple seats
* Prevent duplicate or already-booked seat selection
* Automatic ticket price calculation
* Booking receipt generation
* Persistent storage using text files
* Automatic loading of movies, shows, and bookings on startup

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Standard Template Library (STL)

  * `vector`
  * `set`
  * `string`
  * `algorithm`
* File Handling (`fstream`)
* String Processing (`stringstream`)

---

## Project Structure

```text
Movie-Ticket-Booking-System/
│
├── Movie.h
├── Movie.cpp
├── Show.h
├── Show.cpp
├── Booking.h
├── Booking.cpp
├── BookingSystem.h
├── BookingSystem.cpp
├── main.cpp
│
├── movies.txt
├── shows.txt
├── bookings.txt
│
├── README.md
└── .gitignore
```

---

## How to Compile

Using **g++**:

```bash
g++ main.cpp Movie.cpp Show.cpp Booking.cpp BookingSystem.cpp -o MovieBooking
```

Run the program:

### Windows

```bash
.\MovieBooking.exe
```


## Menu

```text
============================
 MOVIE TICKET BOOKING SYSTEM
============================
1. Display Movies
2. Display Shows
3. Book Ticket
4. Display Bookings
5. Exit
```

---

## Seat Layout

```text
================== SCREEN ==================

        1   2   3   4   5   6   7   8

A     [ ] [ ] [X] [ ] [ ] [ ] [ ] [ ]
B     [ ] [X] [ ] [ ] [ ] [ ] [ ] [ ]
C     [ ] [ ] [ ] [ ] [ ] [X] [ ] [ ]
D     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
E     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
F     [ ] [ ] [ ] [X] [ ] [ ] [ ] [ ]

============================================
[ ] Available    [X] Booked
```

---

## Sample Booking Receipt

```text
==============================
BOOKING DETAILS
==============================
Booking ID   : 1001
Movie        : Interstellar
Show ID      : 101
Show Time    : 10:00 AM
Seats        : A1 A2
Total Amount : 500
==============================
```

---

## Concepts Demonstrated

* Classes and Objects
* Encapsulation
* Constructors
* Member Functions
* Standard Template Library (STL)
* File Handling
* Data Persistence
* Input Validation
* Menu-Driven Programming

---

## Author

**Sheshadri Rathan**

