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
#include <limits.h>
#include "listStat.h" // Includo la libreria listStat.h

int checkValue(int n, int check, int min, int max);
void menu(LISTSTAT_T *listStat);
void exitmenu(LISTSTAT_T *listStat);

int main()
{
    LISTSTAT_T listStat; // Dichiaro una variabile di tipo LISTSTAT_T

    initialize(&listStat); // Inizializzo la variabile passandola come puntatore

    menu(&listStat);

    return 0;
}

void clearBuffer() // Definisco una funzione per pulire il buffer da tastiera che è completamente portabile
{
    char ch;
    do {
        ch = getchar();
    } while (('\n' != ch) && (EOF != ch));
}

int checkValue(int n, int check, int min, int max) // Questa funzione controlla che l'input sia valido
{
    while (n < min || n > max || check != 1) {
        clearBuffer();
        printf("Errore, devi inserire un numero valido compreso tra %d e %d: ", min, max);
        check = scanf("%d", &n);
    }

    return n;
}

void menu(LISTSTAT_T *listStat)
{
    int choice, check, n, prev, position, temp;

    system(CLEAR);
    printf("\t\t ---- LISTE STATICHE ----\n\n");
    printf("0 - Stampa la lista\n");
    printf("1 - Inserisci un elemento in testa\n");
    printf("2 - Inserisci un elemento in coda\n");
    printf("3 - Inserisci dopo un certo elemento\n");
    printf("4 - Cancella un elemento dalla testa\n");
    printf("5 - Cancella un elemento dalla coda\n");
    printf("6 - Cancella la prima occorenza di un elemento\n");
    printf("7 - Cancella tutte le occorenze di un elemento\n");
    printf("8 - Calcola la lunghezza della lista\n");
    printf("9 - Esci dal programma\n\n");
    printf("\nScegliere un opzione dal menu: ");
    check = scanf("%d", &choice);
    choice = checkValue(choice, check, 0, 9);
    printf("\n");

    switch (choice) {
    case 0 : // Stampo la lista
        printList(listStat);
        exitmenu(listStat);
        break;
    case 1 : // Inserisco un nuovo elemento in testa
        printf("Inserisci il numero da inserire in testa: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        insert(listStat, 0, n);
        exitmenu(listStat);
        break;
    case 2 : // Inserisco un nuovo elemento in coda
        printf("Inserisci il numero da inserire in coda: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        insert(listStat, listStat->last + 1, n);
        exitmenu(listStat);
        break;
    case 3 : // Inserisco un nuovo elemento dopo un altro elemento
        printf("Inserisci l'elemento dopo il quale vuoi inserire il tuo elmento: ");
        check = scanf("%d", &prev);
        prev = checkValue(prev, check, 0, INT_MAX);
        position = find(listStat, prev);
        if (position == UNDEFINED)
            printf("Errore, elemento non presente nella lista");
        else if (position == EMPTYLIST)
            printf("Errore, la lista e\' vuota");
        else {
            printf("Inserisci il numero da inserire dopo %d: ", prev);
            check = scanf("%d", &n);
            n = checkValue(n, check, 0, INT_MAX);
            insert(listStat, position + 1, n);
        }
        exitmenu(listStat);
        break;
    case 4 : // Cancella un elemento dalla testa
        del(listStat, 0);
        exitmenu(listStat);
        break;
    case 5 : // Cancella un elemento dalla coda
        del(listStat, listStat->last);
        exitmenu(listStat);
        break;
    case 6 : // Cancella la prima occorenza di un elemento
        printf("Inserisci l'elemento che si vuole eliminare: ");
        check = scanf("%d", &temp);
        temp = checkValue(temp, check, 0, INT_MAX);
        position = find(listStat, temp);
        if (position == UNDEFINED)
            printf("Errore, elemento non presente nella lista");
        else if (position == EMPTYLIST)
            printf("Errore, la lista e\' vuota");
        else
            del(listStat, position);
        exitmenu(listStat);
        break;
    case 7 : // Cancella tutte le occorenze di un numero
        printf("Inserisci l'elemento che si vuole eliminare: ");
        check = scanf("%d", &temp);
        temp = checkValue(temp, check, 0, INT_MAX);
        delAll(listStat, temp);
        exitmenu(listStat);
        break;
    case 8 : // Calcolo il numero di elementi della lista
        printf("Numero elementi nella lista: %d", listStat->last != -1 ? listStat->last + 1 : 0); // Se la lista è vuota stampo 0
        exitmenu(listStat);
    case 9 :
        exit(EXIT_SUCCESS);
    }
}


void exitmenu(LISTSTAT_T *listStat) // Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
{
    int option, check;

    printf("\n\nPremi 0 per continuare con una nuova operazione o 1 per uscire: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 1);

    if (option == 0)
        menu(listStat);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}

