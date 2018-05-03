#pragma once
#include<string>
#include "Tarih.h"
#include<cstdlib>
#include<time.h>
using namespace std;

Tarih::Tarih()
{
	srand(time(0));
	xGun = 1 + rand() % 30;
	xAy = 1 + rand() % 12;
	xYil = 1900 + rand() % 116;


}
int Tarih::tarihGetir()
{
	return 0;
}
int Tarih::gunGetir()
{
	return xGun;
}
int Tarih::yilGetir()
{
	return xYil;
}
void Tarih::gunAta(int gun)
{
	xGun = gun;
}
void Tarih::yilAta(int yil)
{
	xYil = yil;
}
void Tarih::ayAta(int gun)
{
	xAy = ay;
}


int gunUret()
{
	int xGun = 1 + rand() % 30;

	return xGun;
}
int	Tarih::ayUret()
{
	int xAy=1 + rand() % 12;
	return xAy;
}
int Tarih::yilUret()
{
	int xYil=1900 + rand() % 117;
	return xYil;
}


