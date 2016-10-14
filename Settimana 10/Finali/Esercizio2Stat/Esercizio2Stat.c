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

int checkValue(int n, int check, int min, int max);
void menu(TipoPila *pila);
void exitmenu(TipoPila *pila);

int main()
{
    TipoPila pila; // Dichiaro una variabile di tipo "TipoPila"

    initialize(&pila); // Inizializzo la

    menu(&pila);

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

void menu(TipoPila *pila)
{
    int choice, check, n, value;

    system(CLEAR);
    printf("\t\t ---- PILA STATICA ----\n\n");
    printf("0 - Stampa la pila\n");
    printf("1 - Inserisci un elemento nella pila (Push)\n");
    printf("2 - Cancella un elemento dalla pila (Pop)\n");
    printf("3 - Esci dal programma\n\n");
    printf("\nScegliere un opzione dal menu: ");
    check = scanf("%d", &choice);
    choice = checkValue(choice, check, 0, 3);
    printf("\n");

    switch(choice) {
    case 0 :
        printList(pila);
        exitmenu(pila);
        break;
    case 1 :
        printf("Inserisci il numero da inserire (Pop): ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        push(pila, n);
        exitmenu(pila);
        break;
    case 2 :
        pop(pila, &value);
        exitmenu(pila);
    case 3 :
        exit(EXIT_SUCCESS);
    }
}

void exitmenu(TipoPila *pila) // Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
{
    int option, check;

    printf("\n\nPremi 0 per continuare con una nuova operazione o 1 per uscire: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 1);

    if (option == 0)
        menu(pila);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}
