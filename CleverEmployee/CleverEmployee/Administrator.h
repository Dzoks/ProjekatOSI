#pragma once
#include "Korisnik.h"
class Administrator :
	public Korisnik
{
public:
	Administrator();
	~Administrator();
	void kreirajNalog(Korisnik*);
	void izmjenaNaloga(Korisnik*);
	void brisiNalog(Korisnik*);
	void podesavanjeJezika();
	void podesavanjeBoje();
	void pregledStatistike();/*treba dodati niz artikala*/
	void brojIzmjena();
	void ukupanBrojNaloga();
	void dodajObavjestenje();
};

