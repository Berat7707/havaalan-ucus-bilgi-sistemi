#include <iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include "string.h"

using namespace std;
kalkisvaris::kalkisvaris()
{
    next = nullptr;
}

// Node sýnýfý için getter ve setter fonksiyonlarý
int kalkisvaris::getUcusNumarasi() const
{
    return ucus_numarasi;
}

void kalkisvaris::setUcusNumarasi(int numarasi)
{
    ucus_numarasi = numarasi;
}
int kalkisvaris::getBosKoltukSayisi() const
{
    return bos_koltuk_sayisi;
}

void kalkisvaris::setBosKoltukSayisi(int sayisi)
{
    bos_koltuk_sayisi = sayisi;
}
int kalkisvaris::getLukskoltuksayisi()const
{
    return luks_koltuk;
}
void kalkisvaris::setLukskoltuksayisi(int sayi) {
    luks_koltuk = sayi;
}
int kalkisvaris::getKoltukKapasitesi() const
{
    return koltuk_kapasitesi;
}

void kalkisvaris::setKoltukKapasitesi(int kapasite)
{
    koltuk_kapasitesi = kapasite;
}

int kalkisvaris::getKalkisSaati() const
{
    return kalkis_saati;
}

void kalkisvaris::setKalkisSaati(int saati)
{
    kalkis_saati = saati;
}

int kalkisvaris::getKalkisDakikasi() const
{
    return kalkis_dakikasi;
}

void kalkisvaris::setKalkisDakikasi(int dakikasi)
{
    kalkis_dakikasi = dakikasi;
}

std::string kalkisvaris::getKalkisYeri() const
{
    return kalkis_yeri;
}

void kalkisvaris::setKalkisYeri(const std::string& yeri)
{
    kalkis_yeri = yeri;
}

std::string kalkisvaris::getVarisYeri() const
{
    return varis_yeri;
}

void kalkisvaris::setVarisYeri(const std::string& yeri)
{
    varis_yeri = yeri;
}

float kalkisvaris::getBiletFiyat() const
{
    return bilet_fiyat;
}

void kalkisvaris::setBiletFiyat(float fiyat)
{
    bilet_fiyat = fiyat;
}

float kalkisvaris::getDolulukOrani() const
{
    return doluluk_orani;
}

void kalkisvaris::setDolulukOrani(float orani)
{
    doluluk_orani = orani;
}

kalkisvaris* kalkisvaris::getNext() const
{
    return next;
}

void kalkisvaris::setNext(kalkisvaris* nextNode)
{
    next = nextNode;
}

float kalkisvaris::getToplamBiletTutari() const
{
    return toplam_bilet_tutari;
}

void kalkisvaris::setToplamBiletTutari(float tutari)
{
    toplam_bilet_tutari = tutari;
}
void kalkisvaris::setPrev(kalkisvaris* prevNode)
{
    prev = prevNode;
}
ucusvaris::ucusvaris()
{
    head = nullptr;
}


