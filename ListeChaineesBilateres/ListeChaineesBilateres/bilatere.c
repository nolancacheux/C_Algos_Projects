
#include <stdio.h>
#include <stdlib.h>
#include "bilatere.h"



// cr�ation d'une nouvelle liste cha�n�e bilat�re vide
// cette fonction renvoie un pointeur sur la nouvelle structure liste cha�n�e bilat�re vide

DoubleLinkedList* newDoubleLinkedList(){

	DoubleLinkedList* tmp;
	tmp = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	if (tmp != NULL) {
		tmp->premier = NULL;
		tmp->fin = NULL;
		tmp->taille = 0;
	}
	return tmp;
}

// instanciation (cr�ation) d'un �l�ment (maillon) � ins�rer dans une liste cha�n�e bilat�re 
// avec stockage de la donn�e value dans l'�l�ment de liste

DoubleLinkedListElem* NewDoubleLinkedListItem(int value) {

	DoubleLinkedListElem* tmp;
	tmp = (DoubleLinkedListElem*)malloc(sizeof(DoubleLinkedListElem));
	if (tmp != NULL) {
		tmp->elt = value;
		tmp->suivant = NULL;
		tmp->precedent = NULL;
	}
	return(tmp);
}

// affichage des �l�ments d'une liste cha�n�e bilat�re en commen�ant par la t�te

int DisplayDoubleList(DoubleLinkedList* liste) {
	if (liste == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = liste->premier;
	int i = 1;
	while (actuel != NULL) {
		printf("%d <-> ", actuel->elt);
		actuel = actuel->suivant;
		i++;
	}
	printf("NULL\n");
	return 0;

}

// affichage des �l�ments d'une liste cha�n�e bilat�re en commen�ant par la queue (Reverse)
int RevDisplayDoubleList(DoubleLinkedList* list) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->fin;
	int i = 1;
	printf("NULL-> ");
	while (actuel != NULL) {
		printf("%d -> ", actuel->elt);
		actuel = actuel->precedent;
		i++;
	}
	printf("\n");
	return 0;
}

// insertion d'un �l�ment en queue de liste cha�n�e bilat�re
int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {

	if (list == NULL || newItem == NULL || newItem->suivant != NULL)
		return 0;
	// si la liste est vide
	if (list->fin == NULL) {
		list->fin = newItem;
		list->premier = newItem;
		list->taille = 1;
	}
	else {// on ajoute l'�l�ment en fin
		list->fin->precedent = list->fin;
		list->fin->suivant = newItem;
		list->fin = newItem;
		list->taille += 1;
	}
	return 1;
}

// insertion d'un �l�ment en t�te de liste cha�n�e bilat�re
int insertItemAtDoubleLinkedListHead(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {
	//Cr�ation du nouvel �l�ment 
	DoubleLinkedListElem* newElem = malloc(sizeof(*newElem));
	if (list == NULL || newElem == NULL) { exit(EXIT_FAILURE); }
	newElem->elt = newItem;

	// Insertion de l'�l�ment au d�but de la liste //
	newElem->suivant = list->premier;
	list->premier = newElem;
	return 0;

}

// renvoie le nombre d'�l�ment contenus dans la liste
int getDoubleLinkedListSize(DoubleLinkedList* list) {

	/*if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	int i = 1;
	while (actuel != NULL) {
		actuel = actuel->suivant;
		i++;
	}
	return i;*/
	return(list->taille);

}

// insertion d'un �l�ment apr�s un autre �l�ment 
int insertItemAfterItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedListElem* newItem) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	while (actuel != item) {
		actuel = actuel->suivant;
	}
	actuel->suivant = newItem;
	return 0;

	return;

}

// insertion d'un �l�ment avant un autre �l�ment 
int insertItemBeforeItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedListElem* newItem) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	while (actuel != item) {
		actuel = actuel->suivant;
	}
	actuel->precedent = newItem;
	return 0;
	return;

}
// destruction de tous les �l�ments d'une liste cha�n�e
int emptyDoubleLinkedList(DoubleLinkedList* list) {
	free(list);
	return 0;

}

