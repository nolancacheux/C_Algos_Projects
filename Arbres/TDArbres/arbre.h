#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




// élément d'un arbre binaire (noeud)
typedef struct BinaryTreeElement{  
	int data;// le champ donnée d'un noeud, ici une valeur numérique entière
	int nodeID;// numéro d'identification d'un noeud. En option, pour des implémentations spécifiques
	struct BinaryTreeElement* leftChild; // pointeur sur le fils gauche
	struct BinaryTreeElement* rightChild; // pointeur sur le fils droit
} BinaryTreeElement;

typedef struct BinaryTree {
	struct BinaryTreeElement* anchor; // l'ancrage de l'arbre est réalisé à l'aide d'un noeud fictif dont on n'utilisera arbitrairement le lien vers fils gauche
	int nodeCount;// comme pointeur sur la racine de l'arbre. Si celui-ci est NULL alors l'arbre est vide.
} BinaryTree;

typedef enum Direction{ Right, Left } Direction; // utilisé pour implémenter un curseur ou itérateur qui facilite la navigation dans l'arbre.


// un curseur désigne le noeud enfant du côté 'side' du noeud parent référencé par le 'pointeur'
// par exemple, pour placer le curseur à la racine de l'arbre, il faut :
// initialiser le champ 'pointeur' avec la valeur de 'anchor' (le noeud d'ancrage)
// et initialiser 'side' avec la valeur 'Left'
// si l'arbre est vide alors la fonction estEnFin(curseur) renvoie 'true'.

typedef struct Cursor{ 				  
	BinaryTreeElement* pointeur;
	Direction side;
} Cursor;

// renvoie un curseur sur le noeud à la racine de l'arbre
Cursor getCursorOnRoot(BinaryTree tree);

// renvoie un pointeur sur le noeud désigné par le curseur
BinaryTreeElement* getNode(Cursor curs);

// création d'un nouveau noeud d'arbre binaire
int newBinaryTreeElement(BinaryTreeElement** node);

// création d'un nouvel arbre binaire
int newTree(BinaryTree** tree);

// faire descendre un curseur dans l'arbre, à droite ou à gauche
void goDown(Cursor* curs, Direction dir);

// indique qu'il n'y a pas de fils dans la direction du curseur
// le curseur ne désigne pas un noeud
// on pourrait donc greffer (cf insertValueInAbrAt) un nouveau noeud

bool isAtTheEnd(Cursor curs);

// verifie que le noeud désigné par le cursorn'a pas de fils, et est donc une feuille
bool isALeaf(Cursor curs);

// vérifie que le noeud désigné par le cursor possède un successeur dans la direction indiquée
bool hasAChild(Cursor curs, Direction D);

// renvoie la valeur stockée dans le champ data d'un noeud
int getValue(Cursor curs);

// change la valeur contenue dans le champ data d'un noeud
void modifyValue(Cursor curs, int X);

// insere une nouvelle valeur dans une nouvelle feuille à la position indiquée par le curseur
// qui doit être en fin (cf estEnFin())
// utilisé par la fonction addValueToABR() pour ajouter une nouvelle valeur dans l'arbre
void insertValueInAbrAt(Cursor curs, int X);

// recherche l'extremité où on peut ajouter la valeur dans l'arbre ABR sauf si elle existe déjà
void addValueToABR(BinaryTree arbre, int x);

void obtenirProfondeurSousArbre(Cursor C, int n, int* max);
int obtenirProfondeur(BinaryTree Arbre);

void affichage(BinaryTreeElement* courant, int current_level, int max_level);