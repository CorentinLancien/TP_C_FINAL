#include "gestionpays.h"

void chargementPays(PAYS * pPays) {
	char c;
	int i = 0;
	int k = 0;
	int col = 0;
	int Case = 0;
	unsigned char temp[300];
	unsigned char ligne[300] = "";
	unsigned char nom[100];
	unsigned char capitale[100];
	int id;
	int pop;
	int r;
	FILE * curseur = fopen("pays.csv", "r");
	if (curseur != NULL) {
		while (fgets(ligne, 300, curseur) != NULL) {
			i = 0;
			col = 0;
			while (ligne[i] != '\0') {

				if (ligne[i] == ';' || ligne[i] == '\n') {
					temp[k] = '\0';
					switch (col)
					{
					case 0:
						id = atoi(temp);
						break;
					case 1:
						strcpy(capitale, temp);

						break;
					case 2:
						strcpy(nom, temp);
						break;
					case 3:
						pop = atoi(temp);
						(pPays + Case)->id = id;
						(pPays + Case)->populationCapitale = pop;
						gestionAccent(capitale);
						gestionAccent(nom);
						strcpy((pPays + Case)->nom, nom);
						strcpy((pPays + Case)->capitale, capitale);
						Case++;
						break;
					}
					col++;
					k = 0;
				}
				else {
					temp[k] = ligne[i];
					k++;
				}
				i++;
			}
		}


		/*do {
		c = fgetc(curseur);
		printf("%c", c);
		} while (c != EOF);
		system("pause");
		fclose(curseur);*/
	}
	else {
		printf("Ouverture du fichier pays.csv impossible !\n");
	}

}

void afficherListePays(PAYS * pTab) {
	int i = 0;

	PAYS p;
	while ((pTab + i)->id != 0) {
		p = *(pTab + i);
		printf("%d - %s - %s (%d)\n", p.id, p.nom, p.capitale, p.populationCapitale);
		i++;
	}

}

void jeuCapitale(PAYS * pTab) {

	PAYS p;
	char chaine[100];
	int random;
	int difference = 0;
	int error = 0;
	int i = 0;
	int j = 0;
	char nom[100];
	char score[100];
	char topPlayer[100];
	char topScore[100];
	char temp1;
	char temp2;
	int maxScore;

	FILE * curseur = fopen("enregistrement.txt", "r");
	printf("Avant de jouer, veuillez vous enregistrer en tant qu'utilisateur .\n");
	scanf("%s", nom);

	if (curseur != NULL) {
			fgets(topPlayer, 100, curseur);
			fgets(topScore, 100, curseur);
			maxScore = atoi(topScore);
			fclose(curseur);
}
	  else {
		 printf("Ouverture impossible\n");
 }

	  printf("----------------------------------------------------------------------\n");
	  printf("Le meilleur joueur est : %s", topPlayer);
	  printf("Avec un score de : %s\n", topScore);
	  printf("----------------------------------------------------------------------\n");
	do {
		
		random = rand() % 192;
		p = *(pTab + random);
		printf("Quelle sont les trois premieres lettre de la capitale du pays : %s\n", p.nom);
		scanf("%s", chaine);
		
		while (j < 3) {
			temp1 = p.capitale[j];
			temp2 = chaine[j];
			if (65 < temp1 && temp1 < 91) {
				temp1 += 32;
			}
			if (65 < temp2 && temp2 < 91) {
				temp2 += 32;
			}
			FormatAccent(&temp1);		
			FormatAccent(&temp2);

			if (temp1 != temp2) {
				difference++;
			}
			j++;
		}
		j = 0;
		if (difference == 0 ) {
			printf("Bravo vous avez trouver ! \n");
			system("pause");
			i++;
			
		}
		else {
			error = 1;
		}
	} while (error != 1);
	_itoa(i, score, 100);
	printf("C'est perdu votre score est de : %d\n", i);
	printf("La bonne reponse etait : %s\n", p.capitale);

	if (maxScore < i) {
		FILE * ecriture = fopen("enregistrement.txt", "w");
		if (ecriture != NULL) {
			fputs(nom, ecriture);
			fputs("\n", ecriture);
			fputs(score, ecriture);
			fclose(ecriture);
		}
		else {
			printf("Sauvegarde impossible\n");
		}
	}
		
	
}