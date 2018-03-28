#include <iostream>
#include "Bibliotheek.h"
#include <vector>


Bibliotheek::Bibliotheek()
{
}

Bibliotheek::Bibliotheek(std::string filiaal) : filiaal(filiaal)
{
}

Bibliotheek::Bibliotheek(const Bibliotheek& copy)
{
	filiaal = "nieuw filiaal";
	std::cout << "Wij openen een nieuw filiaal en hebben dezelfde boeken als: " << copy.filiaal << std::endl;
	//We maken hier nieuwe pointers aan naar nieuwe boeken zodat we 
	//een deep copy uitvoeren. We hebben nu eigen pointers naar eigen boeken.
	//Deze pointers worden opgeruimt zodra we de destructor van bibliotheek
	//aanroepen.
	for (int  i = 0; i < copy.boekjes.size(); i++)
	{
		Boek* boekje = new Boek(copy.boekjes[i]->naam);
		boekjes.push_back(boekje);
	}
}

Bibliotheek &Bibliotheek::operator=(const Bibliotheek& andereBieb)
{
	std::cout << "Het filiaal: " << andereBieb.filiaal << " is aan ons toegewezen." << std::endl;
	if (this != &andereBieb) 
	{
		std::vector<Boek*>::iterator iter;
		//we willen eerst de pointers weggooien en de objecten waarnaar gewezen worden door deze
		//pointers door "Delete" te gebruiken. We deacllocaten dus eerst het geheugen waar de pointer
		//naartoe wijst. 
		for (iter = boekjes.begin(); iter != boekjes.end(); iter++)
		{
			delete *iter;
		}
		//vervolgens halen we de pointers uit de vector. Dit mag nu omdat we de objecten waar de pointers
		//naar wezen nu ook verwijdert (deallocated) zijn.
		int vectorSize = boekjes.size();
		for (int i = 0; i < vectorSize; i++)
		{
			boekjes.pop_back();
		}
		//dan pas voegen we de nieuwe boeken toe.
		for (int i = 0; i < andereBieb.boekjes.size(); i++)
		{
			Boek* boekje = new Boek(andereBieb.boekjes[i]->naam);
			boekjes.push_back(boekje);
		}
	}
	return *this;
}


Bibliotheek::~Bibliotheek()
{
	std::cout << "Het filiaal: " << filiaal << " is gesloten" << std::endl;
	for (int i = 0; i < boekjes.size(); i++)
	{
		delete boekjes[i];
	}
}

void Bibliotheek::toon()
{
	std::cout << "filiaal: " << filiaal << " heeft de volgende boeken: " << std::endl;
	for (int i = 0; i < boekjes.size() ; i++)
	{
		std::cout << boekjes[i]->naam << std::endl;
	}

}

void Bibliotheek::voegToe(std::string name)
{
	boekjes.push_back(new Boek(name));
}
