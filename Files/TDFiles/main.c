#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filestab.h"
#include <locale.h>

int main() {

	setlocale(LC_ALL, "fr-FR");
	Queue *file = NULL;

	
	int init = 0;
	int *elementSupp = &init;

	NewQueue(&file, FILESIZE);

	affichage(file, FILESIZE);

	queue(file,1);
	queue(file, 2);
	queue(file, 3);

	affichage(file, FILESIZE);

	deQueue(file, elementSupp);
	affichage(file, FILESIZE);

	queue(file, 4);
	affichage(file, FILESIZE);

	queue(file, 5);
	affichage(file, FILESIZE);

	queue(file, 6);
	affichage(file, FILESIZE);

	deQueue(file, elementSupp);
	affichage(file, FILESIZE);


	return(EXIT_SUCCESS);
}