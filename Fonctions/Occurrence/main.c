#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLONNE 100
#define LIGNE 100




void remplirTab(int tab[LIGNE][COLONNE]) {

	for (int ligne = 0; ligne < LIGNE; ligne++) {

		for (int colonne = 0; colonne < COLONNE; colonne++) {
			tab[ligne][colonne] = rangcolRand(0, 20);
		}
	}
}

int main()
{
	int notes[LIGNE][COLONNE];
	//remplirTab(notes);
	srand((unsigned int)time(NULL));
	char caractere =  rand() % 26 + 'a'); // ou +'a' pour les minuscules
	return;
}