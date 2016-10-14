/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto LISTA, implementato sia tramite allocazione
      statica (vettore contenente la sola parte informativa di ogni elemento della lista) che in maniera dinamica con strutture
      collegate. Le funzioni che, come minimo, dovranno essere inserite nella libreria sono: inserisci in testa, inserisci in coda,
      inserisci dopo un certo elemento, cancella dalla testa, cancella dalla coda, cancella la prima occorrenza dell’elemento,
      cancella tutte le occorrenze dell’elemento, calcola la lunghezza della lista. Ove possibile, scrivere anche la versione
      ricorsiva di tali funzioni.
*/

#include <stdio.h>
#include <stdlib.h>
#include "listDin.h"

void initializeDin(LISTDIN_T **pTesta) // Inizializzo la testa a NULL
{
    *pTesta = NULL;
}

int isEmpty(LISTDIN_T **pTesta) // Controllo se la lista è vuota. In caso affermativo restituisco EMPTYLIST
{
    if (*pTesta == NULL)
        return EMPTYLIST;
    return 0;
}

// Questa funzione inserisce un elemento n in testa alla lista
void insertHead(LISTDIN_T **pTesta, int n)
{
    LISTDIN_T *newEle;

    newEle = (LISTDIN_T *) malloc(sizeof(LISTDIN_T)); // Alloco la memoria per un nuovo elemento
    if (newEle == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    newEle->elem = n; // Assegno al campo elem il parametro n
    newEle->next = *pTesta; // Assegno al campo next l'indirizzo a cui puntava la testa
    *pTesta = newEle; // Assegno alla testa l'indirizzo di newEle
}

//Questa funzione inserisce un elemento n in coda alla lista
void insertTail(LISTDIN_T **pTesta, int n)
{
    LISTDIN_T *newEle,*temp;

    newEle = (LISTDIN_T *) malloc(sizeof(LISTDIN_T));
    if (newEle == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    newEle->elem = n;
    newEle->next = NULL; // Il nuovo elemento punterà a NULL dato che si trova in testa

    if (*pTesta == NULL) // Controllo se la lista è vuota
        *pTesta = newEle;
    else {
        temp = *pTesta; // Salvo temporaneamente l'indirizzo della testa in temp
        while (temp->next != NULL) // Scorro la lista fino alla fine
            temp = temp->next;
        temp->next = newEle;

    }
}

// Questa funzione inserisce un elemento "n" dopo un elemento "value"
void insertAfter(LISTDIN_T **pTesta, int n, int value)
{
    LISTDIN_T *newEle, *temp;
    int trovato = 0;

    newEle = (LISTDIN_T*) malloc(sizeof(LISTDIN_T));
    if (newEle == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    newEle->elem = n;

    temp = *pTesta;

    if (isEmpty(pTesta) == EMPTYLIST) // Controllo che la lista non sia vuota
        printf("La lista e\' vuota");
    else {
        while (temp != NULL && trovato == 0) {
            if (temp->elem == value) {
                trovato = 1;
            }
            if (trovato == 0)
                temp = temp->next;
        }
        if (trovato) {
            newEle->next = temp->next; // Il nuovo elemento punterà a quello a cui puntava temp->next
            temp->next = newEle; // temp->next punterà al nuovo elemento
        } else
            printf("Elemento non trovato");
    }
}

// Questa funzione stampa la lista
void printListDin(LISTDIN_T **pTesta)
{
    LISTDIN_T *temp;

    if (isEmpty(pTesta) == EMPTYLIST)
        printf("La lista e\' vuota");
    else {
        temp = *pTesta; // Salvo la testa
        while (temp != NULL){ // Scorro la lista
            printf("%d ", temp->elem);
            temp = temp->next;
        }
    }
}

// Questa funzione calcola la lunghezza della lista
int lenList(LISTDIN_T **pTesta)
{
    LISTDIN_T *temp;
    int len = 0;

    temp = *pTesta;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    return len; // Restituisco la lunghezza

}

// Questa funzione cancella un elemento dalla testa
void cancelHead(LISTDIN_T **pTesta)
{
    LISTDIN_T *temp;

    if (isEmpty(pTesta) != EMPTYLIST) {
        temp = *pTesta;
        *pTesta = temp->next;
        free(temp); // Libero la memoria
    } else
        printf("Errore, la lista e\' vuota");
}

// Questa funzione cancella dalla coda
void cancelTail(LISTDIN_T **pTesta)
{
    LISTDIN_T *temp, *prev = NULL;

    if (isEmpty(pTesta) != EMPTYLIST) {
        temp = *pTesta;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) // Se c'è solo un elemento da eliminare, pongo la nuova testa uguale a NULL
            *pTesta = NULL;
        else
            prev->next = NULL; // Se c'è più id un elemento, assegno al campo next del precedente il valore NULL rendendolo in coda alla lista
        free(temp); // Libero la memoria dell'elemento da eliminare
    } else
        printf("Errore, la lista e\' vuota");
}

// Questa funzione cancella la prima occorenza di "n"
void cancelFirst(LISTDIN_T **pTesta, int n)
{
    LISTDIN_T *temp, *prev;
    int trovato = 0;

    temp = *pTesta;
    prev = NULL; // prev salva l'elemento precedente

    if (isEmpty(pTesta) != EMPTYLIST) {
       while (temp != NULL) {
            if (temp->elem == n) {
                if (prev == NULL) // Se l'elemento precedente è la testa
                    *pTesta = (*pTesta)->next;
                else
                    prev->next = temp->next;
                trovato = 1;
                free(temp); // Libero la memoria
                break;
            }
            prev = temp;
            temp = temp->next;
       }
    if(trovato)
        printf("Elemento eliminato con successo");
    else
        printf("Errore, elemento non trovato");
    } else
        printf("Errore, la lista e\' vuota");



}

// Cancello tutte le occorenze di "n"
void cancelAll(LISTDIN_T **pTesta, int n)
{
    LISTDIN_T *temp, *prev, *del;
    int trovato = 0;

    temp = *pTesta;
    prev = NULL;

    if (isEmpty(pTesta) != EMPTYLIST) {
       while (temp != NULL) {
            if (temp->elem == n) {
                if (prev == NULL)
                    *pTesta = (*pTesta)->next;
                else
                    prev->next = temp->next;
                trovato = 1;
                del = temp; // Salvo temporaneamente temp in del per liberare la memoria
                temp = temp->next;
                free(del);
            } else {
                prev = temp;
                temp = temp->next;
            }
       }
       if(trovato)
           printf("Elemento eliminato con successo");
       else
           printf("Errore, elemento non trovato");
    } else
        printf("Errore, la lista e\' vuota");
}

// Questa funzione stampa la lista in modo ricorsivo
void printListRec(LISTDIN_T **pTesta)
{
	LISTDIN_T *temp = NULL;
	temp = *pTesta;

	if (temp == NULL) { // Se temp è uguale a NULL e quindi siamo alla fine esco dalla funzione
		return;
	} else {
		printf("%d ", temp->elem);
		printListRec(&temp->next); // temp->next a ogni nuova chiamata si sostituisce alla testa
	}

}

// Questa funzione conta le occorenze di "n" in modo ricorsivo
void numberRec(LISTDIN_T **pTesta, int n)
{
	LISTDIN_T *temp = NULL;
	temp = *pTesta;
	static int count = 0; // Dichiaro una variabile static per contare il numero delle occorenze

        if (temp == NULL) { // Se siamo arrivati alla fine della lista
            if (count != 0) {
                printf("Sono state trovate %d occorrenze del numero %d", count, n);
                count = 0; // Ristabilisco il count a 0 una volta che ho stampato il numero di volte delle occorenze
            }else {
                printf("Il numero %d non e\' stato trovato all'interno della lista", n);
            }
            return;
        } else {
            if (temp->elem == n) {
                count++; // Se trovo una corrispondenza aumento count
            }
            numberRec(&temp->next, n); // Richiamo la funzione passando l'elemento successivo
        }
}

// Questa funzione resetta la lista e libera la memoria
void resetListRec(LISTDIN_T **pTesta)
{
    LISTDIN_T *temp;

    if (*pTesta == NULL) // Se siamo arrivati alla fine della lista
        return;

    temp = *pTesta;
    *pTesta = (*pTesta)->next; // Vado all'elemento successivo
    resetListRec(pTesta); // Richiamo la funzione
    free(temp); // Libero la memoria
}
