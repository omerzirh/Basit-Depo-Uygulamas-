#pragma once

#include<string>
#include "Tarih.h"
using namespace std;
class Tarih

{
public:
	Tarih();
	int  tarihGetir();
	int  gunGetir();
	int  ayGetir()
	{
		return xAy;
	}
	int  yilGetir();
	int ayUret();
	int yilUret();
	int gunUret();

	
	void ayAta(int ay);
	void yilAta(int yil);
	void gunAta(int gun);


private:
	int xGun;
	int xAy;
	int xYil;
	int gun, ay, yil;
};

