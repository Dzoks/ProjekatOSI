#include "Korisnik.h"



Korisnik::Korisnik(std::string ime, std::string loz):kor_ime(ime),lozinka(loz)
{}

Korisnik::~Korisnik()
{
}

std::string Korisnik::getIme()
{
	return kor_ime;
}

std::string Korisnik::getLozinka()
{
	return lozinka;
}

void Korisnik::setIme(std::string ime)
{
	kor_ime = ime;
}

void Korisnik::setLozinka(std::string loz)
{
	lozinka = loz;
}

bool Korisnik::prijavaNaSistem()
{
	return false;
}