#pragma once
#include <string>
using namespace std;
class Urun {
public: //Sýnýfa ait verilere rastgele deðer atar 
	Urun();
	void urunEkle();
	void yeniUrunEkle();
	void urunuSil(string silKod);
	void urunSil(string silKod);
	string urunAdiniGetir();
	void urunSil();
	std::string urunAdiGetir();
	std::string urunKodunuGetir();
	std::string fiyatiGetir();
	std::string fiyatiUret();
	void urunAdiniAta(std::string urunAdi);
	void urunKodunuAta(std::string urunkodu);
	void fiyatiAta(string fiyat);
	string urunKodunuUret();

private:
	std::string mUrunKodu;
	std::string  mUrunAdi;
	std::string  mFiyat;
	std::string  fiyat;
};