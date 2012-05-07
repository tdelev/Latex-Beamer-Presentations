#include <iostream>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point(int xx = 0, int yy = 0) {
        cout << "Constructor Point" << endl;
		x = xx;
		y = yy;
	}
    ~Point() { cout << "Destructor Point" << endl; }
	int getX() { return x; }
	int getY() { return y; }
	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy;	}
};
class Point3D : public Point {
private:
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y) {
        cout << "Constructor Point3D" << endl;
		this->z = z;
	}
    ~Point3D() { cout << "Destructor Point3D" << endl; }
	int getZ() { return z; }
	void setZ(int zz) { z = zz; }
};
int main() {
    Point3D p(1, 2, 4);
	return 0;
}
