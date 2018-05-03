#include "Urun.h"
#include <string>
#include <fstream>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;
string urunListesi[] = { "Ekran_karti","Ses_Karti","Islemci","Klavye","Fare","Monitor","Ram","Sabit_Disk","Hoparlor","SSD_Disk","Notebook","Kasa","Flash_Disk","Tablet","Cep_Telefonu","Kulaklik","Yazici","Scanner","Optik_Okuyucu","Tv_Karti" };


Urun::Urun()
{
	srand(time(0));
	int urunRandom = rand() % 20;
	mUrunAdi = urunListesi[urunRandom];		//farkli urun gelmesi icin urunRandom deðiskenine rando deger atadim
	mUrunKodu = urunKodunuUret();
	mFiyat = fiyatiUret();
}

void Urun::yeniUrunEkle()
{
	std::fstream urunadd;

	urunadd.open("Urunler.txt",std::fstream::in|std::fstream::out|std::fstream::app);		//musteri ekle deki kod kopyalanip degiskenleri degistirilmistir.

	if (urunadd.is_open() == true)
	{
		urunadd << urunAdiniGetir() << " "<< urunKodunuGetir() << " "<<fiyatiGetir()<<" " << endl;
	}
	cout << "Urun adi..." << urunAdiniGetir() << endl;
	cout << "Urun Kodu..." <<urunKodunuGetir() << endl;
	cout << "Fiyat..." << fiyatiGetir() << endl;

	urunadd.close();

}
void Urun::urunuSil(string silKod)		
{
	fstream oku;
	fstream sil;

	oku.open("Urunler.txt", std::fstream::in);						//istedigimiz urunu silmek icin fonksiyon olusturdum fonksiyon da eski metin dosyasindaki degerler okunuyor,tcno degerini aldigimiz satir haric yenigecici dosyaya yaziliyor.
	sil.open("gecici.txt", std::fstream::in | std::fstream::out | std::fstream::app);//sonucta eski dosya silinip yeni dosyanin adi eski dosyanin adi ile degistriliyor.

	if (oku.is_open())
	{
		string urunAdi, urunKodu, urunFiyat;
		while (oku >>urunAdi>>urunKodu>>urunFiyat)
		{
			if (silKod != urunKodu)
			{
				sil << urunAdi << " " << urunKodu << " " << urunFiyat << endl;
			}
		}
		oku.close();
		sil.close();
	}
	remove("Urunler.txt");
	rename("gecici.txt", "Urunler.txt");
}

string Urun::urunAdiniGetir()
{
	return mUrunAdi;
}

string Urun::urunKodunuGetir()
{
	return mUrunKodu;
}
string Urun::fiyatiGetir()
{
	return mFiyat;
}
void Urun::urunAdiniAta(string urunAdi)
{
	mUrunAdi = urunAdi;
}
void Urun::urunKodunuAta(string urunKodu)
{
	mUrunKodu = urunKodu;
}
void Urun::fiyatiAta(string fiyat)
{
	mFiyat = fiyat;
}

string Urun::urunKodunuUret()
{
	string urunKodu = "";
	for (int i = 0; i < 4; i++)
	{
		urunKodu += '1' + rand() % 9;
	}
	return urunKodu;
}
string Urun::fiyatiUret()
{
	string fiyat = "";
	for (int i = 0; i < 4; i++)
	{
		fiyat += '1' + rand() % 9;
	}
	return fiyat;
}
