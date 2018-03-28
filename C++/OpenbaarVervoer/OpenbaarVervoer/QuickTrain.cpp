#include "QuickTrain.h"
#include <iostream>


QuickTrain::QuickTrain(const int& passengers, const float& pricePerKm) : passengers(passengers), pricePerKm(pricePerKm)
{
}


QuickTrain::~QuickTrain()
{
}

void QuickTrain::getFullPricePerKm()
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
