#include "Administrator.h"



Administrator::Administrator(std::string ime, std::string loz, std::string status) :Korisnik(ime, loz, status)
{}

Administrator::~Administrator()
{
}

void Administrator::kreirajNalog()
{
	system("cls");
	int kap = 5;
	int brojElemenata = 0;
	Korisnik* niz = new Korisnik[kap];
	std::string ime, loz, status;
	std::fstream dat("Korisnici.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			if (brojElemenata == kap)
			{
				Korisnik* novi = new Korisnik[kap *= 2];
				std::copy(niz, niz + brojElemenata, novi);
				delete[] niz;
				niz = novi;
			}
			dat >> ime >> loz >> status;
			if (ime == "END") break;
			niz[brojElemenata].setIme(ime);
			niz[brojElemenata].setLozinka(loz);
			niz[brojElemenata].setStatus(status);
			brojElemenata++;
		}
		dat.close();
	}
	do
	{
		std::cout << "UNESITE ZELJENO KORISNICKO IME: ";
		std::cin >> ime;
	} while (std::any_of(niz, niz + brojElemenata, [&ime](Korisnik&a) {return a.getIme() == ime; }));
	do
	{
		std::cout << "UNESITE LOZINKU: ";
		std::cin >> loz;
	} while (loz.length() < 6);
	do
	{
		std::cout << "ADMINISTRATOR [A}, ZAPOSLENI [Z] ? ";
		std::cin >> status;
	} while (status != "A"&&status != "Z");
	if (brojElemenata == kap)
	{
		Korisnik* novi = new Korisnik[kap *= 2];
		std::copy(niz, niz + brojElemenata, novi);
		delete[] niz;
		niz = novi;
	}
	niz[brojElemenata].setIme(ime);
	niz[brojElemenata].setLozinka(loz);
	niz[brojElemenata].setStatus(status);
	brojElemenata++;
	dat.open("Korisnici.txt", std::fstream::out);
	for (int i = 0; i < brojElemenata; i++)
	{
		dat << niz[i].getIme() << " " << niz[i].getLozinka() << " " << niz[i].getStatus() << std::endl;
	}
	dat << "END";
	dat.close();
	int izmene = 0;
	std::fstream iz("Izmene.txt", std::ios::in);
	if (iz) { iz >> izmene; iz.close(); }
	izmene++;
	iz.open("Izmene.txt", std::fstream::out);
	iz << izmene;
	iz.close();
	delete[] niz;
	std::cout << "===================================================================" << std::endl;
	std::cout << "||NALOG USPJESNO DODAN, PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "===================================================================" << std::endl;
	std::cin.get();
	std::cin.get();
	system("cls");
}


void Administrator::izmjenaNaloga()
{
	system("cls");
	int kap = 5;
	int brojElemenata = 0;
	Korisnik* niz = new Korisnik[kap];
	std::string ime, loz, status;
	std::fstream dat("Korisnici.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			if (brojElemenata == kap)
			{
				Korisnik* novi = new Korisnik[kap *= 2];
				std::copy(niz, niz + brojElemenata, novi);
				delete[] niz;
				niz = novi;
			}
			dat >> ime >> loz >> status;
			if (ime == "END") break;
			niz[brojElemenata].setIme(ime);
			niz[brojElemenata].setLozinka(loz);
			niz[brojElemenata].setStatus(status);
			brojElemenata++;
		}
		dat.close();
	}
	Korisnik* nadjeni = nullptr;
	do
	{
		std::cout << "UNESITE IME ZA PRETRAGU: ";
		std::cin >> ime;
		nadjeni = std::find_if(niz, niz + brojElemenata, [&ime](Korisnik& a) {return a.getIme() == ime; });
		if (nadjeni == niz + brojElemenata) nadjeni = nullptr;
	} while (!nadjeni);
	std::cout << "STA ZELITE DA MIJENJATE?" << std::endl << "KORISICNICKO IME [1], LOZINKU [2], STATUS KORISNIKA [3]: ";
	char c11;
	std::cin >> c11;
	if (c11 == '1') {
		do
		{
			std::cout << "UNESITE NOVO KORISNICKO IME: ";
			std::cin >> ime;

		} while (std::any_of(niz, niz + brojElemenata, [&ime](Korisnik&a) {return a.getIme() == ime; })); nadjeni->setIme(ime);
	}
	if (c11 == '2')
	{
		do {
			std::cout << "UNESITE NOVU LOZINKU: ";
			std::cin >> loz;

		} while (loz.length() < 6);
		nadjeni->setLozinka(loz);
	}
	if (c11 == '3') {
		do
		{
			std::cout << "ADMINISTRATOR [A}, ZAPOSLENI [Z] ? ";
			std::cin >> status;

		} while (status != "A"&&status != "Z");
		nadjeni->setStatus(status);
	}
	dat.open("Korisnici.txt", std::fstream::out);
	for (int i = 0; i < brojElemenata; i++)
	{
		dat << niz[i].getIme() << " " << niz[i].getLozinka() << " " << niz[i].getStatus() << std::endl;
	}
	dat << "END";
	dat.close();
	int izmene = 0;
	std::fstream iz("Izmene.txt", std::ios::in);
	if (iz) { iz >> izmene; iz.close(); }
	izmene++;
	iz.open("Izmene.txt", std::fstream::out);
	iz << izmene;
	iz.close();
	delete[] niz;
	std::cout << "=======================================================================" << std::endl;
	std::cout << "||NALOG USPJESNO IZMJENJEN, PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "=======================================================================" << std::endl;
	std::cin.get();
	std::cin.get();
	system("cls");
}

