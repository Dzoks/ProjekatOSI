#pragma once
#include<iostream>
#include<string>
class Artikal
{
	friend std::ostream& operator<<(std::ostream&, const Artikal&);
	friend std::istream& operator>>(std::istream&, Artikal&);
public:
	Artikal();
	~Artikal();
	void setSifra(int);
	void setKolicina(int);
	void setNaziv(std::string);
	void setOpis(std::string);
	void setCijena(double);
	int getSifra();
	int getKolicina();
	std::string getNaziv();
	std::string getOpis();
	double getCijena();
private:
	int sifra, kolicina;
	std::string naziv, opis;
	double cijena;

};

