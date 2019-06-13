#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_bowling.h"

//initialisation de la fenetre graphique
void initialisation_fenetre_graphique() {
  init_graphics(LARGEUR,HAUTEUR);
  affiche_auto_off();
}

void terminer_fenetre_graphique(){
  wait_escape();
}

//affichage de totues les fonctions d'affichage
void bowling_afficher(BOWLING B) {
  fill_screen(noir);
  affiche_all();
}
