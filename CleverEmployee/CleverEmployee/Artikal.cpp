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

void Artikal::setKolicina(double x)
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

double Artikal::getKolicina()
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

std::ostream& operator<<(std::ostream &out, const Artikal& a)
{
	out << std::setw(7) << a.sifra<<" ";//ispisuje sifru sa 7 mjesta,a prazna popunjava 0
	out << std::setw(15) << std::left << a.naziv << " ";
	out << std::setw(15) << std::left << a.opis << " ";
	out << std::setprecision(3);//ispisuje na 3 decimale
	out << std::setw(5) << std::left << a.kolicina << "  ";
	out << std::setw(5)<<std::left<<a.cijena << " ";
	return out;
}

std::istream & operator>>(std::istream &in, Artikal &a)
{
	std::cout << "UNOS ARTIKLA: " << std::endl;
	do
	{
		std::cout << "\tSifra: "; in >> a.sifra;
	} while (a.sifra < 1 || a.sifra>999999);//sifra mora biti izmedju 1 i 7
	do
	{
		std::cout << "\tNaziv: "; in >> a.naziv;
	} while (a.naziv.length() < 3);

	std::cout << "\tOpis DA[D]  NE[N]: ";
	char c;
	std::cin >> c;
	a.opis = "";//nema opisa,uneseno N
	if (c == 'D')
	{
		std::cout << "\t\tUnesite opis:";
		in >> a.opis;
	}

	do
	{
		std::cout << "\tKolicina: "; in >> a.kolicina;
	} while (a.kolicina < 0.01);//kolicina je manja od 0.01 jer neki proizvod moze imati kolicinu 0.5,a kolicina ipak mora biti veca od nule
	do
	{
		std::cout << "\tCijena: "; in >> a.cijena;
	} while (a.cijena < 0.01);//cijena je manja od 0.01 jer neki proizvod moze imati cijenu 0.5,a cijena ipak mora biti veca od nule

	return in;
}