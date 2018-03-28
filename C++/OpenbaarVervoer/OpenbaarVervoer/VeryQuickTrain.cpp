#include "VeryQuickTrain.h"
#include <iostream>


VeryQuickTrain::VeryQuickTrain(const int& passengers, const float& pricePerKm) : passengers(passengers), pricePerKm(pricePerKm)
{
}


VeryQuickTrain::~VeryQuickTrain()
{
}

void VeryQuickTrain::getFullPricePerKm()
{
	if (ticket.allowance())
	{
		std::cout << passengers * pricePerKm + passengers * pricePerKm + (pricePerKm * 0.5 * passengers) << std::endl;
	}
	else
	{
		std::cout << passengers * pricePerKm << std::endl;
	}
}