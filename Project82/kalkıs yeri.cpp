#include <iostream>
#include <algorithm> // std::toupper veya std::tolower için
#include <cctype>    // std::toupper veya std::tolower içi
#include "Kalkisyerine_göre_liseleme.h"
#include<iomanip>
using namespace std;
kalkis::kalkis()
{
    next = nullptr;
}

// Node sýnýfý için getter ve setter fonksiyonlarý
int kalkis::getUcusNumarasi() const
{
    return ucus_numarasi;
}

void kalkis::setUcusNumarasi(int numarasi)
{
    ucus_numarasi = numarasi;
}
int kalkis::getBosKoltukSayisi() const
{
    return bos_koltuk_sayisi;
}

void kalkis::setBosKoltukSayisi(int sayisi)
{
    bos_koltuk_sayisi = sayisi;
}
int kalkis::getLukskoltuksayisi()const
{
    return luks_koltuk;
}
void kalkis::setLukskoltuksayisi(int sayi) {
    luks_koltuk = sayi;
}
int kalkis::getKoltukKapasitesi() const
{
    return koltuk_kapasitesi;
}

void kalkis::setKoltukKapasitesi(int kapasite)
{
    koltuk_kapasitesi = kapasite;
}

int kalkis::getKalkisSaati() const
{
    return kalkis_saati;
}

void kalkis::setKalkisSaati(int saati)
{
    kalkis_saati = saati;
}

int kalkis::getKalkisDakikasi() const
{
    return kalkis_dakikasi;
}

void kalkis::setKalkisDakikasi(int dakikasi)
{
    kalkis_dakikasi = dakikasi;
}

std::string kalkis::getKalkisYeri() const
{
    return kalkis_yeri;
}

void kalkis::setKalkisYeri(const std::string& yeri)
{
    kalkis_yeri = yeri;
}

std::string kalkis::getVarisYeri() const
{
    return varis_yeri;
}

void kalkis::setVarisYeri(const std::string& yeri)
{
    varis_yeri = yeri;
}

float kalkis::getBiletFiyat() const
{
    return bilet_fiyat;
}

void kalkis::setBiletFiyat(float fiyat)
{
    bilet_fiyat = fiyat;
}

float kalkis::getDolulukOrani() const
{
    return doluluk_orani;
}

void kalkis::setDolulukOrani(float orani)
{
    doluluk_orani = orani;
}

kalkis* kalkis::getNext() const
{
    return next;
}

void kalkis::setNext(kalkis* nextNode)
{
    next = nextNode;
}

float kalkis::getToplamBiletTutari() const
{
    return toplam_bilet_tutari;
}

void kalkis::setToplamBiletTutari(float tutari)
{
    toplam_bilet_tutari = tutari;
}
void kalkis::setPrev(kalkis* prevNode)
{
    prev = prevNode;
}
ucusliste::ucusliste()
{
    head = nullptr;
}


ucusliste::~ucusliste()
{
    kalkis* current = head;
    while (current != nullptr)
    {
        kalkis* next = current->getNext();
        delete current;
        current = next;
    }
}