void Administrator::pisiSve()
{
	system("cls");
	int kap = 5;
	int brojElemenata = 0;
	Korisnik* niz = new Korisnik[kap];
	std::string ime, loz, status;
	std::fstream dat("Korisnici.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			if (brojElemenata == kap)
			{
				Korisnik* novi = new Korisnik[kap *= 2];
				std::copy(niz, niz + brojElemenata, novi);
				delete[] niz;
				niz = novi;
			}
			dat >> ime >> loz >> status;
			if (ime == "END") break;
			niz[brojElemenata].setIme(ime);
			niz[brojElemenata].setLozinka(loz);
			niz[brojElemenata].setStatus(status);
			brojElemenata++;
		}
		dat.close();
	}
	std::cout << "||===============================================||" << std::endl;
	std::cout << "||" << std::setw(20) << std::setfill(' ') << "KORISNICKO IME" << std::setw(20) << " LOZINKA" << std::setw(6) << " STATUS" << "||" << std::endl;
	std::cout << "||===============================================||" << std::endl;
	for (int i = 0; i < brojElemenata; i++)
		std::cout << "||" << std::setw(20) << std::setfill(' ') << niz[i].getIme() << std::setw(20) << niz[i].getLozinka() << std::setw(7) << niz[i].getStatus() << "||" << std::endl;
	std::cout << "||===============================================||" << std::endl;
	delete[] niz;
	std::cin.get();
	std::cin.get();
}

void Administrator::brisiNalog()
{
	system("cls");
	int kap = 5;
	int brojElemenata = 0;
	Korisnik* niz = new Korisnik[kap];
	std::string ime, loz, status;
	std::fstream dat("Korisnici.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			if (brojElemenata == kap)
			{
				Korisnik* novi = new Korisnik[kap *= 2];
				std::copy(niz, niz + brojElemenata, novi);
				delete[] niz;
				niz = novi;
			}
			dat >> ime >> loz >> status;
			if (ime == "END") break;
			niz[brojElemenata].setIme(ime);
			niz[brojElemenata].setLozinka(loz);
			niz[brojElemenata].setStatus(status);
			brojElemenata++;
		}
		dat.close();
	}
	Korisnik* nadjeni = nullptr;
	do
	{
		std::cout << "UNESITE IME ZA PRETRAGU: ";
		std::cin >> ime;
		nadjeni = std::find_if(niz, niz + brojElemenata, [&ime](Korisnik& a) {return a.getIme() == ime; });
		if (nadjeni == niz + brojElemenata) nadjeni = nullptr;
	} while (!nadjeni || nadjeni->getIme() == this->getIme());
	dat.open("Korisnici.txt", std::fstream::out);
	std::for_each(niz, nadjeni, [&dat](Korisnik& a)
	{
		dat << a.getIme() << " " << a.getLozinka() << " " << a.getStatus() << std::endl;
	});
	std::for_each(nadjeni + 1, niz + brojElemenata, [&dat](Korisnik& a)
	{
		dat << a.getIme() << " " << a.getLozinka() << " " << a.getStatus() << std::endl;
	});
	dat << "END";
	dat.close();
	std::cout << "======================================================================" << std::endl;
	std::cout << "||NALOG USPJESNO IZBRISAN. PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "======================================================================" << std::endl;
	int izmene = 0;
	std::fstream iz("Izmene.txt", std::ios::in);
	if (iz) { iz >> izmene; iz.close(); }
	izmene++;
	iz.open("Izmene.txt", std::fstream::out);
	iz << izmene;
	iz.close();
	delete[] niz;
	std::cin.get();
	std::cin.get();
	system("cls");

}

