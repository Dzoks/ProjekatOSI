#define _CRT_SECURE_NO_WARNINGS

#include "Zaposleni.h"
#include <algorithm>
#include <string>
#include <cstring>
int prestupna(int godina)
{
	return
		!(godina & 4)          
		&&
		(
			godina % 100         
			|| !(godina / 100 & 4)
			);
}
void zavrtiza7(int& d, int&  m, int&  y)
{
	time_t rawtime;
	struct tm * timeinfo;
	const char * weekday[] = { "Sunday", "Monday",
		"Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday" };
	do {
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		timeinfo->tm_year = y - 1900;
		timeinfo->tm_mon = m - 1;
		timeinfo->tm_mday = d;
		mktime(timeinfo);
		if (strcmp(weekday[timeinfo->tm_wday], "Monday")) d--;
	} while (strcmp(weekday[timeinfo->tm_wday], "Monday"));
	if (d <= 0) d = 1;
		
}
Zaposleni::Zaposleni(std::string username, std::string password, std::string status):Korisnik(username, password, status)
{}

Zaposleni::~Zaposleni()
{
}

void Zaposleni::izmjenaArtikla(Niz &other)
{
	char c;
	int sifra,i;
	//if (other.niz.size() == 0)
	std::cout << std::endl;
	std::cout << "================================================="<<std::endl;
	std::cout << "||             IZMJENA    ARTIKLA              ||" << std::endl;
	std::cout << "=================================================" << std::endl;
	if (other.niz.size() == 0)
	{
		std::cout << std::endl;
		std::cout << "====================================================="<<std::endl;
		std::cout << "||NE POSTOJI NIJEDAN ARTIKAL, PRETRAGA NIJE MOGUCA.||" << std::endl;
		std::cout << "||         PRITISNITE ENTER DA NASTAVITE.          ||" << std::endl;
		std::cout << "====================================================="<<std::endl;
		return;
	}
	std::cout << std::endl<< "UNESITE SIFRU ARTIKLA: ";
	do
	{
		std::cout << "\nSifra: "; std::cin >> sifra;
	} while (sifra < 1 || sifra >999999);
	//Pretraga da li postoji artikal sa tom sifrom
	for (i = 0; i < other.niz.size(); i++)
		if (other.niz[i].getSifra() == sifra)
			break;
	if (i == other.niz.size())
	{
		std::cout << "UNESENA SIFRA NE POSTOJI!" << std::endl;
			return;
	}
	Artikal a;
	for (i = 0; i < other.niz.size(); i++)
		if (other.niz[i].getSifra() == sifra)
			break;
	std::cout << "STA SE MIJENJA? \nIME [1], KOLICINA [2], OPIS [3], CIJENA [4]: " ;
	std::cin >> c;
	switch (c)
	{
	case('1') :
	{	
		std::string ime;
		do
		{
			std::cout << "\t\tUNESITE IME: "; std::cin >> ime;
		} while (ime.length() < 3);
		other.niz[i].setNaziv(ime);
		break;
	}
	case('2') :
	{
		double kol;
		do
		{
			std::cout << "\t\tKOLICINA: "; std::cin >> kol;
		} while (kol < 0.01);
		other.niz[i].setKolicina(kol);
		break;
	}
	case('3') :
	{
		std::string opis;
		std::cout << "\t\tOPIS:";
		std::cin >> opis;
		other.niz[i].setOpis(opis);
		break;
	}
	case('4') :
	{
		double cijena;
		do
		{
			std::cout << "\t\tCijena: "; std::cin >>cijena;
		} while (cijena < 0.01);
		other.niz[i].setCijena(cijena);
		break;
	}
	default:
		std::cout << "Unijeli ste pogresnu komandu"<<std::endl;
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Zaposleni::prodajArtikal(Niz& niz)
{
	std::cout << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "||   PRAVLJENJE RACUNA    ||" << std::endl;
	std::cout << "============================" << std::endl;
	if (niz.niz.size() == 0)
	{
		std::cout << std::endl;
		std::cout << "===================================================="<<std::endl;
		std::cout << "||NE POSTOJI NIJEDAN ARTIKAL, PRODAJA NIJE MOGUCA.||" << std::endl;
		std::cout << "||         PRITISNITE ENTER DA NASTAVITE.         ||" << std::endl;
		std::cout << "===================================================="<<std::endl;
		return;
	}
	std::vector<Artikal> racun;
	std::vector<statistika> stats;
	std::fstream stat("Statistika.txt", std::fstream::in);
	if (stat)
	{
		statistika jedinicna;
		while (!stat.eof())
		{
			stat >> jedinicna.day >> jedinicna.month >> jedinicna.year >> jedinicna.h >> jedinicna.m >> jedinicna.s >> jedinicna.sifra >> jedinicna.kolicina >> jedinicna.cena;
			if (jedinicna.day == -1) break;
			stats.push_back(jedinicna);
		}
		stat.close();
	}
	int sifra, i;
	char pom;
	double kolicina,suma=0;
	niz.print();
	std::string kupac;
	std::cout << "Unesite ime kupca: ";
	std::cin >> kupac;
	int kap = 5;
	int brojElemenata = 0;
	std::string* kupci = new std::string[kap];
	std::string ime;
	std::fstream dat("Kupci.txt", std::fstream::in);
	if (dat)
	{	while (!dat.eof())
		{
			if (brojElemenata == kap)
			{
				std::string* novi = new std::string[kap *= 2];
				std::copy(kupci, kupci + brojElemenata, novi);
				delete[] kupci;
				kupci = novi;
			}
			dat >> ime;
			if (ime == "END") break;
			kupci[brojElemenata] = ime;
			brojElemenata++;
		}
		dat.close();
	}
	do
	{
		do
		{
			std::cout << "Unesite sifru artikla: ";
			std::cin >> sifra;
			for (i = 0; i < niz.niz.size(); i++)
				if (niz.niz[i].getSifra() == sifra)
					break;
			if (niz.niz.size() == i)
				std::cout << "Ne postoji sifra!" << std::endl;
		} while (niz.niz.size() == i);
		do
		{
			std::cout << "Unesite kolicinu koju prodajete: ";
			std::cin >> kolicina;
		} while (kolicina<0 || kolicina>niz.niz[i].getKolicina());
		niz.niz[i].setKolicina(niz.niz[i].getKolicina() - kolicina);
		racun.push_back(niz.niz[i]);
		racun.at(racun.size() -1).setKolicina(kolicina);
		std::cout << "AKO NE ZELITE VISE PRODAVATI, UNESITE 1,"<<std::endl;;
		std::cout << "U SUPROTNOM UNESITE BILO KOJI TASTER I PRITISNITE ENTER:";
		std::cin >> pom;
	} while (pom != '1');
	statistika vreme;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	vreme.s = now->tm_sec;
	vreme.m = now->tm_min;
	vreme.h = now->tm_hour;
	std::cout << "==================================================" << std::endl;
	std::cout << "                     RACUN                        " << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "||Naziv           Sifra     Kolicina     Cijena  ||" << std::endl;
	std::cout << "==================================================" << std::endl;
	for (i = 0; i < racun.size(); ++i)
	{
		//formatiran ispis racuna 
		std::cout << std::setw(15) << std::left << racun[i].getNaziv() << " " << std::setw(7) << racun[i].getSifra() <<"     "
			<< std::setw(10) << std::left << racun[i].getKolicina() << "     " << std::setw(10) << std::left << racun[i].getKolicina()* racun[i].getCijena() << std::endl;
		//kraj formatirano ispisa
		suma += racun[i].getCijena()*racun[i].getKolicina();
		vreme.sifra = racun[i].getSifra();
		vreme.kolicina = racun[i].getKolicina();
		vreme.cena = racun[i].getCijena()*racun[i].getKolicina();
		stats.push_back(vreme);
	}
	std::cout << "==================================================" << std::endl;
	std::cout << "UKUPNO:" << std::setw(43) << std::right << suma << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << "KUPAC:" << std::setw(44) << std::right << kupac << std::endl;
	std::cout << "==================================================" << std::endl;
	if (brojElemenata == kap)
	{
		std::string* novi = new std::string[kap *= 2];
		std::copy(kupci, kupci + brojElemenata, novi);
		delete[] kupci;
		kupci = novi;
	}
	kupci[brojElemenata++] = kupac;
	dat.open("Kupci.txt", std::fstream::out);
	for (int i = 0; i < brojElemenata; i++)
	{
		dat << kupci[i] << std::endl;
	}
	dat << "END";
	dat.close();
	stat.open("Statistika.txt", std::fstream::out);
	for (i = 0; i < stats.size();++i)
		stat << stats[i].day <<" "<< stats[i].month << " " << stats[i].year << " " << stats[i].h << " " << stats[i].m << " " << stats[i].s << " " << stats[i].sifra << " " << stats[i].kolicina << " " << stats[i].cena<<std::endl;
	stat << -1;
	stat.close();
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Zaposleni::statistikaDan()
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.day == vreme.day&&temp.month == vreme.month&&vreme.year == temp.year) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}
			
		}
		dat.close();
	}

		std::cout << "Dnevna statistika prodaje za " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
		std::cout << "===============================================================================================" << std::endl;
		std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
		std::cout << "Dnevni prihod: " << ukupnaCena << std::endl;
		std::cout << "===============================================================================================" << std::endl;
		std::cout << "=============================================" << std::endl;
		std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
		std::cout << "=============================================" << std::endl;
	
}

