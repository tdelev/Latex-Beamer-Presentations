/*
 Да се креира хиерархија на класи за репрезентација на музичко и сликарско уметничко дело.  За потребите на оваа хиерархија да се дефинира апстрактна класа UmetnickoDelo од која ќе бидат изведени двете класи MuzickoDelo и SlikarskoDelo. Во класата UmetnickoDelo се чуваат податоци за годината кога е изработено делото (int), авторот на уметничкото дело (динамички алоцирана низа од карактери) и цената на уметничкото дело (float).
 За класата MuzickoDelo дополнително се чува жанрот на делото (низа од 30 карактери).
 За класата SlikarskoDelo дополнително се чуваат техниката во која е изработено делото (низа од 30 карактери) и степенот на оштетеност на делото во проценти (int).
 За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
 -	Конструктор со aргументи кои одговараат на податочните членови
 -	Set и get методи
 -	Метода за пресметување на цената на уметничките дела
 o	Иницијалната цена на музичкото дело се зголемува за 10% доколку тоа е изработено во 17 век.
 o	Иницијалната цена на сликарското дело процентуално се намалува за степенот на неговата оштетеност.
 -	Проптоварување на операторот ==, кој ги споредува уметничките дела според нивната цена
 -	Преоптоварување на операторот << за печатење на сите податоци за уметничките дела
 Сите променливи во класите се чуваат како приватни.
 */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
class UmetnickoDelo {
	char* avtor;
	int godina;
	float cena;
public:
	UmetnickoDelo(char* _avtor, int _godina, float _cena) {
		avtor = new char[strlen(_avtor)];
		strcpy(avtor, _avtor);
		godina = _godina;
		cena = _cena;
	}
	UmetnickoDelo(const UmetnickoDelo& other) {
		avtor = new char[strlen(other.avtor)];
		strcpy(avtor, other.avtor);
		godina = other.godina;
		cena = other.cena;
	}
	UmetnickoDelo& operator=(const UmetnickoDelo& other) {
		if (this != &other) {
			delete[] avtor;
			avtor = new char[strlen(other.avtor)];
			strcpy(avtor, other.avtor);
			godina = other.godina;
			cena = other.cena;
		}
		return *this;
	}
	virtual ~UmetnickoDelo() {
		delete[] avtor;
	}
	const char* get_avtor() {
		return avtor;
	}
	int get_godina() {
		return godina;
	}
	void set_avtor(char* _avtor) {
		delete[] avtor;
		avtor = new char[strlen(_avtor)];
		strcpy(avtor, _avtor);
	}
	void set_godina(int _godina) {
		godina = _godina;
	}
	void set_cena(int _cena) {
		cena = _cena;
	}
	virtual float Cena() {
		return cena;
	}
};
bool operator==(UmetnickoDelo& u1, UmetnickoDelo& u2) {
	if (u1.Cena() == u2.Cena())
		return true;
	else
		return false;
}
class MuzickoDelo: public UmetnickoDelo {
	char zanr[30];
public:
	MuzickoDelo(char* _avtor, int _godina, float _cena, char* _zanr) :
		UmetnickoDelo(_avtor, _godina, _cena) {
		strncpy(zanr, _zanr, 29);
		zanr[29] = 0;
	}

	const char* get_zanr() {
		return zanr;
	}
	void set_zanr(char* _zanr) {
		strncpy(zanr, _zanr, 29);
		zanr[29] = 0;
	}
	float Cena() {
		if (get_godina() < 1700 && get_godina() >= 1600)
			return UmetnickoDelo::Cena() * 1.1;
		return UmetnickoDelo::Cena();
	}
};
class SlikarskoDelo: public UmetnickoDelo {
	char tehnika[30];
	int stepen;
public:
	SlikarskoDelo(char* _avtor, int _godina, float _cena, char* _tehnika,
			int _stepen) :
		UmetnickoDelo(_avtor, _godina, _cena) {
		strncpy(tehnika, _tehnika, 29);
		tehnika[29] = 0;
		stepen = _stepen;
	}
	const char* get_tehnika() {
		return tehnika;
	}
	void set_tehnika(char* _tehnika) {
		strncpy(tehnika, _tehnika, 29);
		tehnika[29] = 0;
	}
	float get_stepen() {
		return stepen;
	}
	void set_stepen(int _stepen) {
		stepen = _stepen;
	}
	float Cena() {
		if (stepen) {
			return UmetnickoDelo::Cena() * (1 - (float) stepen / 100);
		}
		return UmetnickoDelo::Cena();
	}
};
int main() {
	cout << "slikarsko delo:";
	SlikarskoDelo sd("aaaa", 1222, 1000, "tehn1", 50);
	cout << sd.Cena() << endl;
	cout << "muzicko delo:";
	MuzickoDelo md("aaaa", 1622, 1000, "asas");
	cout << md.Cena() << endl;
}

