#ifndef FICHIERS
#define FICHIERS

//faire une enum

struct categorie {
	char nom[20];
	int seuil;
	// Est-ce qu'on met un seul ou trois tableaux ?
	char date[255][11];  // séparé en jour/mois ?
	char type[255][7]; // Type de transaction (carte, liquide, chèque)
	char endroit[255][50];  // Où les transactions ont été faites
	float montant[255];
} ;

struct releve {
	char nom[20];
	char categorie[255][20]
	int seuil;
	// Est-ce qu'on met un seul ou trois tableaux ?
	char date[255][11];  // séparé en jour/mois ?
	char type[255][7]; // Type de transaction (carte, liquide, chèque)
	char endroit[255][50];  // Où les transactions ont été faites
	float montant[255];
} ;

int save(struct categorie cat);

struct categorie load(char *fichier);

#endif
