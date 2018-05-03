	/***************************************************************************
**                         SAKARYA UNIVERSITESI
**                 BILGISAYAR VE BILISIM BILIMLERI FAKULTESI
**                   BILGISAYAR MUHENDISLIGI BOLUMU
**                     PROGRAMLAMAYA GIRISI DERSI
**
**               OGRENCI ADI......: OMER ZIRH
**               OGRENCI NUMARASI.: B161210116
**               DERS GRUBU.......: C
****************************************************************************/
#include"musteri.h"
#include"kontrol.h"
#include"urun.h"
#include"islem.h"
#include "Source.h"
#include <iostream>

using namespace std;

int main()
{
	int secim, secim1,secim3;
	string kod, tcno;
	Musteri must;
	Kontrol kont;		//her siniftan birer nesne olusturuldu.
	Islem i1;
	Urun u1;

	while (true) //dongu true oldukca donuyor.
	{
		kont.anaMenuCiz();
		cin >> secim;
		if (secim == 1)
		{
			kont.musteriListele();
			cout << "tcno gir..." << endl;		//eger secim 1 olursa musteri listeleniyor.ve islem yapmak istenilen tcno isteniliyor.
			cin >> tcno;
			i1.tcNoAta(tcno);
			kont.musteriPaneli();		//musteri paneli cikiyor ve burada yapmak istedigimiz islem soruluyor
			cin >> secim1;
			if (secim1 == 1)
			{
				kont.urunListesi();
				cout << "urun kodu gir...";		//eger secim 1 olursa tcno sunu yazdigimiz musteriye bir urun aliniyor.ve bu islem, islemler dosyasina kaydediliyor.
				cin >> kod;
				cout << endl;
				i1.urunKoduAta(kod);
				i1.kaydet();
			}
			else if (secim1 == 2)
				kont.islemListele(tcno);	//eger secim 2 olursa yapilan islemler listeleniyor.
			else if (secim1 == 3)
			{

				i1.islemleriSil();	//eger 3 olursa (normalde tcnosu yazilan islemler silinmesi gerekiyordu kodu yazdim,hersey dogru gozukuyordu lakin bulamadigim hatadan dolayi calistiramadim)
			}						//butun islemler siliniyor.
		}
		else if (secim == 2)
		{
			kont.yoneticiPanelCiz();		//ilk bolumdeki secim 2 olursa yonetici paneline giriliyor 
			cout << "Secim...";
			cin >> secim3;				//tekrar secim yapmasi isteniyor secim =1 olursa musteri ekleniyor
			if (secim3 == 1)
				must.musteriEkle();
			else if (secim3 == 2)	//2 olursa musteriler listeleniyor
				kont.musteriListele();
			else if (secim3 == 3)
			{
				string silTcno;		//3 olursa tcnosu girilen musteri siliniyor.
				kont.musteriListele();
				cout << "Tcno....";
				cin >> silTcno;
				must.musteriSil(silTcno);

			}
			else if (secim3 == 4)  //4 olursa urun ekleniyor
				u1.yeniUrunEkle();
			else if (secim3 == 5)
				kont.urunListesi(); // 5 olursa urunler listeleniyor
			else if (secim3 == 6)
			{
				string silKod;
				kont.urunListesi(); //6 olursa urun kodunu yazdigimiz urun siliniyor
				cout << "urun kodu...";
				cin >> silKod;
				u1.urunuSil(silKod);

			}
		}
		else if (secim == 3) //eger ilk secim 3 olursa programa son veriliyor
			break;

	}


	
	
	return 0;
}


