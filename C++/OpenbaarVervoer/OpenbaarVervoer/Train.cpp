#include "Train.h"
#include <iostream>


Train::Train(const int& passengers, const float& pricePerKm) : passengers(passengers), pricePerKm(pricePerKm)
{

}

Train::~Train()
{
}


void Train::getFullPricePerKm()
{
	if (ticket.allowance())
	{
		std::cout << passengers * pricePerKm + (pricePerKm * 0.5 * passengers) << std::endl;
	}
	else
	{
		std::cout << passengers * pricePerKm  << std::endl;
	}
}