void Zaposleni::statistikaSedmicaJedan(int sifra, Niz & niz, int i)
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	int d = vreme.day;
	int m = vreme.month;
	int y = vreme.year;
	zavrtiza7(d, m, y);
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.month == vreme.month&&temp.year == vreme.year&&temp.day <= vreme.day&&temp.day >= d&&temp.sifra == sifra) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}
		}
		dat.close();
	}
	std::cout << "Sedmicna statistika prodaje za vrijeme: " << d << "." << m << "." << y << ". - " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "Artikal: " << niz.niz[i].getNaziv() << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Sedmicni prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;

}

void Zaposleni::statistikaDanJedan(int sifra,Niz& niz,int i)
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.day == vreme.day&&temp.month == vreme.month&&vreme.year == temp.year&& temp.sifra==sifra) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}

		}
		dat.close();
	}
	std::cout << "Dnevna statistika prodaje za " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "Artikal: " << niz.niz[i].getNaziv() << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Dnevni prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Zaposleni::statistikaMjesecJedan(int sifra, Niz &niz, int i)
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.day >= 1 && temp.day <= vreme.day&&temp.month == vreme.month&&temp.year == vreme.year&&temp.sifra==sifra) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}

		}
		dat.close();
	}
	std::cout << "Mesecna statistika prodaje za vrijeme: " << 1 << "." << vreme.month << "." << vreme.year << ". - " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "Artikal: " << niz.niz[i].getNaziv() << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Mesecni prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Zaposleni::statistikaGodinaJedan(int sifra, Niz &niz, int i)
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.month <= vreme.month&&temp.year == vreme.year&& temp.sifra==sifra) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}

		}
		dat.close();
	}
	std::cout << "Godisnja statistika prodaje za vrijeme: " << 1 << "." << 1 << "." << vreme.year << ". - " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "Artikal: " << niz.niz[i].getNaziv() << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Godisnji prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Zaposleni::statistikaSedmica()
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	int d = vreme.day;
	int m = vreme.month;
	int y = vreme.year;
	zavrtiza7(d, m, y);
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.month==vreme.month&&temp.year==vreme.year&&temp.day<=vreme.day&&temp.day>=d) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}
		}
		dat.close();
	}
	std::cout << "Sedmicna statistika prodaje za vrijeme: "<<d<<"."<<m<<"."<<y<<". - " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Sedmicni prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;

}

