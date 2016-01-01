#include <iostream>

#include "Artikal.h"
#include "Administrator.h"
#include "Korisnik.h"
#include "Niz.h"
using namespace std;
int main()
{
	Niz b;
	b.ucitajDatoteku();
	b.print();
	b.dodajArtikal();
	b.brisiArtikal();
	b.brisiArtikal();
	b.print();
	b.pisiDatoteku();
	return 0;
}