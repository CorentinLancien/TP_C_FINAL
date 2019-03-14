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
			if (65 <= temp1 && temp1 <= 91) {
				temp1 += 32;
			}
			if (65 <= temp2 && temp2 <= 91) {
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

void jeuPays(PAYS * pTab) {

	PAYS p;
	PLAYER tabPlayer[5];
	PLAYER player1;
	char chaine[100];
	int random;
	int difference = 0;
	int error = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	char nom[100];
	char score[100];
	char temp1;
	char temp2;
	int choice = 0;


	FILE * lecture = fopen("enregistrement2.txt", "r");
	printf("Avant de jouer, veuillez vous enregistrer en tant qu'utilisateur .\n");
	scanf("%s", nom);

	if (lecture != NULL) {

		while (i < 5) {
			player1 = *(tabPlayer + i);
			fgets(player1.nom, 100, lecture);


			fgets(score, 100, lecture);
			player1.score = atoi(score);
			
			*(tabPlayer + i) = player1;
			i++;
		}
		fclose(lecture);
		i = 0;
	}
	else {
		printf("Ouverture impossible\n");
	}

	do {
		system("cls");
		printf("Bienvenue : %s, choisissez l'option qui vous convient\n", nom);
		printf("1 - Afficher les cinqs meilleurs joueurs\n");
		printf("2 - Jouer au jeu\n");
		printf("0 - Quitter\n");
		scanf("%d", &choice);
		switch (choice) {
		
		case 1 :
			i = 0;
			system("cls");
			printf("**********************************************************************************\n");
			printf("Classement des meilleurs joueurs :\n");
			printf("**********************************************************************************\n\n");
			while (i < 5) {
				player1 = *(tabPlayer + i);
				printf("Top : %d - %savec un score de : %d\n", i+1, player1.nom, player1.score);

				i++;
			}
			system("pause");

			break;
		case 2 :
			i = 0;
			do {
				
				random = rand() % 192;
				p = *(pTab + random);
				printf("Quelle sont les trois premieres lettre du pays de la capitale: %s\n", p.capitale);
				scanf("%s", chaine);

				while (j < 3) {
					temp1 = p.nom[j];
					temp2 = chaine[j];
					if (65 <= temp1 && temp1 <= 91) {
						temp1 += 32;
					}
					if (65 <= temp2 && temp2 <= 91) {
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
				if (difference == 0) {
					printf("Bravo vous avez trouver ! \n");
					system("pause");
					i++;

				}
				else {
					error = 1;
				}
			} while (error != 1);
			
			printf("C'est perdu votre score est de : %d\n", i);
			printf("La bonne reponse etait : %s\n", p.nom);
			j = 0;
			FILE * ecriture = NULL;
			ecriture = fopen("enregistrement2.txt", "r+");
			while (k < 5) {

				player1 = *(tabPlayer + k);
				
				if (i >= player1.score) {

					_itoa(i, score, 100);
					fputs(nom, ecriture);
					fputs("\n", ecriture);
					fputs(score, ecriture);
				
					*(tabPlayer + k) = player1;
					
				}
				else {
					_itoa(player1.score, score, 100);
					fputs(player1.nom, ecriture);
					fputs(score, ecriture);
					fputs("\n", ecriture);
				}

				
				k++;
		
			}
			fclose(ecriture);
			system("pause");
			break;

		case 0:
			break;
		default:
			printf("Erreur systeme, valeur introuvable");
			break;
		}

	} while (choice != 0);


	




}

void PaysParLettre(PAYS * ptab) {
	PAYS p;
	PAYS pTemp;
	PAYS Tableau[100];
	char temp1;
	char temp2;
	int n = 0;
	int j = 0;
	int i = 0;
	unsigned char lettre[10] = { '\0' };
	do {
		printf("Veuillez choisir la lettre par laquelle vous voulez afficher vos pays : \n");
		scanf("%s", lettre);
	} while (lettre[1] != '\0');
	
	while (j < 192) {

		p = *(ptab + j);
		pTemp = *(ptab + j);
		
		temp1 = p.nom[0];
		temp2 = lettre[0];
		if (65 <= temp1 && temp1 <= 91) {
			temp1 += 32;
		}
		if (65 <= temp2 && temp2 <= 91) {
			temp2 += 32;
		}
		FormatAccent(&temp1);
		FormatAccent(&temp2);


		if (temp1 == temp2) {
			strcpy(pTemp.nom, p.nom);
			strcpy(pTemp.capitale, p.capitale);
			pTemp.populationCapitale = p.populationCapitale;
			pTemp.id = i + 1;
			*(Tableau + i) = pTemp;
			i++;
		}
		j++;

		
		
	}
	

	while (n < i){
		pTemp = *(Tableau + n);
		printf("%d - %s - %s - (%d)", pTemp.id, pTemp.nom, pTemp.capitale, pTemp.populationCapitale);
		printf("\n");
		n++;
	}

	

}

 void PaysPlusPeuples(PAYS * ptab) {

	PAYS p1;
	PAYS p2;
	int  i = 192;
	int j = 0;
	PAYS temp;
	int choix = 0;

	printf("Combien de capitale voulez vous afficher ?\n");
	scanf("%d", &choix);

	while (i > 0) {
		while (j < i) {
			p1 = *(ptab + j + 1);
			p2 = *(ptab + j);
			if (p1.populationCapitale < p2.populationCapitale) {

				temp = p1;
				p1 = p2;
				p2 = temp;
			}
			j++;
		}
		j = 0;
		i--;
	
	}
	i = 0;
	while (i < choix) {
		p1 = *(ptab + i);
		printf("%d - %s - %s - (%d)", p1.id, p1.nom, p1.capitale, p1.populationCapitale);
		printf("\n");
		i++;
	}  


}