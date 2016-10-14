/* Ho usato una versione leggermente modificata della libreria usata per le lista per usare nomi più chiari e funzioni ottimizzate */

/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto PILA, implementato tramite allocazione statica
      (vettore contenente la sola parte informativa di ogni elemento della lista), in maniera dinamica con strutture collegate
      e sfruttando la libreria scritta sulle liste.


*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "PilaStat.h" // Includo la mia libreria PilaStat.h

// Questa funzione verifica se la pila è piena e in caso affermativo restituisce 1.
int isFull(TipoPila *pila)
{
    if (pila->last == (MAX-1))
        return 1;
    return 0;
}

// Questa funzione controlla se la pila è vuota e in caso affermativo restituisce 1.
int isVoid(TipoPila *pila)
{
    if (pila->last == EMPTYLIST)
        return 1;
    return 0;
}

// Questa funzione inizializza la pila imponendo pila->last = EMPTYLIST (-1)
void initialize(TipoPila *pila)
{
    pila->last = EMPTYLIST;
    return;
}

// Questa funzione inserisce un elemento "ele" nella pila
void push(TipoPila *pila, int ele)
{

    if (isFull(pila)) // Controllo che la pila non sia piena
        printf("Errore, pila piena");
    else {
        pila->last++; // Aumento di 1 il numero elementi
        pila->ele[pila->last] = ele;
    }
}

// Questa funzione elimina l'ultimo elemento che è stato inserito
void pop(TipoPila *pila, int *value)
{

    if (isVoid(pila)) // Controllo che la pila non sia vuota
        printf("Errore, la pila e\' vuota");
    else {
        *value = pila->ele[pila->last];
        pila->last--; // Diminuisco di 1 il numero di elementi della pila
        printf("L\' elemento %d e\' stato eliminato con successo!", *value);
    }
}

// Questa funzione stampa la pila
void printList(TipoPila *pila)
{
    int i;

    if (pila->last != -1) {
        printf("La tua pila e\' formata dai seguenti elementi:\n");
        for (i=0; i <= pila->last; i++) {
            printf("%d ", pila->ele[i]);
        }
        printf(" <-- Elemento affiorante della pila");
    } else
        printf("La lista e\' vuota");
}

