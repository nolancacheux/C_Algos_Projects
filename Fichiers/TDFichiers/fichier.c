#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fichier.h"


void ex_1_a() {
	//ouverture du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd1;
	errno_t errCode = fopen_s(&fd1, "data1.txt", "w+b");

	if (fd1 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "data1.txt");
		exit(0);
	}
	else {

		for (unsigned int i = 1; i <= 1000; i++) {
			fwrite(&i, sizeof(i), 1, fd1);
		}

		//on se place 0 octet à partir du début du fichier pour la relecture 
		fseek(fd1, 0, SEEK_SET);
		int value = 0;

		//lecture des données tant que pas la fin du fichier
		while (fread_s(&value, sizeof(value), sizeof(value), 1, fd1) && !feof(fd1)) {
			printf_s("%d \n", value);
		}
		fclose(fd1);
	}
}
void ex_1_b() {
	ecriture_ex_1_b();
	lecture_ex_1_b();
}

void ecriture_ex_1_b() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	errno_t errCode = fopen_s(&fd2, "data2.bin", "wb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "data2.bin");
		exit(0);
	}
	else {

		for (unsigned int i = 1; i <= 1000; i++) {
			fwrite(&i, sizeof(i), 1, fd2);
		}
		fclose(fd2);
	}
}
void lecture_ex_1_b() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	errno_t errCode = fopen_s(&fd2, "data2.bin", "rb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "data2.bin");
		exit(0);
	}
	else {
		//on se place 0 octet à partir du début du fichier pour la relecture 
		fseek(fd2, 0, SEEK_SET);
		int value = 0;

		//lecture des données tant que pas la fin du fichier
		while (fread_s(&value, sizeof(value), sizeof(value), 1, fd2) && !feof(fd2)) {
			printf_s("%d \n", value);
		}
		fclose(fd2);
	}
}

void ex_2_a() {
	ecriture_ex_2_a();
	lecture_ex_2_a();
}


void ecriture_ex_2_a() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	ADRESSE bob1 = { 1,"Adresse1","Adresse 1","59000",33 };
	ADRESSE bob2 = { 2,"Ad2","Ad2","59012",33 };
	ADRESSE bob3 = { 3,"Ad3","Ad3","12433",33 };
	ADRESSE bob4 = { 4,"Ad4","Ad4","34433",33 };
	ADRESSE bob5 = { 5,"Ad5","Ad5","52311",33 };


	errno_t errCode = fopen_s(&fd2, "adresses.bin", "wb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "adresses.bin");
		exit(0);
	}
	else {
		fwrite(&bob1, sizeof(ADRESSE), 1, fd2);
		fwrite(&bob2, sizeof(ADRESSE), 1, fd2);
		fwrite(&bob3, sizeof(ADRESSE), 1, fd2);
		fwrite(&bob4, sizeof(ADRESSE), 1, fd2);
		fwrite(&bob5, sizeof(ADRESSE), 1, fd2);
	}
	fclose(fd2);
}
void lecture_ex_2_a() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	int type;
	errno_t errCode = fopen_s(&fd2, "adresses.bin", "rb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "adresses.bin");
		exit(0);
	}
	else {
		char row[100] = "";
		for (int i = 4; i > -1;  i--) { //placement sur L'id
			fseek(fd2, sizeof(ADRESSE) * i + sizeof(int), SEEK_SET);
			fgets(row, 30, fd2);
			printf("% s ", row);

			fseek(fd2, sizeof(ADRESSE) * i + sizeof(int) + sizeof(char[50]), SEEK_SET);
			fgets(row, 30, fd2);
			printf("%s ; ", row);
		}
		fclose(fd2);
	}
}


void ex_2_b() {
	ecriture_ex_2_b();
	lecture_ex_2_b();
}


void ecriture_ex_2_b() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	PERSONNE pers1 = { 1,"Nolan","ABCDE"};
	PERSONNE pers2 = { 2,"Nolan","ABCDE" };
	PERSONNE pers3 = { 3,"Nolan","ABCDE" };
	PERSONNE pers4 = { 4,"Nolan","ABCDE" };
	PERSONNE pers5 = { 5,"Nolan","ABCDE" };

	errno_t errCode = fopen_s(&fd2, "personnes.bin", "wb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "personnes.bin");
		exit(0);
	}
	else {
		fwrite(&pers1, sizeof(ADRESSE), 1, fd2);
		fwrite(&pers2, sizeof(ADRESSE), 1, fd2);
		fwrite(&pers3, sizeof(ADRESSE), 1, fd2);
		fwrite(&pers4, sizeof(ADRESSE), 1, fd2);
		fwrite(&pers5, sizeof(ADRESSE), 1, fd2);

	}
	fclose(fd2);
}


void lecture_ex_2_b() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	int type;
	errno_t errCode = fopen_s(&fd2, "personnes.bin", "rb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "personnes.bin");
		exit(0);
	}
	else {
		//on se place 0 octet à partir du début du fichier pour la relecture 
		fseek(fd2, 0, SEEK_SET);
		int value = 0;

		//lecture des données tant que pas la fin du fichier
		char row[100] = "";
		for (int i = 4; i > -1; i--) { //placement sur L'id
			fseek(fd2, sizeof(ADRESSE) * i + sizeof(int), SEEK_SET);
			fgets(row, 30, fd2);
			printf("% s ", row);

			fseek(fd2, sizeof(ADRESSE) * i + sizeof(int) + sizeof(char[50]), SEEK_SET);
			fgets(row, 30, fd2);
			printf("%s ; ", row);
		}
		fclose(fd2);
	}
}


void ex_2_c() {
	ecriture_ex_2_c();
	lecture_ex_2_c();
}


void ecriture_ex_2_c() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	PERSONNE pers1 = { 1,"Nolan","ABCDE" };

	errno_t errCode = fopen_s(&fd2, "index1.bin", "wb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "index1.bin");
		exit(0);
	}
	else {
		fwrite(&pers1, sizeof(ADRESSE), 1, fd2);
	}
	fclose(fd2);
}


void lecture_ex_2_c() {
	//ouvertur
	// e du fichier : Opens an empty file for both reading and writing.
	// If the file exists , its contents are destroyed + binary mode

	FILE* fd2;
	int type;
	errno_t errCode = fopen_s(&fd2, "index1.bin", "rb");

	if (fd2 == NULL) {
		printf("Le fichier %s ne peut pas etre ouvert\n", "index1.bin");
		exit(0);
	}
	else {
		//on se place 0 octet à partir du début du fichier pour la relecture 
		fseek(fd2, 0, SEEK_SET);
		int value = 0;

		//lecture des données tant que pas la fin du fichier
		while (fread_s(&value, sizeof(value), sizeof(value), 1, fd2) && !feof(fd2)) {
			type = sizeof(value);
			if (type == 4) {
				printf_s("%d \n", value);
			}
			if (type == 1) {
				printf_s("%s \n", value);
			}
		}
		fclose(fd2);
	}
}

