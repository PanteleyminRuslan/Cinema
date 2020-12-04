#pragma once
#include <map>
#include "Hall.h"
#include "Movie.h"
#include <fstream>

//Struct reflects the time when the film is going in the hall
struct TimeHall
{
    TimeHall(const std::string& time, Hall* hall);
    std::string time;
    Hall* hall;
};

//Schedule of sessions in the cinema
class Schedule
{
private:
    using TimeTable = std::multimap<Movie*, TimeHall>;
    TimeTable time_table;
    std::map<std::string, Movie> titles;
    std::map<int, Hall> halls;
public:
    void toBookTicket(int i, int j);

    //prints all session in the cinema
    void timeTable();

    //prints all sessions of a particular movie
    void scheduleByFilmName(std::string);

    TimeTable getTimeTable() { return time_table; }

    Schedule() {}

    Schedule(std::string fileName);
};