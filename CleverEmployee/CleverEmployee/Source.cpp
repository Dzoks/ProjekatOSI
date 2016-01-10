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
	fstream poruka("Poruka.txt", fstream::in);
	if (poruka)
	{
		string p;
		getline(poruka, p);
		cout << "PORUKA ADMINISTRATORA:" << endl<< p << endl;//ispis poruke
	}
	Korisnik pom;
	pom.prijavaNaSistem();
	if (pom.getStatus() == "A")
	{
		system("cls");
		char c;
		Administrator admin(pom.getIme(), pom.getLozinka(), pom.getStatus());
		std::cout << "Dobrodosli, " << admin.getIme() << "! Odaberite neku od postojecih opcija da nastavite sa radom: " << std::endl;
		do {
			std::cout << "Rad sa korisnickim nalozima [1], Statistika sistema [2], Ostale opcije [3], Kraj [0] : ";
			cin >> c;
			if (c == '1')
			{
				char c1;
				do
				{
					cout << "Odaberite zeljenu opciju: " << endl << "Kreiranje novog naloga [1], Izmjena postojeceg naloga [2] , Brisanje naloga [3], Lista svih naloga [4], Kraj [0]: " << endl;
					cin >> c1;
					if (c1 == '1') admin.kreirajNalog();
					else if (c1== '2') admin.izmjenaNaloga();
					else if (c1== '3') admin.brisiNalog();
					else if (c1 == '4') admin.pisiSve();
					system("cls");
				} while (c1 != '0');
			}
			else if (c == '2')
			{
				char c1;
				do
				{
				cout << "Odaberite zeljenu opciju: " << endl << "Ukupan broj naloga [1], Ukupan broj izmjena [2], Kraj [0]: " << endl;
				cin >> c1;
				if (c1 == '1') admin.ukupanBrojNaloga();
				else if (c1 == '2') admin.brojIzmjena();
				system("cls");
				} while (c1 != '0');
			}
			else if (c == '3')
			{
				char c1;
				do
				{
				cout << "Odaberite zeljenu opciju: " << endl << "Podesavanje boje sistema [1], Dodavanje obavjestenja [2], Kraj [0]: " << endl;
				cin >> c1;
				if (c1 == '1') admin.podesavanjeBoje();
				else if (c1 == '2') admin.dodajObavjestenje();
				system("cls");
			} while (c1 != '0');
			}
			system("cls");
		} while (c != '0');
		
		
	}
	else { cout << "WORK IN PROGRESS!" << endl; }
}