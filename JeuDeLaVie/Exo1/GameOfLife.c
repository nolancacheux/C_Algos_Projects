#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "GameofLife.h"
#include "ConsoleTools.h"
#include <stdbool.h>



// initLife initialise un tableau, d'abord complètement avec des morts puis place les êtres en vie et renvoie leur nombre
int initLife(char* life, int sizeX, int sizeY) {


	COORD LifePos;

	/*COORD getConsoleSize() {
		COORD Size;

		Size.X = csbiInfo.dwSize.X;
		Size.Y = csbiInfo.dwSize.Y;
		return(Size);
	}*/
	int nbLives = NBLIVES;
	int n = nbLives;
	for (int l = 0; l < sizeY; l++) {
		for (int c = 0; c < sizeX; c++) {
			*(life + (l * sizeX + c)) = Dead;
		}
	}
	while (n > 0) {
		n=n-1;
		LifePos.X = rangedRand(0, sizeX);
		LifePos.Y = rangedRand(0, sizeY);
		*(life + (LifePos.Y * LifeSizeX + LifePos.X)) = Alive;

	}
	return (nbLives);
}

// displayGen Affiche une génération sur la console
void displayGen(char* life, int sizeX, int sizeY) {

	hideCursor();
	moveCursor(0, 0);
	for (int l = 0; l < sizeY; l++) {
		for (int c = 0; c < sizeX; c++) {
			moveCursor(c, l);
			plotChar(*(life + (l * sizeX + c)));
		}
	}
	return;
	/*int lifesize = sizeX * sizeY;

	for (int i = 0; i < lifesize; i++) {
		printf("%s", *(life + i));
	}
	return 0;*/
}

// countNeighbours dénombre les êtres en vie autour de la postion (posX, posY) dans le tableau Life (une génération)
int countNeighbours(char* life, int sizeX, int sizeY, int posX, int posY) {

	int nbVoisinFinal = 0;
	int nbvoisin = 0;
	int col, ligne;
	for (ligne = posY - 1; ligne <= posY + 1; ligne++) {
		for (col = posX - 1; col <= posX + 1; col++) {
			nbvoisin++;
			if ((ligne >= 0) && (ligne < sizeY) && (col >= 0) && (col < sizeX)){
				if ((*(life + (ligne * sizeX + col)) == Alive) && !((col == posX) && (ligne == posY))) {
					nbVoisinFinal++;
				}
			}
		}
	}
	return (nbVoisinFinal);

	/*int NombreDeVoisinsVivants = 0;

	if ((*(life + sizeY * (posX - 1) + (posY - 1)) == '*') && (posX != 0) && (posY != 0));
		NombreDeVoisinsVivants++;
	if (( * (life + sizeY * (posX)+(posY - 1)) == '*') && (posY != 0));
		NombreDeVoisinsVivants++;
	if (( * (life + sizeY * (posX + 1) + (posY - 1)) == '*') && (posY != 0));
		NombreDeVoisinsVivants++;
	if ( *(life + sizeY * (posX)+(posY)) == "*");
		NombreDeVoisinsVivants++;
	if (*(life + sizeY * (posX + 1) + (posY)) == "*");
		NombreDeVoisinsVivants++;
	if ((*(life + sizeY * (posX - 1) + (posY + 1)) == "*") && (posX != 0));
		NombreDeVoisinsVivants++;
	if (*(life + sizeY * (posX)+(posY + 1)) == "*");
		NombreDeVoisinsVivants++;
	if (*(life + sizeY * (posX + 1) + (posY + 1)) == "*");
		NombreDeVoisinsVivants++;

	return(NombreDeVoisinsVivants);*/

}


// Détermine s'il y a une naissance ou une disparition en fonction du nombre de voisins et de l'état actuel
char lifeState(int nbNeighbours, char state) {
	
	/*if ((nbNeighbours==2)&&(state == Alive)) {return (Alive);}
	else { 
		if (nbNeighbours != 3) { return(Dead); }
	}
	return(Alive); */
	switch (nbNeighbours) {
	case 0:
	case 1:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		return (Dead);
		break;
	case 2:
		if (state == Alive) {
			return (Alive);
		}
		else {
			return(Dead);
		}
		break;
	case 3:
		return(Alive);
		break;
	default: 
		return (Alive);
		break;

	}
}

// calcul de la génération suivante
int nextGen(char* gen1, char* gen2, int sizeX, int sizeY) {
	int nbLives = 0;// on crée dans gen2 les êtres vivants à partir de l'état du tableau Gen1
	for (int l = 0; l < sizeY; l++) {// les variables letc représentent la position d’une case en (ligne, colonne)
		for (int c = 0; c < sizeX; c++) {
			*(gen2 + (l * sizeX + c)) = lifeState(countNeighbours(gen1, sizeX, sizeY, c, l), *(gen2 + (l * sizeX + c)));
			if (*(gen2 + (l * sizeX + c)) == Alive) nbLives++;
		}
	}
	return(nbLives);
};