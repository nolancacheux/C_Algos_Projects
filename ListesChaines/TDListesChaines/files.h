
#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

#define FILESIZE 5

// implémentation des Files avec des tableaux dynamiques
typedef struct SLLQueue {
	struct Liste* list;
	int first;// index of the first element in the array
	int last;// index of the last element in the array
	int queueMaxSize;   // maximum number of elements in the Queue
	int queueNbElemt;// current count of elements in the Queue
} SLLQueue;

void SLLNewQueue(SLLQueue** queue, int initialQueueSize);

// teste si la file est vide
int SLLisQueueEmpty(SLLQueue* queue);

// teste si la file est pleine
int SLLisQueueFull(SLLQueue* queue);

// ajoute un élément dans la file
int SLLqueue(SLLQueue* queue, int value);

// sort un élément de la file
int SLLdeQueue(SLLQueue* queue, int* value);