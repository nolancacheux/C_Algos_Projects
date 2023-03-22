
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "snakeGame.h"
#include "ConsoleTools.h"
#include <windows.h>


void color(int t, int f)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, f * 16 + t);
}

/*
t: couleur de ton char
f : couleur du fond

0 : noir
1 : bleu foncé
2 : vert
3 : bleu - gris
4 : marron
5 : pourpre
6 : kaki
7 : gris clair
8 : gris
9 : bleu
10 : vert fluo
11 : turquoise
12 : rouge
13 : rose fluo
14 : jaune fluo
15 : blanc
*/

void initGrille(char* tab) {

	for (int y = 0; y < SIZEY; y++) {
		for (int x = 0; x < SIZEX; x++) {
			*(tab + (y * SIZEX + x)) = space;
		}
	}
	return;
}

void creationCorps(char* tab) {

	int x = 3;
	for (int y = 0; y < TAILLECORPS; y++) {
		*(tab + y * SIZEX + x) = corps;
	}
	return;
}

void creationPomme(char* tab) {

	int x, y;

	for (int i = 0; i < 5; i++) {
		do {
			x = rangedRand(0, SIZEX);
			y = rangedRand(0, SIZEY);
		} while ((x == 3) && (y <= TAILLECORPS));
		*(tab + y * SIZEX + x) = pomme;
	}
}


void afficheGrille(char* tab) {

	hideCursor();
	moveCursor(0, 0);
	for (int y = 0; y < SIZEY; y++) {
		for (int x = 0; x < SIZEX; x++) {
			moveCursor(x, y);
			if (*(tab + (y * SIZEX + x)) == pomme) { color(12, 1); }
			if (*(tab + (y * SIZEX + x)) == space) { color(0, 1); }
			if (*(tab + (y * SIZEX + x)) == corps) { color(10, 1); }
			plotChar(*(tab + (y * SIZEX + x)));
			color(15, 0);
		}
	}
	return;

}
