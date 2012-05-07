#include <iostream>
#include <cstring>
using namespace std;

class Datum {
private:
	int den, mesec, godina;
public:
	Datum(int d = 1, int m = 1, int g = 1) {
		den = d;
		mesec = m;
		godina = g;
	}
	bool operator<(Datum& datum) {
		if (godina != datum.godina)
			return godina < datum.godina;
		if (mesec != datum.mesec)
			return mesec < datum.mesec;
		return den < datum.den;
	}
	friend ostream& operator<<(ostream &out, Datum &datum) {
		out << datum.den << "." << datum.mesec << "." << datum.godina;
		return out;
	}
};

class Vraboten {
private:
	char ime[100];
	Datum datum_na_raganje;
public:
	Vraboten(char *i = "", int den = 0, int mesec = 0, int godina = 0) :
		datum_na_raganje(den, mesec, godina) {
		strcpy(ime, i);
	}

	Datum& getDatum() {
		return datum_na_raganje;
	}

	friend ostream& operator<<(ostream &out, Vraboten &v) {
		out << v.ime << "\t" << v.datum_na_raganje;
		return out;
	}
};
class Firma {
private:
	char ime[100];
	Vraboten *vraboteni;
	int vkupno_vraboteni;
public:
	Firma(char *i = "") {
		vkupno_vraboteni = 0;
		vraboteni = NULL;
		strcpy(ime, i);
	}
	Firma(const Firma &f) {
		vkupno_vraboteni = f.vkupno_vraboteni;
		strcpy(ime, f.ime);
		vraboteni = new Vraboten[vkupno_vraboteni];
		for (int i = 0; i < vkupno_vraboteni; i++)
			vraboteni[i] = f.vraboteni[i];
	}

	Firma& operator=(const Firma &f) {
		if (this != &f) {
			vkupno_vraboteni = f.vkupno_vraboteni;
			strcpy(ime, f.ime);
			delete[] vraboteni;
			vraboteni = new Vraboten[vkupno_vraboteni];
			for (int i = 0; i < vkupno_vraboteni; i++)
				vraboteni[i] = f.vraboteni[i];
		}
		return *this;
	}

	~Firma() {
		delete[] vraboteni;
	}

	Firma& operator+=(Vraboten v) {
		Vraboten *tmp = vraboteni;
		vraboteni = new Vraboten[vkupno_vraboteni + 1];
		for (int i = 0; i < vkupno_vraboteni; i++)
			vraboteni[i] = tmp[i];
		vraboteni[vkupno_vraboteni++] = v;
		delete[] tmp;
		return *this;
	}

	void pecati() {
		cout << ime << endl;
		for (int i = 0; i < vkupno_vraboteni; i++)
			cout << vraboteni[i] << endl;
	}

	void pecatiNajmlad() {
		Vraboten najmlad = vraboteni[0];
		for (int i = 1; i < vkupno_vraboteni; i++)
			if (najmlad.getDatum() < vraboteni[i].getDatum())
				najmlad = vraboteni[i];
		cout << "Najmlad vraboten e :" << endl;
		cout << najmlad;
	}
};
int main() {
	Vraboten v1("Petko", 20, 2, 1990);
	Vraboten v2("Trajko", 3, 7, 1992);
	Vraboten v3("Mitko", 12, 9, 1989);
	Firma firma("Finki");
	firma += v1;
	firma += v2;
	firma += v3;
	firma.pecati();
	cout << endl;
	firma.pecatiNajmlad();
	cout << endl;
	return 0;
}

