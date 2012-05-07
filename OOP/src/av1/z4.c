#include <stdio.h>
#include <string.h>

struct kandidat {
	char ime[15];
	char prezime[20];
	int index;
	int bodovi;
};

void norm(char *s) {
	//Prva bukva golema, ostanatite mali
	*s = toupper(*s);
	while (*(++s) != '\0')
		*s = tolower(*s);
}

void sort(struct kandidat a[], int n) {
	int i, j;
	struct kandidat s;
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j].bodovi < a[j + 1].bodovi) {
				s = a[j];
				a[j] = a[j + 1];
				a[j + 1] = s;
			}
}

int main() {
	struct kandidat st[50];
	int i, n;
	printf("Vnesete broj na studenti: ");
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		printf("Nov student:\n");
		printf("Ime: ");
		scanf("%s", &st[i].ime);
		printf("Prezime: ");
		scanf("%s", &st[i].prezime);
		printf("Indeks: ");
		scanf("%d", &st[i].index);
		printf("Poeni (z1 z2 z3 z4): ");
		int j, zadaca;
		st[i].bodovi = 0;
		for(j = 0; j < 4; j++) {
			scanf("%d", &zadaca);
			st[i].bodovi += zadaca;
		}
		norm(st[i].ime);
		norm(st[i].prezime);
	}
	sort(st, n);
	for (i = 0; i < n; i++) {
		printf("%d. %s %s\t%d\t%d\n", i + 1, st[i].ime, st[i].prezime, st[i].index, st[i].bodovi);
	}
	return 0;
}

