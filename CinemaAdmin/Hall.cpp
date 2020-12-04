#include "Hall.h"
#include <iostream>
#include <string>

bool Hall::isBooked(int i, int j) {
    if (i > number_of_columns || j > number_of_rows ||
        i < 1 || j < 1) {
        throw "No such seat";
    }
    return this->seats[i][j].isBooked();
}

void Hall::setDimension(int dimension) {
    if (dimension < 2 || dimension>3) {
        throw "Invalid dimension";
    }
    this->dimension = dimension;
}

void Hall::setNumberOfRows(int numberOfRows) {
    if (numberOfRows > 10 || numberOfRows < 0)
        throw "Invalid";
    this->number_of_seats = numberOfRows * this->number_of_columns;
    this->number_of_rows = numberOfRows;
}

void Hall::setNumberOfColumns(int numberOfColumns) {
    if (numberOfColumns > 10 || numberOfColumns < 0)
        throw "Invalid";
    this->number_of_seats = numberOfColumns * this->number_of_rows;
    this->number_of_columns = numberOfColumns;
}

Hall::Hall(int number) : number(number)
{
    std::string filename = "Hall" + std::to_string(number) + ".txt";
    std::ifstream fin;
    fin.open(filename);
    fin >> number_of_rows >> number_of_columns >> dimension;
    number_of_seats = number_of_rows * number_of_columns;
    for (int i = 0; i < number_of_rows; i++)
        for (int j = 0; j < number_of_columns; j++)
            seats[i][j] = Seat();
}

void Hall::toBookTicket(int i, int j)
{
    try
    {
        seats[i - 1][j - 1].toBook();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        return;
    }
    std::cout << "The operation was successful";
}

void Hall::allSeats()
{
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            std::cout << seats[i][j].isBooked() << " ";
        }
        std::cout << std::endl;
    }
}