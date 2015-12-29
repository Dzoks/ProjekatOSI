#pragma once
#include "Korisnik.h"
#include<iomanip>
#include <algorithm>
#include <iostream>
#include <fstream>
class Administrator :
	public Korisnik
{
public:
	Administrator(std::string = "", std::string = "");
	~Administrator();
	void kreirajNalog();
	void izmjenaNaloga();
	void brisiNalog(Korisnik**,int);
	void podesavanjeJezika();//najmanji prioritet
	void podesavanjeBoje();
	void pregledStatistike();/*treba dodati niz artikala*/
	void brojIzmjena();
	void ukupanBrojNaloga();
	void dodajObavjestenje();
};

