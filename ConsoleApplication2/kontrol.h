#pragma once
#include<string>
#include<fstream>
using namespace std;
class Kontrol
{
public:
	void tavanCiz(int genislik);
	void zeminCiz(int genislik);
	void araCiz(int genislik, string yazi);
	void araCizSayi(int genislik, string yazi, int sayi, int sayi1, int sayi2);
	void araCizSayi(int genislik, int sayi);
	void ayracCiz(int genislik);
	void anaMenuCiz();
	void musteriListele();

	void islemListele(string mtcno);

	void islemListele();
	
	void yoneticiMenuCiz();
	void ekranaCikar();
	void musteriPaneli();
	void urunListesi();
	void eklenenMusteri();
	void yoneticiPanelCiz();
	/*
	* istenilen fonksiyonlar eklenebilir.
	*/
};
