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
#include "listDin.h" // Uso la mia libreria listDin.h

int checkValue(int n, int check, int min, int max);
void exitmenu(LISTDIN_T **pTesta);
void menu(LISTDIN_T **pTesta);

int main()
{
    LISTDIN_T *testa; // Dichiaro un puntatore a LISTDIN_T

    initializeDin(&testa); // Lo inizializzo a NULL passandolo come puntatore di puntatore

    menu(&testa);

    // Libero la memoria quando viene premuto il tasto per uscire dal programma nella funzione menu

    return 0;
}

void clearBuffer() // Definisco una funzione per pulire il buffer da tastiera che è completamente portabile
{
    char ch;
    do {
        ch = getchar();
    } while (('\n' != ch) && (EOF != ch));
}

int checkValue(int n, int check, int min, int max) // Questa funzione controlla che l'input dell'utente sia valido
{
    while (n < min || n > max || check != 1) {
        clearBuffer();
        printf("Errore, devi inserire un numero valido compreso tra %d e %d: ", min, max);
        check = scanf("%d", &n);
    }

    return n;
}

void menu(LISTDIN_T **pTesta)
{
    int choice, check, n, prev;

    system(CLEAR);
    printf("\t\t ---- LISTE DINAMICHE ----\n\n");
    printf("0 - Stampa la lista\n");
    printf("1 - Inserisci un elemento in testa\n");
    printf("2 - Inserisci un elemento in coda\n");
    printf("3 - Inserisci un elemento dopo un certo elemento\n");
    printf("4 - Cancella un elemento dalla testa\n");
    printf("5 - Cancella un elemento dalla coda\n");
    printf("6 - Cancella la prima occorenza di un elemento\n");
    printf("7 - Cancella tutte le occorenze di un elemento\n");
    printf("8 - Calcola la lunghezza della lista\n");
    printf("9 - Stampa la lista (usando la ricorsione)\n");
    printf("10 - Cerca numero occorenze di un elemento (usando la ricorsione)\n");
    printf("11 - Azzera la lista (usando la ricorsione)\n");
    printf("12 - Esci dal programma\n\n");
    printf("\nScegliere un opzione dal menu: ");
    check = scanf("%d", &choice);
    choice = checkValue(choice, check, 0, 12);
    printf("\n");

    switch(choice) {
    case 0 :
        printListDin(pTesta);
        exitmenu(pTesta);
        break;
    case 1 :
        printf("Inserisci il numero da inserire in testa: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        insertHead(pTesta, n);
        exitmenu(pTesta);
        break;
    case 2 :
        printf("Inserisci il numero da inserire in coda: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        insertTail(pTesta, n);
        exitmenu(pTesta);
        break;
    case 3 :
        printf("Inserisci l'elemento dopo il quale vuoi inserire il tuo elmento: ");
        check = scanf("%d", &prev);
        prev = checkValue(prev, check, 0, INT_MAX);
        printf("Inserisci il numero da inserire dopo %d: ", prev);
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        insertAfter(pTesta, n, prev);
        exitmenu(pTesta);
        break;
    case 4 :
        cancelHead(pTesta);
        exitmenu(pTesta);
        break;
    case 5 :
        cancelTail(pTesta);
        exitmenu(pTesta);
        break;
    case 6 : // Cancella la prima occorenza di un elemento
        printf("Inserisci l'elemento che si vuole eliminare: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        cancelFirst(pTesta, n);
        exitmenu(pTesta);
        break;
    case 7 : // Cancella tutte le occorenze di un numero
        printf("Inserisci l'elemento che si vuole eliminare: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        cancelAll(pTesta, n);
        exitmenu(pTesta);
        break;
    case 8 :
        printf("Numero di elementi nella lista: %d", lenList(pTesta));
        exitmenu(pTesta);
        break;
    case 9 :
        if (isEmpty(pTesta) != EMPTYLIST) {
            printListRec(pTesta);
        } else
            printf("Errore, la lista e\' vuota");
        exitmenu(pTesta);
        break;
    case 10 :
        printf("Inserisci l'elemento che si vuole contare: ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        if (isEmpty(pTesta) != EMPTYLIST)
            numberRec(pTesta, n);
        else
            printf("Errore, la lista e\' vuota");
        exitmenu(pTesta);
        break;
    case 11 :
        if (isEmpty(pTesta) != EMPTYLIST) {
            resetListRec(pTesta);
            printf("Lista resettata!");
        } else
            printf("Errore, la lista e\' vuota");
        exitmenu(pTesta);
        break;
    case 12 :
        resetListRec(pTesta); // Libero la memoria usando la funzione resetListRec
        exit(EXIT_SUCCESS);
    }
}


void exitmenu(LISTDIN_T **pTesta) // Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
{
    int option, check;

    printf("\n\nPremi 0 per continuare con una nuova operazione o 1 per uscire: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 1);

    if (option == 0)
        menu(pTesta);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}
