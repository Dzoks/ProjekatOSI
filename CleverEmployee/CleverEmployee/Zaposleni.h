#pragma once
#include <iostream>
#include <string>
#include "Niz.h"
#include "Korisnik.h"
class Zaposleni : public Korisnik
{
public:
	Zaposleni();
	~Zaposleni();
	void izmjenaArtikla(Niz&);
	void prodajArtikal(Niz&);
	void dodavanjeNovogProizvoda(Niz&);
	void statistikaDan();
	void statistikaDanSvi();
	void statistikaSedmica();
	void statistikaSedmicaSvi();
	void statistikaMjesec();
	void statistikaMjesecSvi();
	void statistikaGodina();
	void statistikaGodinaSvi();
};

