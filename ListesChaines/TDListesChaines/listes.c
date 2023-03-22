#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listes.h"


LinkedList* NewLinkedList() {
    LinkedList* tmp;
    tmp = (LinkedList*)malloc(sizeof(LinkedList));
    if (tmp != NULL) { 
        tmp->premier = NULL; 
        tmp->fin = NULL; 
        tmp->taille = 0; 
    }
    return tmp;
}

SingleLinkedListElt* NewLinkedListItem(int value) {

    SingleLinkedListElt* tmp;
    tmp = (SingleLinkedListElt*)malloc(sizeof(SingleLinkedListElt));
    if (tmp != NULL) { 
        tmp->elt = value;
        tmp->suivant = NULL;
    }
    return(tmp);
}


// renvoie EXIT_SUCCESS si le maillon a été ajouté, EXIT_FAILURE sinon
int AppendNewElemToSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem) {
    /* Création du nouvel élément */
    SingleLinkedListElt* newElem = malloc(sizeof(*newElem));
    if (list == NULL || newElem == NULL){exit(EXIT_FAILURE);}
    newElem->elt = elem;

    /* Insertion de l'élément au début de la liste */
    newElem->suivant = list->premier;
    list->premier = newElem;
	return 0;
}


//ajout d'un maillon à la fin d'une Single list
// renvoie 1 si le maillon a été ajouté, 0 sinon
int AddNewElemToSingleLinkedList(LinkedList*list,SingleLinkedListElt * elem) {
    if(list== NULL|| elem== NULL|| elem->suivant!=NULL) 
        return 0;
    // si la liste est vide
    if(list->fin== NULL) {
        list->fin = elem;
        list->premier= elem;
        list->taille = 1;
    }
    else{// on ajoute l'élément en fin
        list->fin->suivant= elem;
        list->fin= elem;
        list->taille += 1;
    }
    return 1;
}
int RemoveElemFromSingleLinkedList(LinkedList* list, SingleLinkedListElt* elem) {
    // on peut traiter un certain nombre de cas d'erreur
    // La liste n'existe pas
    if(list== NULL) return(0); 
    // liste vide ou anomalie
    if((list->premier == NULL) || (list->fin == NULL)) return(0);
    // anomalie sur la taille
    if((list->premier == list->fin) && (list->taille != 1)) return(0);
    //  pas d'élément dans la liste ou elem invalide
    if((list->taille == 0) || (elem== NULL)) return(0); 
    // initialisation d'un pointeur sur l'élément courant
    SingleLinkedListElt* tmp= list->premier;
    // previous désigne l'élément qui précède l'élément courant
    SingleLinkedListElt *previous= NULL;
    // l'élément est en tête et en queue, il y a donc 1 seul élément dans la liste

    if((elem->elt== list->premier->elt) && (elem->elt == list->fin->elt)) {
        list->premier= NULL;
        list->fin = NULL;
        list->taille = 0;
        free(elem);
        return(1);
    }

    // il est en tête, on supprime la tête

    if (elem == list->premier) {
        list->premier = elem->suivant;
        list->taille--;
        free(elem);
        return(1);
    }
    // Recherche du maillon dans le reste de la liste chaînée
    while ((tmp != NULL) && (tmp != elem)) {
        previous = tmp;
        tmp = tmp->suivant;
    }
    // s'il est en queue, on supprime la queue
    if ((previous != NULL) && (tmp == elem) && (tmp->suivant == NULL)) {
        list->fin = previous;
        previous->suivant = NULL;
        list->taille--;
        free(elem);
        return(1);
    }
    // s'il est au milieu, on supprime l'élément
    if ((previous != NULL) && (tmp == elem) && (tmp->suivant != NULL)) {
        previous->suivant = elem->suivant;
        list->taille--;
        free(elem);
        return(1);
    }

    if(elem->elt == list->premier->elt)  {
        list->premier->elt = 0;
        list->premier = list->premier->suivant;
        list->taille--;
        free(elem);
        return(1);
    }
    if (elem->elt == list->fin->elt) {
        list->fin->elt = NULL;
        list->fin = NULL;
        list->taille--;
        free(elem);
        return(1);
    }

    printf("\nPas de suppression\n");
    return 0;
}

