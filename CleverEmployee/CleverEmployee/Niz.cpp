#include "Niz.h"

Niz::Niz()
{}


Niz::~Niz()
{}

void Niz::ucitajDatoteku()
{
	Artikal a;
	ifstream dat("Artikli.txt");
	if (dat)
	{
		while (!dat.eof())
		{
			dat >> a.sifra >> a.naziv >> a.opis >> a.cijena >> a.kolicina;
			if (a.getSifra() == -1)
				break;
			niz.push_back(a);
		}
		dat.close();
	}
}

void Niz::pisiDatoteku()
{
	ofstream dat("Artikli.txt");
	for (int i = 0; i < niz.size(); i++)
		dat << niz[i].sifra << " " << niz[i].naziv << " " << niz[i].opis << " " << niz[i].cijena << " " << niz[i].kolicina << std::endl;
	dat << -1;
	dat.close();
}

bool Niz::dodajArtikal()
{
	bool flag = true;
	do
	{
		Artikal art;
		std::cin >> art;
		int i;
		for (i = 0; i < niz.size(); i++)
			if (niz[i].getSifra() == art.sifra)
				break;
		if (i == niz.size())
		{
			niz.push_back(art);
			flag = false;
		}
		else
			std::cout << "UNESENA SIFRA VEC POSTOJI , PROBAJTE PONOVO!" << std::endl;
	} while (flag);
	std::cout << "=============================================" << std::endl;
	std::cout << "||PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "=============================================" << std::endl;
	return !flag;
}

bool Niz::brisiArtikal()
{
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~BRISANJE   ARTIKLA~~~~~~~~~~~~~~~~~~" << std::endl;
	int sifra;
	do
	{
	std::cout << "Sifra: "; std::cin >> sifra;
	} while (sifra < 1 || sifra >999999);
	int i;
	Artikal a;
	for (i = 0; i < niz.size(); i++)
		if (niz[i].getSifra() == sifra)
		{
			a = niz[i];
			niz.erase(niz.begin() + i, niz.begin() + i + 1);
			break;
		}
	if (a.sifra == sifra)
	{
		std::cout << "ARTIKAL USPJESNO OBRISAN!" << std::endl;
		ispisi_heder();
		std::cout << a;
		ispisi_footer();
	}
	else 
		std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "=============================================" << std::endl;
	return true;
}

void Niz::traziPoSifri()
{
	std::cout << "~~~~~~~~~~ P R E T R A G A ~~~~~~~~" << std::endl;
	std::cout << "~~~~~~~~~~ P O   S I F R I ~~~~~~~~" << std::endl;
	int sifra;
	do
	{
		std::cout << "\tSifra: "; std::cin >> sifra;
	} while (sifra < 1 || sifra >999999);
	Artikal a;
	for (int i = 0; i < niz.size(); i++)
		if (niz[i].getSifra() == sifra)
		{
			a = niz[i];
			break;
		}
	if (a.getSifra() == sifra)
	{
		std::cout << "ARTIKAL JE PRONADJEN: " << std::endl;
		ispisi_heder();
		std::cout << a;
		ispisi_footer();
	}
	else
	{
		std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "||PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Niz::traziPoNazivu()
{
	std::cout << "~~~~~~~~~~ P R E T R A G A ~~~~~~~~" << std::endl;
	std::cout << "~~~~~~~~~ P O   N A Z I V U  ~~~~~~~" << std::endl;
	std::string naziv;
	do
	{
		std::cout << "\tNaziv: "; std::cin >> naziv;
	} while (naziv.length() < 3);
	Artikal a;
	for (int i = 0; i < niz.size();i++)
		if (niz[i].getNaziv() == naziv)
		{
			a = niz[i];
			break;
		}
	if (a.getNaziv() == naziv)
	{
		std::cout << "ARTIKAL JE PRONADJEN: " << std::endl;
		ispisi_heder();
		std::cout << a;
		ispisi_footer();
	}
	else std::cout << "NIJE PRONADJEN TRAZENI ARTIKAL!" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "||PRITISNITE BILO KOJI TASTER DA NASTAVITE.||" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void Niz::print()
{
	ispisi_heder();
	for (int i = 0; i < niz.size(); i++)
		std::cout << niz[i];
	ispisi_footer();
}

void Niz::ispisi_heder()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "~SIFRA~ ~~~~~NAZIV~~~~~ ~~~~~OPIS~~~~~~ ~KOLICINA~ ~CIJENA~" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Niz::ispisi_footer()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

