#pragma once
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
class Korisnik
{
public:
	Korisnik(std::string = "", std::string = "",std::string="");
	virtual ~Korisnik();
	std::string getIme();
	std::string getLozinka();
	std::string getStatus();
	void setStatus(std::string);
	void setIme(std::string);
	void setLozinka(std::string);
	void prijavaNaSistem();
protected:
	std::string kor_ime, lozinka,status;
};