// fonction de suppression d'un maillon

int DeleteSingleLinkedListElement(LinkedList* liste, SingleLinkedListElt * element) {
    if (liste == NULL){ exit(EXIT_FAILURE);}

    if (liste->premier != NULL)
    {
        SingleLinkedListElt* aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
	return 0;
}

// Affichage des valeurs(entiers) contenues dans une liste chaînée
int DisplayList(LinkedList* liste) {
        if (liste == NULL) { exit(EXIT_FAILURE); }
        SingleLinkedListElt* actuel = liste->premier;
        int i = 1;
        while (actuel != NULL){
            if (actuel->elt != NULL) {
                printf("%d -> ", actuel->elt);
                actuel = actuel->suivant;
                i++;
            }
            else{
                printf("NULL");
                return 0;
            }
        }
        printf("NULL\n");
    return 0;
}

//Créer une liste chainée unilatère contenant un certain nombre de valeurs entières aléatoires
int InitRandLinkedList(LinkedList* List, int ListSize) {
    srand(time(NULL));
    for (int i = 0; i < ListSize; i++){
        AddNewElemToSingleLinkedList(List, NewLinkedListItem(rand()));
    }
	return 0;
}

//Récupérer un pointeur sur le maillon qui se trouve au nième rang de la liste, le 1er est en position 1.
SingleLinkedListElt * GetElementAt(LinkedList* liste, int position) {

    if (liste == NULL) { exit(EXIT_FAILURE); }
    SingleLinkedListElt* actuel = liste->premier;
    for (int i = 1; i < position;i++) {
        actuel = actuel->suivant;
    }

    return actuel;
}

//Insérer un maillon en tête de liste
int insertElemAtLinkedListHead(LinkedList* list, SingleLinkedListElt* elem) {
    //Création du nouvel élément 
    SingleLinkedListElt* newElem = malloc(sizeof(*newElem));
    if (list == NULL || newElem == NULL) { exit(EXIT_FAILURE); }
    newElem->elt = elem;

    // Insertion de l'élément au début de la liste //
    newElem->suivant = list->premier;
    list->premier = newElem;
    return 0;
}

// permute deux maillons appartenant à une liste
int swapSingleLinkedListElements(LinkedList* liste, SingleLinkedListElt* elementA, SingleLinkedListElt* elementB) {

    SingleLinkedListElt * tmp;
    //SingleLinkedListElt ** pred1;
    //SingleLinkedListElt ** pred2;
    //SingleLinkedListElt * mactu;

    //// recherche en tête
    //if (liste != NULL && liste->premier != NULL) {
    //    if (liste->premier == elementA) {
    //        pred1 = &(liste->premier);
    //    }
    //    else if (liste->premier == elementB) {
    //        pred2 = &(liste->premier);
    //    }
    //}
    //mactu = liste->premier;

    //while ((pred1 == NULL) || (pred2 == NULL) && (mactu != NULL) {
    //    if(mactu->)
    //}
    tmp = elementA->elt;
    elementA->elt = elementB->elt;
    elementB->elt = tmp;

	return 0;
}

// concaténation de deux listes chainées.
// la nouvelle liste (listC) comporte une copie de la première liste (listA)
// à laquelle on chaine une copie de la deuxième liste.

int concatSingleLinkedLists(LinkedList* listeC, LinkedList* listeA, LinkedList* listeB) {

    SingleLinkedListElt* actuel = listeA->premier;

    while (actuel != NULL) {
        AddNewElemToSingleLinkedList(listeC, actuel);
        actuel = actuel->suivant;
    }

    actuel = listeB->premier;

    while (actuel != NULL) {
        AddNewElemToSingleLinkedList(listeC, actuel);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}


int nocopyconcatSingleLinkedLists(LinkedList* listeC, LinkedList* listeA, LinkedList* listeB) {

    LinkedList* tmp1 = listeA;
    LinkedList* tmp2 = listeB;

    listeC->taille = listeA->taille + listeB->taille;
    listeC->premier = tmp1->premier;

    listeC->fin = tmp1->fin;
    listeC->fin->suivant = tmp2->premier;
    listeC->fin = tmp2->fin;

    return 0;
}

