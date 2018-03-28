#pragma once
#include "Vehicle.h"

class Train :
	public Vehicle
{
	
public:
	Train(const int& passengers, const float& pricePerKm);
	~Train();

	void getFullPricePerKm();
private:
	int passengers;
	float pricePerKm;
	TicketNoAllowance ticket;
};

