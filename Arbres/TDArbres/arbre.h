#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




// �l�ment d'un arbre binaire (noeud)
typedef struct BinaryTreeElement{  
	int data;// le champ donn�e d'un noeud, ici une valeur num�rique enti�re
	int nodeID;// num�ro d'identification d'un noeud. En option, pour des impl�mentations sp�cifiques
	struct BinaryTreeElement* leftChild; // pointeur sur le fils gauche
	struct BinaryTreeElement* rightChild; // pointeur sur le fils droit
} BinaryTreeElement;

typedef struct BinaryTree {
	struct BinaryTreeElement* anchor; // l'ancrage de l'arbre est r�alis� � l'aide d'un noeud fictif dont on n'utilisera arbitrairement le lien vers fils gauche
	int nodeCount;// comme pointeur sur la racine de l'arbre. Si celui-ci est NULL alors l'arbre est vide.
} BinaryTree;

typedef enum Direction{ Right, Left } Direction; // utilis� pour impl�menter un curseur ou it�rateur qui facilite la navigation dans l'arbre.


// un curseur d�signe le noeud enfant du c�t� 'side' du noeud parent r�f�renc� par le 'pointeur'
// par exemple, pour placer le curseur � la racine de l'arbre, il faut :
// initialiser le champ 'pointeur' avec la valeur de 'anchor' (le noeud d'ancrage)
// et initialiser 'side' avec la valeur 'Left'
// si l'arbre est vide alors la fonction estEnFin(curseur) renvoie 'true'.

typedef struct Cursor{ 				  
	BinaryTreeElement* pointeur;
	Direction side;
} Cursor;

// renvoie un curseur sur le noeud � la racine de l'arbre
Cursor getCursorOnRoot(BinaryTree tree);

// renvoie un pointeur sur le noeud d�sign� par le curseur
BinaryTreeElement* getNode(Cursor curs);

// cr�ation d'un nouveau noeud d'arbre binaire
int newBinaryTreeElement(BinaryTreeElement** node);

// cr�ation d'un nouvel arbre binaire
int newTree(BinaryTree** tree);

// faire descendre un curseur dans l'arbre, � droite ou � gauche
void goDown(Cursor* curs, Direction dir);

// indique qu'il n'y a pas de fils dans la direction du curseur
// le curseur ne d�signe pas un noeud
// on pourrait donc greffer (cf insertValueInAbrAt) un nouveau noeud

bool isAtTheEnd(Cursor curs);

// verifie que le noeud d�sign� par le cursorn'a pas de fils, et est donc une feuille
bool isALeaf(Cursor curs);

// v�rifie que le noeud d�sign� par le cursor poss�de un successeur dans la direction indiqu�e
bool hasAChild(Cursor curs, Direction D);

// renvoie la valeur stock�e dans le champ data d'un noeud
int getValue(Cursor curs);

// change la valeur contenue dans le champ data d'un noeud
void modifyValue(Cursor curs, int X);

// insere une nouvelle valeur dans une nouvelle feuille � la position indiqu�e par le curseur
// qui doit �tre en fin (cf estEnFin())
// utilis� par la fonction addValueToABR() pour ajouter une nouvelle valeur dans l'arbre
void insertValueInAbrAt(Cursor curs, int X);

// recherche l'extremit� o� on peut ajouter la valeur dans l'arbre ABR sauf si elle existe d�j�
void addValueToABR(BinaryTree arbre, int x);

void obtenirProfondeurSousArbre(Cursor C, int n, int* max);
int obtenirProfondeur(BinaryTree Arbre);

void affichage(BinaryTreeElement* courant, int current_level, int max_level);