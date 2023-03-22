#include <stdio.h>
#include <stdlib.h>
#include"application.h"

int strlen2(const char* p) //longueur d'une chaine 
{
	char* c = p;
	while (*c) c++;
	return (c - p);
}

char* strcpy2(char* destination, const char* source)
{
	if (destination == NULL) {
		return NULL;
	}

	char* ptr = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';
	return ptr;
}

char* strcat2(char* strg1, char* strg2) //concaténer deux chaînes
{
	char* mot = strg1;

	while (*strg1 != '\0'){strg1++;}
	while (*strg2 != '\0')
	{
		*strg1 = *strg2;
		strg1++;
		strg2++;
	}

	*strg1 = '\0';
	return mot;
}

char* strncat2(char* destination, const char* source, size_t num)
{
	// faire pointer ptr vers la fin de la chaîne de destination
	char* ptr = destination + strlen(destination);

	// Ajoute les caractères de la source à la chaîne de destination
	while (*source != '\0' && num--) {
		*ptr++ = *source++;
	}
	*ptr = '\0';

	return destination;
}

int strcmp2(const char* s1, const char* s2)
{
	const unsigned char* p1 = (const unsigned char*)s1;
	const unsigned char* p2 = (const unsigned char*)s2;

	while (*p1 && *p1 == *p2) 
		++p1,
		++p2;

	return (*p1 > *p2) - (*p2 > *p1);
}

int atoi2(const char* S)
{
	long num = 0;
	int i = 0;
	//jusqu’à ce que la fin de la chaîne soit atteinte, ou que le
	//le caractère actuel n’est pas un nombre

	while (S[i] && (S[i] >= '0' && S[i] <= '9')){
		num = num * 10 + (S[i] - '0');
		i++;
	}
	return num;
}