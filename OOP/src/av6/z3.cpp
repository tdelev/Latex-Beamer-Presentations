#include<iostream>
#include<cstring>
using namespace std;

class Telefon {
protected:
	int god_proizvodstvo;
	int pocetna_cena;
	char proizvoditelModel[40];
public:
	Telefon() {
	}
	Telefon(int g, int p, const char *m) {
		god_proizvodstvo = g;
		pocetna_cena = p;
		strncpy(proizvoditelModel, m, 39);
		proizvoditelModel[39] = '\0';

	}
	virtual float presmetajVrednost()= 0;
	friend bool operator<(Telefon &t1, Telefon &t2) {
		return t1.presmetajVrednost() < t2.presmetajVrednost();
	}
	void Pecati() {
		cout << "God:" << god_proizvodstvo << endl;
		cout << "Poc:" << pocetna_cena << endl;
		cout << "Model:" << proizvoditelModel << endl;
	}
};
class Mobilen: public Telefon {
private:
	float visina;
	float sirina;
	float debelina;

public:
	Mobilen() {
	}
	Mobilen(int g, int p, const char *m, float v, float s, float d) :
		Telefon(g, p, m), visina(v), sirina(s), debelina(d) {
	}
	float presmetajVrednost() {
		double cena = pocetna_cena;
		if (god_proizvodstvo < 2010)
			cena *= 0.95;
		if (debelina < 0.7)
			cena *= 1.05;
		return cena;
	}
};
class Fiksen: public Telefon {
private:
	int masa;
public:
	Fiksen() {
	}
	Fiksen(int g, int p, const char *m, int t) :
		Telefon(g, p, m) {
		masa = t;
	}
	float presmetajVrednost() {
		double cena = pocetna_cena;
		if (god_proizvodstvo < 2009)
			cena *= 0.95;
		if (masa < 100)
			cena *= 1.07;
		return cena;
	}
};
void minCena(Telefon **t, int br) {
	Telefon* temp = t[0];
	for (int i = 1; i < br; i++) {
		if ((*t[i]) < *temp)
			temp = t[i];

	}
	cout << temp->presmetajVrednost() << endl;

}
int main() {
	Mobilen m1(2005, 1500, "mod1", 10, 5, 1.5);
	Mobilen m2(2011, 1500, "mod2", 7, 5, 0.5);

	Fiksen f1(2009, 10000, "mod3", 80);
	cout << "M1:" << m1.presmetajVrednost() << endl;
	cout << "M2:" << m2.presmetajVrednost() << endl;
	cout << "F1:" << f1.presmetajVrednost() << endl;

	Telefon** telefoni;
	telefoni = new Telefon*[3];
	telefoni[0] = &m1;
	telefoni[1] = &m2;
	telefoni[2] = &f1;
	minCena(telefoni, 3);
	return 0;
}
