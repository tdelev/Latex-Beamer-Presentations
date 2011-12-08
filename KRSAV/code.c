#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

void trim(char *str) {
	int i;
	while (isspace(str[0])) {
		for (i = 0; str[i] != '\0'; i++)
			str[i] = str[i + 1];
	}
	for (i = strlen(str) - 1; isspace(str[i]); i--)
		;
	str[i + 1] = '\0';
}
void trim1(char *s) {
	char *d = s;
	while (isspace(*s++))
		;
	s--;
	while (*d++ = *s++)
		;
	d--;
	while (isspace(*--d))
		*d = 0;
}
int main() {
	char s[MAX];
	printf("Vnesete string: ");
	gets(s);
	printf("[%s] -> ", s);
	trim1(s);
	printf("[%s]", s);
	return 0;
}
