#include <iostream>

#include "Artikal.h"
#include "Administrator.h"
#include "Korisnik.h"
#include "Niz.h"

using namespace std;
int main()
{
	//Administrator a;
	//a.kreirajNalog();
	
	//a.izmjenaNaloga();
	
	//cout << art;
	Niz n;
	n.dodajArtikal();
	n.dodajArtikal();
	//n.traziPoSifri(12345);
	n.print();
	n.brisiArtikal();
	n.print();
	return 0;
}