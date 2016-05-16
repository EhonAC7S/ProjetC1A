#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menus.h"
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

int main (int argc, char *argv[])  {
	struct categorie cat1;
	cat1 = load("test");
	strcpy(cat1.nom,"test2");
	save(cat1);
	printf("%s\n",cat1.nom);
	return 0;
}
