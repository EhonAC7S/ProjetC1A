#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichiers.h"

/*
Un fichier par type de dépense ? -> les ranger dans un dossier

Début du fichier : seuil à ne par dépasser (par semaine ou mois) ;
        -> alerte lorsque l'on s'approche du seuil d'un certain pourcentage
                    dépense totale actuelle

Un fichier pour les revenus avec en début de fichier la somme présente sur le compte
*/

int save(struct categorie cat) {
	FILE *fp;

	fp = fopen(cat.nom,"w");
	//On utilise fputs("",fp); pour écrire des trucs
	int i;
	char chaine[255];
	while (cat.montant[i]!=0.) {//for (i=0;i<sizeof(cat.date);i++) {
		strcpy(chaine,cat.date[i]);
		strcat(chaine,",");
		strcat(chaine,cat.type[i]);
		strcat(chaine,",");
		strcat(chaine,cat.endroit[i]);
		strcat(chaine,",");
		char str[20];
		sprintf(str, "%f", cat.montant[i]);
		strcat(chaine,str);
		strcat(chaine,"\n");
		fputs(chaine,fp);
		i++;
	}
	fclose(fp);

	return 0;
}

struct categorie load(char *fichier) {   //renvoie la structure contenant la catégorie chargée depuis le fichier donné
	struct categorie cat; //structure que l'on crée
	strcpy(cat.nom,fichier);
	FILE *fp;

	fp = fopen(fichier,"r");
	// fgetc() pour lire des caractères, fgets( char *buf, int n, FILE *fp ) pour des chaines
	// fgets() lit n caractères ou jusqu'au \n
	int i=0;
	char buf[255];
	char *ret;
	char *ret2;
	char dates[10];
	fgets(buf,255,fp);  //Les fgets doivent être faits avant de vérifier que l'on n'est pas à la fin du fichier (-> seg fault sinon)
	while (!feof(fp)) { //tant qu'on n'est pas à la fin du fichier
		strncpy(dates,buf,10); //copie les 10 premiers caractères de buf dans cat.dates[i]
		strcat(dates,"\0");
		strcpy(cat.date[i],dates);
        	ret = strchr(buf,',')+1;
        	ret2 = strchr(ret,',');  //ou : memchr(ret, (int) ',', 20);
		*ret2 = '\0';
        	strcpy(cat.type[i],(char*) ret);
        	ret = ret2+1;
        	ret2 = strchr(ret,',');  //ou : memchr(ret, (int) ',', 50);
		*ret2 = '\0';
        	strcpy(cat.endroit[i],(char*) ret);
        	ret = ret2+1;
        	ret2 = memchr(ret, (int) '\n', 20);
		*ret2 = '\0';
        	cat.montant[i] = atof(ret);
        	i++;
		fgets(buf,255,fp);
	}
	fclose(fp);
	return cat;
}
