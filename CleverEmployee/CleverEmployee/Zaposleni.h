#pragma once
#include "Niz.h"
#include "Korisnik.h"
class Zaposleni :
	public Korisnik
{
public:
	Zaposleni();
	~Zaposleni();
	void izmjenaArtikla(Niz, int);
	void prodajArtikal(Niz);
	void statistikaDan();
	void statistikaDanSvi();
	void statistikaSedmica();
	void statistikaSedmicaSvi();
	void statistikaMjesec();
	void statistikaMjesecSvi();
	void statistikaGodina();
	void statistikaGodinaSvi();
	void dodavanjeNovogProizvoda(Niz&);
};

