#pragma once
#include<string>
#include "Tarih.h"
using namespace std;
class Musteri
{
public:
	Musteri();
	void musteriEkle();
	void musteriSil(string silTcno);
	std::string	tcnoGetir();
	std::string	telnoGetir();
	std::string	isimGetir();
	std::string	soyisimGetir();
	Tarih	tarihGetir();

	void isimAta(std::string isim);
	void telnoAta(std::string telno);
	void tcnoAta(std::string tcno);
	void soyisimAta(std::string soyisim);
	void tarihAta(Tarih tarih);

	std::string	tcnouret();
	std::string	telnoUret();
	std::string donustur();
private:
	std::string mIsim;
	std::string mSoyisim;
	std::string mTcno;
	std::string mTelno;
	Tarih  mDogumTarihi;
	string silTcno;
};
