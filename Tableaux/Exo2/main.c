#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

#define NBLIGNE 10
#define NBCOLONNE 10



int main()
{
    /* Un tableau avec 10 lignes et 10 colonnes*/
    double tableau[NBLIGNE][NBCOLONNE];

    int randomValue = (int)(rand() / (double)RAND_MAX * (20 - 1));

    /* Initialisation de chaque élément du tableau à 0.*/
    for (int i = 0; i < NBLIGNE; i++)
    {
        for (int j = 0; j < NBCOLONNE; j++)
        {

            tableau[i][j] = randomValue;

            printf_s("%.2lf ", tableau[i][j]);

        }
        printf_s("\n");
    }

}
