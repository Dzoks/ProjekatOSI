#include "Administrator.h"



Administrator::Administrator(std::string ime, std::string loz):Korisnik(ime,loz)
{}

Administrator::~Administrator()
{
}

void Administrator::kreirajNalog()
{
	/*std::ifstream dat("Korisnici.txt");


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
	std::ofstream dat1("Korisnici.txt",std::ios::app);
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
	dat1.close();*/
	/*std::fstream dat("Korisnici.txt", std::fstream::in);
	std::string ime,lozinka,status,pomime;
	bool flag;
	do
	{
		flag = true;
		dat.seekg(0, std::fstream::beg);
		std::cout << "Unesite korisnicko ime: ";
		std::cin >> ime;
		if (dat)
		{
			while (!dat.eof() && flag)
			{
				dat >> pomime >> lozinka >> status;
				if (pomime == ime) flag = false;
			}
		}

	} while (!flag);
	dat.close();
	do
	{
		std::cout << "Unesite zeljenu lozinku: ";
		std::cin >> lozinka;
	} while (lozinka.length() < 6);
	do
	{
		std::cout << "Administrator [A}, Zaposleni [Z] ? ";
		std::cin >> status;
	} while (status!="A"&&status!="Z");
	dat.open("Korisnici.txt", std::fstream::app);

	dat<< ime <<" "<<lozinka << " "<<status<<std::endl;
	dat.close();*/
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
			std::cout << "Unesite korisnicko ime: ";
			std::cin >> ime;
		} while (std::any_of(niz, niz + brojElemenata, [&ime](Korisnik&a) {return a.getIme() == ime; }));
		do
		{
			std::cout << "Unesite lozinku: ";
			std::cin >> loz;
		} while (loz.length() < 6);
		do
		{
			std::cout << "Administrator [A}, Zaposleni [Z] ? ";
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
		for (int i = 0; i < brojElemenata;i++)
		{
			dat << niz[i].getIme() << " " << niz[i].getLozinka() << " " << niz[i].getStatus() << std::endl; 
		}
		dat << "END";
		dat.close();
		delete[] niz;
}


void Administrator::izmjenaNaloga()
{
	/*std::ifstream dat("Korisnici.txt");
	std::string novi,pom1,pom2,pom3,novi1,pom11,pom22,pom33;
	bool flag = false;
	int lokacija = 0;
	do
	{
		dat.clear();
		dat.seekg(0);
		flag = true;
		std::cout << "Korisnicko ime: ";
		std::cin >> novi;
		while (!dat.eof() && flag)
		{
			dat >> pom1 ;
			dat >> pom2;
			dat >> pom3;
			if (pom1 == novi)
			{
				flag = false;
				lokacija = dat.tellg();
			}
		}
	} while (flag);
	dat.close();

	std::fstream dat1("Korisnici.txt",std::ios::in|std::ios::out);
	char c;
	do
	{
		
		std::cout << "Promjena KORISKICKOG IMENA[1]   LOZINKE[2]: ";
		std::cin >> c;
		if (c == '1')
		{
			std::ifstream dat2("Korisnici.txt");
			bool flag = false;
			do
			{
				flag = true;
				std::cout << "Novo korisnicko ime: ";
				std::cin >> novi1;
				while (!dat2.eof() && flag)
				{
					dat2 >> pom11 >> pom22>> pom33;
					if (pom1 == novi1)
					{
						lokacija = dat2.tellg();
						flag = false;
					}
				}
			} while (!flag);
			dat2.close();
			dat1.clear();
			long duzina = pom1.length() + pom2.length() + pom3.length() + 2;
			dat1.seekp(lokacija-duzina,std::ios::beg);
			//cout << lokacija <<"    "<< duzina<<endl;
			dat1 << novi1 << " " << pom2 << " " << pom3 << std::endl;
		}
	} while (c!='1' && c!='2');
	dat1.close();*/
	/*std::string ime, lozinka, status, pomime;
	std::streamoff lokacija;
	bool flag;
	do
	{
		flag = true;
		std::fstream dat("Korisnici.txt", std::fstream::in);
		//dat.seekg(0, std::fstream::beg);
		std::cout << "Unesite korisnicko ime: ";
		std::cin >> ime;
		if (dat)
		{
			while (!dat.eof() && flag)
			{
				lokacija = dat.tellg();
				dat >> pomime >> lozinka >> status;
				if (pomime == ime) flag = false;
			}
			dat.close();
		}
	} while (flag);
	std::fstream dat("Korisnici.txt", std::fstream::in|std::fstream::out);
	dat.seekp(lokacija, std::fstream::beg);
	do
	{
		std::cout << "Unesite zeljenu lozinku: ";
		std::cin >> lozinka;
	} while (lozinka.length() < 6);
	do
	{
		std::cout << "Administrator [A}, Zaposleni [Z] ? ";
		std::cin >> status;
	} while (status != "A"&&status != "Z");
	dat << ime << " " << lozinka << " " << status << std::endl;
	dat.close();*/

}

void Administrator::podesavanjeBoje()
{
	std::fstream dat("Kontrola.txt",std::ios::out);
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
		else if(c != '1'&& c != '2'&& c != '3') std::cout << "POGRESNA OPCIJA!" << std::endl;
	} while (c != '1'&& c != '2'&& c!='3');
	std::cout << "PROMJENE CE BITI IZVRSENE NAKON PONOVNOG POKRETANJA." << std::endl;
		dat.close();
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
	do
	{
		std::cout << "ISPIS NA KONZOLU[1], TEKSTUALNI FAJL[2]: ";
		std::cin >> cha;
		if (cha == '1')
		{
			std::cout << "=============================================" << std::endl;
			std::cout << "||UKUPAN BROJ KORISNICKIH NALOGA JE: " << std::setw(6) << br << "||" << std::endl;
			std::cout << "=============================================" << std::endl;
		}
		else if (cha == '2')
		{
			std::fstream out("BrojNaloga.txt", std::ios::out);
			out << "=============================================" << std::endl;
			out << "||UKUPAN BROJ KORISNICKIH NALOGA JE: " << std::setw(6) << br << "||" << std::endl;
			out << "=============================================" << std::endl;
			std::cout << "=====================================================================" << std::endl;
			std::cout << "||INFORMACIJA KOJA STE TRAZILI JE UPISANA U DATOTEKU BrojNaloga.txt||" << std::endl;
			std::cout << "=====================================================================" << std::endl;
			out.close();
		}

	} while (cha != '1'&&cha != '2');


}
