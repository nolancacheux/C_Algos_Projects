#include<stdio.h>
#include <stdlib.h>
#include <locale.h>

int Mystrlen (char* mot){
    int longueur = 0;
    while (*mot != '\0') {
        longueur++;
        mot++;
    }

    return longueur;
}

int main(){
    setlocale(LC_ALL, "fr-FR");

    char chaine[20];
    printf("Entre un mot : ");
    char chaine[20];
    scanf_s("%9s", chaine, (unsigned) _countof(chaine));

    printf("Le mot %s contient %d caractères\n", chaine, Mystrlen(chaine));

    return 0;
}
