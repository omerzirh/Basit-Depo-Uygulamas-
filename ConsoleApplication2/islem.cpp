#include"islem.h"
#include"musteri.h"	
#include"urun.h"	
#include<fstream>
#include<iostream>
#include<string>
#include<ctime>

using namespace std;
 
Islem::Islem()
{
	srand(time(0));
	mIslemKodu = islemKoduUret();

}
void Islem::kaydet()
{
	std::fstream ýslemKaydet;

	ýslemKaydet.open("Islemler.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	if (ýslemKaydet.is_open() == true)
	{
		ýslemKaydet << tcNoGetir() << " " << urunKoduGetir() << " " << islemKoduGetir() << endl;
	}

	ýslemKaydet.close();
}
void Islem::islemleriSil()
{
	std::fstream islemSil;

	islemSil.open("Islemler.txt", std::fstream::out);

	if (islemSil.is_open() == true)
	{
		islemSil << endl;
	}

	islemSil.close();

}
void Islem::secilenIslemSil(string silTcno)
{
	fstream oku;
	fstream sil;

	oku.open("Islemler.txt", std::fstream::in);
	sil.open("gecici.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	if (oku.is_open())
	{
		string tcno, urunKodu, islemkodu;
		while (oku >> tcno >> urunKodu >> islemkodu)
		{
			if (silTcno != urunKodu)
			{
				sil << tcno << " " << urunKodu << " " << islemkodu << endl;
			}
		}
		oku.close();
		sil.close();
	}
	remove("Islemler.txt");
	rename("gecici.txt", "Islemler.txt");
}
std::string  Islem::urunKoduGetir()
{
	return mUrunKodu;
}
void Islem::urunKoduAta(std::string  kod)
{
	mUrunKodu = kod;
}
std::string Islem::tcNoGetir()
{
	return mMusteriTcNo;

}
void  Islem::tcNoAta(std::string tcno)
{
	
	mMusteriTcNo = tcno;
}
std::string Islem::islemKoduGetir()
{
	return mIslemKodu;
}
std::string Islem::islemKoduUret()
{
	string mIslemKodu = "";

	for (int i = 0; i < 4; i++)
	{
		mIslemKodu += '1' + rand() % 9;
	}
	return mIslemKodu;
}
