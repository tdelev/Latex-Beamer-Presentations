#include<stdio.h>

typedef struct tocka2D {
	double x;
	double y;
} tocka2D;

float rastojanie(tocka2D t1, tocka2D t2) {
	return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

typedef struct tocka3D {
	//vasiot kod ovde
} tocka3D;

float rastojanie3D(tocka3D t1, tocka3D t2) {
	//vasiot kod ovde
}

void ista_prava(tocka2D t1, tocka2D t2, tocka2D t3) {
	//vasiot kod ovde
}
int main() {
	tocka2D t1 = { 4.54, -7.35 };
	tocka2D t2 = { -3.76, 10.45 };

	printf("Rastojanieto pomegu tockite t1 i t2 e: %.2f\n", rastojanie(t1, t2));
	return 0;
}
