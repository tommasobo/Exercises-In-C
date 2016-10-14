/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#define DAYS 31 // Definisco la costante DAYS che indica il numero massimo di giorni in un mese

int main()
{
    int vet1[DAYS], vet2[DAYS], vet3[DAYS], i, j, k, days1, days2, conta;

    // Chiedo quanti giorni disponibili ha il primo collega
    printf("Numero giorni disponibili dal primo collega: ");
    scanf("%d", &days1);

    // Controllo che il dato inserito sia compreso tra 1 e 31
    while (days1 < 0 || days1 > 31) {
        printf("Errore, il numero di giorni deve essere compreso tra 0 e 31: ");
        scanf("%d", &days1);
    }

    // Chiedo quali sono i giorni disponibili al primo collega
    for (i=0; i < days1; i++) {
        printf("%d) Giorno disponibile: ", i+1);
        scanf("%d", &vet1[i]);
        // Controllo che il numero sia compreso tra 1 e 31
        while (vet1[i] <= 0 || vet1[i] > 31) {
            printf("Errore, devi inserire un giorno valido (tra 1 e 31): ");
            scanf("%d", &vet1[i]);
        }
        conta = 0;
        // Controllo che il numero inserito non sia già presente nell'array e in caso lo sia aumento la variabile conta
        for (j=0; j < days1; j++) {
            if (vet1[j] == vet1[i])
                conta++;
        }
        // Se conta è maggiore di uno e quindi ci sono doppioni visualizzo un errore e richiedo all'utente di inserire il valore
        if (conta > 1) {
            printf("Errore, il giorno %d e\' gia stato inserito\n", vet1[i]);
            i--; // Diminuisco i in modo che al prossimo ciclo mi venga richiesto
        }


    }

    // Chiedo quanti giorni disponibili ha il primo collega
    printf("\nNumero giorni disponibili dal secondo collega: ");
    scanf("%d", &days2);

    // Controllo che il dato inserito sia compreso tra 1 e 31
    while (days2 < 0 || days2 > 31) {
        printf("Errore, il numero di giorni deve essere compreso tra 0 e 31: ");
        scanf("%d", &days2);
    }

    // Elenco giorni disponibili del secondo collega
    for (i=0; i < days2; i++) {
        printf("%d) Giorno disponibile: ", i+1);
        scanf("%d", &vet2[i]);
        // Controllo che il numero sia compreso tra 1 e 31
        while (vet2[i] <= 0 || vet2[i] > 31) {
            printf("Errore, devi inserire un giorno valido (tra 1 e 31): ");
            scanf("%d", &vet2[i]);
        }
        conta = 0;
        // Controllo che il numero inserito non sia già presente nell'array e in caso lo sia aumento la variabile conta
        for (j=0; j < days2; j++) {
            if (vet2[j] == vet2[i])
                conta++;
        }
        // Se conta è maggiore di uno e quindi ci sono doppioni visualizzo un errore e richiedo all'utente di inserire il valore
        if (conta > 1) {
            printf("Errore, il giorno %d e\' gia stato inserito\n", vet2[i]);
            i--; // Diminuisco i in modo che al prossimo ciclo mi venga richiesto
        }


    }


    // Stampo i giorni disponibili dai due colleghi
    printf("\nGiorni disponibili del primo collega: ");
    for (i=0; i < days1; i++)
        printf("%d ", vet1[i]);
    printf("\nGiorni disponibili del secondo collega: ");
    for (i=0; i < days2; i++)
        printf("%d ", vet2[i]);
    puts("");

    // Confronto i due array e salvo i giorni in comune in un terzo array
    conta = 0;
    k = 0;
    for (i=0; i < days1; i++) {
        for (j=0; j < days2; j++) {
            if (vet1[i] == vet2[j]) {
                conta++; // Conto il numero di elementi in comune
                vet3[k] = vet1[i];
                k++;
            }
        }
    }

    // Se ci sono giorni in comune li stampo
    if (conta > 0) {
        printf("\nI due colleghi si possono incontrare %d volte il: ", conta);
        for (i=0; i < conta ; i++)
            printf("%d ", vet3[i]);
    }
    else {
        printf("\nI due colleghi non hanno giorni in comune quando incontrarsi");
    }

    printf("\n\n");
    system("pause"); // Compatibile solo con Windows

    return 0;
}
