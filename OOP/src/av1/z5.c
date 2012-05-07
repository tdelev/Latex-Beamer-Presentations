#include<stdio.h>

typedef struct grad {
	char ime[30];
	long brZiteli;
} grad;

typedef struct pretsedatel {
	char ime[20];
	char prezime[20];
	char partija[20];
} pret;

typedef struct drzava {
	char ime[30];
	pret pretsedatel;
	long brZiteli;
	grad glaven;
} drzava;

int main() {
	drzava d[20];
	int n, i, maxi, max;
	printf("Vnesete broj na drzavi:\n");
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		printf("Drzava: ");
		scanf("%s", &d[i].ime);
		printf("Pretsedatel:\n");
		printf("Ime: ");
		scanf("%s", &d[i].pretsedatel.ime);
		printf("Prezime: ");
		scanf("%s", &d[i].pretsedatel.prezime);
		printf("Partija: ");
		scanf("%s", &d[i].pretsedatel.partija);
		printf("Broj na ziteli: ");
		scanf("%d", &d[i].brZiteli);
		printf("Glaven grad: ");
		scanf("%s", &d[i].glaven.ime);
		printf("Ziteli vo gradot: ");
		scanf("%d", &d[i].glaven.brZiteli);
	}
	maxi = 0;
	max = d[maxi].glaven.brZiteli;
	for (i = 0; i < n; ++i)
		if (d[i].glaven.brZiteli > max) {
			max = d[i].glaven.brZiteli;
			maxi = i;
		}
	printf(
			"Imeto na pretsedatelot na drzavata so najgolem glaven grad e: %s %s\n",
			d[maxi].pretsedatel.ime, d[maxi].pretsedatel.prezime);
	return 0;
}
