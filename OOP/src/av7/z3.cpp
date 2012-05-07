/*
 Да се дефинира класа Casovnik, за која се чуваат информации за:
 -	час (цел број),
 -	минути (цел број),
 -  	секунди (цел број),
 -  	призводител на часовникот (динамички алоцирана листа од знаци).
 Од оваа класа да се изведат две нови класи DigitalenCasovnik и AnalogenCasovnik. За дигиталниот часовник дополнително се чуваат информации за стотинките и форматот на прикажување на времето (АМ или PM).
 За секоја од класите да се дефинираат конструктори со аргументи.
 Во рамките на изведените класи да се дефинира функција (Vreme) која го печати времето на дигиталниот часовник во формат:
 -	производител, час, миннути, секунди, стотинки, АМ или PM.
 За аналогниот часовник функцијата печати:
 -	производител, час, минути, секунди.
 Дополнително да се преоптовари операторот == кој го споредува времето кое го мерат два часовника и враќа true доколку времето на едниот часовник не отстапува за повеќе од 30 секунди во однос на времето на другиот часовник, а во спротивно враќа false (без да се води сметка за запоцнување на новиот ден).
 Да се напише и надворешна функција (Pecati) која прима низа од покажувачи кон класата Casovnik и нивниот број, а го печати времето на сите часовници од низата.
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
class Casovnik {
protected:
	int cas;
	int min;
	int sec;
	char* proizvoditel;
public:
	Casovnik(int _cas, int _min, int _sec, char* _proizvoditel) {
		cas = _cas;
		min = _min;
		sec = _sec;
		proizvoditel = new char[strlen(_proizvoditel)];
		strcpy(proizvoditel, _proizvoditel);
	}
	Casovnik(const Casovnik& other) {
		cas = other.cas;
		min = other.min;
		sec = other.sec;
		proizvoditel = new char[strlen(other.proizvoditel)];
		strcpy(proizvoditel, other.proizvoditel);
	}
	Casovnik& operator=(const Casovnik& other) {
		if (this != &other) {
			cas = other.cas;
			min = other.min;
			sec = other.sec;
			delete[] proizvoditel;
			proizvoditel = new char[strlen(other.proizvoditel)];
			strcpy(proizvoditel, other.proizvoditel);
		}
		return *this;
	}
	virtual ~Casovnik() {
		delete[] proizvoditel;
	}
	virtual void vreme()=0;

	int get_cas() {
		return cas;
	}
	int get_min() {
		return min;
	}
	int get_sec() {
		return sec;
	}
};

bool operator==(Casovnik& c1, Casovnik& c2) {
	int prv_sec = c1.get_sec() + c1.get_min() * 60 + c1.get_cas() * 3600;
	int vtor_sec = c2.get_sec() + c2.get_min() * 60 + c2.get_cas() * 3600;
	if (abs(double(prv_sec - vtor_sec)) < 30)
		return true;
	else
		return false;
}
enum format {
	AM, PM
};

class DigitalenCasovnik: public Casovnik {
	int stotinki;
	format f;
public:
	DigitalenCasovnik(int _cas, int _min, int _sec, char* _proizvoditel,
			int _stotinki, format _f) :
		Casovnik(_cas, _min, _sec, _proizvoditel) {
		stotinki = _stotinki;
		f = _f;
	}
	void vreme() {
		cout << proizvoditel << endl;
		cout << cas << ":" << min << ":" << sec << ":" << stotinki;
		if (f == AM) {
			cout << " AM" << endl;
		} else {
			cout << " PM" << endl;
		}
	}
};

class AnalogenCasovnik: public Casovnik {
public:
	AnalogenCasovnik(int _cas, int _min, int _sec, char* _proizvoditel) :
		Casovnik(_cas, _min, _sec, _proizvoditel) {
	}
	void vreme() {
		cout << proizvoditel << endl;
		cout << cas << ":" << min << ":" << sec << endl;
	}
};
void Pecati(Casovnik** casovnici, int broj_casovnici) {
	for (int i = 0; i < broj_casovnici; i++) {
		casovnici[i]->vreme();
	}
}
int main() {
	Casovnik** casovnici;
	casovnici = new Casovnik*[2];
	casovnici[0] = new DigitalenCasovnik(10, 10, 20, "casio", 34, AM);
	casovnici[1] = new AnalogenCasovnik(10, 10, 50, "casio");

	cout << "ednakvost:" << (*casovnici[0] == *casovnici[1]) << endl;

	Pecati(casovnici, 2);

	for (int i = 0; i < 2; i++) {
		delete casovnici[i];
	}
	delete[] casovnici;
}

