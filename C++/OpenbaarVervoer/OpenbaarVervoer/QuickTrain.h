#pragma once
#include "Vehicle.h"
class QuickTrain :
	public Vehicle
{
public:
	QuickTrain(const int& passengers, const float& pricePerKm);
	~QuickTrain();


	void getFullPricePerKm();
private:
	int passengers;
	float pricePerKm;
	TicketNoAllowance ticket;
};

