#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


#define tailleTab 10000

//int tri_naif(int* T, taille) {
//    int i = 0;
//    while (i != (taille - 1))
//    {
//
//        for (int j = 0; j < taille - 1; j++)
//        {
//            if (*(T + j) > *(T + j + 1))
//            {
//                swap((T + j), (T + j + 1));
//            }
//        }
//        i++;
//    }
//}


void tri_naif(int *T, int taille) {

    int comparaisons = 0;
    int permutations = 0;
    int a;

    for (int i = 1; i < taille; i++) {
        if (T[i] < T[i - 1]) { 
            comparaisons++;
            a = 0;
            while (T[a] < T[i]) {
                a++;
                comparaisons++;
            }
            int b = T[i];
            for (int c = i - 1; c >= a; c--){
                T[c + 1] = T[c];
                permutations++;
            }
            T[a] = b; 
            permutations++;
        }
    }
    printf("\n\n\n\nPour ce tableau de n = %d valeurs, le tri naif a effectuée %d comparaisons, %d permutations,n^2 vaut %d \n\n", taille, comparaisons, permutations, taille * taille);
	return;
}

void initialise(int* T,int taille) {
    srand(time(NULL));
    for (int i = 0; i < taille; i++) {
        *(T+i) = rand() % 100; //Nombre aléatoire entre 0 et 100 
    }
    return;
}

void affiche(int* T,int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d - ", *(T + i));
    }
    return;
}

void triABulle(int* T, int taille) {

    int tmp;
    int comparaisons = 0;
    int permutations = 0;

    for (int j = 1; j <= taille; j++) { //Pour chaque case :
        for (int i = 0; i < taille - 1; i++) { 
        if (*(T + i) > *(T + i + 1)) {// On compare chaque deux à deux 
            tmp = *(T + i);
            *(T + i) = *(T + i + 1);
            permutations++;
            *(T + i + 1) = tmp;
            }
        comparaisons++;
        }
    }
    printf("\n\n\n\nPour ce tableau de n = %d valeurs, le tri à bulle a effectuée %d comparaisons, %d permutations,n^2 vaut %d \n\n", taille, comparaisons, permutations, taille * taille);
}

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}



void ajouter(int* T, int position) {
    int currentNode, father;
    currentNode = position;

    father = (currentNode - 1) / 2;
    while ((currentNode > 0) && *(T+currentNode) > *(T+father)) {
        swap(T+currentNode, T+father);
        currentNode = father;
        father = (currentNode - 1) / 2;
    }
    return;
}

void supp(int* T,int position) {

    int currentChild = 0;
    int leftChild, rightChild, maxChild;
    bool stop = false;

    swap(T,T + position);
    //swap(T, 0, position);

    leftChild = 2 * currentChild + 1;
    rightChild = 2 * currentChild + 2;

    while ( (!stop) && ((leftChild) <= (position - 1)) ){

        if ((leftChild = position - 1) || *(T+leftChild) > *(T+rightChild)) {
            maxChild = leftChild;
        }
        else {
            maxChild = rightChild;
        }

        if (*(T+currentChild) < *(T+maxChild)) {
            swap(T + currentChild, T + maxChild);
            //swap(T, currentChild, maxChild);
            currentChild = maxChild;
            leftChild = 2 * currentChild + 1;
            rightChild = 2 * currentChild + 2;
        }
        else {
            stop = true;
        }
    }
    return;
}



void triTas(int* T, int n){
    int i;
    for (i = 0; i < n - 1; i++) {
        ajouter(T, i);
    }
    for (i = 0; i < n - 1; i++) {
        supp(T, n - i - 1);
    }
    return;
}


int rang(int *tab, int valeur, int indmin, int indmax)
{

    int milieu;

    if (indmax < indmin)
    {
        return -1;
    }
    else
    {
        milieu = ((indmin + indmax) / 2);
        /*x = t[milieu]; (facultatif)*/
        if (valeur == *(tab + milieu))
        {
            return milieu;
        }

        else
        {
            if (valeur < *(tab + milieu))
            {
                return(rang(tab, valeur, indmin, milieu - 1));
            }
            else
            {
                return(rang(tab, valeur, milieu + 1, indmax));
            }

        }
    }
    return 0;
}

int TriInsertionDichotomique(int* tab, int tabsize) {

    int i, j, tmp;

    for (i = 1; i <= tabsize - 1; i++) {
        j = rang(tab, *(tab), *(tab + tabsize - 1), i);

        while (j > 0 && *(tab + j - 1) > *(tab + j)) {
            tmp = *(tab + j);
            *(tab + j) = *(tab + j - 1);
            *(tab + j - 1) = tmp;

            j--;
        }
    }
    return 0;
}




int main() {
    setlocale(LC_ALL, "fr-FR");

    //int tab[tailleTab];
    //initialise(tab, tailleTab);
    //tri_naif(tab,tailleTab);
    ////triABulle(tab, tailleTab);
    //affiche(tab, tailleTab);

    /*int TabTest01[100];
    initialise(TabTest01, 100);
    //tri_naif(TabTest01);
    triABulle(TabTest01, 100);
    affiche(TabTest01, 100);

    int TabTest02[100];
    initialise(TabTest02, 100);
    tri_naif(TabTest02,100);
    //triABulle(TabTest02, 100);
    affiche(TabTest02, 100);

    int TabTest03[100];
    initialise(TabTest03, 100);
    triTas(TabTest03, 100);
    affiche(TabTest03, 100);*/

    int TabTest04[100];
    initialise(TabTest04, 100);

    TriInsertionDichotomique(TabTest04, 100);
    affiche(TabTest04, 100);


	return 0;
}