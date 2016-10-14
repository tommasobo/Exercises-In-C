#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "listStat.h"

int checkValue(int n, int check, int min, int max);
void menu(LISTSTAT_T *listStat);
void exitmenu(LISTSTAT_T *listStat);

int main()
{
    LISTSTAT_T listStat;
    LISTDIN_T *testa;

    initialize(&listStat);
    initializeDin(&testa);

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

int checkValue(int n, int check, int min, int max)
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
    int choice, check, n, option, prev, position, temp;

    system(CLEAR);
    printf("\t\t ---- GESTIONE LISTE ----\n\n");
    printf("0 - Utilizzare lista statica\n");
    printf("1 - Utilizzare lista dinamica\n");
    printf("2 - Esci dal programma\n");

    printf("\nScegliere un opzione dal menu: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 2);
    system(CLEAR);

    if (option == 2)
        exit(EXIT_SUCCESS);

        }
    } else {
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
        case 0 :
            printList(listStat);
            exitmenu(listStat);
            break;
        case 1 :
            printf("Inserisci il numero da inserire in testa: ");
            check = scanf("%d", &n);
            n = checkValue(n, check, 0, INT_MAX);
            insert(listStat, 0, n);
            exitmenu(listStat);
            break;
        case 2 :
            printf("Inserisci il numero da inserire in coda: ");
            check = scanf("%d", &n);
            n = checkValue(n, check, 0, INT_MAX);
            insert(listStat, listStat->last + 1, n);
            exitmenu(listStat);
            break;
        case 3 :
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
        case 8 :
            printf("Numero elementi nella lista: %d", listStat->last != -1 ? listStat->last + 1 : 0);
        case 9 :
            exit(EXIT_SUCCESS);
        }
    }

}

void exitmenu(LISTSTAT_T *listStat) // Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
{
    int option, check;

    printf("\n\nPremi 0 per tornare al menu o 1 per uscire: ");
    check = scanf("%d", &option);
    option = checkValue(option, check, 0, 1);

    if (option == 0)
        menu(listStat);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}

