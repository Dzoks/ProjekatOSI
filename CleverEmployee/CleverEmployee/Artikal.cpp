#include "Artikal.h"



Artikal::Artikal()
{
}


Artikal::~Artikal()
{
}

void Artikal::setSifra(int x)
{
	sifra = x;
}

void Artikal::setKolicina(int x)
{
	kolicina = x;
}

void Artikal::setNaziv(std::string ime)
{
	naziv = ime;
}

void Artikal::setOpis(std::string x)
{
	opis = x;
}

void Artikal::setCijena(double x)
{
	cijena = x;
}

int Artikal::getSifra()
{
	return sifra;
}

int Artikal::getKolicina()
{
	return kolicina;
}

std::string Artikal::getNaziv()
{
	return naziv;
}

std::string Artikal::getOpis()
{
	return opis;
}

double Artikal::getCijena()
{
	return cijena;
}
