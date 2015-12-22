#pragma once
#include "Artikal.h"
class Niz
{
	friend std::ostream& operator<<(std::ostream&, const Niz&);
public:
	Niz();
	~Niz();
	Niz& operator+=(const Artikal&);
	Niz& operator-=(int);
	void traziPoSifri(int);
	void traziPoNazivu(std::string);

private:
	Artikal *niz;
	int kapacitet, trenutniBroj;
};

