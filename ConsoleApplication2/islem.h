#pragma once
#include <string>
#include<iostream>
using namespace std;
class Islem
{
public:
	Islem();

	std::string	urunKoduGetir();
	std::string	tcNoGetir();
	std::string	islemKoduGetir();
	void	urunKoduAta(std::string  kod);
	void	tcNoAta(std::string  tcno);
	void	kaydet();
	std::string islemKoduUret();
	void islemleriSil();
	void secilenIslemSil(string silTcno);

private:
	std::string  mIslemKodu;
	std::string	mUrunKodu;
	std::string  mMusteriTcNo;
	std::string  tcno;

};

