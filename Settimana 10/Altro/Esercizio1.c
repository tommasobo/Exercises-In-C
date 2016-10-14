#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

void menu(int option)
{
    switch (option) {
    case 1 :
        testa = inserisciTesta(&testa);
        break;
    }
}

void inserisciTesta(struct list **t)
{
    struct list *nuovo;
    int val;

    printf("Inserisci elemento che vuoi inserire in testa: ");
    scanf("%d", &val);
    nuovo = (struct list*)malloc(sizeof(struct list));
    nuovo->ele = val;
    nuovo->next = *t;
    *t = nuovo;

    return;
}


int main()
{
    int option, check;

    printf("\t\t ---- GESTIONE LISTE ----\n\n");
    printf("0 - Stampa la lista\n");
    printf("1 - Inserisci un elemento in testa\n");
    printf("2 - Inserisci un elemento in coda\n");
    printf("3 - Inserisci un elemento dopo un certo elemento\n");
    printf("4 - Cancella un elemento dalla testa\n");
    printf("5 - Cancella un elemento dalla coda\n");
    printf("6 - Cancella la prima occorenza di un elemento\n");
    printf("7 - Cancella tutte le occorenze di un elemento\n");
    printf("8 - Calcola la lunghezza della lista\n");
    printf("9 - Esci dal programma\n\n");
    printf("Scegliere un opzione dal menu: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 9);

    menu(option);


    return 0;
}
