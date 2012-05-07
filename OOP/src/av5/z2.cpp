#include <iostream>
#include <cstring>
using namespace std;

class Smetka {
private:
	char ime[100];
	long broj;
	double saldo;
public:
	Smetka(char *i = "", long b = 0, double s = 0) {
		strcpy(ime, i);
		broj = b;
		saldo = s;
	}
	void deposit(double suma) {
		saldo += suma;
	}
	void podiganje(double suma) {
		if (suma > saldo) {
			cout << "Ne moze da podignete " << suma << " denari.";
		} else {
			saldo -= suma;
		}
	}
	double getSaldo() {
		return saldo;
	}
	void pregled() {
		cout << "Ime: " << ime << endl;
		cout << "Broj na smetka: " << broj << endl;
		cout << "Saldo: " << saldo << endl;
	}
};
class SmetkaPlus: public Smetka {
private:
	double maxZaem;
	double kamata;
	double dolzi;
public:
	SmetkaPlus(char *i = "", long b = 0, double s = 0, double m = 0, double k =
			0, double d = 0) :
		Smetka(i, b, s) {
		maxZaem = m;
		kamata = k;
		dolzi = d;
	}
	void podiganje(double suma) {
		if (suma <= getSaldo()) {
			Smetka::podiganje(suma);
		} else if (suma < getSaldo() + maxZaem - dolzi) {
			double advance = suma * (1.0 + kamata);
			deposit(advance);
			Smetka::podiganje(suma);
		} else {
			cout << "Ne moze da podignete sredstva!" << endl;
		}
	}
	void pregled() {
		Smetka::pregled();
		cout << "Dolzi: " << dolzi << endl;
	}
};
int main() {
	Smetka Petko("Petko Petkovski", 381299, 4000);
	SmetkaPlus Trpe("Trpe Trpevski", 382288, 3000);
	Petko.pregled();
	Trpe.pregled();
	cout << "Deposit od 1000 den na smetkata na Trpe:\n";
	Trpe.deposit(1000);
	cout << "Novo saldo: " << Trpe.getSaldo() << endl;
	cout << "Podiganje na 4200 den od smetkata na Petko:\n";
	Petko.podiganje(4200);
	cout << "Saldoto na Petko e: " << Petko.getSaldo() << endl;
	cout << "Podiganje na 4200 den od smetkata na Trpe:\n";
	Trpe.podiganje(4200);
	Trpe.pregled();
	return 0;
}
