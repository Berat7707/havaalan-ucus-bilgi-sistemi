#include <iostream>
#include<iomanip>
#include "Üst Bilgi.h"
using namespace std;

// Node sýnýfý için constructor
Node::Node()
{
	next = nullptr;
}

// Node sýnýfý için getter ve setter fonksiyonlarý
int Node::getUcusNumarasi() const
{
	return ucus_numarasi;
}

void Node::setUcusNumarasi(int numarasi)
{
	ucus_numarasi = numarasi;
}
int Node::getBosKoltukSayisi() const
{
	return bos_koltuk_sayisi;
}

void Node::setBosKoltukSayisi(int sayisi)
{
	bos_koltuk_sayisi = sayisi;
}
int Node::getLukskoltuksayisi()const
{
	return luks_koltuk;
}
void Node::setLukskoltuksayisi(int sayi) {
	luks_koltuk = sayi;
}
int Node::getKoltukKapasitesi() const
{
	return koltuk_kapasitesi;
}

void Node::setKoltukKapasitesi(int kapasite)
{
	koltuk_kapasitesi = kapasite;
}

int Node::getKalkisSaati() const
{
	return kalkis_saati;
}

void Node::setKalkisSaati(int saati)
{
	kalkis_saati = saati;
}

int Node::getKalkisDakikasi() const
{
	return kalkis_dakikasi;
}

void Node::setKalkisDakikasi(int dakikasi)
{
	kalkis_dakikasi = dakikasi;
}

std::string Node::getKalkisYeri() const
{
	return kalkis_yeri;
}

void Node::setKalkisYeri(const std::string& yeri)
{
	kalkis_yeri = yeri;
}

std::string Node::getVarisYeri() const
{
	return varis_yeri;
}

void Node::setVarisYeri(const std::string& yeri)
{
	varis_yeri = yeri;
}

float Node::getBiletFiyat() const
{
	return bilet_fiyat;
}

void Node::setBiletFiyat(float fiyat)
{
	bilet_fiyat = fiyat;
}

float Node::getDolulukOrani() const
{
	return doluluk_orani;
}

void Node::setDolulukOrani(float orani)
{
	doluluk_orani = orani;
}

Node* Node::getNext() const
{
	return next;
}

void Node::setNext(Node* nextNode)
{
	next = nextNode;
}

float Node::getToplamBiletTutari() const
{
	return toplam_bilet_tutari;
}

void Node::setToplamBiletTutari(float tutari)
{
	toplam_bilet_tutari = tutari;
}

FlightList::FlightList()
{
	head = nullptr;
}

FlightList::~FlightList()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->getNext();
		delete current;
		current = next;
	}
}


void FlightList::addFlight(int ucusNumarasi, int bosKoltukSayisi, int luks_koltuk, int koltukKapasitesi, int kalkisSaati, int kalkisDakikasi, const std::string& kalkisYeri, const std::string& varisYeri)
{
	system("cls");
	Node* current = head;
	while (current != nullptr)
	{
		if (current->getUcusNumarasi() == ucusNumarasi)
		{
			cout << "Ucus numarasi zaten mevcut. Yeni ucus eklenmedi." << endl;
			return;
		}
		current = current->getNext();
	}


	Node* newNode = new Node();
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
		Node* current = head;
		while (current->getNext() != nullptr && current->getNext()->getUcusNumarasi() < ucusNumarasi)
		{
			current = current->getNext();
		}

		newNode->setNext(current->getNext());
		current->setNext(newNode);
	}
}



void FlightList::sil(int ucus_numarasi)
{
	system("cls");
	Node* current = head;
	Node* prev = nullptr;


	while (current != nullptr && current->getUcusNumarasi() != ucus_numarasi) {
		prev = current;
		current = current->getNext();
	}

	if (current == nullptr) {
		cout << "Uçuþ numarasýna sahip kayýt bulunamadý." << endl;
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
void FlightList::guncelle(int ucus_numarasi, int yeniLuksKoltukSayisi)
{
	system("cls");
	Node* current = head;
	while (current != nullptr && current->getUcusNumarasi() != ucus_numarasi) {
		current = current->getNext();
	}
	if (current == nullptr) {
		cout << "Uçuþ numarasýna sahip kayýt bulunamadý." << endl;
		return;
	}
	else {
		current->setLukskoltuksayisi(yeniLuksKoltukSayisi);
		cout << "Luks koltuk sayisi guncellendi." << endl;
	}
}
void FlightList::listeleme()
{
	system("cls");
	Node* current = head;
	cout << "ucus no     kalkis yeri     varis yeri     zamani     koltuk kapasitesi     bos koltuk sayisi      Luks Koltuk" << endl;
	cout << "-------     -----------     ----------     ------     -----------------     -----------------     -------------" << endl;
	while (current != NULL && current->getLukskoltuksayisi() > 0)
	{
		cout << current->getUcusNumarasi() << setw(15);
		cout << current->getKalkisYeri() << setw(16);
		cout << current->getVarisYeri() << setw(12);
		cout << current->getKalkisSaati() << ":" << current->getKalkisDakikasi() << setw(15);
		cout << current->getKoltukKapasitesi() << setw(21);
		cout << current->getBosKoltukSayisi() << setw(19);
		cout << current->getLukskoltuksayisi() << endl;


		current = current->getNext();
	}
}