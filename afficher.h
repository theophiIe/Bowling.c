#include "gestion_bowling.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H

//Structure pour la boule
struct boule{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
};
typedef struct boule BOULE;

//Déplacement boule//
void deplacement_boule(BOULE B);

//Fonction à appeler au début pour créer la fenetre graphique
void initialisation_fenetre_graphique();

//Fonction à appeler à la fin pour terminer proprement la fenetre graphique
void terminer_fenetre_graphique();

//Fonction qui affiche l'état courant du bowling
void bowling_afficher(BOULE B);

#endif
