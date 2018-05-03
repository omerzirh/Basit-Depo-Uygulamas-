#include "Kontrol.h"
#include"musteri.h"
#include"urun.h"
#include"islem.h"
#include<fstream>
#include <iostream>
#include<string>
#include<iomanip>
#include<Windows.h>
using namespace std;
char DUZCIZGI = 205;
char SOLUSTKOSE = 201;
char SAGUSTKOSE = 187;
char DIKEYCIZGI = 186;
char ASAGIAYRAC = 203;
char SOLALTKOSE = 200;
char SAGALTKOSE = 188;
char YUKARIAYRAC = 202;
char YATAYSAGAAYRAC = 204; //
char YATAYSOLAAYRAC = 185;
enum RENKLER
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};
void renkAta(int yazirenk)
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + yazirenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}
void karakterCikar(RENKLER renk)
{
	renkAta(renk);
	renkAta(WHITE);
}


void Kontrol::tavanCiz(int genislik)
{
	cout << SOLUSTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGUSTKOSE;

	cout << endl;

}

void Kontrol::zeminCiz(int genislik)
{
	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;
}
void Kontrol::araCiz(int genislik, string yazi)
{
	cout << DIKEYCIZGI;

	cout << std::left << setw(genislik) << yazi;

	cout << DIKEYCIZGI;
	cout << endl;
}
void Kontrol::araCizSayi(int genislik, string yazi,int sayi,int sayi1,int sayi2)
{
	cout << DIKEYCIZGI;

	cout << std::left << yazi << sayi << "/" << sayi1 << "/" << sayi2 << " ";

	cout << DIKEYCIZGI;
	cout << endl;
}

void Kontrol::ayracCiz(int genislik)
{
	cout << YATAYSAGAAYRAC;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << YATAYSOLAAYRAC;

	cout << endl;
}

void Kontrol::anaMenuCiz()
{
	tavanCiz(25);
	araCiz(25, "ANA KONTROL PANELI");	//hazir fonksiyonlarla ana panel cizilmistir.
	ayracCiz(25);
	araCiz(25, "1.Musteri paneli");
	ayracCiz(25);
	araCiz(25, "2.Yonetici Paneli");
	ayracCiz(25);
	araCiz(25, "3.Cikis");
	zeminCiz(25);


}
void Kontrol::musteriListele()
{
	std::fstream muslis;
	muslis.open("Musteriler.txt", std::fstream::in);

	if (muslis.is_open())
	{
		string isim, soyisim, telno, tcno;			//dogum tarihi ve diger bilgiler icin ayri degiskenler turetilmistir.
		int gun, ay, yil;					//bu degiskenler dosya icindeki degerler okunarak ekrana yazdirilmistir
		tavanCiz(47);
		araCiz(47, "MUSTERILER LISTESI");
		ayracCiz(47);
		while (muslis >> isim >> soyisim >> tcno >> telno >> gun >> ay >> yil)
		{
			int genislik =20 - (isim.length() + soyisim.length());		//farkli degerlere gore dikeycizgiyi duzensiz olarak  koydu. belli bi noktaya koymasi icin ugrastim ancak elimden bu kadar geldi.
			cout << DIKEYCIZGI;
			cout<< isim << " " << soyisim << " " << tcno << " " << telno << " " << gun << " " << ay << " " << yil<<setw(genislik);
			cout<< right<<DIKEYCIZGI << endl;
			ayracCiz(47);
		}
		araCiz(47, "LISTE SONU");
		zeminCiz(47);
	}
}
void Kontrol::islemListele(string mtcno)
{
	
	fstream islemlist;
	islemlist.open("islemler.txt", ios::in);
	if(islemlist.is_open())
	{
		int tcno, urunKodu, islemkodu;
		while(islemlist >> tcno >> urunKodu >> islemkodu)
		{
			cout << tcno << " " << urunKodu << " " << islemkodu << endl;
		}
		
	}
}
void Kontrol::musteriPaneli()
{
	tavanCiz(25);
	cout << DIKEYCIZGI;
	cout << "MUSTERI PANELI";
	cout << right<<setw(12) << DIKEYCIZGI << endl;
	ayracCiz(25);
	cout << DIKEYCIZGI << "1.Urun Al" <<right<<setw(17) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "2.Islemleri Listele" << setw(7) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "3.Islem Sil" << setw(15) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "4.Geri" << setw(20) << DIKEYCIZGI << endl;
	zeminCiz(25);
}
void Kontrol::urunListesi()
{
	std::fstream islemlist;
	islemlist.open("Urunler.txt", std::fstream::in);

	if (islemlist.is_open())
	{
		string urunAdi, urunKodu, fiyat;

		tavanCiz(25);
		cout << DIKEYCIZGI;
		cout << "URUNLER LISTESI";		//urunler icin farkli degiskenler atayarak urunleri cikarmasini istedim.
		cout << right << setw(11) << DIKEYCIZGI << endl;
		ayracCiz(25);
		while (islemlist >> urunAdi >> urunKodu >> fiyat)
		{

			cout << DIKEYCIZGI;
			cout << " " << urunAdi << " " << urunKodu << " " << fiyat;
			cout <<right<<setw(7) << DIKEYCIZGI << endl;
			zeminCiz(25);
		}

	}
}
void Kontrol::yoneticiPanelCiz()
{
	tavanCiz(25);
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "YONETICI PANELI" << right<<setw(11) << DIKEYCIZGI << endl;
	ayracCiz(25);
	karakterCikar(WHITE);
	cout << DIKEYCIZGI << "1.Musteri Ekle" << right << setw(12) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "2.Musteri Listele" << right << setw(9) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "3.Musteri Sil" << right << setw(13) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "4.Urun Ekle" << right << setw(15) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "5.Urunleri Listele" << right << setw(8) << DIKEYCIZGI << endl;
	cout << DIKEYCIZGI << "6.Urun Sil " << right << setw(15) << DIKEYCIZGI << endl;
	zeminCiz(25);
}