ucusvaris::~ucusvaris()
{
    kalkisvaris* current = head;
    while (current != nullptr)
    {
        kalkisvaris* next = current->getNext();
        delete current;
        current = next;
    }
}
void ucusvaris::ucusekle1(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri)
{
    kalkisvaris* newNode = new kalkisvaris();
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
        kalkisvaris* current = head;
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
void ucusvaris::ucusSilme(int ucusNumarasi)
{
    kalkisvaris* current = head;
    kalkisvaris* prevNode = nullptr;

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
void ucusvaris::guncelleme1(int ucus_numarasi, int yeniLuksKoltukSayisi)
{
    kalkisvaris* current = head;
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

std::ostream& operator<<(std::ostream& os, const kalkisvaris& u)
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
bool operator==(const kalkisvaris& ucus1, const kalkisvaris& ucus2)
{
    return ucus1.getKalkisYeri() == ucus2.getKalkisYeri();
}
void ucusvaris::varislisteleme(const std::string& varisYeri) const
{
    kalkisvaris* current = head;
    bool found = false;

    std::string lowercaseVarisYeri = varisYeri;
    std::transform(lowercaseVarisYeri.begin(), lowercaseVarisYeri.end(), lowercaseVarisYeri.begin(), [](unsigned char c) { return std::tolower(c); });
    cout << "ucus no     kalkis yeri     varis yeri     zamani     koltuk kapasitesi     bos koltuk sayisi      Luks Koltuk" << endl;
    cout << "-------     -----------     ----------     ------     -----------------     -----------------     -------------" << endl;
    while (current != nullptr)
    {
        std::string currentVarisYeri = current->getVarisYeri();
        std::transform(currentVarisYeri.begin(), currentVarisYeri.end(), currentVarisYeri.begin(), [](unsigned char c) { return std::tolower(c); });

        if (currentVarisYeri == lowercaseVarisYeri)
        {
            found = true;
            std::cout << *current; // << operatörünü kullanarak uçuþ bilgilerini yazdýr
        }

        current = current->getNext();
    }

    if (!found)
    {
        std::cout << "Belirtilen varis yerine ait ucus bulunamadi." << std::endl;
    }
}

void ucusvaris::kalkisvarislisteleme(const std::string& kalkisYeri, const std::string& varisYeri) const
{
    kalkisvaris* current = head;
    bool found = false;

    // Kalkýþ yeri ve varýþ yeri eþleþen uçuþlarý depolamak için bir vektör kullanalým
    std::vector<kalkisvaris*> uygunUcuslar;

    std::string lowercaseKalkisYeri = kalkisYeri;
    std::transform(lowercaseKalkisYeri.begin(), lowercaseKalkisYeri.end(), lowercaseKalkisYeri.begin(), [](unsigned char c) { return std::tolower(c); });

    std::string lowercaseVarisYeri = varisYeri;
    std::transform(lowercaseVarisYeri.begin(), lowercaseVarisYeri.end(), lowercaseVarisYeri.begin(), [](unsigned char c) { return std::tolower(c); });
    cout << "ucus no     kalkis yeri     varis yeri     zamani     koltuk kapasitesi     bos koltuk sayisi      Luks Koltuk" << endl;
    cout << "-------     -----------     ----------     ------     -----------------     -----------------     -------------" << endl;
    while (current != nullptr)
    {
        std::string currentKalkisYeri = current->getKalkisYeri();
        std::transform(currentKalkisYeri.begin(), currentKalkisYeri.end(), currentKalkisYeri.begin(), [](unsigned char c) { return std::tolower(c); });

        std::string currentVarisYeri = current->getVarisYeri();
        std::transform(currentVarisYeri.begin(), currentVarisYeri.end(), currentVarisYeri.begin(), [](unsigned char c) { return std::tolower(c); });

        if (currentKalkisYeri == lowercaseKalkisYeri && currentVarisYeri == lowercaseVarisYeri)
        {
            found = true;
            uygunUcuslar.push_back(current);
        }

        current = current->getNext();
    }

    if (!found)
    {
        std::cout << "Belirtilen kalkis ve varis yerlerine ait ucus bulunamadi." << std::endl;
    }
    else
    {
        // Kalkýþ zamanlarýna göre uçuþlarý azalan sýrada sýralayalým
        std::sort(uygunUcuslar.begin(), uygunUcuslar.end(), [](const kalkisvaris* u1, const kalkisvaris* u2) {
            if (u1->getKalkisSaati() == u2->getKalkisSaati()) {
                return u1->getKalkisDakikasi() > u2->getKalkisDakikasi();
            }
            return u1->getKalkisSaati() > u2->getKalkisSaati();
            });

        // Sýralanmýþ uçuþlarý ekrana yazdýralým
        for (const auto* ucus : uygunUcuslar) {
            std::cout << *ucus; // << operatörünü kullanarak uçuþ bilgilerini yazdýr
        }
    }
}


