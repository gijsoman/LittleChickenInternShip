#include <iostream>
using namespace std;
#include "Vehicle.h"
#include "Train.h"
#include "QuickTrain.h"
#include "VeryQuickTrain.h"

int main()
{
	/*
	Ik heb het als volgt gedaan. Eerst heb ik de baseclass Vehicle
	gemaakt. Deze heeft een functie die de prijs van een gevuld voertuig kan uitrekenen
	De voertuigen beschikken over een type kaartje. Ze kunnen een kaartje hebben met of
	zonder toeslag(allowance). Het vershilt per voertuig welk type kaartje ze hebben.
	Het aantal passagiers wat in een voertuig kan kun je aangeven bij het aanmaken van 
	het voertuig. Ook de prijs per kilometer kun je hier aanmaken. Ieder voertuig beschikt 
	over een functie die de prijs per kilometer van een vol voertuig kan uitrekenen. Dit leveren
	de kaartjes op per kilometer. 
	Vehicle = abstract Baseclass
	Ticket = abstract Baseclass
	*/
	Train vehicle1(2000, 0.2);
	QuickTrain snelTrein(5000, 0.2);
	VeryQuickTrain verySnelTrein(7000, 0.2);

	vehicle1.getFullPricePerKm();
	snelTrein.getFullPricePerKm();
	verySnelTrein.getFullPricePerKm();
	char c;
	cin >> c;
}