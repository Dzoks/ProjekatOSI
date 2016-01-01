#include "Niz.h"



Niz::Niz()
{}


Niz::~Niz()
{}

void Niz::ucitajDatoteku()
{
	Artikal a;
	ifstream dat("Artikli.txt");
	while (!dat.eof())
	{
		dat >> a.sifra >> a.naziv >> a.opis >> a.cijena >> a.kolicina;
		niz.push_back(a);
	}
	dat.close();
}

void Niz::pisiDatoteku()
{
	ofstream dat("Artikli.txt");
	for (int i = 0; i < niz.size(); i++)
		dat << niz[i].sifra << " " << niz[i].naziv << " " << niz[i].opis << " " << niz[i].cijena << " " << niz[i].kolicina << std::endl;
	dat.close();
}

bool Niz::dodajArtikal()
{
	Artikal art;
	std::cin >> art;
	niz.push_back(art);
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
	int i;
	Artikal a;
	for (i = 0; i < niz.size(); i++)
		if (niz[i].getSifra() == sifra)
		{
			a = niz[i];
			niz.erase(niz.begin() + i, niz.begin() + i + 1);
			break;
		}
	if (a.sifra==sifra)
		std::cout << "ARTIKAL USPJESNO OBRISAN!" << std::endl;
	else 
		std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
	return true;
}

void Niz::traziPoSifri()
{
	int sifra;
	do
	{
		std::cout << "Sifra: "; std::cin >> sifra;
	} while (sifra < 1 || sifra >999999);
	Artikal a;
	for (int i = 0; i < niz.size(); i++)
		if (niz[i].getSifra() == sifra)
		{
			a = niz[i];
			break;
		}
	if (a.getSifra() == sifra)
	{
		std::cout << "ARTIKAL JE PRONADJEN: " << std::endl;
		ispisi_heder();
		std::cout << a;
	}
	else std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
}

void Niz::traziPoNazivu()
{
	std::string naziv;
	do
	{
		std::cout << "\tNaziv: "; std::cin >> naziv;
	} while (naziv.length() < 3);
	Artikal a;
	for (int i = 0; i < niz.size();i++)
		if (niz[i].getNaziv() == naziv)
		{
			a = niz[i];
			break;
		}
	if (a.getNaziv() == naziv)
	{
		std::cout << "ARTIKAL JE PRONADJEN: " << std::endl;
		ispisi_heder();
		std::cout << a;
	}
	else std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
}

void Niz::print()
{
	ispisi_heder();
	for (int i = 0; i < niz.size(); i++)
		std::cout << niz[i];
	std::cout << std::endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Niz::ispisi_heder()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~SIFRA~ ~~~~~NAZIV~~~~~ ~~~~~OPIS~~~~~~ ~KOLICINA~ ~CIJENA~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

