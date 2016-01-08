#pragma once
#include "Artikal.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
class Niz
{
	friend class Zaposleni;
	friend std::ostream& operator<<(std::ostream&, const Niz&);
public:
	Niz();
	~Niz();
	void ucitajDatoteku();
	void pisiDatoteku();
	bool dodajArtikal();//dodaje novi artikal u niz
	bool brisiArtikal();//brise artikal iz niza
	void traziPoSifri();//pronadje traženi Artikal i ispiše ga
	void traziPoNazivu();
	void print();
private:
	std::vector<Artikal> niz;

	void ispisi_heder();//ispisuje formatirano CIJENA KOLICINA
};

