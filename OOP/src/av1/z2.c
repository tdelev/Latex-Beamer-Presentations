#include<stdio.h>

struct vektor {
	float x;
	float y;
	float z;
};

typedef struct vektor vektor;

float skalaren_proizvod(vektor v1, vektor v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vektor vektorski_proizvod(vektor v1, vektor v2) {
	vektor v;
	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return v;
}

int main() {
	vektor v1 = { 2, 4, 6 };
	vektor v2 = { 3, 5, 9 };
	vektor v;
	v = vektorski_proizvod(v1, v2);
	printf("v1 * v2 = %.2f\n", skalaren_proizvod(v1, v2));
	printf("v1 x v2 = [%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
	return 0;
}
