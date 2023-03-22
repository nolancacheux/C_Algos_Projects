


#define FILESIZE 5

// implémentation des Files avec des tableaux dynamiques
typedef struct Queue{
	int*tab;// Pointer towards dynamically allocated array
	int first;// index of the first element in the array
	int last;// index of the last element in the array
	int queueMaxSize;   // maximum number of elements in the Queue
	int queueNbElemt;// current count of elements in the Queue
} Queue;

void NewQueue(Queue**queue, int initialQueueSize);

// teste si la file est vide
bool isQueueEmpty(Queue*queue);

// teste si la file est pleine
bool isQueueFull(Queue*queue);

// ajoute un élément dans la file
int queue(Queue*queue, int value);

// sort un élément de la file
int deQueue(Queue*queue, int*value);