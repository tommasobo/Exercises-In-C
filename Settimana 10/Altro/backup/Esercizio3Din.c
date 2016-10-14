#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CodaDin.h" // Includo la mia libreria "CodaDin.h"

int checkValue(int n, int check, int min, int max);
void menu(TipoCoda **primo, TipoCoda **ultimo);
void exitmenu(TipoCoda **primo, TipoCoda **ultimo);

int main()
{
    TipoCoda *primo = NULL; //Dichiaro due puntatori a TipoCoda e gli inizializzo a NULL
    TipoCoda *ultimo = NULL;

    menu(&primo, &ultimo);

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

void menu(TipoCoda **primo, TipoCoda **ultimo)
{
    int choice, check, n;

    system(CLEAR);
    printf("\t\t ---- PILA DINAMICA ----\n\n");
    printf("0 - Stampa la pila\n");
    printf("1 - Inserisci un elemento nella pila (EnQueue)\n");
    printf("2 - Cancella un elemento dalla pila (DeQueue)\n");
    printf("3 - Esci dal programma\n\n");
    printf("\nScegliere un opzione dal menu: ");
    check = scanf("%d", &choice);
    choice = checkValue(choice, check, 0, 3);
    printf("\n");

    switch(choice) {
    case 0 :
        printListDin(primo);
        exitmenu(primo, ultimo);
        break;
    case 1 :
        printf("Inserisci il numero da inserire (Push): ");
        check = scanf("%d", &n);
        n = checkValue(n, check, 0, INT_MAX);
        enQueue(primo, ultimo, n);
        exitmenu(primo, ultimo);
        break;
    case 2 :
        deQueue(primo);
        exitmenu(primo, ultimo);
    case 3 :
        exit(EXIT_SUCCESS);
    }
}

void exitmenu(TipoCoda **primo, TipoCoda **ultimo) // Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
{
    int option, check;

    printf("\n\nPremi 0 per continuare con una nuova operazione o 1 per uscire: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 1);

    if (option == 0)
        menu(primo, ultimo);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}
