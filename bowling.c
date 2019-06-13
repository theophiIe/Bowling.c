#include <stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_bowling.h"
#include "lire_ecrire.h"

int int main(int argc, char const *argv[]) {
  BOWLING B;
  B = lire_fichier(argv[1]);
  initialisation_fenetre_graphique();
  bowling_afficher(B);
  terminer_fenetre_graphique();
  exit(0);
}
