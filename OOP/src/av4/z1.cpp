#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
private:
	int *elem;//pokazuvac kon poleto
	int count;//kolku elementi ima
	int size;//kolku elementi moze da ima
public:
	Array(int size = 10) {
		this->size = size;
		count = 0;
		elem = new int[size];
	}
	Array(const Array &ob) {
		size = ob.size;
		count = ob.count;
		elem = new int[size];
		for (int i = 0; i < count; i++)
			elem[i] = ob.elem[i];
	}
	Array &operator=(Array &ob) {
		// Se sprechuva samododeluvanje
		if (this != &ob) {
			size = ob.size;
			count = ob.count;
			elem = new int[size];
			for (int i = 0; i < count; i++)
				elem[i] = ob.elem[i];
		}
		return *this;
	}
	Array &operator+=(int el) {
		//ako ima kapacite seuste  dodadi go clenot
		if (count < size) {
			elem[count++] = el;
		} else { //ako kapacitetot e popolnet
			int *tmp = new int[size * 2];//alociraj dvojno poveke memorija (100%)
			for (int i = 0; i < count; i++)
				tmp[i] = elem[i];
			tmp[count++] = el;
			size *= 2;
			delete[] elem;
			elem = tmp;
		}
		return *this;
	}
	~Array() {
		delete[] elem;
	}
	int &operator[](int i) {
		if (i >= 0 && i < count)
			return elem[i];
		else {
			cout << "Nadvor od opseg" << endl;
			exit(-1);
		}

	}
	int getCapacity() {
		return size;
	}
	int getCount() {
		return count;
	}
};
int main() {
	Array pole;
	int n, tmp;
	cout << "Kolku elementi ke vnesete?" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		pole += tmp;
	}
	for (int i = 0; i < pole.getCount(); i++)
		cout << pole[i] << "\t";
	cout << endl << pole.getCapacity();
	return 0;
}