// suppression et destruction d'un �l�ment de liste chain�e
int deleteDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item) {
	// on peut traiter un certain nombre de cas d'erreur
	// La liste n'existe pas
	if (list == NULL) return(0);
	// liste vide ou anomalie
	if ((list->premier == NULL) || (list->fin == NULL)) return(0);
	// anomalie sur la taille
	if ((list->premier == list->fin) && (list->taille != 1)) return(0);
	//  pas d'�l�ment dans la liste ou elem invalide
	if ((list->taille == 0) || (item == NULL)) return(0);
	// initialisation d'un pointeur sur l'�l�ment courant
	DoubleLinkedListElem* tmp = list->premier;
	// previous d�signe l'�l�ment qui pr�c�de l'�l�ment courant
	DoubleLinkedListElem* previous = NULL;
	// l'�l�ment est en t�te et en queue, il y a donc 1 seul �l�ment dans la liste
	if ((item == list->premier) && (item == list->fin)) {
		list->premier = NULL;
		list->fin = NULL;
		list->taille = 0;
		free(item);
		return(1);
	}
	// il est en t�te, on supprime la t�te

	if (item == list->premier) {
		list->premier = item->suivant;
		list->taille--;
		free(item);
		return(1);
	}
	// Recherche du maillon dans le reste de la liste cha�n�e
	while((tmp!= NULL) && (tmp!= item)) {
		previous= tmp;
		tmp= tmp->suivant;
	}
	// s'il est en queue, on supprime la queue
	if((previous != NULL) && (tmp== item) && (tmp->suivant ==NULL)) {
		list->fin= previous;
		previous->suivant = NULL;
		list->taille--;
		free(item);
		return(1);
	}
	// s'il est au milieu, on supprime l'�l�ment
	if((previous !=NULL) && (tmp== item) && (tmp->suivant!=NULL)) {
		previous->suivant = item->suivant;
		list->taille--;
		free(item);
		return(1);
	}// l'�l�ment recherch� n'a pas �t� trouv�
	return(0);  
}

// obtention d'un pointeur sur le prochain �l�ment contenant "value", en partant de l'�l�ment "item" et en 
// allant soit vers la t�te (UP), soit vers la queue (DOWN)

DoubleLinkedListElem* getNextDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item, int value, int sens) {

	return;

}

// d�placement d'un �l�ment apr�s un autre �l�ment
int moveDoubleLinkedListItemAfterItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedListElem* itemDest) {
	deleteDoubleLinkedListItem(list,item);
	insertItemAfterItem(list, item, itemDest);
	return 0;

}

//permutation de deux �l�ments de la liste chain�e
int swapDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* itemA, DoubleLinkedListElem* itemB) {
	DoubleLinkedListElem* tmp;

	tmp = itemA->elt;
	itemA->elt = itemB->elt;
	itemB->elt = tmp;

	return 0;

}

// // trier au mieux
int sortDoubleLinkedList(DoubleLinkedList* list) {

	return 0;

}

// impl�mentation du tri bulles, pas tr�s performant ...
int sortBublesDoubleLinkedList(DoubleLinkedList* list) {

	int tmp;

	DoubleLinkedListElem* actuel = list->premier;

	for (int i = 0; i < list->taille - 1; i++)
	{
		for (int j = 0; j < list->taille - i - 1; j++)
		{
			/* Pour un ordre d�croissant utiliser < */
			if (actuel > actuel->suivant)
			{
				tmp = actuel;
				actuel = actuel->suivant;
				actuel->suivant = actuel;
			}
			actuel = actuel->suivant;
		}
		actuel = list->premier;
	}

	return;

}

// modifie la valeur d'un �l�ment
int setValueOfDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item, int value) {

	DoubleLinkedListElem* actuel = list->premier;
	while (actuel != item) {
		actuel = actuel->suivant;
	}
	actuel->elt = value;
	return 0;
}

// obtient la valeur d'un �l�ment
int getValueOfDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item, int* value) {

	*value = item->elt;
	return *value;
}

// cr�e une nouvelle liste cha�n�e avec les �l�ments dont la valeur est comprise entre min et max
DoubleLinkedList* extractRangedValueFromNewDoubleLinkedList(DoubleLinkedList* list, int Min, int Max) {

	
	return;

}

// clonage d'une liste cha�n�e (cr�ation d'une nouvelle listequi contient la copie de tous les �l�ments)
DoubleLinkedList* cloneDoubleLinkedList(DoubleLinkedList* list) {

	DoubleLinkedList* tmp = list;
	return tmp;

}

// greffe d'une liste dans une autre liste � la suite de l'�l�ment item, 
// � l'issue de l'op�ration la liste greff�e n'existe plus
int graftDoubleLinkedListAfterItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedList* graftList) {

	DoubleLinkedList* tmp1 = list;
	DoubleLinkedList* tmp2 = graftList;
	DoubleLinkedList* listeC = newDoubleLinkedList();

	listeC->taille = list->taille + graftList->taille;
	listeC->premier = tmp1->premier;

	listeC->fin = tmp1->fin;
	listeC->fin->suivant = tmp2->premier;
	listeC->fin = tmp2->fin;

}

// fonctions qui manipulent la liste en utilisant l'index (no d'ordre dans la liste) des Items
// renvoie EXIT_FAILURE ou NULL s'il n'y a pas d'�l�ment en ni�me position
// renvoie un pointeur sur le ni�me �l�ment de la liste
DoubleLinkedListElem* getItemAtIndexFromDoubleLinkedList(DoubleLinkedList* list, int index) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	for (int i = 1; i < index; i++) {
		actuel = actuel->suivant;
	}

	return actuel;

}

// ins�re un nouvel �l�ment contenant "value" en ni�me position, 
int insertItemAtIndexIntoLinkedList(DoubleLinkedList* list, int index, int value) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	for (int i = 1; i < index; i++) {
		actuel = actuel->suivant;
	}
	actuel->elt = value;

	return actuel;

}