void ucusliste::ucusekle(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri)
{
    system("cls");
    kalkis* newNode = new kalkis();
    newNode->setUcusNumarasi(ucusNumarasi);
    newNode->setBosKoltukSayisi(bosKoltukSayisi);
    newNode->setLukskoltuksayisi(luks_koltuk);
    newNode->setKoltukKapasitesi(koltukKapasitesi);
    newNode->setKalkisSaati(kalkisSaati);
    newNode->setKalkisDakikasi(kalkisDakikasi);
    newNode->setKalkisYeri(kalkisYeri);
    newNode->setVarisYeri(varisYeri);

    if (head == nullptr || kalkisYeri < head->getKalkisYeri() || (kalkisYeri == head->getKalkisYeri() && kalkisSaati < head->getKalkisSaati()))
    {
        newNode->setNext(head);
        newNode->setPrev(nullptr);
        if (head != nullptr)
            head->setPrev(newNode);
        head = newNode;
    }
    else
    {
        kalkis* current = head;
        while (current->getNext() != nullptr && (kalkisYeri > current->getNext()->getKalkisYeri() || (kalkisYeri == current->getNext()->getKalkisYeri() && kalkisSaati >= current->getNext()->getKalkisSaati())))
        {
            current = current->getNext();
        }

        newNode->setNext(current->getNext());
        newNode->setPrev(current);
        if (current->getNext() != nullptr)
            current->getNext()->setPrev(newNode);
        current->setNext(newNode);
    }
}
void ucusliste::guncelleme(int ucus_numarasi, int yeniLuksKoltukSayisi)
{
    system("cls");
    kalkis* current = head;
    while (current != nullptr && current->getUcusNumarasi() != ucus_numarasi) {
        current = current->getNext();
    }
    if (current == nullptr) {
        cout << "Uçuþ numarasýna sahip kayýt bulunamadý." << endl;
        return;
    }
    else {

        current->setLukskoltuksayisi(yeniLuksKoltukSayisi);
    }
}

void ucusliste::ucusSil(int ucusNumarasi)
{
    system("cls");
    kalkis* current = head;
    kalkis* prevNode = nullptr;

    // Ýlk düðümün silinmesi durumu
    if (current != nullptr && current->getUcusNumarasi() == ucusNumarasi)
    {
        head = current->getNext();
        if (head != nullptr)
            head->setPrev(nullptr);
        delete current;
        return;
    }

    // Ýstenilen düðümün arama ve silme iþlemi
    while (current != nullptr && current->getUcusNumarasi() != ucusNumarasi)
    {
        prevNode = current;
        current = current->getNext();
    }

    if (current == nullptr)
    {
        std::cout << "Belirtilen ucus numarasina ait ucus bulunamadi." << std::endl;
        return;
    }

    prevNode->setNext(current->getNext());
    if (current->getNext() != nullptr)
        current->getNext()->setPrev(prevNode);

    delete current;
}

std::ostream& operator<<(std::ostream& os, const kalkis& u)
{

    os << u.getUcusNumarasi() << setw(15);
    os << u.getKalkisYeri() << setw(16);
    os << u.getVarisYeri() << setw(12);
    os << u.getKalkisSaati() << ":" << u.getKalkisDakikasi() << setw(15);
    os << u.getKoltukKapasitesi() << setw(21);
    os << u.getBosKoltukSayisi() << setw(19);
    os << u.getLukskoltuksayisi() << endl;

    return os;
}
bool operator==(const kalkis& ucus1, const kalkis& ucus2)
{
    return ucus1.getKalkisYeri() == ucus2.getKalkisYeri();
}


void ucusliste::kalkislisteleme(const std::string& kalkisYeri) const
{
    system("cls");
    kalkis* current = head;
    bool found = false;

    std::string kalkisYeriUpper = kalkisYeri;
    std::transform(kalkisYeriUpper.begin(), kalkisYeriUpper.end(), kalkisYeriUpper.begin(), std::toupper); // Büyük harfe dönüþtürme
    cout << "ucus no     kalkis yeri     varis yeri     zamani     koltuk kapasitesi     bos koltuk sayisi      Luks Koltuk" << endl;
    cout << "-------     -----------     ----------     ------     -----------------     -----------------     -------------" << endl;
    while (current != nullptr)
    {
        std::string currentKalkisYeri = current->getKalkisYeri();
        std::transform(currentKalkisYeri.begin(), currentKalkisYeri.end(), currentKalkisYeri.begin(), std::toupper); // Büyük harfe dönüþtürme

        if (currentKalkisYeri == kalkisYeriUpper)
        {
            found = true;
            std::cout << *current; // << operatörünü kullanarak uçuþ bilgilerini yazdýr
        }

        current = current->getNext();
    }

    if (!found)
    {
        std::cout << "Belirtilen kalkis yerine ait ucus bulunamadi." << std::endl;
    }
}

