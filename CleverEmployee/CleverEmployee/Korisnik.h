#pragma once
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
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
	void prijavaNaSistem();//nije rijesen
protected:
	std::string kor_ime, lozinka,status;
};

