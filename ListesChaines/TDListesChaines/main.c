#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include "piles.h"
#include "files.h"


int main() {
    setlocale(LC_ALL, "fr-FR");

    LinkedList* test = NewLinkedList();
    InitRandLinkedList(test, TAILLELISTE);
    printf("\n Impl�mentation avec les listes chain�es :\n");
    printf("\n");
    printf("Liste A : \n");
    DisplayList(test);
    printf("\n");

    printf("L'�l�ment � la position %d est : %d\n", 2, GetElementAt(test, 2)->elt);
    printf("L'�l�ment � la position %d est : %d\n", 3, GetElementAt(test, 3)->elt);

    swapSingleLinkedListElements(test, GetElementAt(test, 2), GetElementAt(test, 3));
    printf("\nApr�s le swap :\n ");

    printf("L'�l�ment � la position %d est : %d\n", 2, GetElementAt(test, 2)->elt);
    printf("L'�l�ment � la position %d est : %d\n", 3, GetElementAt(test, 3)->elt);

    printf("\n");
    printf("Liste A : \n");
    DisplayList(test);
    // Cr�ation d'une Single LinkedList
    LinkedList*test2 = NewLinkedList();
    // Ajout des valeurs 10-20-30 .. � la liste
    for(int i = 10; i <= 100; i += 10) {
        // cr�ation d'un maillon
        SingleLinkedListElt* elem= NewLinkedListItem(i);
        // ajout du maillon � la liste
        AddNewElemToSingleLinkedList(test2, elem);
    }
    // affichage des valeurs de la liste chain�e
    printf("\n");
    printf("Liste B : \n");
    DisplayList(test2);
    
    LinkedList* test3 = NewLinkedList();

    nocopyconcatSingleLinkedLists(test3, test, test2);
    printf("\n");
    printf("Liste concat�n�e : \n");
    DisplayList(test3);
    printf("\n");

    printf("----------------------------------------------------------------------");
    printf("\n Impl�mentation avec les piles :\n");


    SLLStack* pile = NULL;

    int inipile = 3;
    int* elementSupp1 = &inipile;
    printf("%d", *elementSupp1);

    SLLNewStack(&pile, PILESIZE);

    DisplayList(pile->list);

    SLLpush(pile, 1);
    DisplayList(pile->list);

    SLLpush(pile, 2);
    DisplayList(pile->list);

    SLLpush(pile, 3);
    DisplayList(pile->list);

    SLLpull(pile, elementSupp1);
    DisplayList(pile->list);
    printf("\n----------------------------------------------------------------------");
    printf("\n Impl�mentation avec les files :\n");


    SLLQueue* file = NULL;

    int inifile = 1;
    int* elementSupp2 = &inifile;

    SLLNewQueue(&file, FILESIZE);

    DisplayList(file->list);

    SLLqueue(file, 1);
    DisplayList(file->list);

    SLLqueue(file, 2);
    DisplayList(file->list);

    SLLqueue(file, 3);
    DisplayList(file->list);

    SLLdeQueue(file, elementSupp2);
    DisplayList(file->list);


    return 0;
}
