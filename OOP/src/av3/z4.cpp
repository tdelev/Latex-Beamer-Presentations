#include<iostream>
#include<cmath>
using namespace std;
class kompleksen {
private:
	float re, im;
public:
	kompleksen(float x = 0.0, float y = 0.0) {
		re = x;
		im = y;
	}
	~kompleksen() {
	}
	void print() {
		cout << re;
		if (im < 0)
			cout << "-j";
		else
			cout << "+j";
		cout << fabs(im) << endl;
	}
	kompleksen& operator+=(const kompleksen &a) {
		re += a.re;
		im += a.im;
		return *this;
	}
	kompleksen& operator-=(const kompleksen &a) {
		re -= a.re;
		im -= a.im;
		return *this;
	}
	kompleksen& operator*=(const kompleksen &a) {
		re = re * a.re - im * a.im;
		im = im * a.re + re * a.im;
		return *this;
	}
	kompleksen& operator/=(const kompleksen &a) {
		float m = a.re * a.re + a.im * a.im;
		float r = (re * a.re - im * a.im) / m;
		im = (im * a.re + re * a.im) / m;
		re = r;
		return *this;
	}
	friend ostream& operator<<(ostream &out, const kompleksen &k) {
		out << k.re;
		if (k.im < 0)
			out << "-j";
		else
			out << "+j";
		out << fabs(k.im) << endl;
		return out;
	}
	friend istream& operator>>(istream &in, kompleksen &k) {
		cout << "Vnesi realen del: ";
		in >> k.re;
		cout << "Vnesi imaginaren del: ";
		in >> k.im;
		return in;
	}
};
kompleksen operator+(kompleksen a, kompleksen b) {
	kompleksen c = a;
	return c += b;
}
kompleksen operator-(kompleksen a, kompleksen b) {
	kompleksen c = a;
	return c -= b;
}
kompleksen operator*(kompleksen a, kompleksen b) {
	kompleksen c = a;
	return c *= b;
}
kompleksen operator/(kompleksen a, kompleksen b) {
	kompleksen c = a;
	return c /= b;
}
int main() {
	kompleksen k1(2.0, -3.5), k2(1.0, 7.5); //2-j3.5, 1+j7.5
	kompleksen k = k1 + k2;
	k.print();
	k = k1 - k2;
	cin >> k;
	cout << k;
	return 0;
}
