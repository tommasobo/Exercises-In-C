/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#define N 2

int main()
{
    struct gestione_date { // Definisco la struttura
        int day;
        int month;
        int year;
    };

    struct gestione_date date[N];  // Dichiaro una variabile array di due elmementi di tipo struttura precedentemente definita
    int i, bisestile = 0;

    // Inizio un ciclo for per l'inserimento dei dati da parte dell'utente
    for (i = 0; i < N; i++) {
        printf("Data %d)\n",i+1);
        printf("\tInserisci il giorno: ");
        scanf("%d", &date[i].day);
        // Controllo che il giorno inserito sia compreso tra 1 e 31
        while (date[i].day < 1 || date[i].day > 31) {
            printf("\tErrore, devi inserire un giorno valido: ");
            scanf("%d", &date[i].day);
        }

        printf("\tInserisci il mese (in numero): ");
        scanf("%d", &date[i].month);
        // Controllo che il mese inserito sia compreso tra 1 e 12
        while (date[i].month < 1 || date[i].month > 12) {
            printf("\tErrore, devi inserire un mese valido: ");
            scanf("%d", &date[i].month);
        }

        // Controllo che il giorno inserito esista veramente nel mese scelto
        if ((date[i].month == 2 && date[i].day > 29) ||
            (date[i].month == 4 && date[i].day > 30) ||
            (date[i].month == 6 && date[i].day > 30) ||
            (date[i].month == 8 && date[i].day > 30) ||
            (date[i].month == 10 && date[i].day > 30)) {
            // Se il 31 non esiste nel mese scelto, stampo un errore
            printf("\tErrore, il mese numero %d contiene solo 30 giorni\n", date[i].month);
            i--; // Diminuisco di 1 i in modo che mi venga richiesto la stessa data alla prossima iterazione
            continue; // Uso un continue per tornare all'inizio del for
        }

        printf("\tInserisci l\'anno: ");
        scanf("%d", &date[i].year);
        // Controllo che l'anno inserito sia maggiore di 0
        while (date[i].year < 1) {
            printf("\tErrore, devi inserire un\'anno valido: ");
            scanf("%d", &date[i].year);
        }

        // Controllo che il mese sia bisestile
        if (((date[i].year % 4) == 0) && ((date[i].year % 100) != 0) )
            bisestile = 1;
        else if ((date[i].year % 400) == 0)
            bisestile = 1;

        // Se il mese non è bisestile stampo un errore e interrompo il ciclo tornando all'elemento precedente
        if ((bisestile != 1) && (date[i].day == 29)) {
            printf("\tErrore, il %d non era bisestile e quindi non esisteva il giorno %d\n", date[i].year, date[i].day);
            i--; // Diminuisco di 1 i in modo che mi venga richiesto la stessa data alla prossima iterazione
            continue; // Uso un continue per tornare all'inizio del for
        }
    }

    // Controllo con una serie di if/else quale delle due date si trova prima nel calendario
    if (date[0].year > date[1].year)
        printf("La prima dato sul calendario e\': %d/%d/%d", date[1].day, date[1].month, date[1].year);
    else if (date[0].year < date[1].year)
        printf("La prima dato sul calendario e\': %d/%d/%d", date[0].day, date[0].month, date[0].year);
    else {
        if (date[0].month > date[1].month)
            printf("La prima dato sul calendario e\': %d/%d/%d", date[1].day, date[1].month, date[1].year);
        else if (date[0].month < date[1].month)
            printf("La prima dato sul calendario e\': %d/%d/%d", date[0].day, date[0].month, date[0].year);
        else {
            if (date[0].day > date[1].day)
                printf("La prima dato sul calendario e\': %d/%d/%d", date[1].day, date[1].month, date[1].year);
            else if (date[0].day < date[1].day)
                printf("La prima dato sul calendario e\': %d/%d/%d", date[0].day, date[0].month, date[0].year);
            else
                printf("Le due date inserite coincidono");
        }
    }

    system("pause"); // Compatibile solo con Windows

    return 0;
}
