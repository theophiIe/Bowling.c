#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
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
	p2.x = LARGEUR;			p2.y = HAUTEUR - HAUTEUR/4;
	draw_fill_rectangle(p1,p2,black);
}

void quille(int a, int b){
	POINT p1,p2;

	//Partie inférieur de la quille//
	p1.x = a;	p1.y = HAUTEUR - b + 30;
	p2.x = a;	p2.y = HAUTEUR - b - 30;
	draw_fill_ellipse(p1,p2,9,black);
	draw_fill_ellipse(p1,p2,8,white);

	//Partie supérieur de la quille//
	p1.y +=30;
	p2.y +=50;
	draw_fill_ellipse(p1,p2,4,black);
	draw_fill_ellipse(p1,p2,3,white);

	//Trait rouge de la quille//
	p1.x = a+5;		p1.y = p2.y;
	p2.x = a-5;
	draw_line(p1,p2,red);
}

void premier_rang_quille(){
	int a,b;

	//Quille centre//
	a = LARGEUR/2;
	b = 2*HAUTEUR/3;
	quille(a,b);
}

void deuxieme_rang_quille(){
	int a,b;

	//Quille droite//
	a = LARGEUR/2 + 35; 
	b = 3*HAUTEUR/5;
	quille(a,b);

	//Quille gauche//
	a -= 70;
	quille(a,b);
}

void troisieme_rang_quille(){
	int a,b;

	//Quille centre//
	a = LARGEUR/2;
	b = 3*HAUTEUR/5 - 30;
	quille(a,b);

	//Quille gauche//
	a -= 70;
	quille(a,b);

	//Quille droite//
	a += 140;
	quille(a,b);
}

void quatrieme_rang_quille(){
	int a,b;

	//Quille droite//
	a = LARGEUR/2 + 35;
	b = 3*HAUTEUR/5 - 60;
	quille(a,b);

	//Quille très à droite//
	a += 70;
	quille(a,b);

	//Quille gauche//
	a = LARGEUR/2 - 35;
	quille(a,b);

	//Quille très à gauche//
	a -= 70;
	quille(a,b);
}

void affichage_quille(){
	quatrieme_rang_quille();
	troisieme_rang_quille();
	deuxieme_rang_quille();
	premier_rang_quille();
}

BOULE la_boule(BOULE B){
	B.rayon = 20;
	B.dx = LARGEUR/2;	B.dy = B.rayon;
	B.centre.x = B.dx;	B.centre.y = B.dy;
	B.coul = red;
	return B;
}

void affiche_boule(BOULE B){
	draw_fill_circle(B.centre,B.rayon,B.coul);
}

void efface_boule(BOULE B){
	draw_fill_circle(B.centre,B.rayon,COUL_PISTE);
}

void deplacement_boule(BOULE B){
	while(B.dy - B.rayon != 2*HAUTEUR/3){
		efface_boule(B);
		B.dy++;
		affiche_boule(B);
	}
}

void terminer_fenetre_graphique(){
	wait_escape();
}

//affichage de totues les fonctions d'affichage
void bowling_afficher(BOULE B) {
	fill_screen(COUL_FOND);
	piste();
	piste_decors();
	gouttiere();
	gouttiere_decors();
	fond();
	fond_piste();
	affichage_quille();
	affiche_boule(B);
	affiche_all();
}
