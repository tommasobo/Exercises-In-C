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
#include "listStat.h"

int isFull(LISTSTAT_T *listStat) // Questa funzione controlla se la lista è piena
{
    if (listStat->last == (N-1))
        return 1; // Se è piena restituisce 1
    return 0; // Se non è piena restituisce 0
}

void initialize(LISTSTAT_T *listStat) // Questa funzione inizializza la lista rendendo il campo last uguale a EMPTYLIST (-1)
{
    listStat->last = EMPTYLIST;
    return;
}

int next(LISTSTAT_T *listStat) // Questa funzione mi restituisce l'elmento successivo a quello corrente
{
    return (listStat->last + 1);
}

// Questa funzione inserisce un elemento "ele" in posizione "pos" all'interno della lista
void insert(LISTSTAT_T *listStat, int pos, int ele)
{
    int i;

    if (!isFull(listStat)){ // Controllo che la lista non sia piena
        if ((pos>=0) && (pos<= listStat->last+1)) { // Considero valido anche un inserimento nella prima posizione libera (End(l))
            for (i=listStat->last; i>=pos; i--)
                listStat->ele[i+1]=listStat->ele[i];
            listStat->last++; // Incremento di uno il numero di elementi della lista
            listStat->ele[pos] = ele;
        }
    }
}

void printList(LISTSTAT_T *listStat) // Questa funzione stampa la lista
{
    int i;

    if (listStat->last != -1) { // Controllo che la lista non sia vuota
        printf("La tua lista e\' formata dai seguenti elementi:\n");
        for (i=0; i <= listStat->last; i++) {
            printf("%d ", listStat->ele[i]);
        }
    } else
        printf("La lista e\' vuota");
}

// Questa funzione cancella un elemento dalla posizione pos
void del(LISTSTAT_T *listStat, int pos)
{
    int i;

    if (listStat->last != EMPTYLIST) { // Controllo che la lista non sia vuota
        if (pos >= 0 && pos <= listStat->last) {
            for (i = pos; i < listStat->last; i++)
                listStat->ele[i] = listStat->ele[i+1]; // Faccio scorrere tutti gli elementi a partire da pos
        listStat->last--; // Diminuisco il numero di elementi
        }


    }
}

// Questa funzione elimina tutte le occorenze di un elemento
void delAll(LISTSTAT_T *listStat, int value)
{
    int i, found = 0;

    if (listStat->last != EMPTYLIST) {
        for (i=0; i <= listStat->last; i++) {
            if (value == listStat->ele[i]) {
                del(listStat, i); // Richiamo la funzione del con i come posizione
                listStat->last--; // Diminuisco il numero di elementi
                found = 1;
            }
        }
    } else
        printf("Errore, la lista e\' vuota");

    if (found != 1)
        printf("Errore, elemento cercato non presente nella lista");
}

// Questa funzione trova un elemento all'interno della lista e restituisce la posizione
int find(LISTSTAT_T *listStat, int value)
{
    int i;

    if (listStat->last != EMPTYLIST) {
        for (i=0; i <= listStat->last; i++) {
            if (value == listStat->ele[i])
                return i; // restituisco la posizione
        }
    } else
        return EMPTYLIST; // Se la lista è vuota restituisco -1
    return UNDEFINED;
}
