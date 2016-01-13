#include "Zaposleni.h"
#include <algorithm>

Zaposleni::Zaposleni(std::string username, std::string password, std::string status):Korisnik(username, password, status)
{}

Zaposleni::~Zaposleni()
{
}

void Zaposleni::izmjenaArtikla(Niz &other)
{
	char c;
	int sifra,i;
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~IZMJENA    ARTIKLA~~~~~~~~~~~~";
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "UNESITE SIFRU ARTIKLA: ";
	do
	{
		std::cout << "Sifra: "; std::cin >> sifra;
	} while (sifra < 1 || sifra >999999);

	Artikal a;
	for (i = 0; i < other.niz.size(); i++)
		if (other.niz[i].getSifra() == sifra)
			break;
	std::cout << "STA SE MJENJA? \n\tIME  [I]: \n\tKOLICINA  [K]: \n\tOPIS   [O]: \n\tCIJENA  [C]: " << std::endl;
	std::cin >> c;
	switch (c)
	{
	case('I') :
	{	
		std::string ime;
		do
		{
			std::cout << "\t\TUNESITE IME: "; std::cin >> ime;
		} while (ime.length() < 3);
		other.niz[i].setNaziv(ime);
		break;
	}
	case('K') :
	{
		double kol;
		do
		{
			std::cout << "\tKOLICINA: "; std::cin >> kol;
		} while (kol < 0.01);
		other.niz[i].setKolicina(kol);
		break;
	}
	case('O') :
	{
		std::string opis;
		std::cout << "\t\tOPIS:";
		std::cin >> opis;
		other.niz[i].setOpis(opis);
		break;
	}
	case('C') :
	{
		double cijena;
		do
		{
			std::cout << "\tCijena: "; std::cin >>cijena;
		} while (cijena < 0.01);
		other.niz[i].setCijena(cijena);
		break;
	}
	default:
		std::cout << "Pogresan unos";
	}
}

void Zaposleni::prodajArtikal(Niz& niz)
{
	std::vector<Artikal> racun;
	int sifra, i,pom;
	double kolicina,suma=0;
	do
	{
		do
		{
			std::cout << "Unesite sifru artikla: ";
			std::cin >> sifra;
			for (i = 0; i < niz.niz.size(); i++)
				if (niz.niz[i].getSifra() == sifra)
					break;
			if (niz.niz.size() == i)
				std::cout << "Ne postoji sifra!" << std::endl;
		} while (niz.niz.size() == i);
		do
		{
			std::cout << "Unesite kolicinu koju prodajete: ";
			std::cin >> kolicina;
		} while (kolicina<0 || kolicina>niz.niz[i].getKolicina());
		niz.niz[i].setKolicina(niz.niz[i].getKolicina() - kolicina);
		racun.push_back(niz.niz[i]);
		racun.at(racun.size() -1).setKolicina(kolicina);
		std::vector<Artikal>::iterator it = niz.niz.begin();
		it += i;
		if (niz.niz.at(i).getKolicina() == 0)
			niz.niz.erase(it);
		std::cout << "Hocete li jos robe prodavati?" << std::endl;
		std::cout << "DA [1], NE[2]: ";
		std::cin >> pom;
	} while (pom != 2);
	std::cout << "========================================================" << std::endl;
	std::cout << "                           RACUN                        " << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "Naziv          Sifra         Kolicina             Cijena" << std::endl;
	std::cout << "========================================================" << std::endl;
	for (i = 0; i < racun.size(); ++i)
	{
		std::cout << racun[i].getNaziv() << " " << racun[i].getSifra() << " " << racun[i].getKolicina() << " " << racun[i].getKolicina()* racun[i].getCijena() << std::endl;
		suma += racun[i].getCijena()*racun[i].getKolicina();
	}
	std::cout << "========================================================" << std::endl;
	std::cout << "UKUPNO:                                  " << suma << std::endl;
	std::cout << "========================================================" << std::endl;
}
