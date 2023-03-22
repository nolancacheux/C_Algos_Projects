#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct adresse{ 
	int adrID; // Identifiant unique d'une adresse (ex noordre de création)
	char adr1[50];
	char adr2[50];
	char CP[10];  // code postal
	int codePays; // choisir un code pays ex France= 33
} ADRESSE;


typedef struct pers{
	int persID; // Identifiant unique de pers (ex no ordre de création)
	char nom[50];
	char prenom[50];
}PERSONNE;

typedef struct idx1{
	int persID; // identifiant de personne
	int adrID;  // identifiant de son adresse
} INDEX1;

void ex_1_a();

void ex_1_b();
void ecriture_ex_1_b();
void lecture_ex_1_b();

void ex_2_a();
void ecriture_ex_2_a();
void lecture_ex_2_a();

void ex_2_b();
void ecriture_ex_2_b();
void lecture_ex_2_b();

void ex_2_c();
void ecriture_ex_2_c();
void lecture_ex_2_c();