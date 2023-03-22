#include <stdlib.h>
#include <stdio.h>

#define rang 15

void triangleDePascal() {


    int TableauPascal[rang];

    // on d�finit la premi�re ligne du triangle de pascal

    TableauPascal[0] = 1;

    for (int i = 0; i < rang; i++)
    {
        int tmpTableauPascal[rang]; // On d�finit un tableau temporaire de la ligne pr�c�dente afin de trouver la ligne actuelle.

        for (int tmp_rang = 0; tmp_rang < rang; tmp_rang++) { // Assignation de chaque valeur de ce tableau les valeurs du tableau de la ligne prec�dente 
            tmpTableauPascal[tmp_rang] = TableauPascal[tmp_rang];
        }

        for (int j = 0; j <= i; j++)
        {
            if (j != 0)
                if (j < i)
                    TableauPascal[j] += tmpTableauPascal[j - 1] ;
                else
                    TableauPascal[j] = 1;

            printf("%d ", TableauPascal[j]);
        }
        printf("\n");
    }


}

int main() {
    triangleDePascal();
    return EXIT_SUCCESS;
}