#pragma once
#include <stdexcept>

class Seat
{
private:
    int type{};
    bool booked{};
public:
    Seat()
    {
        booked = false;
        type = 1;
    }

    Seat(int type)
    {
        this->type = type;
    }

    void toBook()
    {
        if (booked)
        {
            throw  std::runtime_error("This seat has already booked");
        }
        booked = true;
    }
    bool isBooked()
    {
        return this->booked;
    }
    void setType(int type)
    {
        if (type > 2)
        {
            throw "Illegal type";
        }
        this->type = type;
    }
    int getType()
    {
        return this->type;
    }
};