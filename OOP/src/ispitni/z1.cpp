#include <iostream>
#include <cmath>
using namespace std;

struct Koordinata {
	float latituda;
	float longituda;
	float nadmorskaVisocina;
};

float rastojanie(Koordinata &k1, Koordinata &k2) {
	return sqrt(pow((k1.latituda - k2.latituda), 2) + pow((k1.longituda
			- k2.longituda), 2));
}

struct Pateka {
	char ime[50];
	Koordinata niza[500];
	int n;
};

float dolzina(Pateka &p) {
	float s = 0;
	for (int i = 0; i < p.n - 1; i++) {
		s += rastojanie(p.niza[i], p.niza[i + 1]);
	}
	return s;
}

void pecati(Pateka &p) {
	cout << p.ime << endl;
	cout << dolzina(p) << endl;
}

void najdolga(Pateka p[], int n) {
	float max = dolzina(p[0]);
	int m = 0;
	for (int i = 1; i < n; i++) {
		float d = dolzina(p[i]);
		if (d > max) {
			max = d;
			m = i;
		}
	}
	pecati(p[m]);
}

int main() {
	return 0;
}

