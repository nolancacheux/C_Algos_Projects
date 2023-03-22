
#include <stdio.h>
#include <stdlib.h>
#ifndef TAILLELISTE

#define TAILLELISTE 10


typedef struct Element {
	int elt;
	struct Element *suivant;
}SingleLinkedListElt;


typedef struct Liste {
	struct Element* premier;
	int taille;
	struct Element* fin;
}LinkedList;


LinkedList* NewLinkedList();

//fonction de création d'un maillon
SingleLinkedListElt* NewLinkedListItem(int value);

// renvoie EXIT_SUCCESS si le maillon a été ajouté, EXIT_FAILURE sinon
int AppendNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem);

// A la fin 
int AddNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem);

// fonction de suppression d'un maillon
int DeleteSingleLinkedListElement(LinkedList* liste, SingleLinkedListElt* element);

// Affichage des valeurs(entiers) contenues dans une liste chaînée
int DisplayList(LinkedList* Liste);

//Créer une liste chainée unilatère contenant un certain nombre de valeurs entières aléatoires
int InitRandLinkedList(LinkedList* List, int ListSize);

//Récupérer un pointeur sur lemaillon qui se trouve au nième rang de la liste, le 1erest en position 1.
SingleLinkedListElt* GetElementAt(LinkedList * Liste, int position);

//Insérer un maillon en tête de liste
int insertElemAtLinkedListHead(LinkedList* list, SingleLinkedListElt* elem);

// permute deux maillons appartenant à une liste
int swapSingleLinkedListElements(LinkedList* liste, SingleLinkedListElt* elementA, SingleLinkedListElt* elementB);


// concaténation de deux listes chainées.
// la nouvelle liste (listC) comporte une copie de la première liste (listA)
// à laquelle on chaine une copie de la deuxième liste.
int concatSingleLinkedLists(LinkedList* listC, LinkedList* listA, LinkedList* listB);


int nocopyconcatSingleLinkedLists(LinkedList* listC, LinkedList* listA, LinkedList* listB);

int RemoveElemFromSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem);

#endif