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


void Administrator::izmjenaNaloga()
{
	std::ifstream dat("Korisnici.txt");
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

	std::fstream dat1("Korisnici.txt",ios::in|ios::out);
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
			dat1.seekp(lokacija-duzina,ios::beg);
			cout << lokacija <<"    "<< duzina<<endl;
			dat1 << novi1 << " " << pom2 << " " << pom3 << endl;
		}
	} while (c!='1' && c!='2');
	dat1.close();

}

void Administrator::podesavanjeBoje()
{
	std::cout << "=====~~~~~~~~~~~~~~=====" << std::endl << "     BOJA POZADINE: " << std::endl << "=====~~~~~~~~~~~~~~=====" << std::endl;
	std::cout << "0 = CRNA" << std::endl
		<< "1 = PLAVA" << std::endl
		<< "2 = ZELENA" << std::endl
		<< "3 = CRVENA" << std::endl
		<< "4 = LJUBICASTA" << std::endl
		<< "5 = ZUTA" << std::endl
		<< "6 = BIJELA" << std::endl
		<< "7 = SIVA" << std::endl;
	int boja;
	std::cin >> boja;
	while (boja < 0 || boja >7)
	{
		std::cout << "Pogresan unos!" << std::endl;
		std::cout << "Unesite boju ponovo: ";
		std::cin >> boja;
	}
	switch (boja)
	{
	case 0: {system("color 0F"); break; };//crna pozadina,bijela slova
	case 1: {system("color 10"); break; }//plava pozadina,crna slova
	case 2: { system("color 20"); break; };//zelena pozadina,crna slova
	case 3: { system("color 40"); break; };//crvena pozadina,crna slova
	case 4: { system("color 5F"); break; };//ljubicasta pozadina,bijela slova
	case 5: { system("color E0"); break; };//zuta pozadina,crna slova
	case 6: { system("color 70"); break; };//bijela pozadine,crna slova
	case 7: { system("color 8C"); break; };//siva pozadina,crvena slova
	}
	std::cout << "Boja uspjesno promjenjena" << std::endl;
}
