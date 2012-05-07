#include<iostream>
#include<cstring>
using namespace std;

class Fotoaparat {
private:
	char model[30];
	double osnCena;
	int rezolucija;
public:
	Fotoaparat(char const *m = "", double o = 0.0, int r = 0) {
		strncpy(model, m, 29);
		model[29] = '\0';
		osnCena = o;
		rezolucija = r;
	}
	int getRezolucija() const {
		return rezolucija;
	}
	int getOsnCena() const {
		return osnCena;
	}
	virtual double cena()= 0;
	friend bool operator<(Fotoaparat &f1, Fotoaparat &f2) {
		return f1.cena() < f2.cena();
	}
	friend ostream& operator<<(ostream& o, const Fotoaparat& f) {
		o << "Model:" << f.model << endl;
		o << "Osnovna cena:" << f.osnCena << endl;
		o << "Rezolucija:" << f.rezolucija << endl;
		return o;
	}
};
class DSLR: public Fotoaparat {
private:
	char vidObjektiv[20];
	double cenaObjektiv;

public:
	DSLR(char const *m = "", double o = 0.0, int r = 0, char const *vo = "",
			double co = 0.0) :
		Fotoaparat(m, o, r), cenaObjektiv(co) {
		strncpy(vidObjektiv, vo, 19);
		vidObjektiv[19] = '\0';
	}
	friend ostream& operator<<(ostream& o, const DSLR& f) {
		o << (Fotoaparat&) f;
		o << "Vid na objektivot:" << f.vidObjektiv << endl;
		o << "Cena na objektivot:" << f.cenaObjektiv << endl;
		return o;
	}
	double cena() {
		if (getRezolucija() >= 15)
			return getOsnCena() * 1.15 + cenaObjektiv;
		return getOsnCena() + cenaObjektiv;
	}
};
class Kompakten: public Fotoaparat {
private:
	bool zum;
public:
	Kompakten(char const *m = "", double o = 0.0, int r = 0, bool z = true) :
		Fotoaparat(m, o, r), zum(z) {
	}
	friend ostream& operator<<(ostream& o, const Kompakten& k) {
		o << (Fotoaparat&) k;
		o << "Zum: ";
		if (k.zum)
			o << "opticki" << endl;
		else
			o << "digitalen" << endl;
		return o;
	}
	double cena() {
		double tmp = getOsnCena();
		if (getRezolucija() >= 10)
			tmp *= 1.12;
		if (zum)
			tmp *= 1.1;
		return tmp;
	}
};
int main() {
	return 0;
}
