#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "filestab.h"

void NewQueue(Queue ** queue, int initialQueueSize) { 

	*queue = (Queue*)malloc(sizeof(Queue)); 
	if (*queue != NULL) { 
		(*queue)->tab = (int*)malloc(sizeof(int) * initialQueueSize);
		
		if (((*queue)->tab) != NULL) { 
			for (int i = 0; i < initialQueueSize; i++) {
				(*queue)->tab[i] = 0;
			}
			(*queue)->first = -1;
			(*queue)->last = -1;
			(*queue)->queueNbElemt = 0;
			(*queue)->queueMaxSize = initialQueueSize; 
		} 
		else { 
			free(*queue); 
			*queue = NULL;
		} 
	} 
}

bool isQueueEmpty(Queue* queue) { 
	return(queue->queueNbElemt == 0);
}

bool isQueueFull(Queue * queue) {
	return(queue->queueNbElemt == queue->queueMaxSize);
}


// Ajout d'un élément dans la file

int queue(Queue *queue, int value) { // gestion de la file en tableau circulaire
	// si la file est pleine, on ne fait rien

	if(isQueueFull(queue)) return(EXIT_FAILURE);

	// si la file est vide
	// écriture du premier élément dans la file
	if(isQueueEmpty(queue)) {
		queue->first = 0;
		queue->last = 0;
		queue->queueNbElemt = 1;
		queue->tab[queue->last] = value;
	}

	else{
		// calculer la position du prochain élément et le stocker
		queue->last = ((queue->last)+1) % FILESIZE;
		
		// écriture d'un élément dans la file
		queue->queueNbElemt++;
		queue->tab[queue->last] = value;
		
		
	}
	printf("\nL'élement %d a été ajouté à la file.\n", value);
	return(EXIT_SUCCESS);
}


// Sortie d'un élément de la file

int deQueue(Queue *queue, int *value) {

	// COMPLETER ICI
	*value = queue->tab[queue->first];
	printf("\nL'élement %d a été supprimé de la file.\n", *value);
	queue->tab[queue->first] = 0;
	queue->first++;
	queue->queueNbElemt--;

	
	return(EXIT_SUCCESS);
}

void affichage(Queue *queue, int initialQueueSize) {
	printf("\n Affichage de la file actuelle : ");
	for (int i = 0; i < initialQueueSize; i++) {
		printf("%d ", queue->tab[i]);
	}
	printf("\n\n");
}