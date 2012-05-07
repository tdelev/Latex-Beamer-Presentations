#include <stdio.h>

typedef struct kompleksen {
	float realen;
	float imag;
} kompl;

kompl soberi(kompl a, kompl b) {
	kompl c = a;
	c.realen += b.realen;
	c.imag += b.imag;
	return c;
}

kompl odzemi(kompl *pok1, kompl *pok2) {
	kompl c = *pok1;
	c.realen -= (*pok2).realen;
	c.imag -= (*pok2).imag;
	return c;
}

void mnozi(kompl a, kompl b, kompl *c) {
	c->realen = a.realen * b.realen - a.imag * b.imag;
	c->imag = a.realen * b.imag + a.imag * b.realen;
}

void pecati(kompl *pok) {
	printf("%.2f", pok->realen);
	if (pok->imag >= 0)
		printf("+j%.2f\n", pok->imag);
	else
		printf("-j%.2f\n", abs(pok->imag));
}

int main() {
	kompl a, b, c;
	printf("Vnesete dva kompleksni broevi:\n");
	printf("Prv broj:\n");
	printf("Realen: ");
	scanf("%f", &a.realen);
	printf("Imaginaren: ");
	scanf("%f", &a.imag);
	printf("Prv broj:\n");
	printf("Realen: ");
	scanf("%f", &b.realen);
	printf("Imaginaren: ");
	scanf("%f", &b.imag);
	printf("Gi vnesovte broevite:\n");
	pecati(&a);
	pecati(&b);
	printf("Nivniot zbir e:\n");
	c = soberi(a, b);
	pecati(&c);
	printf("Nivnata razlika e:\n");
	c = odzemi(&a, &b);
	pecati(&c);
	printf("Nivniot proizvod e:\n");
	mnozi(a, b, &c);
	pecati(&c);
	return 0;
}
