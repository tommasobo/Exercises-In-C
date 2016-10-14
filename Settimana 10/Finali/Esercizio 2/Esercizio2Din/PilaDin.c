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
#include "PilaDin.h" // Includo la mia libreria "PilaDin.h"

void initialize(TipoPilaDin **pTesta) // Questa funzione inizializza la testa a NULL
{
    *pTesta = NULL;
}

int isEmpty(TipoPilaDin **pTesta) // Questa funzione verifica se la pila è vuota. In caso affermativo restituisce EMPTYLIST (-1)
{
    if (*pTesta == NULL)
        return EMPTYLIST;
    return 0;
}

// Questa funzione inserisce un elemento "n" nella pila
void push(TipoPilaDin **pTesta, int n)
{
    TipoPilaDin *newEle, *temp;

    newEle = (TipoPilaDin *) malloc(sizeof(TipoPilaDin));
    if (newEle == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    newEle->elem = n;
    newEle->next = NULL;

    if (*pTesta == NULL)
        *pTesta = newEle;
    else {
        temp = *pTesta;
        while (temp->next != NULL)
            temp = temp->next;
            temp->next = newEle;

    }
}

// Questa funzione elimina il primo elemento che è stato inserito dalla pila e restituisce l'elemento eliminato nella variabile value
void pop(TipoPilaDin **pTesta, int *value)
{
    TipoPilaDin *temp, *prev = NULL;

    if (isEmpty(pTesta) != EMPTYLIST) {
        temp = *pTesta;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) { // Se c'è solo un elemento da eliminare, pongo la nuova testa uguale a NULL
            *pTesta = NULL;
            *value = temp->elem;
            printf("Elimino dalla pila l'elemento %d", *value);
        }
        else {
            prev->next = NULL; // Se c'è più id un elemento, assegno al campo next del precedente il valore NULL rendendolo in coda alla lista
            *value = temp->elem;
            printf("Elimino dalla pila l'elemento %d", *value);
        }
        free(temp); // Libero la memoria dell'elemento da eliminare
    } else
        printf("Errore, la lista e\' vuota");
}

// Questa funzione stampa la pila
void printListDin(TipoPilaDin **pTesta)
{
    TipoPilaDin *temp;

    if (isEmpty(pTesta) == EMPTYLIST)
        printf("La pila e\' vuota");
    else {
        temp = *pTesta;
        while (temp != NULL){
            printf("%d ", temp->elem);
            temp = temp->next;
        }
        printf(" <-- Elemento affiorante della pila");
    }
}
