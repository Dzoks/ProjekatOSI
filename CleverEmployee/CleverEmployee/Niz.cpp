#include "Niz.h"



Niz::Niz()
{
	kapacitet = 2;
	trenutniBroj = -1;//jer trenutni broj pokazuje na lokaciju zadnjeg dodanog,a ne na prvo mjesto poslije njega(zato je -1)
	niz = new Artikal[kapacitet + 1];
}


Niz::~Niz()
{
}

bool Niz::dodajArtikal()
{
	Artikal *art = new Artikal;
	std::cin >> *art;
	if (kapacitet == trenutniBroj)
		prosiri_kapacitet();
	niz[++trenutniBroj] = *art;
	return true;
}

bool Niz::brisiArtikal()
{
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout <<"~~~~~~~~~~~~~~~~~~BRISANJE   ARTIKLA~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	int sifra;
	do
	{
		std::cout << "Sifra: "; std::cin >> sifra;
	} while (sifra < 1 || sifra >999999);
	Artikal *a = std::find_if(niz, niz + trenutniBroj, [&sifra](Artikal a) { return a.getSifra() == sifra; });//pronalazimo artikal sa sifrom
	if (a->getSifra() == sifra)
	{
		//nije zavrseno izbacivanje elementa iz niza

	}
	else std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
	return true;
}

void Niz::traziPoSifri(int sifra)
{
	Artikal *a=std::find_if(niz, niz + trenutniBroj, [&sifra](Artikal a) { return a.getSifra() == sifra; });
	if (a->getSifra() == sifra)
	{
		std::cout << "ARTIKAL JE PRONADJEN: " << std::endl;
		std::cout << "~SIFRA~ ~~~~~NAZIV~~~~~ ~~~~~OPIS~~~~~~ ~KOLICINA~ ~CIJENA~" << std::endl;
		std::cout << *a;
	}
	else std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
}

void Niz::traziPoNazivu(std::string naziv)
{
	Artikal *a = std::find_if(niz, niz + trenutniBroj, [&naziv](Artikal a) { return a.getNaziv() == naziv; });
	if (a->getNaziv() == naziv)
	{
		std::cout << "ARTIKAL JE PRONADJEN: " << std::endl;
		std::cout << "~SIFRA~ ~~~~~NAZIV~~~~~ ~~~~~OPIS~~~~~~ ~KOLICINA~ ~CIJENA~" << std::endl;
		std::cout << *a;
	}
	else std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
}

void Niz::print()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~SIFRA~ ~~~~~NAZIV~~~~~ ~~~~~OPIS~~~~~~ ~KOLICINA~ ~CIJENA~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i <= trenutniBroj; i++)
		std::cout << niz[i];
	std::cout << std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}


void Niz::prosiri_kapacitet()
{
	Artikal *novi_niz = new Artikal[trenutniBroj + 1];
	kapacitet *= 2;
	std::copy(niz, niz + trenutniBroj, novi_niz);
	delete[] niz;
	niz = new Artikal[kapacitet + 1];
	std::copy(novi_niz, novi_niz + trenutniBroj, niz);
	delete[] novi_niz;
}
