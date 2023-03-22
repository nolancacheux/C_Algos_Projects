
#include <stdio.h>

//L’accès aux champs d’une structure pointée se fait avec->

typedef struct heure{ 
	int heure; 
	int minute; 
} Heure; 

void incrementMinute(Heure *now)
{
	now->heure = (now->minute + 1) / 60 + now->heure;
	now->minute = (now->minute + 1) % 60; 
}

Heure* cloneLog(Heure* Log, int nbLog) {  

	Heure* extrait = (Heure*)malloc(nbLog * sizeof(Heure));
	if (extrait != NULL) {
		for (int i = 0; i < nbLog; i++) {
			
			*(extrait + i) = *(Log + i);//copies des structures
		}
	}
	return extrait;
}
void afficheLog(Heure* Log, int nbLog) {   }

int main(int argc, void** argv) {}
