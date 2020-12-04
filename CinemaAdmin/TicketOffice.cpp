#include "TicketOffice.h"

#include <iostream>

TicketOffice::TicketOffice()
{
	schedule = Schedule("TimeTable.txt");
}

void TicketOffice::purchaseTicket()
{
	std::cout << "Enter a movie title: ";
	int i = 0, n;
	std::string filmName;
	std::cin >> filmName;
	schedule.scheduleByFilmName(filmName);
	std::cout << "Enter number of session: ";
	std::cin >> n;

	for (auto table : schedule.getTimeTable())
	{

		if (table.first->getTitle() == filmName)
		{
			i++;
			if (i == n)
			{
				table.second.hall->allSeats();
				std::cout << "Input number of seat in format (i j)): ";
				std::cin >> i >> n;
				table.second.hall->toBookTicket(i, n);
				return;
			}
		}
	}
}

void TicketOffice::open()
{
	using namespace std;
	while (true)
	{
		std::cout << "Hello, admin!" << endl;
		cout << "1. Schedule all sessions \n2. Session schedule by movie title \n3. Buy ticket \n4. Exit \n";
		int n = 0;
		cin >> n;
		switch (n)
		{
		case 1:
			schedule.timeTable();
			break;
		case 2:
		{
			cout << "Enter a movie title: ";
			string filmName;
			cin >> filmName;
			schedule.scheduleByFilmName(filmName); }
		break;
		case 3:
			purchaseTicket();
			break;
		case 4:
			return;
		}
		getchar();
		getchar();
		system("cls");
	}
}