#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "files.h"

void SLLNewQueue(SLLQueue** queue, int initialQueueSize) {

	*queue = (SLLQueue*)malloc(sizeof(SLLQueue));
	if (*queue != NULL) {
		(*queue)->list = NewLinkedList();

		if (((*queue)->list) != NULL) {
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

int SLLisQueueEmpty(SLLQueue* queue) {
	if((queue->queueNbElemt == 0)) return 1;
}

int SLLisQueueFull(SLLQueue* queue) {
	if (queue->queueNbElemt == queue->queueMaxSize) return 1;
}


// Ajout d'un �l�ment dans la file

int SLLqueue(SLLQueue* queue, int value) { // gestion de la file en tableau circulaire
	// si la file est pleine, on ne fait rien

	if (SLLisQueueFull(queue)==1) return(EXIT_FAILURE);

	// si la file est vide
	// �criture du premier �l�ment dans la file
	if (SLLisQueueEmpty(queue)==1) {
		queue->first = 0;
		queue->last = 0;
		queue->queueNbElemt = 1;
		AddNewElemToSingleLinkedList(queue->list, NewLinkedListItem(value));
	}

	else {
		// calculer la position du prochain �l�ment et le stocker
		queue->last = ((queue->last) + 1) % FILESIZE;

		// �criture d'un �l�ment dans la file
		queue->queueNbElemt++;
		AddNewElemToSingleLinkedList(queue->list, NewLinkedListItem(value));


	}
	printf("\nL'�lement %d a �t� ajout� � la file.\n", value);
	return(EXIT_SUCCESS);
}


// Sortie d'un �l�ment de la file

int SLLdeQueue(SLLQueue* queue, int* value) {

	RemoveElemFromSingleLinkedList(queue->list, NewLinkedListItem(*value));
	printf("\nL'�lement %d a �t� supprim� de la file.\n",*value);
	queue->first++;
	queue->queueNbElemt--;


	return(EXIT_SUCCESS);
}
