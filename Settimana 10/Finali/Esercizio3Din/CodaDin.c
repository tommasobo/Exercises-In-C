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
#include "CodaDin.h" // Includo la mia libreria "CodaDin.h"

void initialize(TipoCoda *coda) // Questa funzione inizializza la coda
{
    coda->first = coda->last = NULL;
}

void resetCoda(TipoCoda *coda) // Questa funzione resetta la coda e libera le aree di memoria allocate
{
    struct s_nodocoda *previous;

    coda->last= NULL; // Rsetto il puntatore a last coda
    while (coda->first != NULL){ // Sposto il puntatore a first coda fino alla last
        previous = coda->first;
        coda->first = previous->next;
        free(previous); // Libero la memoria di ogni elemento
    }
}

int isEmpty(TipoCoda coda) // Questa funzione controlla se la coda è vuota o meno
{
    return (coda.first == NULL);
}

int first(TipoCoda coda, int *elemento) // Restituisce il primo elemento
{
    if (coda.first == NULL) {
        return 0;
    }
    *elemento = coda.first->elem;
    return 1;
}

int deQueue(TipoCoda *coda, int *elemento) // Rimuove l'elemento inserito per primo e restituisce il suo valore
{
    struct s_nodocoda *current = coda->first;

    if (coda->first == NULL) {
        printf("Errore, la coda e\' vuota");
        return 0;
    }
    *elemento = current->elem;
    printf("Elimino l'elemento %d dalla coda", *elemento);
    if (coda->first == coda->last)
        coda->last = NULL;
    coda->first = current->next;
    free(current);
    return 1;
}

int enQueue(TipoCoda *coda, int elemento){ // Questa funzione inserisce un elemento
    struct s_nodocoda *nuovo;

    nuovo = (struct s_nodocoda*) malloc(sizeof(struct s_nodocoda));
    if (nuovo == NULL) {
        printf("Errore nell'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    nuovo->next = NULL;
    nuovo->elem = elemento;
    if (coda->first == NULL)
        coda->first = nuovo;
    if (coda->last != NULL)
        coda->last->next = nuovo;
    coda->last = nuovo;
    return 1;
}
