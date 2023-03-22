
#include <stdio.h>
#include <stdlib.h>
#include "piles.h"
#include "listes.h"

#define STACKOVERFLOW -1

// cr�ation d'une pile 
// stack : nom de la pile
// initialStackSize: taille de la pile en nombre de valeurs empilables
void SLLNewStack(SLLStack** stack, int initialStackSize) {

	// allocation de la structure pile
	*stack = (SLLStack*)malloc(sizeof(SLLStack));


	if (*stack != NULL) {

		// allocation du tableau de donn�es
		(*stack)->list = NewLinkedList();

		if (((*stack)->list) != NULL) {// initialisation des param�tres de la pile
			(*stack)->stackMaxSize = initialStackSize;
			(*stack)->stackNbElemts = 0;
		}

		else {// la pile n'a pas pu �tre cr��e, stack vaut NULL
			free(*stack);
			*stack = NULL;
		}

	}
}

// teste si la piles est pleine
int SLLisStackFull(SLLStack* stack) {
	if ((stack->stackNbElemts >= stack->stackMaxSize)) return 1;
	return 0;
};

// teste si la pile est vide
int  SLLisStackEmpty(SLLStack* stack) {
	if (stack->stackNbElemts == 0) return 1;
	return 0;
}

// pousse une valeur sur la pile
int SLLpush(SLLStack* stack, int value) {

	if (SLLisStackFull(stack) == 0) {
		AddNewElemToSingleLinkedList(stack->list, NewLinkedListItem(value));
		stack->stackNbElemts++;
		return(0);
	}
	else {
		return(STACKOVERFLOW);
	}
}

// r�cup�re la valeur au sommet de la pile (la retire)
int SLLpull(SLLStack* stack, int* value) {

	if (SLLisStackEmpty(stack) == 0) {
		RemoveElemFromSingleLinkedList(stack->list, NewLinkedListItem(*value));
		stack->stackNbElemts--;
		return(EXIT_SUCCESS);
	}
	return(EXIT_FAILURE);
}

// r�cup�re la valeur au sommet de la pile sans la retirer
int SLLpeek(SLLStack* stack, int* value) {
	if (SLLisStackEmpty(stack)==0) {
		*value = stack->list->fin;
		return(EXIT_SUCCESS);
	}
	return(EXIT_FAILURE);
}
