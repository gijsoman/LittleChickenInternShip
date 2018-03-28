#include <iostream>
#include "Bibliotheek.h"

/* dit is bieb die meerdere boeken kan vasthouden en een filiaalnaam heeft. 
Ook is er een copyconstructor toegevoegd aan de bibliotheek en ruimen we alles netjes op*/


void geefBoekDoor(Bibliotheek* bibliotheek)
{
	std::cout << "Boek gekregen" << std::endl;
	bibliotheek->toon();

	bibliotheek->voegToe("Kippenvel: de man met het masker");
	bibliotheek->toon();
}

int main()
{
	//eerst maken we een normale bibliotheek aan met een naam
	Bibliotheek almelo = Bibliotheek("almelo");
	//dan voegen we een aantal boeken toe en laten ze zien
	almelo.voegToe("Het duistere bos");
	almelo.voegToe("Het kasteel in het duistere bos");
	almelo.voegToe("Het kamertje in het kasteel in het duistere bos"); 
	almelo.toon();

	
	//we roepen de copy constructor aan om een nieuwe bieb te maken 
	//deze nieuwe bieb gaan we vullen met nieuwe pointers naar nieuwe boeken
	//als we namelijk de pointers in de lijst van almelo pakken dan proberen
	//we memory te lezen waar geen boeken meer zijn.
	Bibliotheek hengelo = almelo;
	almelo.~Bibliotheek();
	hengelo.filiaal = "hengelo";
	hengelo.toon();
	
	
	//vervolgens roepen we de assignment operator aan.
	//we assignen alles van hengelo aan enschede :)
	Bibliotheek enschede("enschede");
	enschede = hengelo;
	enschede.toon();

	//We gaan nu 2 bestaande bibliotheken aan elkaar assignen. 
	//De boeken zullen bij elkaar worden opgeteld maar dat willen we niet
	hengelo = enschede;
	hengelo.toon();


	char c;
	std::cin >> c;
	return 0;
}
