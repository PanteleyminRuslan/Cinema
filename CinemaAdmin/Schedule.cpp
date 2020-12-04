#include "Schedule.h"

#include <iostream>

Schedule::Schedule(std::string fileName)
{
    using namespace std;
    ifstream fin;
    fin.open(fileName);
    while (!fin.eof())
    {
        int hallNumber;
        string movieName;
        string time;
        fin >> movieName >> hallNumber >> time;
        titles.insert(pair< string, Movie >(movieName, Movie(movieName)));
        halls.insert(pair<int, Hall>(hallNumber, Hall(hallNumber)));
        time_table.insert(pair<Movie*, TimeHall>(&titles[movieName],
            TimeHall(time, &halls[hallNumber])));
    }
    fin.close();
}

TimeHall::TimeHall(const std::string& time, Hall* hall)
{
    this->time = time;
    this->hall = hall;
}

void Schedule::timeTable()
{
    for (auto table : time_table)
    {
        std::cout << table.first->getTitle() << " hall #" << table.second.hall->getNumber() << " " << table.second.time << std::endl;
    }
}



void Schedule::scheduleByFilmName(std::string filmName)
{
    int i = 1;
    for (auto table : time_table)
    {

        if (table.first->getTitle() == filmName)
        {
            std::cout << i << ". " << table.first->getTitle() << " hall #" << table.second.hall->getNumber() << " " << table.second.time << std::endl;
            i++;
        }
    }
}