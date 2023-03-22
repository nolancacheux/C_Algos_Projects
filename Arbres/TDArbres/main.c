#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int main() {

	// A la main : 

	BinaryTree* arbre= NULL;
	newTree(&arbre);

	BinaryTreeElement* racine;
	newBinaryTreeElement(&racine);

	BinaryTreeElement* E1;
	newBinaryTreeElement(&E1);

	BinaryTreeElement* E2;
	newBinaryTreeElement(&E2);

	BinaryTreeElement* E3;
	newBinaryTreeElement(&E3);

	BinaryTreeElement* E4;
	newBinaryTreeElement(&E4);

	BinaryTreeElement* E5;
	newBinaryTreeElement(&E5);

	BinaryTreeElement* E6;
	newBinaryTreeElement(&E6);

	BinaryTreeElement* E7;
	newBinaryTreeElement(&E7);


	racine->data = 50;
	E1->data = 40;
	E2->data = 38;
	E3->data = 32;
	E4->data = 28;
	E5->data = 22;
	E6->data = 19;
	E7->data = 16;


	racine->leftChild = E1;
	racine->rightChild= E2;
	E1->leftChild = E3;
	E1->rightChild = E4;
	E2->leftChild = E5;
	E1->rightChild = E6;
	E2->rightChild = E7;


	arbre->anchor = racine;
	Cursor curs = getCursorOnRoot(*arbre);

	/*affichage(curs.pointeur, 0, obtenirProfondeur(*arbre));

	printf("\n");
	modifyValue(curs, 98);

	printf("\nLa valeur de la racine vaut maintenant : %d\n", getValue(curs));

	printf("\n");
	affichage(curs.pointeur, 0, obtenirProfondeur(*arbre));*/

	printf("\n");
	addValueToABR(*arbre, 10);
	addValueToABR(*arbre, 8);
	affichage(curs.pointeur, 0, obtenirProfondeur(*arbre));
	return 0;
}