void Administrator::podesavanjeBoje()
{
	system("cls");
	std::fstream dat("Kontrola.txt", std::ios::out);
	char c;
	do {

		std::cout << "ZA PROMJENU BOJE ODABERITE JEDNU OD SLEDECE TRI OPCIJE:" << std::endl;
		std::cout << "CRNA[1], PLAVA [2], BIJELA [3]: " << std::endl;
		std::cin >> c;
		if (c == '1')
			dat << "color 07" << std::endl;
		if (c == '2')
			dat << "color 17" << std::endl;
		if (c == '3')
			dat << "color F0" << std::endl;
		else if (c != '1'&& c != '2'&& c != '3') std::cout << "POGRESNA OPCIJA!" << std::endl;
	} while (c != '1'&& c != '2'&& c != '3');
	std::cout << "==================================================================================================" << std::endl;
	std::cout << "||PROMJENE CE BITI IZVRSENE NAKON PONOVNOG POKRETANJA, pritisnite bilo koji taster da nastavite.||" << std::endl;
	std::cout << "==================================================================================================" << std::endl;
	dat.close();
	std::cin.get();
	std::cin.get();
	system("cls");
}

void Administrator::brojIzmjena()
{
	int izmene = 0;
	std::fstream iz("Izmene.txt", std::ios::in);
	if (iz) { iz >> izmene; iz.close(); }
	std::cout << "=====================================" << std::endl;
	std::cout << "||UKUPAN BROJ IZMJENA IZNOSI" << std::setw(7) << izmene << "||" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cin.get();
	std::cin.get();
	system("cls");
}

void Administrator::ukupanBrojNaloga()
{

	std::fstream dat("Korisnici.txt", std::ios::in);
	int br = 0;
	std::string a, b, c;
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> a >> b >> c;
			br++;
		}
		dat.close();
	}
	char cha;
	br--;
	do
	{
		std::cout << "ISPIS NA KONZOLU[1], TEKSTUALNI FAJL[2]: ";
		std::cin >> cha;
		if (cha == '1')
		{
			std::cout << "========================================================================================" << std::endl;
			std::cout << "||UKUPAN BROJ KORISNICKIH NALOGA JE: " << std::setw(6) << br << ", pritisnite bilo koji taster da nastavite.||" << std::endl;
			std::cout << "========================================================================================" << std::endl;
		}
		else if (cha == '2')
		{
			std::fstream out("BrojNaloga.txt", std::ios::out);
			out << "==============================================" << std::endl;
			out << "||UKUPAN BROJ KORISNICKIH NALOGA JE: " << std::setw(6) << br << "||" << std::endl;
			out << "==============================================" << std::endl;
			std::cout << "================================================================================================================" << std::endl;
			std::cout << "||INFORMACIJA KOJA STE TRAZILI JE UPISANA U DATOTEKU BrojNaloga.txt, pritisnite bilo koji taster da nastavite.||" << std::endl;
			std::cout << "================================================================================================================" << std::endl;
			out.close();
		}
		std::cin.get();
		std::cin.get();
		system("cls");

	} while (cha != '1'&&cha != '2');


}

void Administrator::dodajObavjestenje()
{
	std::string poruka;
	std::cout << "UNESITE OBAVJESTENJE KOJE ZELITE:" << std::endl;
	std::cin.get();
	getline(std::cin, poruka);
	std::fstream por("Poruka.txt", std::fstream::out);
	por << poruka;
	por.close();
	std::cout << "===========================================================================" << std::endl;
	std::cout << "||OBAVJESTENJE USPJESNO DODANO, PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "===========================================================================" << std::endl;
	std::cin.get();
	std::cin.get();
	system("cls");
}
