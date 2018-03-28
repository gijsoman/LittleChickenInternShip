#pragma once
#include <string>
#include "Boek.h"
#include <vector>

class Bibliotheek
{
public:
	Bibliotheek();
	Bibliotheek(std::string filiaal);
	Bibliotheek(const Bibliotheek& copy);
	Bibliotheek& operator=(const Bibliotheek& andereBieb);
	virtual ~Bibliotheek();

	void toon();
	void voegToe(std::string name);

	std::string filiaal = "onbekend";
private:
	std::vector<Boek*> boekjes;


};

