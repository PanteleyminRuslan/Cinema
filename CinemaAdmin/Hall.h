#pragma once
#include <fstream>
#include "Seat.h"

class Hall {
private:
    int number{};
    int number_of_seats{};
    int dimension{};
    int number_of_rows{};
    int number_of_columns{};
    Seat seats[10][10];

public:

    //Constructors
    Hall() {};
    Hall(int number);

    //Getters
    int getNumber() { return number; }

    int getDimension() const { return dimension; }

    int getNumberOfRows() const { return number_of_rows; }

    int getNumberOfColumns() const { return number_of_columns; }

    bool isBooked(int i, int j);

    //Setters
    void setNumberOfColumns(int numberOfColumns);

    void setDimension(int dimension);

    void setNumberOfRows(int numberOfRows);

    //print all seats info (booked or not)
    void allSeats();

    //Function to purchase a ticket
    void toBookTicket(int i, int j);

};