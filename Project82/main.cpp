#include <iostream>
#include <string>
#include<iomanip>
#include "�st Bilgi.h"
#include"Kalkisyerine_g�re_liseleme.h"
#include"string.h"
#include"ucus_numarsina_g�re_listeleme.h"
using namespace std;

int main() {
	FlightList flightList;
	ucusliste ucuslisteleme;		//ana menu
	ucusvaris variskalkislisteleme;
	ucus_numara numara_ucus;
	setlocale(LC_ALL, "Turkish");//T�rk�e Karakter ��kt�s� ��in 

	cout << setw(70) << "* * * * * * * * * * * * * * * * *" << endl;
	cout << setw(70) << "*                               *" << endl;
	cout << setw(70) << "*                               *" << endl;
	cout << setw(70) << "*    ucuslar 3 e hosgeldiniz    *" << endl;
	cout << setw(70) << "*                               *" << endl;
	cout << setw(70) << "*                               *" << endl;
	cout << setw(70) << "* * * * * * * * * * * * * * * * *" << endl << endl;


	int secim, tercih;
	int ucusNumarasi, bosKoltukSayisi, koltukKapasitesi, kalkisSaati, kalkisDakikasi, luksKoltuk;
	string kalkisYeri, varisYeri;
	float biletFiyat, dolulukOrani;

	while (true)
	{
		system("color 2");
		cout << " _______________________________________________________________________________________" << endl;
		cout << "|                     1 yeni ucus ekleme                                                |" << endl;	//kullan�c�ya secenek sunmak icin yap�lan menu
		cout << "|                     2 luks kltuk say�s� guncelle                                      |" << endl;
		cout << "|                     3 ucus sil                                                        |" << endl;
		cout << "|                     4 ucus listeleme                                                  |" << endl;
		cout << "|                     5 luks olanlar� listele                                           |" << endl;
		cout << "|                     6 var�s yerine gore listele                                       |" << endl;
		cout << "|                     7 kalk�s yerine gore listeleme                                    |" << endl;
		cout << "|                     8 kalk�s ve var�s yer�ne gore listeleme                           |" << endl;
		cout << "|                                                                                       |" << endl;
		cout << "|_______________________________________________________________________________________|" << endl;
		cout << "Secilen islem:";
		cin >> secim;
		switch (secim) {
		case 0:std::cout << "programdan cikis yapiliyor..." << endl;
			std::exit(0);
			break;
		case 1:
			// U�u� bilgilerini kullan�c�dan al
			cout << "Ucus Numarasi:";
			cin >> ucusNumarasi;
			cout << "Bos Koltuk Sayisi:";
			cin >> bosKoltukSayisi;
			cout << "Luks koltuk eklemek istiyorsaniz 1'e basin istemiyorsaniz 2'ye basin:";	//luks koltuk ekleme ucusa
			cin >> tercih;
			if (tercih == 1)
			{
				cout << "Eklemek istediginiz luks koltuk sayisini giriniz:";
				cin >> luksKoltuk;
			}
			else if (tercih == 2) {
				luksKoltuk = 0;
			}
			cout << "Koltuk Kapasitesi:";
			cin >> koltukKapasitesi;				//kullan�c�dan ucusa ait bilgiler alma
			cout << "Kalkis Saati (saat dakika olarak):";
			cin >> kalkisSaati >> kalkisDakikasi;
			cout << "Kalkis Yeri:";
			cin.ignore();
			getline(cin, kalkisYeri);
			cout << "Varis Yeri:";
			getline(cin, varisYeri);

			// U�u�u listeye ekle
			flightList.addFlight(ucusNumarasi, bosKoltukSayisi, luksKoltuk, koltukKapasitesi, kalkisSaati, kalkisDakikasi, kalkisYeri, varisYeri);
			ucuslisteleme.ucusekle(ucusNumarasi, bosKoltukSayisi, luksKoltuk, koltukKapasitesi, kalkisSaati, kalkisDakikasi, kalkisYeri, varisYeri);
			numara_ucus.ucusekleme(ucusNumarasi, bosKoltukSayisi, luksKoltuk, koltukKapasitesi, kalkisSaati, kalkisDakikasi, kalkisYeri, varisYeri);
			variskalkislisteleme.ucusekle1(ucusNumarasi, bosKoltukSayisi, luksKoltuk, koltukKapasitesi, kalkisSaati, kalkisDakikasi, kalkisYeri, varisYeri);// U�u�lar� listele
			break;

		case 2:
			cout << "Luks koltuk sayisini guncellemek istediginiz ucusun kodunu giriniz:";	//luks koltuk sayisini guncelleme
			cin >> ucusNumarasi;
			int yeniLuksKoltukSayisi;
			cout << "Yeni luks koltuk sayisini giriniz:";
			cin >> yeniLuksKoltukSayisi;
			flightList.guncelle(ucusNumarasi, yeniLuksKoltukSayisi);
			ucuslisteleme.guncelleme(ucusNumarasi, yeniLuksKoltukSayisi);
			variskalkislisteleme.guncelleme1(ucusNumarasi, yeniLuksKoltukSayisi);
			numara_ucus.ucusguncelle(ucusNumarasi, yeniLuksKoltukSayisi);
			break;
		case 3:
			cout << "Silmek istediginiz ucusun kodunu giriniz:";
			cin >> ucusNumarasi;									//ucus silme
			numara_ucus.sil(ucusNumarasi);
			ucuslisteleme.ucusSil(ucusNumarasi);
			variskalkislisteleme.ucusSilme(ucusNumarasi);


			break;
		case 4:
			cout << "Bilgilerini gormek istediginiz ucusun numarasini giriniz:";
			cin >> ucusNumarasi;								//ucus listeleme
			numara_ucus.listFlights(ucusNumarasi);

			break;
		case 5:
			cout << "Luks koltuk iceren tum ucuslari listeleme:\n";
			flightList.listeleme();		//Luks koltuk olanlari listeleme

			break;
		case 6:
			cout << "Varis yerine gore listelmek icin lutfen varis yerini giriniz:";
			cin >> varisYeri;
			variskalkislisteleme.varislisteleme(varisYeri);		//varis yerine gore ucuslari listeleme
			break;

		case 7:
			cout << "Kalkis yerine g�re ucus listelemek icin lutfen kalkis yerini giriniz:";
			cin >> kalkisYeri;

			ucuslisteleme.kalkislisteleme(kalkisYeri);		//Kalkis yerine gore ucuslari listeleme
			break;
		case 8:
			cout << "Kalkis ve varis yerine gore listelemek icin kalkis ve varis yeri giriniz:";
			cin >> kalkisYeri >> varisYeri;								//kalkis ve varis yerlerine gore listeleme
			variskalkislisteleme.kalkisvarislisteleme(kalkisYeri, varisYeri);
			break;
		}
	}
	return 0;
}
