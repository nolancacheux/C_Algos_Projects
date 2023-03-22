#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"


int main(int argc, char** argv) {

	setlocale(LC_ALL, "FR");
	openConsole();

	int nbPommes = 5;
	int tailleCorpsActuel = 5;

	char* buffer = (char*)malloc(SIZEX * SIZEY);

	if (buffer != NULL) {
		grille = buffer;
	}
	else {
		free(grille);
		return 0;
	}

	POSITION snake[TAILLECORPSMAX] = { {3,0},{3,1},{3,2},{3,3},{3,4},{0,0},{0,0},{0,0},{0,0},{0,0} };

	//Après test snake vers le bas par exemple , on aura :
	//POSITION snake[TAILLECORPSMAX] = { {3,1},{3,2},{3,3},{3,4},{3,5},{0,0},{0,0},{0,0},{0,0},{0,0} };

	//POSITION tmpTab[TAILLECORPSMAX] = { {3,0},{3,1},{3,2},{3,3},{3,4},{0,0},{0,0},{0,0},{0,0},{0,0} };

	initGrille(grille);
	creationCorps(grille);
	creationPomme(grille);

	while (nbPommes > 0){

		color(15, 0);
		afficheGrille(grille);
		
		int direction;
		do {
			direction = rangedRand(0, 4);
			// 0 en haut , 1 en bas , 2 à droite , 3 à gauche.
		} while (((direction == 0) && (snake[tailleCorpsActuel-1].Y < 1)) || ((direction == 1) && (snake[tailleCorpsActuel -1].Y +2 > SIZEY)) ||((direction == 2) && (snake[tailleCorpsActuel -1].X + 1  > SIZEX)) || ((direction == 3) && (snake[tailleCorpsActuel -1].X < 1)));


		for (int y = 0; y < SIZEY; y++) {
			for (int x = 0; x < SIZEX; x++) {
				if ((x == snake[0].X) && (y == snake[0].Y)) {
					*(grille + (y * SIZEX + x)) = space;
				}
			}
		}
		switch (direction)
		{
		case 0: 
			--snake[tailleCorpsActuel - 1].Y;
			break;

		case 1: 
			++snake[tailleCorpsActuel - 1].Y;
			break;

		case 2: 
			++snake[tailleCorpsActuel - 1].X;
			break;

		case 3:

			--snake[tailleCorpsActuel - 1].X;
			break;

		default: 
			break;

		}
		for (int i = 0; i < tailleCorpsActuel - 1; i++) {
			snake[i].X = snake[i + 1].X;
			snake[i].Y = snake[i + 1].Y;
		}

		for (int y = 0; y < SIZEY; y++) {
			for (int x = 0; x < SIZEX; x++) {
				for (int z = 0; z < tailleCorpsActuel-1; z++) {
					if ((x == snake[z].X) && (y == snake[z].Y)) {
						*(grille + (y * SIZEX + x)) = corps;
					}
				}
				if ((*(grille + (y * SIZEX + x)) == pomme) && ((x == snake[tailleCorpsActuel - 1].X) && (y == snake[tailleCorpsActuel - 1].Y))) {
					--nbPommes;
					++tailleCorpsActuel;
					*(grille + (y * SIZEX + x)) = space;
					snake[tailleCorpsActuel - 1].X = x;
					snake[tailleCorpsActuel - 1].Y = y;
				}
			}
		}
		if ((nbPommes == 0)) {
			afficheGrille(grille);
			color(15, 0);
			printf("\n \n Merci d'avoir joué à la chenille ! Bye !     \n\n\n");
		}
	}
	
	showCursor();
	closeConsole();

	printf("\n\n\n\n\n");
	return EXIT_SUCCESS;
}