#pragma once
#include <map>
#include <string>
#include "Hall.h"
//The class describes the structure of the film...
class Movie
{
public:
	int movie_length{};
	std::string title{};
	int age_limit{};
public:
	//Constructors
	Movie(const std::string& title);
	Movie() {}

	//Getters
	virtual int getMovieLength() { return movie_length; }

	virtual int getAgeLimit() { return this->age_limit; }

	virtual std::string getTitle() { return title; }

	//Setters
	virtual void setMovieLength(int length)
	{
		movie_length = length;
	}

	virtual void setAgeLimit(int age);
};
class ActionMovie : public Movie {
public:
	int actionAmount{};
	ActionMovie(const int am) : actionAmount(am) {
	}
};
class DramaMovie : public Movie {
public:
	int dramaAmount{};
	DramaMovie(const int dm) : dramaAmount(dm) {
	}
};
class DocMovie : public Movie {
public:
	int docAmount{};
	DocMovie(const int docAm) : docAmount(docAm) {
	}
};