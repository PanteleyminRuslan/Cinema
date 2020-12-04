#include "Movie.h"

void Movie::setAgeLimit(int age)
{
	if (age < 0 || age > 21)
	{
		throw "Illegal age limit";
	}
	this->age_limit = age;
}

Movie::Movie(const std::string& title) : title(title)
{
	std::ifstream fin;
	fin.open(title + ".txt");
	fin >> age_limit >> movie_length;
}