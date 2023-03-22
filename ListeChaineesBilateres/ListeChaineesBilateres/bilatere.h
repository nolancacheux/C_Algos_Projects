#include <stdio.h>
#include <stdlib.h>

// LISTES BILATERES **************************************************

typedef struct DoubleLinkedListElem{
	int elt;
	struct DoubleLinkedListElem *precedent;
	struct DoubleLinkedListElem *suivant;
} DoubleLinkedListElem;

typedef struct DoubleLinkedList{
	DoubleLinkedListElem *premier;
	int taille;
	DoubleLinkedListElem *fin;
} DoubleLinkedList;

// cr�ation d'une nouvelle liste cha�n�e bilat�re vide
// cette fonction renvoie un pointeur sur la nouvelle structure liste cha�n�e bilat�re vide

DoubleLinkedList*newDoubleLinkedList();

//fonction de cr�ation d'un maillon
DoubleLinkedListElem* NewDoubleLinkedListItem(int value);

// instanciation (cr�ation) d'un �l�ment (maillon) � ins�rer dans une liste cha�n�e bilat�re 
// avec stockage de la donn�e value dans l'�l�ment de listeDoubleLinkedListElem*NewDoubleLinkedListItem(intvalue);
// affichage des �l�ments d'une liste cha�n�e bilat�re en commen�ant par la t�te

int DisplayDoubleList(DoubleLinkedList * liste);

// affichage des �l�ments d'une liste cha�n�e bilat�re en commen�ant par la queue (Reverse)
 int RevDisplayDoubleList(DoubleLinkedList*list);

 // insertion d'un �l�ment en queue de liste cha�n�e bilat�re
 int insertItemAtDoubleLinkedListTail(DoubleLinkedList*list, DoubleLinkedListElem*newItem);

 // insertion d'un �l�ment en t�te de liste cha�n�e bilat�re
 int insertItemAtDoubleLinkedListHead(DoubleLinkedList*list, DoubleLinkedListElem*newItem);

 // renvoie le nombre d'�l�ment contenus dans la liste
 int getDoubleLinkedListSize(DoubleLinkedList*list);

 // insertion d'un �l�ment apr�s un autre �l�ment 
 int insertItemAfterItem(DoubleLinkedList*list, DoubleLinkedListElem*item, DoubleLinkedListElem*newItem);

 // insertion d'un �l�ment avant un autre �l�ment 
 int insertItemBeforeItem(DoubleLinkedList*list, DoubleLinkedListElem*item, DoubleLinkedListElem*newItem);

 // destruction de tous les �l�ments d'une liste cha�n�e
 int emptyDoubleLinkedList(DoubleLinkedList*list);

 // suppression et destruction d'un �l�ment de liste chain�e
 int deleteDoubleLinkedListItem(DoubleLinkedList*list, DoubleLinkedListElem*item);

 // obtention d'un pointeur sur le prochain �l�ment contenant "value", en partant de l'�l�ment "item" et en 
 // allant soit vers la t�te (UP), soit vers la queue (DOWN)

DoubleLinkedListElem* getNextDoubleLinkedListItem(DoubleLinkedList*list, DoubleLinkedListElem*item, int value, int sens);

 // d�placement d'un �l�ment apr�s un autre �l�ment
 int moveDoubleLinkedListItemAfterItem(DoubleLinkedList*list, DoubleLinkedListElem*item, DoubleLinkedListElem*itemDest);

 //permutation de deux �l�ments de la liste chain�e
 int swapDoubleLinkedListItem(DoubleLinkedList*list, DoubleLinkedListElem*itemA, DoubleLinkedListElem*itemB);

 // // trier au mieux
 int sortDoubleLinkedList(DoubleLinkedList*list);

 // impl�mentation du tri bulles, pas tr�s performant ...
int sortBublesDoubleLinkedList(DoubleLinkedList*list);

// modifie la valeur d'un �l�ment
// intsetValueOfDoubleLinkedListItem(DoubleLinkedList*list, DoubleLinkedListElem*item, intvalue);
// obtient la valeur d'un �l�ment
int getValueOfDoubleLinkedListItem(DoubleLinkedList*list, DoubleLinkedListElem*item, int*value);

// cr�e une nouvelle liste cha�n�e avec les �l�ments dont la valeur est comprise entre min et max
DoubleLinkedList* extractRangedValueFromNewDoubleLinkedList(DoubleLinkedList*list, int Min, int Max);

// clonage d'une liste cha�n�e (cr�ation d'une nouvelle listequi contient la copie de tous les �l�ments)
DoubleLinkedList*cloneDoubleLinkedList(DoubleLinkedList*list);

// greffe d'une liste dans une autre liste � la suite de l'�l�ment item, 
// � l'issue de l'op�ration la liste greff�e n'existe plus
int graftDoubleLinkedListAfterItem(DoubleLinkedList*list, DoubleLinkedListElem*item, DoubleLinkedList *graftList);

// fonctions qui manipulent la liste en utilisant l'index (no d'ordre dans la liste) des Items
// renvoie EXIT_FAILURE ou NULL s'il n'y a pas d'�l�ment en ni�me position
// renvoie un pointeur sur le ni�me �l�ment de la liste
DoubleLinkedListElem*getItemAtIndexFromDoubleLinkedList(DoubleLinkedList*list, int index);

// ins�re un nouvel �l�ment contenant "value" en ni�me position, 
int insertItemAtIndexIntoLinkedList(DoubleLinkedList*list, int index, int value);