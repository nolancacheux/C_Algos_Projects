
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilestab.h"

#define TAILLEPILE 10


// 1-Expressions Postfixée - a)

/*
bool test_lettre(char c)
{
	return(toupper(c) >= 'A' && toupper(c) <= 'Z');
}

bool test_chiffre(char c)
{
	return(c <= '1' || c >= '9');
}
bool test_espace(char c)
{
	return(c == 32 || c == 9 || c == 13);
}

int main() {
	char c;
	
	do {
		printf("Entre un caractère : ");
		c = getchar();
	} while (test_lettre(c) || test_chiffre(c) || test_espace(c));

	return (int)(c);

}

CORRIGE :

tableau d'entiers (char) tab
entier indice <- 0;
entier (int) résultat

repeter lirecar jusqu'à une valeur en dehors de [0,9]

faire 
	tab[indice]<- lirecar()
	indice++
tant que('0'<= tab[indice-1] <= '9')

placer '\0'
resultat <- atoi(tab)
*/

// b.Calcul d'une expression postfixée 



int main() {

	Stack * pile = NULL;
	char caractere;
	NewStack(&pile, TAILLEPILE);
	for (int i = 0; i < TAILLEPILE; i++) {
		pile->tab[i] = 0;
	}


	do {
		scanf_s("%c",&caractere);
		push(pile, caractere);
	} while (caractere != ' ');

	affichage(pile, TAILLEPILE);
	return 0;
}
//
//for (int v = 0; v < max; v++) {
//    int i = 0;
//    if (calcul[v].id == 1) {
//        do {
//            buff[i] = lirechar();
//            i++;
//        } while (buff[i - 1] != ' ');
//        int n1 = atoi(buff);
//        //calcul[v].n1 = atoi(buff);
//        i = 0;
//        do {
//            buff[i] = lirechar();
//            i++;
//        } while (buff[i - 1] != ' ');
//        int n2 = atoi(buff);
//        //calcul[v].n2 = atoi(buff);
//        calcul[v].operand = lirechar();
//        if (calcul[v].operand == '+') calcul[v].lRes = n1 + n2;
//        printf("\nres: %d ", calcul[v].lRes);
//    }
//    else {
//        do {
//            buff[i] = lirechar();
//            i++;
//        } while (buff[i - 1] != ' ');
//        int n2 = atoi(buff);
//        calcul[v].operand = lirechar();
//        if (calcul[v].operand == '+') calcul[v].lRes = calcul[v - 1].lRes + n2;
//        printf(" %d ", calcul[v].lRes);
//    }s
//}
//printf("| final res : %d", calcul[max - 1].lRes);
//
//
