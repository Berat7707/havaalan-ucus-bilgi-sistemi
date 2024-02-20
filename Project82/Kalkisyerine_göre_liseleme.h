#ifndef kalkis_H
#define kalkis_H
#include <string>


class kalkis
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
    kalkis* next;
    kalkis* prev;
    float toplam_bilet_tutari;

public:
    // Constructor
    kalkis();
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
    kalkis* getNext() const;
    void setNext(kalkis* nextNode);
    float getToplamBiletTutari() const;
    void setToplamBiletTutari(float tutari);
    kalkis* getPrev() const; // Önceki düðümü döndüren fonksiyon
    void setPrev(kalkis* prevNode); // Önceki düðümü ayarlayan fonksiyon
};

class ucusliste
{
private:


public:
    kalkis* head;
    // Constructor
    ucusliste();

    // Destructor
    ~ucusliste();

    // Uçuþ ekleme iþlemi
    void ucusekle(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri);
    void kalkislisteleme(const std::string& kalkisYeri)const;
    void ucusSil(int ucusnumara);
    void guncelleme(int ucusnumara, int yeniLuksKoltukSayisi);


    // Uçuþlarý listeleme iþlemi

};

#endif
