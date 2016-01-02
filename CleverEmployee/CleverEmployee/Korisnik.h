#pragma once
#include <string>
#include <algorithm>
class Korisnik
{
public:
	Korisnik(std::string = "", std::string = "");
	virtual ~Korisnik();
	std::string getIme();
	std::string getLozinka();
	std::string getStatus();
	void setStatus(std::string);
	void setIme(std::string);
	void setLozinka(std::string);
	bool prijavaNaSistem();//nije rijesen
protected:
	std::string kor_ime, lozinka,status;
};

