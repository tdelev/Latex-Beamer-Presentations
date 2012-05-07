#include <iostream>
using namespace std;
class Triagolnik {
private:
	int a, b, c;
public:
	Triagolnik(int x, int y, int z) {
		a = x;
		b = y;
		c = z;
	}
	~Triagolnik() {
	}
	int perimetar() {
		return a + b + c;
	}
};
int main() {
	int p, q, r;
	cout << "Vnesi tri strani:" << endl;
	cin >> p >> q >> r;
	Triagolnik t(p, q, r);
	cout << "Perimetar na triagolnikot:" << t.perimetar() << endl;
	return 0;
}
