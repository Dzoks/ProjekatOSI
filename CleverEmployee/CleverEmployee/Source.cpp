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
	cout << endl << endl;
	cout << "===============================" << endl;
	cout << "||     CLEVER EMPLOYEE       ||" << endl;
	cout << "===============================" << endl;
	cout << endl << endl;
	fstream poruka("Poruka.txt", fstream::in);
	if (poruka)
	{
		string p;
		getline(poruka, p);
		cout << "PORUKA ADMINISTRATORA:" << endl<< p << endl;//ispis poruke
	}
	Korisnik pom;
	cout << endl << endl;
	pom.prijavaNaSistem();
	if (pom.getStatus() == "A")
	{
		system("cls");
		char c;
		Administrator admin(pom.getIme(), pom.getLozinka(), pom.getStatus());
		do {
			system("cls");
			cout << endl;
			cout << "========================================" << endl;
			cout << "||  ADMINISTRATORSKA KONTROLNA PLOCA  ||" << endl;
			cout << "========================================" << endl;
			cout << endl;
			std::cout << "DOBRODOSLI, " << admin.getIme() << "! ODABERITE NEKU OD POSTOJECIH OPCIJA: " << std::endl << endl;
			std::cout << "RAD SA KORISNICKIM NALOZIMA [1], STATISTIKA SISTEMA [2], OSTALE OPCIJE [3], Kraj [0] : ";
			cin >> c;
			if (c == '1')
			{
				char c1;
				do
				{
					system("cls");
					cout << endl;
					cout << "======================================" << endl;
					cout << "||   RAD SA KORISNICKIM NALOZIMA    ||" << endl;
					cout << "======================================" << endl;
					cout << endl;
					cout << "ODABERITE ZELJENU OPCIJU: " << endl << endl<<"KREIRANJE NOVOG NALOGA [1], IZMJENA POSTOJECEG NALOGA [2], " << endl << endl << "BRISANJE NALOGA [3], LISTA SVIH NALOGA [4], KRAJ [0]: ";
					cin >> c1;
					if (c1 == '1') admin.kreirajNalog();
					else if (c1 == '2') admin.izmjenaNaloga();
					else if (c1 == '3') admin.brisiNalog();
					else if (c1 == '4') admin.pisiSve();
					system("cls");
				} while (c1 != '0');
				system("cls");
			}
			else if (c == '2')
			{
			
				char c1;
				do
				{
					system("cls");
					cout << endl;
					cout << "=============================" << endl;
					cout << "||   STATISTIKA SISTEMA    ||" << endl;
					cout << "=============================" << endl;
					cout << endl;
					cout << "ODABERITE ZELJENU OPCIJU: " << endl << endl<<"UKUPAN BROJ NALOGA [1], UKUPAN BROJ IZMJENA [2], KRAJ [0]: ";
					cin >> c1;
					if (c1 == '1') admin.ukupanBrojNaloga();
					else if (c1 == '2') admin.brojIzmjena();
					system("cls");
				} while (c1 != '0');
				system("cls");
			}
			else if (c == '3')
			{
				char c1;
				do

				{
					system("cls");
					cout << endl;
					cout << "========================" << endl;
					cout << "||   OSTALE OPCIJE    ||" << endl;
					cout << "========================" << endl;
					cout << endl;
					cout << "ODABERITE OPCIJU: " << endl << "PODESAVANJE BOJE SISTEMA [1], DODAVANJE OBAVJESTENJA [2], KRAJ [0]: ";
					cin >> c1;
					if (c1 == '1') admin.podesavanjeBoje();
					else if (c1 == '2') admin.dodajObavjestenje();
					system("cls");
				} while (c1 != '0');
				system("cls");
			}
		} while (c != '0');
	}
		
	else if (pom.getStatus() == "G")
	{
		system("cls");
		char c;
		Niz artikli;
		artikli.ucitajDatoteku();
		Zaposleni z(pom.getIme(), pom.getLozinka(), pom.getStatus());
		std::cout << "DOBRODOSLI, " << z.getIme() << "! ODABERITE OPCIJU: " << std::endl;
		do {
			std::cout << "ISPIS [1], PRETRAGA [2], KRAJ [0]: ";
			std::cin >> c;
			if (c == '1') {
				 artikli.print();
				 cin.get();
				 cin.get();
				 system("cls");
			}
			else if (c == '2') {
				 artikli.traziPoNazivu();
				 cin.get();
				 cin.get();
				 system("cls");
			}
		} while (c != '0');
	}
	else 
	{
		system("cls");
		Zaposleni zaposlen(pom.getIme(), pom.getLozinka(), pom.getStatus());
		cout << "DOBRO DOSLI, " << pom.getIme() << "! ODABERITE NEKU OD POSTOJECIH OPCIJA: " << endl;
		Niz artikli;
		artikli.ucitajDatoteku();
		char c;
		do
		{
			cout << endl;
			cout << "===========================" << endl;
			cout << "||   RAD SA ARTIKLIMA    ||" << endl;
			cout << "===========================" << endl;
			cout << endl;
			cout << "DODAVANJE [1], BRISANJE [2], IZMJENA [3], PRETRAGA [4]," << endl << endl<<"ISPIS [5], PRODAJA[6], STATISTIKA [7], KRAJ [0]: ";
			cin >> c;
			if (c == '1')
			{
				system("cls");
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
					cout << endl;
					cout << "=============================" << endl;
					cout << "||        PRETRAGA         ||" << endl;
					cout << "=============================" << endl;
					cout << endl;
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
				artikli.print();
				std::cout << "=============================================" << std::endl;
				std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
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
				char c2;
				do
				{
					cout << endl;
					cout << "=====================" << endl;
					cout << "||   STATISTIKA    ||" << endl;
					cout << "=====================" << endl;
					cout << endl;
					cout << "UKUPNA STATISTIKA [1], ZA ODREDJENI ARTIKAL [2]: ";
					std::cin >> c2;
				} while (c2 != '1' && c2 != '2');
				if (c2 == '1')
				{
					system("cls");
					char c1;
					do {
						cout << endl;
						cout << "============================" << endl;
						cout << "||   UKUPNA STATISTIKA    ||" << endl;
						cout << "============================" << endl;
						cout << endl;
						std::cout << "DNEVNA STATISTIKA [1], SEDMICNA STATISTIKA [2], MJESECNA STATISTIKA [3], " << endl << endl<<"GODISNJA STATISTIKA [4], LISTA KUPACA [5], KRAJ [0]: ";
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
						system("cls");
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
						cout << endl;
						cout << "=========================================" << endl;
						cout << "||   STATISTIKA  ODREDJENOG ARTIKLA    ||" << endl;
						cout << "=========================================" << endl;
						cout << endl;
						std::cout << "UNESITE SIFRU ARTIKLA: ";
						std::cin >> sifra;
						for (i = 0; i < artikli.niz.size(); i++)
							if (artikli.niz[i].getSifra() == sifra)
								break;
						if (artikli.niz.size() == i)
							std::cout << "NE POSTOJI SIFRA!" << std::endl;
					} while (artikli.niz.size() == i);
					char c1;
					do {

						std::cout << "DNEVNA STATISTIKA [1], SEDMICNA STATISTIKA [2], " << endl <<endl<< "MJESECNA STATISTIKA [3], GODISNJA STATISTIKA [4],  KRAJ [0]: ";
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
						system("cls");
					} while (c1 != '0');
					system("cls");
				}
			}
		} while (c != '0');
		artikli.pisiDatoteku();
		system("cls");
	}
}