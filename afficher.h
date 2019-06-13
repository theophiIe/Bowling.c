#include "gestion_bowling.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H

//Fonction à appeler au début pour créer la fenetre graphique
void initialisation_fenetre_graphique();

//Le jeu vu du haut avec les score et le meilleur score
void jeu_vu_de_haut();

//Fonction à appeler à la fin pour terminer proprement la fenetre graphique
void terminer_fenetre_graphique();

//Fonction qui affiche l'état courant du bowling
void bowling_afficher(BOWLING B);

#endif
