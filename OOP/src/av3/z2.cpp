#include <iostream>
#include <string.h>
using namespace std;
enum pozicija {
	vraboten, direktor, sef
};
class Person {
private:
	// podatoci
	char name[100];
	int plata;
	pozicija pos;
public:
	// konstruktori
	Person() {
	}

	Person(char *n, int s, pozicija p) {
		strcpy(name, n);
		plata = s;
		pos = p;
	}
	//destruktor
	~Person() {
	}
	// Interfejs funkcii
	void setName(char const *n) {
		strcpy(name, n);
	}
	void setPlata(int p) {
		plata = p;
	}
	void setPosition(pozicija p) {
		pos = p;
	}
	char const *getName(void) {
		return name;
	}
	int const getPlata(void) {
		return plata;
	}
	pozicija const getPosition(void) {
		return pos;
	}
};

void Sort(Person a[], int n);

int main() {
	Person vraboteni[100];
	float plata;
	int n, pos;
	char name[100];
	cout << "Vnesi broj na vraboteni (max 100): ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Vnesi ime: ";
		cin >> name;
		cout << "Vnesi plata: ";
		cin >> plata;
		cout << "Vnesi pozicija (0 - vraboten, 1 - direktor, 2 - shef): ";
		cin >> pos;
		vraboteni[i].setName(name);
		vraboteni[i].setPlata(plata);
		vraboteni[i].setPosition((pozicija) pos);
	}
	Sort(vraboteni, n);
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << vraboteni[i].getName() << "\t"
				<< vraboteni[i].getPlata() << "\t"
				<< vraboteni[i].getPosition() << endl;
	}
	return 0;
}
void Sort(Person a[], int n) {
	int i, j;
	Person p;
	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (a[i].getPlata() < a[j].getPlata()) {
				p = a[j];
				a[j] = a[i];
				a[i] = p;
			}
}
