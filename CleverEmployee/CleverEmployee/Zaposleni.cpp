#include "Zaposleni.h"



Zaposleni::Zaposleni()
{
}


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

void Zaposleni::prodajArtikal(Niz&)
{

}
