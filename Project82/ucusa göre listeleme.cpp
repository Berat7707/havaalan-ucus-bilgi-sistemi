#include <iostream>
#include<iomanip>
#include "ucus_numarsina_g�re_listeleme.h"
#include"�st Bilgi.h"
using namespace std;

// Node s�n�f� i�in constructor
numara::numara()
{
    next = nullptr;
}

// Node s�n�f� i�in getter ve setter fonksiyonlar�
int numara::getUcusNumarasi() const
{
    return ucus_numarasi;
}

void numara::setUcusNumarasi(int numarasi)
{
    ucus_numarasi = numarasi;
}
int numara::getBosKoltukSayisi() const
{
    return bos_koltuk_sayisi;
}

void numara::setBosKoltukSayisi(int sayisi)
{
    bos_koltuk_sayisi = sayisi;
}
int numara::getLukskoltuksayisi()const
{
    return luks_koltuk;
}
void numara::setLukskoltuksayisi(int sayi) {
    luks_koltuk = sayi;
}
int numara::getKoltukKapasitesi() const
{
    return koltuk_kapasitesi;
}

void numara::setKoltukKapasitesi(int kapasite)
{
    koltuk_kapasitesi = kapasite;
}

int numara::getKalkisSaati() const
{
    return kalkis_saati;
}

void numara::setKalkisSaati(int saati)
{
    kalkis_saati = saati;
}

int numara::getKalkisDakikasi() const
{
    return kalkis_dakikasi;
}

void numara::setKalkisDakikasi(int dakikasi)
{
    kalkis_dakikasi = dakikasi;
}

std::string numara::getKalkisYeri() const
{
    return kalkis_yeri;
}

void numara::setKalkisYeri(const std::string& yeri)
{
    kalkis_yeri = yeri;
}

std::string numara::getVarisYeri() const
{
    return varis_yeri;
}

void numara::setVarisYeri(const std::string& yeri)
{
    varis_yeri = yeri;
}

float numara::getBiletFiyat() const
{
    return bilet_fiyat;
}

void numara::setBiletFiyat(float fiyat)
{
    bilet_fiyat = fiyat;
}

float numara::getDolulukOrani() const
{
    return doluluk_orani;
}

void numara::setDolulukOrani(float orani)
{
    doluluk_orani = orani;
}

numara* numara::getNext() const
{
    return next;
}

void numara::setNext(numara* nextNode)
{
    next = nextNode;
}

float numara::getToplamBiletTutari() const
{
    return toplam_bilet_tutari;
}

void numara::setToplamBiletTutari(float tutari)
{
    toplam_bilet_tutari = tutari;
}

ucus_numara::ucus_numara()
{
    head = nullptr;
}

ucus_numara::~ucus_numara()
{
    numara* current = head;
    while (current != nullptr)
    {
        numara* next = current->getNext();
        delete current;
        current = next;
    }
}
void ucus_numara::ucusekleme(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri)
{
    system("cls");

    numara* current = head;
    while (current != nullptr)
    {
        if (current->getUcusNumarasi() == ucusNumarasi)
        {
            cout << "Ucus numarasi zaten mevcut. Yeni ucus eklenmedi." << endl;
            return;
        }
        current = current->getNext();
    }


    numara* newNode = new numara();
    newNode->setUcusNumarasi(ucusNumarasi);
    newNode->setBosKoltukSayisi(bosKoltukSayisi);
    newNode->setLukskoltuksayisi(luks_koltuk);
    newNode->setKoltukKapasitesi(koltukKapasitesi);
    newNode->setKalkisSaati(kalkisSaati);
    newNode->setKalkisDakikasi(kalkisDakikasi);
    newNode->setKalkisYeri(kalkisYeri);
    newNode->setVarisYeri(varisYeri);

    if (head == nullptr || ucusNumarasi < head->getUcusNumarasi())
    {
        newNode->setNext(head);
        head = newNode;
    }
    else
    {
        numara* current = head;
        while (current->getNext() != nullptr && current->getNext()->getUcusNumarasi() < ucusNumarasi)
        {
            current = current->getNext();
        }

        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
}
void ucus_numara::sil(int ucus_numarasi)
{
    system("cls");          //ucus silme
    numara* current = head;
    numara* prev = nullptr;


    while (current != nullptr && current->getUcusNumarasi() != ucus_numarasi) {
        prev = current;
        current = current->getNext();
    }

    if (current == nullptr) {
        cout << "U�u� numaras�na sahip kay�t bulunamad�." << endl;
        return;
    }


    if (prev == nullptr) {

        head = current->getNext();
    }
    else {
        prev->setNext(current->getNext());
    }


    delete current;
}
void ucus_numara::ucusguncelle(int ucus_numarasi, int yeniLuksKoltukSayisi)     //ucus guncelleme
{
    system("cls");
    numara* current = head;
    while (current != nullptr && current->getUcusNumarasi() != ucus_numarasi) {
        current = current->getNext();
    }
    if (current == nullptr) {
        cout << "U�u� numaras�na sahip kay�t bulunamad�." << endl;
        return;
    }
    else {
        current->setLukskoltuksayisi(yeniLuksKoltukSayisi);
    }
}
std::ostream& operator<<(std::ostream& os, const numara& ucus)      //ucus listeleme
{
    os << "ucus no     kalkis yeri     varis yeri     zamani     koltuk kapasitesi     bos koltuk sayisi      Luks Koltuk" << endl;
    os << "-------     -----------     ----------     ------     -----------------     -----------------     -------------" << endl;
    os << ucus.getUcusNumarasi() << setw(15);
    os << ucus.getKalkisYeri() << setw(16);
    os << ucus.getVarisYeri() << setw(12);
    os << ucus.getKalkisSaati() << ":" << ucus.getKalkisDakikasi() << setw(15);
    os << ucus.getKoltukKapasitesi() << setw(21);
    os << ucus.getBosKoltukSayisi() << setw(19);
    os << ucus.getLukskoltuksayisi() << setw(15) << endl;

    return os;
}

void ucus_numara::listFlights(int ucusNumarasi) const
{
    system("cls");          //ucus listeleme
    numara* current = head;
    bool found = false;
    while (current != NULL)
    {
        if (current->getUcusNumarasi() == ucusNumarasi)
        {
            found = true;
            std::cout << *current; // U�u� bilgilerini yazd�r
        }

        current = current->getNext();
    }

    if (!found)
    {
        std::cout << "Belirtilen ucus numarasina ait ucus bulunamadi." << std::endl;
    }
}

