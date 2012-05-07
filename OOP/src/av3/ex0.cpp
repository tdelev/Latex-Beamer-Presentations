class Pumpa {
private:
public:
};
int main() {
	int x;
	double d;
	char i[30];
	cout << "Vnesi adresa na benzinskata pumpa: ";
	cin >> i;
	cout << "Vnesi ja kolicinata beznin: ";
	cin >> d;
	Pumpa p(i, d);
	cout << "1. Dodavanje benzin vo pumpata" << endl;
	cout << "2. Zemanje benzin od pumpata" << endl;
	cout << "0. Kraj" << endl;
	while (1) {
		cout << ">";
		cin >> x;
		if (x == 0)
			break;
		else {
			cout << "vnesi litri:";
			cin >> d;
			if (x == 1)
				s.dodajVoPumpata(d);
			else if (x == 2)
				s.odzemiOdPumpata(d);
			cout << "Pumpata " << s.getAdresa() << "ima " << s.getSostojba()
					<< " litri." << endl;
		}
	}
	return 0;
}
