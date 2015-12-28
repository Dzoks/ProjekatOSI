#pragma once
#include "Korisnik.h"

#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
class Administrator :
	public Korisnik
{
public:
	Administrator(std::string = "", std::string = "");
	~Administrator();
	void kreirajNalog();
	void izmjenaNaloga();
	void brisiNalog(Korisnik**,int);
	void podesavanjeJezika();
	void podesavanjeBoje();
	void pregledStatistike();/*treba dodati niz artikala*/
	void brojIzmjena();
	void ukupanBrojNaloga();
	void dodajObavjestenje();
};

