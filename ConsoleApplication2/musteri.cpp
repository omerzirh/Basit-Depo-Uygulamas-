#include "Musteri.h"
#include"tarih.h"
#include"kontrol.h"
#include <string>
#include <fstream>
#include<cstdlib>
#include<iostream>
#include<iomanip>


using namespace  std;

string isimlerListesi[] = { "Ahmet","Osman","Ali","Mehmet","Veli","Sarp","Emrah","Eser","Erbil","Oguz","Can","Murat","Sinan","Mert","Mete","Sait","Ervah","Cihat","Orhan","Fatih","Ahu","Binnur","Bilge","Candan","Cahide","Demet","Deste","Gizem","Ece","Elanur","Fatma","Fidan","Gamze","Hale","Hilal","Irmak","Jale","Kader","Kamile","Lale" };
string soyisimlerListesi[] = { "KANDEMIR","ORHON","VURAL","YAVUZ","UZ","ERDEM","DEDE","UYANIK","ASLAN","ERKURAN","ER","DAL","KARAKUM","YILMAZ","TAHTACI","KAYA","ERGE","ONUK","TOPAL","BEDER" };

Musteri::Musteri()
{
	int isimIndex = rand() % 40;				//rasgele isim ve soyisim icin indexlere random degerler atadim
	int soyisimIndex = rand() % 20;

	mIsim = isimlerListesi[isimIndex];
	mSoyisim = soyisimlerListesi[soyisimIndex];

	mTcno = tcnouret();
	mTelno = telnoUret();
}
void Musteri::musteriEkle()
{
	Kontrol k1;
	std::fstream kayit;
	kayit.open("Musteriler.txt", std::fstream::in | std::fstream::out | std::fstream::app);			//yeni musteri eklemek icin dosya olusturdum ve dogum tarihiyle beraber olusturdugum dosyanin icine yazdirdim. 
	if (kayit.is_open() == true)
	{
		kayit << isimGetir() << " " << soyisimGetir() << " " << " " << tcnoGetir() << " " << telnoGetir() << " " << tarihGetir().gunGetir() << " " << tarihGetir().ayGetir() << " " << tarihGetir().yilGetir() << endl;
	}
	k1.tavanCiz(25);
	k1.araCiz(25, "EKLENEN MUSTERI");
	k1.ayracCiz(25);
	k1.araCiz(25, "Isim..." + isimGetir());
	k1.araCiz(25, "Soyisim..." + soyisimGetir());
	k1.araCiz(25, "TCno..." + tcnoGetir());
	k1.araCiz(25, "Telno..." + telnoGetir());
	k1.araCizSayi(25, "Dogum tarihi...", tarihGetir().gunGetir(), tarihGetir().ayGetir(), tarihGetir().yilGetir());
	k1.zeminCiz(25);
	kayit.close();
}
void Musteri::musteriSil(string silTcno)
{
	
	fstream kayit;
	fstream sil;

	kayit.open("Musteriler.txt", std::fstream::in);
	sil.open("gecici.txt", std::fstream::in | std::fstream::out | std::fstream::app);
			
	if (kayit.is_open())
	{
		string nisim, nsoyisim, ntcno, ntelno, ngun, nay, nyil;
		while (kayit>>nisim>>nsoyisim>>ntcno>>ntelno>>ngun>>nay>>nyil)
		{
			if (silTcno != ntcno)
			{
				sil << nisim << " " << nsoyisim << " " << ntcno << " " << ntelno << " " << ngun << " " << nay << " " << " " << nyil << endl;
			}
		}
		kayit.close();
		sil.close();
	}
	remove("Musteriler.txt");
	rename("gecici.txt", "Musteriler.txt");

}
string	Musteri::tcnoGetir()
{
	return mTcno;
}
string	Musteri::telnoGetir()
{
	return mTelno;
}
string	Musteri::isimGetir()
{
	return mIsim;
}

string	Musteri::soyisimGetir()
{
	return mSoyisim;
}
Tarih	Musteri::tarihGetir()
{
	return mDogumTarihi;
}

void Musteri::isimAta(std::string isim)
{
	mIsim = isim;
}
void Musteri::telnoAta(string telno)
{
	mTelno = telno;
}
void Musteri::tcnoAta(string tcno)
{
	mTcno = tcno;
}
void Musteri::soyisimAta(string soyisim)
{
	mSoyisim = soyisim;
}
void Musteri::tarihAta(Tarih tarih)
{
	mDogumTarihi = tarih;			
}

string	Musteri::tcnouret()
{
	string tcno = "";

	for (int i = 0; i < 4; i++)
	{
		tcno += '1' + rand() % 9;
	}
	return tcno;
}

std::string	Musteri::telnoUret()
{
	std::string telno = "";
	for (int i = 0; i < 10; i++)
	{
		telno += '0' + rand() % 10;
	}
	return telno;
}

