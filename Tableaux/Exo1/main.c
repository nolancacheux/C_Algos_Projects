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
    double nvvaleur;
    double moyenne = 0;
    double valeur = 1.0;
    int i, j, ligne, colonne;


    /* Initialisation de chaque élément du tableau à 0.*/
    for (i = 0; i < NBLIGNE; i++)
    {
        for (j = 0; j < NBCOLONNE; j++)
        {

            tableau[i][j] = 0.0;
            printf_s("%.2lf ", tableau[i][j]);

        }
        printf_s("\n");
    }

    /* L'utilisateur choisit la valeur pour chaque case. (La ligne d'index 0 est ici la ligne 1) */

    for (i = 0; i < NBLIGNE; i++)
    {
        if (valeur >= 0)
        {
            for (j = 0; j < NBCOLONNE; j++)
            {
                printf_s("Pour la ligne %d , colonne %d , valeur du tableau : ", i + 1, j + 1);
                scanf_s("%lf", &valeur);
                if (valeur >= 0)
                {
                    tableau[i][j] = valeur;
                }
                else
                {
                    break;
                }

            }
        }

    }
    /* Affichage de chaque élément de tableau */
    for (i = 0; i < NBLIGNE; i++)
    {
        for (j = 0; j < NBCOLONNE; j++)
        {
            printf_s("%.2lf ", tableau[i][j]);
        }
        printf_s("\n");
    }


    printf_s("\n Choisissez la ligne du tableau qu'il faut modifier :  ");
    scanf_s("%d", &ligne);
    printf_s("\nChoisissez la colonne du tableau qu'il faut modifier :  ");
    scanf_s("%d", &colonne);
    printf_s("\nChoisissez la valeur qu'il faut inserer :  ");
    scanf_s("%lf", &nvvaleur);
    printf_s("\n");

    if ((ligne >= 10) || (colonne >= 10))
    {
        printf("Modification impossible , dépassement.\n");
    }
    else
    {
        tableau[ligne][colonne] = nvvaleur;

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {

                printf_s("%.2lf ", tableau[i][j]);

            }
            printf_s("\n");

        }

    }

    printf_s("\n Choisissez la ligne de la valeur du tableau qu'il faut supprimer :  ");
    scanf_s("%d", &ligne);
    printf_s("\nChoisissez la colonne de la valeur du tableau qu'il faut supprimer :  ");
    scanf_s("%d", &colonne);
    printf_s("\n");


    if ((ligne >= 10) || (colonne >= 10))
    {
        printf("Modification impossible , dépassement.\n");
    }
    else
    {
        tableau[ligne][colonne] = 0.0;
        printf_s("\n \n Valeur supprimée avec succès. \n \n");

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {

                printf_s("%.2lf ", tableau[i][j]);

            }
            printf_s("\n");

        }

    }




    //calcul de la moyenne
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {

            moyenne += tableau[i][j];

        }

    }
    printf_s("\n\n La moyenne des valeurs dans le tableau : %.2lf \n\n", moyenne / (NBLIGNE * NBCOLONNE));


    return EXIT_SUCCESS;

}