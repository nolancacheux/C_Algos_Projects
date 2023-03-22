#include <stdio.h>
#include <stdbool.h>
//exercice du carré magique

#define sizeCarre 3


carremagique = true;
int sommeLigne, sommeColonne,sommediagonale,sommemagique;
int ligne = 0;
int colonne = 0;

bool isMagic(int carre[sizeCarre][sizeCarre]) {

	for (int ligne = 0; ligne < sizeCarre; ligne++)
	{
		sommemagique += carre[ligne][0];
	}

	while (carremagique && colonne < sizeCarre)
	{
		for (int ligne = 0; ligne < sizeCarre; ligne++)
		{
			sommeLigne += carre[ligne][colonne];
		}
		if (sommeLigne != sommemagique)
		{
			carremagique = false;
			break;

		}
		else
		{

			sommeLigne = 0;
			colonne++;
		}

	}

	while (carremagique && ligne < sizeCarre)
	{

		for (int colonne = 0; colonne < sizeCarre; colonne++)
		{
			sommeColonne += carre[ligne][colonne];
		}
		if (sommeColonne != sommemagique)
		{
			carremagique = false;
			break;

		}
		else
		{
			sommeColonne = 0;
			ligne++;
		}

	}

	if (carremagique)
	{

		sommediagonale = 0;
		for (ligne = 0, colonne = 0; ligne < sizeCarre; ligne++, colonne++) {

			sommediagonale += carre[ligne][colonne];

		}
		if (sommediagonale != sommemagique) {
			carremagique = false;
		}
	
	}

	if (carremagique)
	{

		sommediagonale = 0;
		for (ligne = 0, colonne = sizeCarre - 1; ligne < sizeCarre; ligne++, colonne--) {

			sommediagonale += carre[ligne][colonne];

		}
		if (sommediagonale != sommemagique) {
			carremagique = false;
		}
		
	}

	return (carremagique);

}


int carre[sizeCarre][sizeCarre] = { 
	{2,7,6},
	{9,5,1},
	{4,3,8} };


int main()
{
	if (isMagic(carre))
	{
		printf_s("Ceci est un carre magique. \n");
	}
	else 
	{
		printf_s("Ceci n'est pas un carre magique. \n");
	}
	return 0;
}
