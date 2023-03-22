#include<stdlib.h>
#include<stdio.h>
#include"somme.h"
#include"application.h"

int main() {
	int premier = 2;
	int second  = 3;
	printf("La somme de %d et %d est : %d\n", premier, second, somme(premier, second));
}
