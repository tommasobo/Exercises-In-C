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

int checkValue(int n, int check, int min, int max);
void menu(TipoCoda *coda);
void exitmenu(TipoCoda *coda);

int main()
{
    TipoCoda coda; // Dichiaro una variabile di tipo "TipoCoda"
    int choice, check, n, value, exitmenu = 0;

    initialize(&coda); // Inizializzo la coda

    while (exitmenu != 1) {
        system(CLEAR);
        printf("\t\t ---- CODA DINAMICA ----\n\n");
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
            if (first(coda,&value))
                printf("Il primo elemento in coda e\': %d", value);
            else
                printf("Errore, la coda e\' vuota.");
            break;
        case 1 :
            printf("Inserisci il numero da inserire (Push): ");
            check = scanf("%d", &n);
            n = checkValue(n, check, 0, INT_MAX);
            enQueue(&coda, n);
            break;
        case 2 :
            deQueue(&coda, &value);
            break;
        case 3 :
            resetCoda(&coda); // Libero la memoria allocata dinamicamente
            exit(EXIT_SUCCESS);
        }
        printf("\n\nPremi 0 per continuare o 1 per uscire dal programma: ");
        check = scanf("%d", &exitmenu);
        exitmenu = checkValue(exitmenu, check, 0, 1);
    }
    resetCoda(&coda); // Libero la memoria allocata dinamicamente
    return 0;
}

void clearBuffer() // Definisco una funzione per pulire il buffer da tastiera che è completamente portabile
{
    char ch;
    do {
        ch = getchar();
    } while (('\n' != ch) && (EOF != ch));
}

int checkValue(int n, int check, int min, int max) // Questa funzione controlla l'input dell'utente
{
    while (n < min || n > max || check != 1) {
        clearBuffer();
        printf("Errore, devi inserire un numero valido compreso tra %d e %d: ", min, max);
        check = scanf("%d", &n);
    }

    return n;
}
