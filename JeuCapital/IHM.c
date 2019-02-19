#include "IHM.h"
#include "gestionpays.h"

void menu() {
	srand(time(NULL));
	PAYS tab[250] = { 0 };
	chargementPays(tab);
	int choix;
	do
	{
		system("cls");
		printf("1 - Afficher tous les pays\n");
		printf("2 - Jeu des capitales par pays\n");
		printf("3 - Jeu des pays par capitales\n");
		printf("4 - Les pays par lettre\n");
		printf("5 - Les N capitales les plus peuplees\n");
		printf("0 - Quitter\n");
		scanf("%d", &choix);
		system("cls");
		switch (choix)
		{
		case 1: 
			afficherListePays(tab);
			system("pause");
			break;

		case 2:
			jeuCapitale(tab);
			system("pause");
			break;
		}


	} while (choix != 0);
}