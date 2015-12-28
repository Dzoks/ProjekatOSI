#include "Administrator.h"



Administrator::Administrator(std::string ime, std::string loz):Korisnik(ime,loz)
{}

Administrator::~Administrator()
{
}

void Administrator::kreirajNalog()
{
	std::ifstream dat("Korisnici.txt");


	std::string pom_ime;
	bool flag = false;
	do
	{
		flag = false;
		dat.seekg(0, std::ios::beg);
		std::cout << "Unesite ime: ";
		std::cin >> pom_ime;
		std::string pom1,pom2,pom3;
		while (!dat.eof() && !flag)
		{
			dat >> pom1;
			dat >> pom2;
			dat >> pom3;
			if (pom1 == pom_ime)
				flag = true;
		}
	} while (flag);
	std::string pom_loz;
	do
	{
		std::cout << "Unesite lozinku: ";
		std::cin >> pom_loz;
	}while(pom_loz.length() < 6);
	dat.close();
	std::ofstream dat1("Korisnici.txt",ios::app);
	dat1 << pom_ime << " " << pom_loz << " ";
	char c;
	do
	{
		std::cout << "Status korisnika ADMINISTRATOR[1]  ZAPOSLENI[2]:";
		std::cin >> c;
		if (c == '1')
			dat1 << "A" << std::endl;
		else dat1 << "Z" << std::endl;
	} while (c != '1' && c != '2');
	dat1.close();
}

void Administrator::izmjenaNaloga(Korisnik **niz,int brojac)
{
	Korisnik **pok = 0;
	std::string pom;
	do
	{
		std::cout << "Unesite korisnicko ime: ";
		std::cin >> pom;
		pok=std::find_if(niz, niz + brojac, [&pom](Korisnik *k) { return pom == k->getIme(); });
	} while (pok==niz+brojac && (*pok)->getIme()==this->getIme());
	
	char c;
	do
	{
		std::cout << "Promjena SIFRE[S]  KORISNISKOG IMENA[K]  KRAJ[0]: ";
		std::cin >> c;
		if (c == 'S')
		{
			do
			{
				std::cout << "Unesite novu sifru: ";
				std::cin >> pom;
			} while (pom.length() < 6);
			(*pok)->setLozinka(pom);
			std::cout << "Uspjesna promjena lozinke";
		}
		else if (c == 'K')
		{
			do
			{
				std::cout << "Unesite novo korisnicko ime: ";
				std::cin >> pom;
			} while (std::any_of(niz, niz + brojac, [&pom](Korisnik *k) { return pom == k->getIme(); }));
			(*pok)->setLozinka(pom);
		}
	}while(c!='0');	
}

void Administrator::brisiNalog(Korisnik **niz,int brojac)
{
	std::string pom;
	Korisnik **pok = 0;
	do
	{
		std::cout << "Unesite korisnicko ime: ";
		std::cin >> pom;
		pok = std::find_if(niz, niz + brojac, [&pom](Korisnik *k) { return pom == k->getIme(); });
	} while (pok == niz + brojac && (*pok)->getIme() == this->getIme());

	Korisnik **novi_niz = new Korisnik*[brojac - 1];
	std::copy(niz, pok, novi_niz);
	std::copy(pok + 1, niz + brojac, novi_niz);
	delete[] niz;
	niz = novi_niz;
	delete pok;
}
