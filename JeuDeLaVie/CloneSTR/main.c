#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


char *cloneStr(char* chaine) {

	char *buffer;
	int tailleChaine = strlen(chaine);
	int i = 0;

	buffer =(char *) malloc(strlen(chaine)+1);// +1 pour le fat chain, adresse du début du stockage.
	if (buffer != NULL) {
		do {
			*(buffer+i) = *(chaine++);
			i++;
		} while (*chaine != '\0');
	}
	return buffer;
}

int main() {
	setlocale(LC_ALL, "fr-FR");
	char chaine[20];
	printf("Entre un mot : ");
	scanf_s("%s", chaine, (unsigned)_countof(chaine));

	printf("Le mot %s ; le mot cloné : %s\n", chaine, cloneStr(chaine));
	return 0;
}