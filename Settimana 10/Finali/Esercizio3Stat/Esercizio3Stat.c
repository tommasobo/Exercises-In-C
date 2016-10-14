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

int checkValue(int n, int check, int min, int max);
void menu(TipoCoda *coda);
void exitmenu(TipoCoda *coda);

int main()
{
    TipoCoda coda; // Dichiaro una variabile coda di tipo "TipoCoda"

    initialize(&coda); // Inizializzo la variabile coda attraverso la funzione "initialize"

    menu(&coda);

    return 0;
}

void clearBuffer() // Definisco una funzione per pulire il buffer da tastiera che è completamente portabile
{
    char ch;
    do {
        ch = getchar();
    } while (('\n' != ch) && (EOF != ch));
}

int checkValue(int n, int check, int min, int max)
{
    while (n < min || n > max || check != 1) {
        clearBuffer();
        printf("Errore, devi inserire un numero valido compreso tra %d e %d: ", min, max);
        check = scanf("%d", &n);
    }

    return n;
}

void menu(TipoCoda *coda)
{
    int choice, check, n, value;

    system(CLEAR);
    printf("\t\t ---- CODA STATICA ----\n\n");
    printf("0 - Stampa il primo elemento della coda\n");
    printf("1 - Inserisci un elemento nella coda (EnQueue)\n");
    printf("2 - Cancella un elemento dalla coda (DeQueue)\n");
    printf("3 - Esci dal programma\n\n");
    printf("\nScegliere un opzione dal menu: ");
    check = scanf("%d", &choice);
    choice = checkValue(choice, check, 0, 3);
    printf("\n");

    switch(choice) {
    case 0 :
        printfirst(coda);
        exitmenu(coda);
        break;
    case 1 :
        printf("Inserisci il numero da inserire (EnQueue): ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        enQueue(coda, n);
        exitmenu(coda);
        break;
    case 2 :
        deQueue(coda, &value);
        exitmenu(coda);
    case 3 :
        exit(EXIT_SUCCESS);
    }
}

void exitmenu(TipoCoda *coda) // Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
{
    int option, check;

    printf("\n\nPremi 0 per continuare con una nuova operazione o 1 per uscire: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 1);

    if (option == 0)
        menu(coda);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}
