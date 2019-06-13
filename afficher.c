#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_bowling.h"

//initialisation de la fenetre graphique
void initialisation_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_off();
}

void jeu_vu_de_haut(){
	POINT p1,p2;
	
	p1.x = LARGEUR - LARGEUR/5;		p1.y = HAUTEUR - HAUTEUR/8;
	p2.x = LARGEUR;					p2.y = HAUTEUR - HAUTEUR/2;
	draw_fill_rectangle(p1,p2,COUL_PISTE);
}

void terminer_fenetre_graphique(){
	wait_escape();
}

//affichage de totues les fonctions d'affichage
void bowling_afficher(BOWLING B) {
	fill_screen(COUL_FOND);
	jeu_vu_de_haut();
	affiche_all();
}
