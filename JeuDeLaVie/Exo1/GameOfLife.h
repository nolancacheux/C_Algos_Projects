#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <minwindef.h>

#define LifeSizeX 30
#define LifeSizeY 30
#define NBLIVES 150
#define Alive '*'
#define Dead ' '


// Gen1 et Gen2 contiennent les générations successives d'êtres en vie ou morts
char* Gen1;
char* Gen2;

// gestion des empreintes MD5 sur historique des jeux déjà joués
// taille du journal
#define LogSize 5
// taille d'une empreinte en caractères
#define FingerprintSize 32
// nombres d'entrées dans le journal
int nbLogEntries;
// tableau de stockage de l'historique des empreintes
char logFingerprint[100][32];
// fonction de calcul d'une signature sur une génération et renvoyée dans le tableau fingerprint
DWORD createmd5(char* life, char fingerprint[FingerprintSize], int lifeNbline, int lifeNbCol);
// vérifier que la signature d'une nouvelle génération est unique
bool checkUnique(char logThumb[LogSize][FingerprintSize], int nbLogEntries, char fingerprint[FingerprintSize]);
// ajoute une signature dans le journal
int addEntryToFringerPrintLog(char logThumb[LogSize][FingerprintSize], int maxLogSize, char fingerprint[FingerprintSize], int* nbLogEntries);
// purge l'historique des empreintes
void cleanFingerprintLog(int* nbLogEntries);
// InitLife initialise un tableau, d'abord complètement avec des morts puis place les êtres en vie
int initLife(char* life, int sizeX, int sizeY);

// NextGen calcule l'apparition ou la disparition des êtres à la génération suivante, de Gen1 vers Gen2
int nextGen(char* gen1, char* gen2, int sizeX, int sizeY);

// DisplayGen Affiche une génération sur la console
void displayGen(char* life, int sizeX, int sizeY);

// CountNeighbours dénombre les êtres en vie autour de la postion (PosX, PosY) dans le tableau Life (une génération)
int countNeighbours(char* life, int sizeX, int sizeY, int posX, int posY);

int countNeighbours2(char* life, int sizeX, int sizeY, int posX, int posY);


// Détermine s'il y a une naissance ou une disparition en fonction du nombre de voisins et de l'état actuel
char lifeState(int NbNeighbours, char state);

char lifeStateOtherVersion(int NbNeighbours, char state);



