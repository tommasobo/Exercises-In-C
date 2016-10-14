/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ELE 10

int main()
{
    int intero, *pIntero, i; // Dichiaro una variabile "normale" e una variabile puntatore per ogni tipo
    char carattere, *pCarattere;
    float reale, *pReale;
    int vettore[ELE], *pVettore;

    srand((unsigned) time(NULL)); // Inizializzo i numeri casuali usando il tempo attuale

    intero = (rand() % 100); // Calcolo un numero casuale compreso tra 0 e 100
    pIntero = &intero;
    printf("Il contenuto dell'inidirizzo di memoria %p e\': %d\n", (void *)pIntero, *pIntero);
    // Per stampare un indirizzo di memoria utilizzo l'apposito specificatore %p dopo aver convertito l'indirizzo stesso in un tipo void

    carattere = 126;
    pCarattere = &carattere; // Associo l'indirizzo di memoria della variabile carattere al puntatore pCarattere
    printf("Il contenuto dell'inidirizzo di memoria %p e\': %c\n", (void *)pCarattere, *pCarattere);

    reale = 126.55;
    pReale = &reale;
    printf("Il contenuto dell'inidirizzo di memoria %p e\': %g\n\n", (void *)pReale, *pReale);

    pVettore = vettore; // Il nome del vettore indica l'indirizzo di memoria del primo elemento
    for (i=0; i < ELE; i++) {
        vettore[i] = (rand() % 100);
        printf("Il contenuto dell'indirizzo di memoria %p e\': %d\n", (void *)(pVettore + i), pVettore[i]);
    }


    system("pause"); // Compatibile solo con Windows

    return 0;
}
