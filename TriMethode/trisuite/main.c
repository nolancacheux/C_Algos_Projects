#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define SIZE_MAX 10

/*Swap*/
void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/*Remplir le tableau*/
void remplir_tab(int* tab) {
    srand(time(NULL));
    for (int i = 0; i < SIZE_MAX; i++)
    {
        *(tab + i) = rand() % 100;
    }
}

/*Tri selection ordinaire*/

int TriSelection(int* tab, int tabsize) {
    for (int iSwap = 0; iSwap < tabsize - 1; iSwap++)
    {
        int iMin = iSwap;
        for (int i = iSwap; i < tabsize; i++)
        {
            if (tab[i] < tab[iMin])
            {
                iMin = i;
            }
        }
        swap((tab + iSwap), (tab + iMin));
    }
}

/*Tri insertion séquentielle*/

int TriInsertionSequentiel(int* tab, int tabsize) {

    int i, j, tmp;
    for (i = 1; i <= tabsize - 1; i++) {
        j = i;

        while (j > 0 && *(tab+j - 1) > *(tab+j)) {
            tmp = *(tab+j);
            *(tab+j) = *(tab+j - 1);
            *(tab+j - 1) = tmp;

            j--;
        }
    }
    return 0;
}

void tri_rapide(int* tableau, int taille) {

    int mur, courant, pivot, tmp;

    if (taille < 2) return;

    pivot = tableau[taille - 1];

    mur = courant = 0;

    while (courant < taille) {

        if (tableau[courant] <= pivot) {

            if (mur != courant) {

                tmp = tableau[courant];
                tableau[courant] = tableau[mur];
                tableau[mur] = tmp;
            }

            mur++;
        }
        courant++;
    }

    tri_rapide(tableau, mur - 1);

    tri_rapide(tableau + mur - 1, taille - mur + 1);
}


int afficher_tab(int tab[]) {
    for (int i = 0; i < SIZE_MAX; i++)
    {
        printf("%d | ", tab[i]);
    }
}

int main() {
    int tab[SIZE_MAX];

    remplir_tab(tab);
    printf("\n");
    //TriInsertionSequentiel(tab, SIZE_MAX);
    tri_rapide(tab, SIZE_MAX);
    afficher_tab(tab);
}