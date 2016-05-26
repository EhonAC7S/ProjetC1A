#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fichiers.h"

/*
Projet de C
Fonctionnalités du programme :
    - classifier dépenses et revenus : charges immobilières, habillement... (sous-catégories possibles)
    - fournir statistiques sur les dépenses/revenus mensuels (eventuellement graphiques)
            -> chercher une librairie du type matplotlib pour python
    - définir un budget max par poste de dépense et être allerté dès qu'on s'approche du seuil
    - sauvegarder les données dans des fichiers
*/

void accueil() {
	int choix,choixCorrect;
	printf("\n          *** Gestion de budget ***\n\n\n");
	printf(" Que souhaitez-vous faire ?\n");
	printf("    1. Trier le relevé de compte\n");
	printf("    2. Afficher les statistiques\n");
	printf("    3. Saisir le relevé\n");
	printf("    4. Quitter l'application\n");
	while (choixCorrect == 0) {
		printf(" Entrez votre choix : ");
		scanf("%d",&choix);
		switch (choix) {
			case 1:
				tri();
				printf("Le relevé de compte a bien été trié.\n");
				choixCorrect = 1;
				break;
			case 2:
				choixCorrect = 1;
				break;
			case 3: 
				saisirReleve();
				accueil();
				choixCorrect = 1;
				break;
			case 4:
				choixCorrect = 1;
				break;
			default:
				break;
		}
	}
}

int main (int argc, char *argv[])  { 
	accueil();
	return 0;
}
