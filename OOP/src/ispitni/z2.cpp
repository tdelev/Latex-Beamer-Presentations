#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
	char ime[100];
	char reziser[50];
	int *rejtinzi;
	int n;
	int gledanja;
public:
	Film() {
		rejtinzi = 0;
	}
	Film(char *i, char *r, int *rej, int nn, int g) {
		strcpy(ime, i);
		strcpy(reziser, r);
		n = nn;
		rejtinzi = new int[n];
		for (int i = 0; i < n; i++) {
			rejtinzi[i] = rej[i];
		}
		gledanja = g;
	}
	Film(const Film &f) {
		strcpy(ime, f.ime);
		strcpy(reziser, f.reziser);
		n = f.n;
		rejtinzi = new int[n];
		for (int i = 0; i < n; i++) {
			rejtinzi[i] = f.rejtinzi[i];
		}
		gledanja = f.gledanja;
	}
	Film& operator=(const Film &f) {
		if (this == &f)
			return *this;
		strcpy(ime, f.ime);
		strcpy(reziser, f.reziser);
		n = f.n;
		delete[] rejtinzi;
		rejtinzi = new int[n];
		for (int i = 0; i < n; i++) {
			rejtinzi[i] = f.rejtinzi[i];
		}
		gledanja = f.gledanja;
	}
	~Film() {
		delete[] rejtinzi;
	}
	float rejting() const {
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += rejtinzi[i];
		}
		return s * 1.0 / n;
	}

	Film& operator++() {
		gledanja++;
		return *this;
	}

	Film operator++(int) {
		Film res(*this);
		gledanja++;
		return res;
	}

	bool operator<(Film &f) {
		return rejting() < f.rejting();
	}

	bool operator>(Film &f) {
		return rejting() > f.rejting();
	}

	bool operator==(Film &f) {
		return strcmp(ime, f.ime) == 0;
	}

	bool operator!=(Film &f) {
		return !(*this == f);
	}

	friend ostream& operator<<(ostream &out, const Film &f) {
		out << f.ime << endl;
		out << f.reziser << endl;
		out << f.rejting() << endl;
		out << f.gledanja << endl;
		return out;
	}

	Film& operator+=(int rejting) {
		int *temp = rejtinzi;
		rejtinzi = new int[n + 1];
		for (int i = 0; i < n; i++) {
			rejtinzi[i] = temp[i];
		}
		rejtinzi[n] = rejting;
		n++;
		return *this;
	}

};

void topFilmovi(Film f[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (f[j] < f[j + 1]) {
				Film temp = f[j];
				f[j] = f[j + 1];
				f[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n && i < 10; i++) {
		cout << f[i] << endl;
	}
}
int main() {
	int r1[] = { 10, 6, 7, 8 };
	Film f1("Inception", "Christopher Nolan", r1, 4, 10);
	int r2[] = { 10, 6, 7, 8, 10, 9 };
	Film f2("Departed", "Martin Scorsese", r2, 6, 20);
	cout << f1;
	cout << f2;
	if (f1 == f2) {
		cout << "Filmovite se isti." << endl;
	} else {
		cout << "Filmovite ne se isti." << endl;
	}
	f2++;
	f1 += 10;
	Film f[] = { f1, f2 };
	topFilmovi(f, 2);
	return 0;
}

