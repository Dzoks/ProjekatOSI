
#pragma once
#include<iostream>
#include<string>
#include <iomanip>
class Artikal
{
	friend class Niz;
	friend std::ostream& operator<<(std::ostream&, const Artikal&);
	friend std::istream& operator>>(std::istream&, Artikal&);
public:
	Artikal();
	Artikal(int, std::string, std::string, double, double);//da možemo formirati gotov artikla,samo mu proslijedimo parametre
	~Artikal();
	void setSifra(int);
	void setKolicina(double);
	void setNaziv(std::string);
	void setOpis(std::string);
	void setCijena(double);
	int getSifra();
	double getKolicina();
	std::string getNaziv();
	std::string getOpis();
	double getCijena();
private:
	int sifra;
	std::string naziv, opis;
	double cijena,kolicina;//kolicina je stavljena double jer artikal moze biti i nebrojiv(jabuke(kg))

};

