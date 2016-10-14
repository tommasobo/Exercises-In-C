/* Ho usato una versione leggermente modificata della libreria usata per le lista per usare nomi più chiari e funzioni ottimizzate */

/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto CODA, implementato tramite allocazione statica
      (vettore contenente la sola parte informativa di ogni elemento della lista), in maniera dinamica con strutture collegate
      e sfruttando la libreria scritta sulle liste.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CodaStat.h" // Includo la libreria CodaStat.h

// Questa funzione inizializza last e first a -1 (EMPTYLIST)
void initialize(TipoCoda *coda)
{
    coda->last = EMPTYLIST;
    coda->first = EMPTYLIST;

    return;
}

// Questa funzione controlla se la coda è vuota
int isEmpty(TipoCoda *coda)
{
    if (coda->first == EMPTYLIST)
        return 1;
    return 0;
}

// Questa funzione controlla se la coda è piena
int isFull(TipoCoda *coda)
{
    if ((coda->first - coda->last == 1)||((coda->last - coda->first) == (MAX-1)))
        return 1;
    else
        return 0;

}

// Questa funzione inserisce un elemento "n" nella coda
void enQueue(TipoCoda *coda, int n)
{
    if (isFull(coda))
        printf("Errore, la pila e\' piena");
    else {
        if (coda->first == -1) { // Se la coda è vuota
            coda->first = 0;
            coda->last = 0;
        } else {
            coda->last = (coda->last +1) % MAX; // Ricalcolo l'elemento last
        }
        coda->ele[coda->last] = n;
    }
}

// Questa funziona elimina il primo elemento che è stato inserito nella coda
void deQueue(TipoCoda *coda, int *n)
{
    if (isEmpty(coda))
        printf("Errore, la coda e\' vuota");
    else {
        *n = coda->ele[coda->first];
        if (coda->first == coda->last) { // Se il primo e l'ultimo elemento combaciano
            coda->first = -1;
            coda->last = -1;
        } else
            coda->first = (coda->first +1) % MAX; // Ricalcolo l'elemento "first"
        printf("Numero %d rimosso dalla coda", *n);
    }
}

// Questa funzione stampa la coda
void printfirst(TipoCoda *coda)
{

	if (isEmpty(coda)) { // Controllo che la coda non sia vuota
		printf("Errore, la coda e\' vuota\n");
		return;
	}
    printf("Il primo elemento in coda e\': %d", coda->ele[coda->first]);
}

