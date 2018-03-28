#pragma once
#include "Vehicle.h"
class VeryQuickTrain :
	public Vehicle
{
public:
	VeryQuickTrain(const int& passengers, const float& pricePerKm);
	~VeryQuickTrain();

	void getFullPricePerKm();
private:
	int passengers;
	float pricePerKm;
	TicketWithAllowance ticket;
};

