#include <stdio.h>
#include <stdlib.h>
#include "bilatere.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "fr-FR");
    DoubleLinkedList* test = newDoubleLinkedList();
    printf("\n Impl�mentation avec les listes doublement chain�es :\n");
    printf("\n");
    printf("Liste A : \n");
    for (int i = 1; i <= 10; i += 1) {
        // cr�ation d'un maillon
        DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
        // ajout du maillon � la liste
        insertItemAtDoubleLinkedListTail(test, elem);
    }
    DisplayDoubleList(test);
    printf("\n");

    printf("Liste A renvers�e: \n");
    RevDisplayDoubleList(test);
    printf("\n");

    printf("L'�l�ment � la position %d est : %d\n", 2, getItemAtIndexFromDoubleLinkedList(test, 2)->elt);
    printf("L'�l�ment � la position %d est : %d\n", 3, getItemAtIndexFromDoubleLinkedList(test, 3)->elt);

    swapDoubleLinkedListItem(test, getItemAtIndexFromDoubleLinkedList(test, 2), getItemAtIndexFromDoubleLinkedList(test, 3));
    printf("\nApr�s le swap :\n ");

    printf("L'�l�ment � la position %d est : %d\n", 2, getItemAtIndexFromDoubleLinkedList(test, 2)->elt);
    printf("L'�l�ment � la position %d est : %d\n", 3, getItemAtIndexFromDoubleLinkedList(test, 3)->elt);

    printf("\n");
    printf("D�sormais la liste A : \n");
    DisplayDoubleList(test);
    printf("\n La taille de la liste A est de : %d \n", getDoubleLinkedListSize(test));

    // Cr�ation d'une Single LinkedList
    DoubleLinkedList* test2 = newDoubleLinkedList();
    // Ajout des valeurs 10-20-30 .. � la liste
    for (int i = 10; i <= 100; i += 10) {
        // cr�ation d'un maillon
        DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
        // ajout du maillon � la liste
        insertItemAtDoubleLinkedListTail(test2, elem);
    }

    
	return 0;
}