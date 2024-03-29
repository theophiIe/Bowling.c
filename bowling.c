#include <stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_bowling.h"
#include "lire_ecrire.h"

void jouer(BOULE B) {
	int fleche; 
	char touche;
	POINT P;
	int res = wait_key_arrow_clic(&touche,&fleche,&P);
	
	if(EST_CLIC == res){
			printf("clic\n");
			deplacement_boule(B);
		}

	if(EST_TOUCHE == res){
		if('S' == touche){ //Sauvegarde
			printf("sauvegarde faite\n");
		}

		else if('Q' == touche){ //Quitte
			printf("Partie terminer\n");
			exit(0);
		}
	}
	
}

int main(int argc, char const *argv[]) {
	JEU J;
	BOULE B;
	J = lire_fichier(argv[1]);
	initialisation_fenetre_graphique();
	bowling_afficher(B);
	
	while(1){
		jouer(B);
		bowling_afficher(B);
	}
	terminer_fenetre_graphique();
	exit(0);
}
