#pragma once
#include "Artikal.h"
#include <iostream>
#include <algorithm>
class Niz
{
	friend std::ostream& operator<<(std::ostream&, const Niz&);
public:
	Niz();
	~Niz();
	bool dodajArtikal();//dodaje novi artikal u niz
	bool brisiArtikal();//brise artikal iz niza
	void traziPoSifri(int);//pronadje traženi Artikal i ispiše ga
	void traziPoNazivu(std::string);
	void print();
private:
	Artikal *niz;
	int kapacitet, trenutniBroj;

	void prosiri_kapacitet();
};

