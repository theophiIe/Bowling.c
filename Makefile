CFLAGS = -g -Wall -c
CFLAGSGR = ${CFLAGS} `sdl-config --cflags`
LFLAGS = -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

run: bowling
	./bowling exemple1.bowling

# Edition de lien du programme principal
bowling: bowling.o afficher.o gestion_bowling.o lire_ecrire.o
	gcc -o $@ $^ ${LFLAGS}

# Compilation du programme principal
bowling.o: bowling.c lire_ecrire.h gestion_bowling.h constantes.h
	gcc ${CFLAGSGR} $*.c

# Compilation des différents.o
afficher.o: afficher.c afficher.h gestion_bowling.h constantes.h
	gcc ${CFLAGSGR} $*.c

gestion_bowling.o: gestion_bowling.c gestion_bowling.h
	gcc ${CFLAGS} $*.c

lire_ecrire.o: lire_ecrire.c lire_ecrire.h gestion_bowling.h
	gcc ${CFLAGS} $*.c


# Le clean
clean:
	rm -f *.o
	rm -f bowling


# Pour faire un zip
# Mettre son nom à la place de SUDOKU
LENOM=NOM_Prenoms
zip:
	rm -rf ${LENOM}
	rm -rf ${LENOM}.zip
	mkdir ${LENOM}
	cp Makefile ${LENOM}
	cp *.h *.c ${LENOM}
	cp README.md ${LENOM}
	zip -r ${LENOM}.zip ${LENOM}
	rm -rf ${LENOM}
