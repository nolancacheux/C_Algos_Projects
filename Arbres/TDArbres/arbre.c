#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include <stdbool.h>



// renvoie un curseur sur le noeud à la racine de l'arbre
Cursor getCursorOnRoot(BinaryTree tree) {

	// par exemple, pour placer le curseur à la racine de l'arbre, il faut :
// initialiser le champ 'pointeur' avec la valeur de 'anchor' (le noeud d'ancrage)
// et initialiser 'side' avec la valeur 'Left'
// si l'arbre est vide alors la fonction estEnFin(curseur) renvoie 'true'.
	
	Cursor* curseur = (Cursor*)malloc(sizeof(Cursor));
	if (curseur != NULL) {
		curseur->pointeur = tree.anchor;
		curseur->side = Left;
		curseur->pointeur->data = tree.anchor->data;
		return *curseur;
	}
	else {
		free(curseur);
	}
	
}


// renvoie un pointeur sur le noeud désigné par le curseur
BinaryTreeElement* getNode(Cursor curs) { return curs.pointeur; }

// création d'un nouveau noeud d'arbre binaire
int newBinaryTreeElement(BinaryTreeElement** node) {

	*node = (BinaryTreeElement*)malloc(sizeof(BinaryTreeElement));

	if (*node != NULL) {
		(*node)->data = 0;
		(*node)->nodeID = 0;
		(*node)->leftChild = NULL;
		(*node)->rightChild = NULL;
		return EXIT_SUCCESS;
	}
	else { return EXIT_FAILURE; }
}


// création d'un nouvel arbre binaire
int newTree(BinaryTree** tree) {

	*tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (*tree != NULL) {
		BinaryTreeElement* ancrage;
		(*tree)->anchor = newBinaryTreeElement(&ancrage);
		(*tree)->nodeCount = 1;
	}
	return 0;
}

// faire descendre un curseur dans l'arbre, à droite ou à gauche
void goDown(Cursor* curs, Direction dir) {
	if (dir == Right) {curs->pointeur = curs->pointeur->rightChild;}
	else if (dir == Left) { curs->pointeur = curs->pointeur->leftChild; }
	return;
}

// indique qu'il n'y a pas de fils dans la direction du curseur
// le curseur ne désigne pas un noeud
// on pourrait donc greffer (cf insertValueInAbrAt) un nouveau noeud

bool isAtTheEnd(Cursor curs) {if (hasAChild(curs, curs.side)){return false;} return true;}

// verifie que le noeud désigné par le cursor n'a pas de fils, et est donc une feuille
bool isALeaf(Cursor curs) {
	if (curs.pointeur->leftChild == NULL && curs.pointeur->rightChild == NULL) {return true;}return false;
}

// vérifie que le noeud désigné par le cursor possède un successeur dans la direction indiquée
bool hasAChild(Cursor curs, Direction D) {
	if (D == Right) {if (curs.pointeur->rightChild != NULL) { return true; }}
	if (D == Left) { if (curs.pointeur->leftChild != NULL) { return true; } }
	return false;
}

// renvoie la valeur stockée dans le champ data d'un noeud
int getValue(Cursor curs) {return curs.pointeur->data;}


// change la valeur contenue dans le champ data d'un noeud
void modifyValue(Cursor curs, int X) {curs.pointeur->data = X;return;}

// insere une nouvelle valeur dans une nouvelle feuille à la position indiquée par le curseur
// qui doit être en fin (cf estEnFin())
// utilisé par la fonction addValueToABR() pour ajouter une nouvelle valeur dans l'arbre

void insertValueInAbrAt(Cursor curs, int X) {

	BinaryTreeElement* fils;
	newBinaryTreeElement(&fils);

	if (curs.side == Left) {
		curs.pointeur->leftChild = fils;
		fils->data = X;
	}
	if (curs.side == Right) {
		curs.pointeur->rightChild = fils;
		fils->data = X;
	}
}


// recherche l'extremité où on peut ajouter la valeur dans l'arbre ABR sauf si elle existe déjà
void addValueToABR(BinaryTree arbre, int x) {

	Cursor curs = getCursorOnRoot(arbre);

	while (!(isAtTheEnd(curs)) && (x != getValue(curs))) {
		if (x < getValue(curs)) {goDown(&curs, Left);}
		else {goDown(&curs, Right);}
	}
	if (isAtTheEnd(curs)) {
		if (curs.pointeur->leftChild) {
			curs.side = Right;
		}
		insertValueInAbrAt(curs, x);
	}
	return;
}


void obtenirProfondeurSousArbre(Cursor C, int n, int* max) {

	Cursor X;
	// parcours du sous-arbre gauche
	if (hasAChild(C, Left)) {
		// le curseur X prend la valeur de la racine du sous arbre
		X = C; // backtracking
		goDown(&X, Left);
		obtenirProfondeurSousArbre(X, n + 1, max);
	}
	// parcours du sous-arbre droit
	if (hasAChild(C, Right)) {
		// le curseur X prend la valeur de la racine du sous arbre
		X = C; // backtracking
		goDown(&X, Right);
		obtenirProfondeurSousArbre(X, n + 1, max);
	}
	// on garde le max de n comme étant le plus grand nombre de nœuds parcourus
	if(n > *max) { *max = n; }
}

// Calcul de la profondeur d'un arbre : WRAPPER
int obtenirProfondeur(BinaryTree Arbre) {
	Cursor C = getCursorOnRoot(Arbre);// Curseur pour se déplacer dans l'arbre
	int n = 0;
	int depth = 0;

	if (!isAtTheEnd(C)){ // on peut descendre
		obtenirProfondeurSousArbre(C, n, &depth);
		return depth;
	}
	return 0; // pas de sous-niveau
}


void affichage(BinaryTreeElement* courant, int current_level, int max_level)
{
	int i;
	if (courant) {
		affichage(courant->rightChild, current_level + 1, max_level);
		for (i = 0; i < current_level; i++) {
			printf("    ");
		}
		printf(" %d--|\n", courant->data);
		affichage(courant->leftChild, current_level + 1, max_level);
	}
	else {
		if (current_level < max_level) {
			affichage(NULL, current_level + 1, max_level);
			for (i = 0; i < current_level; i++) {
				printf("    ");
			}
			printf("..\n");
			affichage(NULL, current_level + 1, max_level);
		}
	}
}



//Parcours largeur(tree* t) {
//	queue* f = newqueue();
//	if (t != NULL && t->root != NULL) {
//		enqueue(f, t->root);
//		while (!isEmpty(f)) {
//			node* cur = dequeue(f);
//			printf("%d", cur->data);
//			if (cur->fg != NULL) { enqueue(f, cut->fg); }
//			if (cur->fd != NULL) { enqueue(f, cur->fd); }
//		}
//	}
//	delete(f);
//}