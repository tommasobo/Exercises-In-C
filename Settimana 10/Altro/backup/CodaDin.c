#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CodaDin.h" // Includo la mia libreria "CodaDin.h"

int isEmpty (TipoCoda **primo) // Questa funzione controlla se la coda è vuota. In caso affermativo restituisce uno
{
	if (*primo == NULL) {
		return 1;
	} else {
		return 0;
	}
}

// Questa funzione inserisce un elemento alla coda
void enQueue(TipoCoda **primo, TipoCoda **ultimo, int n)
{
	TipoCoda *temp;


    temp = (TipoCoda*)malloc(sizeof(TipoCoda));
    if (temp == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }

    temp->elem = n;
    temp->next = *ultimo;
    if (*primo == *ultimo && *primo == NULL) {
        *primo = temp;
        *ultimo = temp;
        temp->next = NULL;
    } else {
        (*ultimo)->next = temp;
        *ultimo = temp;
        temp->next = NULL;
    }
}

void deQueue(TipoCoda **primo)
{
	if (isEmpty(primo)) {
		printf("Errore, la pila e\' vuota");
		return;
	}
	printf("Elimino %d, ovvero l'elemento inserito meno di recente.\n", (*primo)->elem);
	(*primo) = (*primo)->next;
}

void printListDin(TipoCoda **primo)
{
    TipoCoda *temp;

	if (isEmpty(primo)) {
		printf("Errore, la pila e\' vuota.\n");
		return;
	}

    temp = *primo;
	while (temp != NULL) {
		printf("%d ",temp->elem);
        temp = temp->next;
	}

}
