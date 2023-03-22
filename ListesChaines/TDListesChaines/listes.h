
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

//fonction de cr�ation d'un maillon
SingleLinkedListElt* NewLinkedListItem(int value);

// renvoie EXIT_SUCCESS si le maillon a �t� ajout�, EXIT_FAILURE sinon
int AppendNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem);

// A la fin 
int AddNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem);

// fonction de suppression d'un maillon
int DeleteSingleLinkedListElement(LinkedList* liste, SingleLinkedListElt* element);

// Affichage des valeurs(entiers) contenues dans une liste cha�n�e
int DisplayList(LinkedList* Liste);

//Cr�er une liste chain�e unilat�re contenant un certain nombre de valeurs enti�res al�atoires
int InitRandLinkedList(LinkedList* List, int ListSize);

//R�cup�rer un pointeur sur lemaillon qui se trouve au ni�me rang de la liste, le 1erest en position 1.
SingleLinkedListElt* GetElementAt(LinkedList * Liste, int position);

//Ins�rer un maillon en t�te de liste
int insertElemAtLinkedListHead(LinkedList* list, SingleLinkedListElt* elem);

// permute deux maillons appartenant � une liste
int swapSingleLinkedListElements(LinkedList* liste, SingleLinkedListElt* elementA, SingleLinkedListElt* elementB);


// concat�nation de deux listes chain�es.
// la nouvelle liste (listC) comporte une copie de la premi�re liste (listA)
// � laquelle on chaine une copie de la deuxi�me liste.
int concatSingleLinkedLists(LinkedList* listC, LinkedList* listA, LinkedList* listB);


int nocopyconcatSingleLinkedLists(LinkedList* listC, LinkedList* listA, LinkedList* listB);

int RemoveElemFromSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem);

#endif