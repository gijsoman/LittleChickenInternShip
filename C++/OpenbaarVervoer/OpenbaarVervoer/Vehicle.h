#pragma once
#include <string>
#include <vector>
#include "Ticket.h"
#include "TicketWithAllowance.h"
#include "TicketNoAllowance.h"
class Vehicle
{
public:
	Vehicle();
	Vehicle(const int & maxPassengers, const float & pricePerKm);
	~Vehicle();

	virtual void getFullPricePerKm() = 0;
};

