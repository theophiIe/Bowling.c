#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_bowling.h"

//initialisation de la fenetre graphique
void initialisation_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_off();
}

void piste(){
	POINT p1,p2,p3;

	p1.x = LARGEUR/5;		p1.y = 0;
	p2.x = LARGEUR/3;		p2.y = HAUTEUR/2;
	p3.x = 4*LARGEUR/5;		p3.y = 0;
	draw_fill_triangle(p1,p2,p3,COUL_PISTE);

	p1.x = LARGEUR/3;		p1.y = HAUTEUR/2;
	p2.x = 4*LARGEUR/5;		p2.y = 0;
	p3.x = 2*LARGEUR/3;		p3.y = HAUTEUR/2;
	draw_fill_triangle(p1,p2,p3,COUL_PISTE);
}

void piste_decors(){
	POINT p1,p2,p3;

	p1.x = 0;				p1.y = 0;
	p2.x = 1;				p2.y = HAUTEUR/2;
	p3.x = LARGEUR/6;		p3.y = HAUTEUR/2;
	draw_fill_triangle(p1,p2,p3,COUL_PISTE);

	p1.x = 5*LARGEUR/6;		p1.y = HAUTEUR/2;
	p2.x = LARGEUR;		p2.y = 0;
	p3.x = LARGEUR;		p3.y = HAUTEUR/2;
	draw_fill_triangle(p1,p2,p3,COUL_PISTE);
}

void gouttiere(){
	POINT p1,p2,p3;

	p1.x = LARGEUR/6;		p1.y = 0;
	p2.x = LARGEUR/3;		p2.y = HAUTEUR/2;
	p3.x = LARGEUR/5;		p3.y = 0;
	draw_fill_triangle(p1,p2,p3,COUL_GOUTTIERE);

	p1.x = 4*LARGEUR/5;		p1.y = 0;
	p2.x = 2*LARGEUR/3;		p2.y = HAUTEUR/2;
	p3.x = 5*LARGEUR/6;		p3.y = 0;
	draw_fill_triangle(p1,p2,p3,COUL_GOUTTIERE);
}

void gouttiere_decors(){
	POINT p1,p2,p3;

	p1.x = 0;		p1.y = 0;
	p2.x = LARGEUR/6;		p2.y = HAUTEUR/2;
	p3.x = LARGEUR/25;		p3.y = 0;
	draw_fill_triangle(p1,p2,p3,COUL_GOUTTIERE);

	p1.x = 24*LARGEUR/25;		p1.y = 0;
	p2.x = 5*LARGEUR/6;		p2.y = HAUTEUR/2;
	p3.x = LARGEUR;		p3.y = 0;
	draw_fill_triangle(p1,p2,p3,COUL_GOUTTIERE);
}

void fond(){
	POINT p1,p2;

	p1.x = 0;			p1.y = HAUTEUR/2;
	p2.x = LARGEUR;		p2.y = HAUTEUR;
	draw_fill_rectangle(p1,p2,darkslategray);
}

void fond_piste(){
	POINT p1,p2;

	p1.x = 0;				p1.y = HAUTEUR/2;
	p2.x = LARGEUR/6;		p2.y = HAUTEUR - HAUTEUR/4;
	draw_fill_rectangle(p1,p2,black);

	p1.x = LARGEUR/3;		p1.y = HAUTEUR/2;
	p2.x = 2*LARGEUR/3;		p2.y = HAUTEUR - HAUTEUR/4;
	draw_fill_rectangle(p1,p2,black);

	p1.x = 5*LARGEUR/6;		p1.y = HAUTEUR/2;
	p2.x = LARGEUR;		p2.y = HAUTEUR - HAUTEUR/4;
	draw_fill_rectangle(p1,p2,black);
}

void quille(){
	

}

void terminer_fenetre_graphique(){
	wait_escape();
}

//affichage de totues les fonctions d'affichage
void bowling_afficher(JEU J) {
	fill_screen(COUL_FOND);
	piste();
	piste_decors();
	gouttiere();
	gouttiere_decors();
	fond();
	fond_piste();
	affiche_all();
}
