#include <iostream>
#include "Artikal.h"
#include "Administrator.h"
#include "Korisnik.h"
#include "Niz.h"
#include "Zaposleni.h"
#include <windows.h>
using namespace std;
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
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
					cout << "Odaberite zeljenu opciju: " << endl << "Kreiranje novog naloga [1], Izmjena postojeceg naloga [2], " << endl << "Brisanje naloga [3], Lista svih naloga [4], Kraj [0]: ";
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
				cout << "Odaberite zeljenu opciju: " << endl << "Ukupan broj naloga [1], Ukupan broj izmjena [2], Kraj [0]: ";
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
				cout << "Odaberite zeljenu opciju: " << endl << "Podesavanje boje sistema [1], Dodavanje obavjestenja [2], Kraj [0]: ";
				cin >> c1;
				if (c1 == '1') admin.podesavanjeBoje();
				else if (c1 == '2') admin.dodajObavjestenje();
				system("cls");
			} while (c1 != '0');
			}
			system("cls");
		} while (c != '0');
		
		
	}
	else if (pom.getStatus() == "G")
	{
		system("cls");
		char c;
		Niz artikli;
		artikli.ucitajDatoteku();
		Zaposleni z(pom.getIme(), pom.getLozinka(), pom.getStatus());
		std::cout << "Dobrodosli, " << z.getIme() << "! Odaberite neku od postojecih opcija da nastavite sa radom: " << std::endl;
		do {
			std::cout << "Ispis [1], Pretraga [2], Kraj [0]: ";
			std::cin >> c;
			if (c == '1') artikli.print();
			else if (c == '2') artikli.traziPoNazivu();
		} while (c != '0');
	}
	else 
	{
		system("cls");
		Zaposleni zaposlen(pom.getIme(), pom.getLozinka(), pom.getStatus());
		cout << "Dobro dosli," << pom.getIme() << "! Odaberite neku od postojecih opcija da nastavite sa radom: " << endl;
		Niz artikli;
		artikli.ucitajDatoteku();
		char c;
		do
		{
			cout << "Dodavanje [1], Brisanje [2], Izmjena [3], Pretraga [4]," << endl << "Ispis [5], Prodaja[6], Statistika [7], Kraj [0]: ";
			cin >> c;
			if (c == '1')
			{
				system("cls");
				cout << "~~~~~~ D O D A V A N J E ~~~~~~" << endl;
				artikli.dodajArtikal();
				cin.get();
				cin.get();
				system("cls");
			}
			else if (c == '2')
			{
				system("cls");
				artikli.brisiArtikal();
				cin.get();
				cin.get();
				system("cls");
			}
			else if (c == '3')
			{
				system("cls");
				zaposlen.izmjenaArtikla(artikli);
				cin.get();
				cin.get();
				system("cls");
			}
			else if (c == '4')
			{
				system("cls");
				char ce;
				do
				{
					cout << "~~~~~~ P R E T R A G A ~~~~~~" << endl;
					cout << " Po nazivu [1], Po sifri [2], Kraj[0]: ";
					cin >> ce;
					if (ce == '1')
					{
						system("cls");
						artikli.traziPoNazivu();
						cin.get();
						cin.get();
						system("cls");
					}
					else if (ce == '2')
					{
						system("cls");
						artikli.traziPoSifri();
						cin.get();
						cin.get();
						system("cls");
					}
				} while (ce == '1' || ce == '2');
				system("cls");
			} 
			else if (c == '5')
			{
				system("cls");
				cout << "~~~~~~ UKUPNO STANJE ROBE ~~~~~~" << endl;
				artikli.print();
				std::cout << "=============================================" << std::endl;
				std::cout << "||PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
				std::cout << "=============================================" << std::endl;
				cin.get();
				cin.get();
				system("cls");
			}
			else if (c == '6')
			{
				system("cls");
				zaposlen.prodajArtikal(artikli);
				cin.get();
				cin.get();
				system("cls");
			}
			else if (c == '7')
			{
				system("cls");
				cout << "~~~~~~ S T A T I S T I K A ~~~~~~" << endl;
				char c2;
				do
				{
					cout << "UKUPNA STATISTIKA [1], ZA ODREDJENI ARTIKAL [2]: ";
					std::cin >> c2;
				} while (c2 != '1' && c2 != '2');
				if (c2 == '1')
				{
					system("cls");
					char c1;
					do {
						std::cout << "Dnevna statistika [1], Sedmicna statistika [2], Mesecna statistika [3], " << endl << "Godisnja statistika [4], Lista kupaca [5], Kraj [0]: ";
						std::cin >> c1;
						if (c1 == '5')
						{
							system("cls");
							zaposlen.statistikaKupci();
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '1')
						{
							system("cls");
							zaposlen.statistikaDan();
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '2')
						{
							system("cls");
							zaposlen.statistikaSedmica();
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '3')
						{
							system("cls");
							zaposlen.statistikaMjesec();
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '4')
						{
							system("cls");
							zaposlen.statistikaGodina();
							cin.get();
							cin.get();
							system("cls");
						}
					} while (c1 != '0');
					system("cls");
				}
				else
				{
					system("cls");
					int sifra, i;
					artikli.print();
					do
					{
						std::cout << "Unesite sifru artikla: ";
						std::cin >> sifra;
						for (i = 0; i < artikli.niz.size(); i++)
							if (artikli.niz[i].getSifra() == sifra)
								break;
						if (artikli.niz.size() == i)
							std::cout << "Ne postoji sifra!" << std::endl;
					} while (artikli.niz.size() == i);
					char c1;
					do {
						std::cout << "Dnevna statistika [1], Sedmicna statistika [2], " << endl << "Mesecna statistika [3],Godisnja statistika [4],  Kraj [0]: ";
						std::cin >> c1;
						if (c1 == '1')
						{
							system("cls");
							zaposlen.statistikaDanJedan(sifra,artikli,i);
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '2')
						{
							system("cls");
							zaposlen.statistikaSedmicaJedan(sifra, artikli, i);
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '3')
						{
							system("cls");
							zaposlen.statistikaMjesecJedan(sifra, artikli, i);
							cin.get();
							cin.get();
							system("cls");
						}
						else if (c1 == '4')
						{
							system("cls");
							zaposlen.statistikaGodinaJedan(sifra, artikli, i);
							cin.get();
							cin.get();
							system("cls");
						}
					} while (c1 != '0');
					system("cls");
				}
			}
		} while (c != '0');
		artikli.pisiDatoteku();
		system("cls");
	}
}