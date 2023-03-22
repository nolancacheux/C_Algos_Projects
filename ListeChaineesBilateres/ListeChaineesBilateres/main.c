#include <stdio.h>
#include <stdlib.h>
#include "bilatere.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "fr-FR");
    DoubleLinkedList* test = newDoubleLinkedList();
    printf("\n Implémentation avec les listes doublement chainées :\n");
    printf("\n");
    printf("Liste A : \n");
    for (int i = 1; i <= 10; i += 1) {
        // création d'un maillon
        DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
        // ajout du maillon à la liste
        insertItemAtDoubleLinkedListTail(test, elem);
    }
    DisplayDoubleList(test);
    printf("\n");

    printf("Liste A renversée: \n");
    RevDisplayDoubleList(test);
    printf("\n");

    printf("L'élément à la position %d est : %d\n", 2, getItemAtIndexFromDoubleLinkedList(test, 2)->elt);
    printf("L'élément à la position %d est : %d\n", 3, getItemAtIndexFromDoubleLinkedList(test, 3)->elt);

    swapDoubleLinkedListItem(test, getItemAtIndexFromDoubleLinkedList(test, 2), getItemAtIndexFromDoubleLinkedList(test, 3));
    printf("\nAprès le swap :\n ");

    printf("L'élément à la position %d est : %d\n", 2, getItemAtIndexFromDoubleLinkedList(test, 2)->elt);
    printf("L'élément à la position %d est : %d\n", 3, getItemAtIndexFromDoubleLinkedList(test, 3)->elt);

    printf("\n");
    printf("Désormais la liste A : \n");
    DisplayDoubleList(test);
    printf("\n La taille de la liste A est de : %d \n", getDoubleLinkedListSize(test));

    // Création d'une Single LinkedList
    DoubleLinkedList* test2 = newDoubleLinkedList();
    // Ajout des valeurs 10-20-30 .. à la liste
    for (int i = 10; i <= 100; i += 10) {
        // création d'un maillon
        DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
        // ajout du maillon à la liste
        insertItemAtDoubleLinkedListTail(test2, elem);
    }

    
	return 0;
}