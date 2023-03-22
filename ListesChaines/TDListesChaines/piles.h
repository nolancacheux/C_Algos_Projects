
#include "listes.h"
#include <stdio.h>
#include <stdlib.h>

#define PILESIZE 5

// Pile implémentée à l'aide d'une Single Linked List
typedef struct SLLStack {
	struct Liste* list;
	int stackMaxSize;  // doit-on garder cette propriété ?
	int stackNbElemts; // nb elements actuellement stockés
} SLLStack;

// implémentation avec des listes unilatères (SLL)

void SLLNewStack(SLLStack** stack, int initialStackSize);

int SLLisStackFull(SLLStack* stack);

int SLLisStackEmpty(SLLStack* stack);

int SLLpush(SLLStack* stack, int value);

int SLLpull(SLLStack* stack, int* value);

int SLLpeek(SLLStack* stack, int* value);