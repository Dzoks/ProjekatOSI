#include <iostream>

#include "Artikal.h"
#include "Zaposleni.h"
#include "Administrator.h"
#include "Korisnik.h"
#include "Niz.h"
using namespace std;
int main()
{
	Niz b;
	Zaposleni z;
	b.dodajArtikal();
	b.dodajArtikal();
	z.izmjenaArtikla(b);
	b.print();
	return 0;
}