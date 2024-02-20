#ifndef varis_H
#define varis_H
#include <string>


class kalkisvaris
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
    kalkisvaris* next;
    kalkisvaris* prev;
    float toplam_bilet_tutari;

public:
    // Constructor
    kalkisvaris();
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
    kalkisvaris* getNext() const;
    void setNext(kalkisvaris* nextNode);
    float getToplamBiletTutari() const;
    void setToplamBiletTutari(float tutari);
    kalkisvaris* getPrev() const; // Önceki düðümü döndüren fonksiyon
    void setPrev(kalkisvaris* prevNode); // Önceki düðümü ayarlayan fonksiyon
};

class ucusvaris
{
private:


public:
    kalkisvaris* head;
    // Constructor
    ucusvaris();

    // Destructor
    ~ucusvaris();

    // Uçuþ ekleme iþlemi
    void ucusekle1(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri);
    void varislisteleme(const std::string& varisYeri)const;
    void kalkisvarislisteleme(const std::string& kalkisYeri, const std::string& varisYeri)const;
    void ucusSilme(int ucusnumara);
    void guncelleme1(int ucusnumara, int yeniLuksKoltukSayisi);

    // Uçuþlarý listeleme iþlemi

};

#endif
