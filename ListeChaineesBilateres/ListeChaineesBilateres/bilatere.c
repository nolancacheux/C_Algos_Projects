
#include <stdio.h>
#include <stdlib.h>
#include "bilatere.h"



// création d'une nouvelle liste chaînée bilatère vide
// cette fonction renvoie un pointeur sur la nouvelle structure liste chaînée bilatère vide

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

// instanciation (création) d'un élément (maillon) à insérer dans une liste chaînée bilatère 
// avec stockage de la donnée value dans l'élément de liste

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

// affichage des éléments d'une liste chaînée bilatère en commençant par la tête

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

// affichage des éléments d'une liste chaînée bilatère en commençant par la queue (Reverse)
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

// insertion d'un élément en queue de liste chaînée bilatère
int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {

	if (list == NULL || newItem == NULL || newItem->suivant != NULL)
		return 0;
	// si la liste est vide
	if (list->fin == NULL) {
		list->fin = newItem;
		list->premier = newItem;
		list->taille = 1;
	}
	else {// on ajoute l'élément en fin
		list->fin->precedent = list->fin;
		list->fin->suivant = newItem;
		list->fin = newItem;
		list->taille += 1;
	}
	return 1;
}

// insertion d'un élément en tête de liste chaînée bilatère
int insertItemAtDoubleLinkedListHead(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {
	//Création du nouvel élément 
	DoubleLinkedListElem* newElem = malloc(sizeof(*newElem));
	if (list == NULL || newElem == NULL) { exit(EXIT_FAILURE); }
	newElem->elt = newItem;

	// Insertion de l'élément au début de la liste //
	newElem->suivant = list->premier;
	list->premier = newElem;
	return 0;

}

// renvoie le nombre d'élément contenus dans la liste
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

// insertion d'un élément après un autre élément 
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

// insertion d'un élément avant un autre élément 
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
// destruction de tous les éléments d'une liste chaînée
int emptyDoubleLinkedList(DoubleLinkedList* list) {
	free(list);
	return 0;

}

// suppression et destruction d'un élément de liste chainée
int deleteDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item) {
	// on peut traiter un certain nombre de cas d'erreur
	// La liste n'existe pas
	if (list == NULL) return(0);
	// liste vide ou anomalie
	if ((list->premier == NULL) || (list->fin == NULL)) return(0);
	// anomalie sur la taille
	if ((list->premier == list->fin) && (list->taille != 1)) return(0);
	//  pas d'élément dans la liste ou elem invalide
	if ((list->taille == 0) || (item == NULL)) return(0);
	// initialisation d'un pointeur sur l'élément courant
	DoubleLinkedListElem* tmp = list->premier;
	// previous désigne l'élément qui précède l'élément courant
	DoubleLinkedListElem* previous = NULL;
	// l'élément est en tête et en queue, il y a donc 1 seul élément dans la liste
	if ((item == list->premier) && (item == list->fin)) {
		list->premier = NULL;
		list->fin = NULL;
		list->taille = 0;
		free(item);
		return(1);
	}
	// il est en tête, on supprime la tête

	if (item == list->premier) {
		list->premier = item->suivant;
		list->taille--;
		free(item);
		return(1);
	}
	// Recherche du maillon dans le reste de la liste chaînée
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
	// s'il est au milieu, on supprime l'élément
	if((previous !=NULL) && (tmp== item) && (tmp->suivant!=NULL)) {
		previous->suivant = item->suivant;
		list->taille--;
		free(item);
		return(1);
	}// l'élément recherché n'a pas été trouvé
	return(0);  
}

// obtention d'un pointeur sur le prochain élément contenant "value", en partant de l'élément "item" et en 
// allant soit vers la tête (UP), soit vers la queue (DOWN)

DoubleLinkedListElem* getNextDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item, int value, int sens) {

	return;

}

// déplacement d'un élément après un autre élément
int moveDoubleLinkedListItemAfterItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedListElem* itemDest) {
	deleteDoubleLinkedListItem(list,item);
	insertItemAfterItem(list, item, itemDest);
	return 0;

}

//permutation de deux éléments de la liste chainée
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

// implémentation du tri bulles, pas très performant ...
int sortBublesDoubleLinkedList(DoubleLinkedList* list) {

	int tmp;

	DoubleLinkedListElem* actuel = list->premier;

	for (int i = 0; i < list->taille - 1; i++)
	{
		for (int j = 0; j < list->taille - i - 1; j++)
		{
			/* Pour un ordre décroissant utiliser < */
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

// modifie la valeur d'un élément
int setValueOfDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item, int value) {

	DoubleLinkedListElem* actuel = list->premier;
	while (actuel != item) {
		actuel = actuel->suivant;
	}
	actuel->elt = value;
	return 0;
}

// obtient la valeur d'un élément
int getValueOfDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item, int* value) {

	*value = item->elt;
	return *value;
}

// crée une nouvelle liste chaînée avec les éléments dont la valeur est comprise entre min et max
DoubleLinkedList* extractRangedValueFromNewDoubleLinkedList(DoubleLinkedList* list, int Min, int Max) {

	
	return;

}

// clonage d'une liste chaînée (création d'une nouvelle listequi contient la copie de tous les éléments)
DoubleLinkedList* cloneDoubleLinkedList(DoubleLinkedList* list) {

	DoubleLinkedList* tmp = list;
	return tmp;

}

// greffe d'une liste dans une autre liste à la suite de l'élément item, 
// à l'issue de l'opération la liste greffée n'existe plus
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
// renvoie EXIT_FAILURE ou NULL s'il n'y a pas d'élément en nième position
// renvoie un pointeur sur le nième élément de la liste
DoubleLinkedListElem* getItemAtIndexFromDoubleLinkedList(DoubleLinkedList* list, int index) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	for (int i = 1; i < index; i++) {
		actuel = actuel->suivant;
	}

	return actuel;

}

// insère un nouvel élément contenant "value" en nième position, 
int insertItemAtIndexIntoLinkedList(DoubleLinkedList* list, int index, int value) {

	if (list == NULL) { exit(EXIT_FAILURE); }
	DoubleLinkedListElem* actuel = list->premier;
	for (int i = 1; i < index; i++) {
		actuel = actuel->suivant;
	}
	actuel->elt = value;

	return actuel;

}