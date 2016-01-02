#include <iostream>

#include "Artikal.h"
#include "Administrator.h"
#include "Korisnik.h"

using namespace std;
int main()
{
	fstream boja("Kontrola.txt", ios::in);
	if (boja)
	{
		string pozadina;
		getline(boja, pozadina);
		const char* cpozadina = pozadina.c_str();
		boja.close();
		system(cpozadina);
	}
	Administrator a;
	char c;
	do {
		a.kreirajNalog();
		cin >> c;
	} while (c != '0');
	a.ukupanBrojNaloga();
	return 0;
}