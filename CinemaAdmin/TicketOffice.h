#pragma once
#include "Schedule.h"
class TicketOffice
{
private:
	Schedule schedule;
public:
	TicketOffice();
	void open();
	void purchaseTicket();
};