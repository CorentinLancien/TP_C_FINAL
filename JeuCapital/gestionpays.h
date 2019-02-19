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

void chargementPays(PAYS * );
void jeuCapitale(PAYS * );
void afficherListePays(PAYS * );

#endif;