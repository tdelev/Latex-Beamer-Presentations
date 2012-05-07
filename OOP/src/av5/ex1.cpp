#include <iostream>
#include <cmath>
using namespace std;
float const PI = 3.14;
class Tocka {
private:
	float x, y;
protected:
	float rast(Tocka t) {
		return (sqrt((x - t.x) * (x - t.x) + (y - t.y) * (y - t.y)));
	}
public:
	Tocka(float xx = 0, float yy = 0) {
		x = xx;
		y = yy;
	}
	void set(float xx, float yy) {
		x = xx;
		y = yy;
	}
	friend ostream & operator<<(ostream & out, Tocka &t) {
		return out << "(" << t.x << "," << t.y << ")";
	}
};
class Krug: public Tocka {
protected:
	float r;
public:
	Krug(float xx = 0, float yy = 0, float rr = 1) :
		Tocka(xx, yy) {
		r = rr;
	}
	bool leziVo(Tocka t) {
		return (rast(t) < r);
	}
	float plostina() {
		return r * r * PI;
	}
};
class Sfera: protected Krug {
private:
	float z;
public:
	Sfera(float xx, float yy, float zz, float rr) :
		Krug(xx, yy, rr) {
		z = zz;
	}
	void set(float xx, float yy, float zz) {
		Tocka::set(xx, yy);
		z = zz;
	}
	float plostina() {
		return 4. * Krug::plostina();
	}
	float volumen() {
		return 4. / 3 * Krug::plostina() * r;
	}
};
int main() {
	Tocka t1(5, 5);
	Krug k(5, 5, 3);
	Sfera s(5, 5, 5, 3);

	cout << k << endl; // se povikuva operatorot << nasleden od tocka
	cout << t1 << endl;
	k.set(7, 7);

	cout << (k.leziVo(t1) ? "Tockata lezi vo krugot"
			: "Tockata ne lezi vo krugot") << endl;
	cout << k.plostina() << endl;
	t1 = k;
	cout << t1 << endl;

	//cout << k.rast(t1) << endl;
	cout << s.plostina() << endl;
	cout << s.volumen() << endl;
	//cout << s.leziVo(t1) << endl;
	return 0;
	return 0;
}

