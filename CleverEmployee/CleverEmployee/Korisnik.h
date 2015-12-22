#pragma once
#include <string>
class Korisnik
{
public:
	Korisnik();
	virtual ~Korisnik();
	bool prijavaNaSistem();
protected:
	std::string kor_ime, lozinka;
	


};

