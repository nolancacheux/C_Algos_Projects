#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "GameofLife.h"
#include "ConsoleTools.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char** argv) {

	int nbLives = 0;
	char c = 'B';
	int fin = 0;
	int repeat = 0;

	openConsole();

	char* buffer = (char*)malloc(LifeSizeX * LifeSizeY);

	if (buffer != NULL) {
		Gen1 = buffer;
		char* buffer2 = (char*)malloc(LifeSizeX * LifeSizeY);
		if (buffer2 != NULL) {
			Gen2 = buffer2;
		}
		else {
			free(Gen2);
			return 0;
		}

	}
	else { 
		free(Gen1);
		return 0;
	}

	do{
		
		moveCursor(10, 10);

		plotChar('*');

		moveCursor(15, 0); // ramène le curseur en colonne 0

		do {
			nbLives = initLife(Gen1, LifeSizeX, LifeSizeY);
		} while (nbLives == 0);

		do {
			++repeat;

			displayGen(Gen1, LifeSizeX, LifeSizeY);

			nbLives = nextGen(Gen1, Gen2, LifeSizeX, LifeSizeY);

			Sleep(50);

			displayGen(Gen2, LifeSizeX, LifeSizeY);

			if (nbLives != 0) {
				nbLives = nextGen(Gen2, Gen1, LifeSizeX, LifeSizeY);
			}
		} 
		while ((nbLives != 0) && ((char)c != 'A')&&(repeat<30));

		printf("\n A : Quitter le jeu \n B : Nouvelle vie \n");

		do {
			c = _getch();
		} while (((char)c != 'A') && ((char)c != 'B'));

		if ((char)c == 'A') {
			fin = 1;
		}
		else {
			fin = 0;
			repeat = 0;
		}
	}while ((fin == 0) && (repeat <= 30));

	showCursor();
	closeConsole();
}

