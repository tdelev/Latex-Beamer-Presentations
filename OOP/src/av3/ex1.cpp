#include <iostream>
using namespace std;
class Kvadar {
private:
	int a, b, c;
public:
	// Default constructor
	Kvadar(){
		cout << "Default constructor" << endl;
	}
	// Constructor so argumenti
	Kvadar(int aa, int bb, int cc) {
		a = aa;
		b = bb;
		c = cc;
		cout << "Constructor" << endl;
	}
	~Kvadar() {	cout << "Destructor" << endl; }
	// Metod za presmetuvanje plostina
	int plostina() {
		return 2 * (a * b + a * c + b * c);
	}
	// Metod za presmetuvanje volumen
	int volumen() {
		return a * b * c;
	}
};
int main() {
	Kvadar k1(10, 15, 20);
	cout << "Plostinata e: " << k1.plostina() << endl;
	cout << "Volumenot e: " << k1.volumen() << endl;
	return 0;
}
