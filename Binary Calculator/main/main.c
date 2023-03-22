#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int convertisseurbindec(int binaire){

    int decimal=0, reste=0,place=0;

    while(binaire)
    {
        reste=binaire%10;
        decimal = decimal + reste *(pow(2,place));
        binaire = binaire / 10;
        ++place;
    }
    return decimal;
}

int convertisseurdecbin(int decimal)
{
    int binaire = 0, reste = 0, place = 1;

    while(decimal)
    {
        reste = decimal % 2;
        decimal = decimal / 2;
        binaire = binaire + (reste * place);
        place = place * 10;
    }
    return binaire;


}

int main() {

    setlocale(LC_ALL, "fr-FR");
    int binaire1, binaire2,choix=-1,somme,soustraction,multiplication;
    float division;

    printf("\n------- Calculatrice en binaire ------- \n\n");

    printf("\n Entre ton nombre en binaire : ");
    scanf_s ("%d",&binaire1);
    int resultat1 = convertisseurbindec(binaire1);

    printf("\n Entre un deuxième nombre en binaire : ");
    scanf_s("%d", &binaire2);
    int resultat2 = convertisseurbindec(binaire2);

    /*printf("\nLe nombre 1 en décimal : %d\n", resultat1);
    printf("\nLe nombre 2 en décimal : %d\n", resultat2);*/

    printf("\n 1 - Addition \n 2 - Soustraction \n 3 - Multiplication \n 4 - Division\n");
    printf("\n Entre ton choix d'opérations : ");
    scanf_s("%d", &choix);
    
    while (choix > 4 || choix < 0)
    {
        printf("\n Votre demande n'a pas été saisie , veuillez réessayer !\n");
        printf("\n Entre ton choix d'opérations : ");
        scanf_s("%d", &choix);
    }
 
    switch (choix)
    {
    case 1 :
        somme = resultat1 + resultat2;
        /*printf("\nSomme en decimal: %d\n", somme);*/
        somme = convertisseurdecbin(somme);
        printf("\nVous avez choisi l'addition :\n\n");
        printf(" %d + %d = %d \n\n", binaire1, binaire2, somme);
        break;
    case 2:
        soustraction = resultat1 - resultat2;
        soustraction = convertisseurdecbin(soustraction);
        printf("\nVous avez choisi la soustraction :\n\n");
        printf(" %d - %d = %d \n\n", binaire1, binaire2, soustraction);
        break;
    case 3:
        multiplication = resultat1 * resultat2;
        multiplication = convertisseurdecbin(multiplication);
        printf("\nVous avez choisi la multiplication :\n\n");
        printf(" %d * %d = %d \n\n", binaire1, binaire2, multiplication);
        break;
    case 4:
        if (resultat2 != 0)
        {
            division = (float)resultat1 / (float)resultat2;
            division = convertisseurdecbin((int)division);
            printf("\nVous avez choisi la division :\n\n");
            printf(" %d / %d = %lf \n\n", binaire1, binaire2, division);
        }
        else
            printf("Erreur : la division par 0 n'existe pas !");
        break;
    }

    return EXIT_SUCCESS;
}

