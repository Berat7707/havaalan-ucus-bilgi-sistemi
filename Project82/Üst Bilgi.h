#ifndef HEADER_H
#define HEADER_H

#include <string>

class Node
{
private:
    int ucus_numarasi;
    int bos_koltuk_sayisi;
    int luks_koltuk;
    int koltuk_kapasitesi;
    int kalkis_saati;
    int kalkis_dakikasi;
    std::string kalkis_yeri;
    std::string varis_yeri;
    float bilet_fiyat;
    float doluluk_orani;
    Node* next;
    float toplam_bilet_tutari;

public:
    // Constructor
    Node();
    int getUcusNumarasi() const;
    void setUcusNumarasi(int numarasi);
    int getBosKoltukSayisi() const;
    void setBosKoltukSayisi(int sayisi);
    int getLukskoltuksayisi() const;
    void setLukskoltuksayisi(int sayi);
    int getKoltukKapasitesi() const;
    void setKoltukKapasitesi(int kapasite);
    int getKalkisSaati() const;
    void setKalkisSaati(int saati);
    int getKalkisDakikasi() const;
    void setKalkisDakikasi(int dakikasi);
    std::string getKalkisYeri() const;
    void setKalkisYeri(const std::string& yeri);
    std::string getVarisYeri() const;
    void setVarisYeri(const std::string& yeri);
    float getBiletFiyat() const;
    void setBiletFiyat(float fiyat);
    float getDolulukOrani() const;
    void setDolulukOrani(float orani);
    Node* getNext() const;
    void setNext(Node* nextNode);
    float getToplamBiletTutari() const;
    void setToplamBiletTutari(float tutari);
};

class FlightList
{
private:


public:
    Node* head;
    // Constructor
    FlightList();

    // Destructor
    ~FlightList();

    // Uçuþ ekleme iþlemi
    void addFlight(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri);

    // Uçuþlarý listeleme iþlemi
  //  void listFlights() const;
    void sil(int ucusNumarasi);
    void guncelle(int ucusnmarasi, int yeniLuksKoltukSayisi);
    void listeleme();
};

#endif
