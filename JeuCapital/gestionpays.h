#ifndef GESTIONPAYS
#define GESTIONPAYS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "chaine.h"
#include<time.h>

typedef struct {
	int id;
	unsigned char nom[100];
	unsigned char capitale[100];
	int populationCapitale;
}PAYS;

typedef struct {
	int score;
	char nom[100];
}PLAYER;

void chargementPays(PAYS * );
void jeuCapitale(PAYS * );
void PaysParLettre(PAYS *);
void jeuPays(PAYS * pTab);
void afficherListePays(PAYS * );
void PaysPlusPeuples(PAYS *);

#endif;