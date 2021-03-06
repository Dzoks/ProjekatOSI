#include "Korisnik.h"



Korisnik::Korisnik(std::string ime, std::string loz,std::string stat):kor_ime(ime),lozinka(loz),status(stat)
{}

Korisnik::~Korisnik()
{
}

std::string Korisnik::getIme()
{
	return kor_ime;
}

std::string Korisnik::getLozinka()
{
	return lozinka;
}

std::string Korisnik::getStatus()//vraca status
{
	return status;
}

void Korisnik::setStatus(std::string s)
{
	status = s;
}

void Korisnik::setIme(std::string ime)
{
	kor_ime = ime;
}

void Korisnik::setLozinka(std::string loz)
{
	lozinka = loz;
}

void Korisnik::prijavaNaSistem()
{
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
		Korisnik* nadjeni = nullptr;
		char ch;
		do
		{
			loz = "";
			std::cout << "UNESITE VASE KORISNICKO IME:";
			std::cin >> ime;
			std::cout << "UNESITE VASU LOZINKU: ";
			HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD mode = 0;
			GetConsoleMode(hStdin, &mode);
			SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
			std::cin >> loz;
			SetConsoleMode(hStdin, mode/* & (~ENABLE_ECHO_INPUT)*/);
			if (ime == "gost"&&loz == "gost")
			{
				this->kor_ime = "Gost";
				this->lozinka = "Gost";
				this->status = "G";
				return;
			}
			nadjeni = std::find_if(niz, niz + brojElemenata, [&ime](Korisnik& a) {return a.getIme() == ime; });
			if (nadjeni == niz + brojElemenata) {
				nadjeni = nullptr;
				std::cout <<std::endl<< "POGRESNI PODACI, MOLIMO POKUSAJTE PONOVO." << std::endl;
			}
			else if (nadjeni->getLozinka() != loz) {
				nadjeni = nullptr;
				std::cout << std::endl<<"POGRESNI PODACI MOLIMO POKUSAJTE PONOVO." << std::endl;
			}
		} while (!nadjeni);
		this->kor_ime = nadjeni->kor_ime;
		this->lozinka = nadjeni->lozinka;
		this->status = nadjeni->status;

	}
	else
	{
		std::cout << "NA SISTEMU NE POSTOJI ADMINISTRATORSKI NALOG." << std::endl << "DA BI MOGLI KORISTITI SOFTVER, MORATE NAPRAVITI KORISNICKI NALOG."<<std::endl<<"MOLIMO UNESITE PODATKE:" << std::endl;
		std::string ime, loz;
		std::cout << "UNESITE KORISNICKO IME: ";
		std::cin >> ime;
		do {
			std::cout << "UNESITE LOZINKU:";
			std::cin >> loz;
		} while (loz.length() < 6);
		std::cout << "NALOG USPJESNO KREIRAN, DA BI STE NASTAVILI PRITISNITE ENTER." << std::endl;
		dat.open("Korisnici.txt", std::fstream::out);
		dat << ime << " " << loz << " A" << std::endl;
		dat << "END";
		dat.close();
		this->kor_ime = ime;
		this->lozinka = loz;
		this->status = "A";
		std::cin.get();
		std::cin.get();
		system("cls");
		//test
	}
}