#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class Tocka {
private:
	double x, y;
public:
	Tocka(double xx = 0, double yy = 0) {
		x = xx;
		y = yy;
	}
	void set(double xx, double yy) {
		x = xx;
		y = yy;
	}
	double getx() const { return x; }
	double gety() const { return y;	}
	Tocka interpolate(const Tocka &t) const {
		Tocka i;
		i.x = (x + t.x) / 2;
		i.y = (y + t.y) / 2;
		return i;
	}
	friend ostream & operator<<(ostream &out, const Tocka &t) {
		return out << '(' << t.x << ',' << t.y << ')';
	}
};
class Tocka3D: public Tocka {
private:
	double z;
public:
	Tocka3D(double xx = 0, double yy = 0, double zz = 0) :
		Tocka(xx, yy) {
		z = zz;
	}
	void set(double xx, double yy, double zz) {
		Tocka::set(xx, yy);
		z = zz;
	}
	double getz() { return z; }

	Tocka3D interpolate(const Tocka3D &t) const {
		Tocka3D i;
		i.set((getx() + t.getx()) / 2, (gety() + t.gety()) / 2, (z + t.z) / 2);
		return i;
	}

	friend ostream & operator<<(ostream &out, const Tocka3D &t) {
		return out << '(' << t.getx() << ',' << t.gety() << ',' << t.z << ')';
	}
};
class F {
private:
	Tocka3D *tocki;
	int max;
	int broj;
public:
	F(int m = 0) {
		max = m;
		tocki = new Tocka3D[m];
		broj = 0;
	}
	F(const F &f) {
		max = f.max;
		broj = f.broj;
		tocki = new Tocka3D[max];
		for (int i = 0; i < broj; i++)
			tocki[i] = f.tocki[i];
	}
	F operator=(const F &f) {
		if (this != &f) {
			max = f.max;
			broj = f.broj;
			delete[] tocki;
			tocki = new Tocka3D[max];
			for (int i = 0; i < broj; i++)
				tocki[i] = f.tocki[i];
		}
		return *this;
	}
	F operator +=(const Tocka3D &t) {
		if (broj < max) {
			tocki[broj] = t;
			broj++;
		} else
			cout << "nema mesto za nova tocka\n";
		return *this;
	}
	Tocka3D & operator [](int i) {
		if (i >= 0 && i < broj)
			return tocki[i];
		else {
			cout << "nevaliden indeks\n";
			exit(1);
		}
	}
	F interpolacija() {
		F f(max * 2 - 1);
		f += tocki[0];
		for (int i = 0; i < broj - 1; i++) {
			f += tocki[i].interpolate(tocki[i + 1]);
			f += tocki[i + 1];
		}
		return f;
	}
	~F() {
		delete[] tocki;
	}
	friend ostream& operator<<(ostream &out, const F &f) {
		for (int i = 0; i < f.broj - 1; i++)
			out << f.tocki[i] << "->";
		return out << f.tocki[f.broj - 1];
	}
};
int main() {
	Tocka3D t(1, 1, 1);
	F f(5);
	for (int i = 0; i < 3; i++) {
		f += t;
		t.set(2 * (i + 1), 2 * (i + 1), 2 * (i + 1));
	}
	cout << f << endl;
	cout << t << endl;
	F fi;
	fi = f.interpolacija();
	cout << fi << endl;
	fi[0] = t;
	fi += t;

	cout << fi << endl;
	cout << fi[0] << ' ';
	cout << fi[7] << endl;
	return 0;
}
