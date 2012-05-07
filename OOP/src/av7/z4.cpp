/*
 Да се дефинира класа Otpornik во која се чува вредноста на импедансата на отпорникот (Z=R). Класата треба да има метод кој ќе ја пресметува напонот на краевите на отпорникот кога низ него тече дадена струја I (U=I*|Z|). Од класата отпорник да се изведе класата  Impedansa која ќе работи со комплексни импеданси (Z=R+jX). Класите треба да овозможуваат собиранје на вредностите на две импеданси преку операторот + (сериска врска на две компоненети). Дополнително да се преоптовари и операторот <<.
 */
#include <iostream>
#include <cmath>
using namespace std;

class Otpornik {
private:
	double R;
public:
	Otpornik(double Rr = 1) {
		R = Rr;
	}
	double getR() {
		return R;
	}
	void setR(double Rr) {
		R = Rr;
	}
	virtual double modul() {
		return R;
	}
	double napon(double I) {
		return I * modul();
	}
	Otpornik operator+(Otpornik &o) {
		Otpornik rez;
		rez.R = R + o.R;
		return rez;
	}
	friend ostream& operator<<(ostream &out, Otpornik &o) {
		return out << "Z=" << o.R << " oma";
	}
};

class Impedansa: public Otpornik {
private:
	double X;
public:
	Impedansa(double Rr = 1, double Xx = 1) :
		Otpornik(Rr) {
		X = Xx;
	}
	virtual double modul() {
		return sqrt(getR() * getR() + X * X);
	}
	Impedansa operator+(Impedansa &i) {
		Impedansa rez;
		rez.setR(getR() + i.getR());
		rez.X = X + i.X;
		return rez;
	}

	Impedansa operator+(Otpornik &o) {
		Impedansa rez;
		rez.setR(getR() + o.getR());
		rez.X = X;
		return rez;
	}

	friend Impedansa operator+(Otpornik &o, Impedansa &i) {
		Impedansa rez;
		rez.setR(o.getR() + i.getR());
		rez.X = i.X;
		return rez;
	}
	friend ostream& operator<<(ostream &out, Impedansa &i) {
		return out << "Z=" << i.getR() << "+j" << i.X << " oma";
	}
};

int main() {
	Otpornik R1(10), R2, R3(3);
	Impedansa L1(3, 10), L2, L3(4);
	Otpornik *pok;
	cout << R1 << endl << L1 << endl;
	cout << R2 << endl << L2 << endl;
	pok = &L1;
	cout << "Za struja I=5 A, U=" << pok->napon(5) << " V\n";
	R3 = R1 + R2;
	cout << R3 << endl;
	L3 = L2 + L1;
	cout << L3 << endl;
	L3 = L2 + R1;
	cout << L3 << endl;
	L3 = R1 + L2;
	cout << L3 << endl;
	return 0;
}