void Zaposleni::statistikaMjesec()
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if(temp.day>=1&&temp.day<=vreme.day&&temp.month==vreme.month&&temp.year==vreme.year){
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}

		}
		dat.close();
	}
	std::cout << "Mesecna statistika prodaje za vrijeme: " << 1 << "."<< vreme.month << "." << vreme.year << ". - " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Mesecni prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Zaposleni::statistikaGodina()
{
	statistika vreme, temp;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	vreme.day = now->tm_mday;
	vreme.month = now->tm_mon + 1;
	vreme.year = now->tm_year + 1900;
	double ukupnaKolicina = 0;
	double ukupnaCena = 0;
	std::fstream dat("Statistika.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> temp.day >> temp.month >> temp.year >> temp.h >> temp.m >> temp.s >> temp.sifra >> temp.kolicina >> temp.cena;
			if (temp.day == -1) break;
			if (temp.month <= vreme.month&&temp.year == vreme.year) {
				ukupnaCena += temp.cena;
				ukupnaKolicina += temp.kolicina;
			}

		}
		dat.close();
	}
	std::cout << "Godisnja statistika prodaje za vrijeme: " << 1 << "." << 1 << "." << vreme.year << ". - " << vreme.day << "." << vreme.month << "." << vreme.year << "." << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "Ukupna kolicina prodanih proizvoda: " << ukupnaKolicina << std::endl;
	std::cout << "Godisnji prihod: " << ukupnaCena << std::endl;
	std::cout << "===============================================================================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;
}


void Zaposleni::statistikaKupci()
{
	int kap = 5;
	int brojElemenata = 0;
	std::string* kupci = new std::string[kap];
	std::string ime;
	std::fstream dat("Kupci.txt", std::fstream::in);
	if (dat)
	{
		while (!dat.eof())
		{
			if (brojElemenata == kap)
			{
				std::string* novi = new std::string[kap *= 2];
				std::copy(kupci, kupci + brojElemenata, novi);
				delete[] kupci;
				kupci = novi;
			}
			dat >> ime;
			if (ime == "END") break;
			kupci[brojElemenata] = ime;
			brojElemenata++;
		}
		dat.close();
	}
	std::cout << std::endl;
	std::cout << "================" << std::endl;
	std::cout << "||LISTA KUPACA||" << std::endl;
	std::cout << "================" << std::endl;
	for (int i = 0; i < brojElemenata; i++)
		std::cout << kupci[i] << std::endl;
	std::cout << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||     PRITISNITE ENTER DA NASTAVITE.      ||" << std::endl;
	std::cout << "=============================================" << std::endl;

}
