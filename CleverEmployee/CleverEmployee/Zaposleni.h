#pragma once
#include <iostream>
#include <string>
#include "Niz.h"
#include "Korisnik.h"
#include <ctime>
class Zaposleni : public Korisnik
{
public:
	Zaposleni(std::string="",std::string="", std::string="");
	~Zaposleni();
	void izmjenaArtikla(Niz&);
	void prodajArtikal(Niz&);
	void statistikaDan();
	void statistikaSedmicaJedan(int, Niz&, int);
	void statistikaDanJedan(int,Niz&,int);
	void statistikaMjesecJedan(int, Niz&, int);
	void statistikaGodinaJedan(int, Niz&, int);
	void statistikaSedmica();
	void statistikaMjesec();
	void statistikaGodina();
	void statistikaKupci();
	
};

struct statistika
{
	int h, m, s, day, month, year,sifra;
	double kolicina, cena;
};