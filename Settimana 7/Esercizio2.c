/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Richiedo che il numero di studenti sia almeno 4 in modo da utilizzare le quattro modalità per stampare il voto
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mark[200], students, mod, i;
    int *ptr; // Dichiaro un puntatore ad intero

    ptr = mark; // Inizializzo il puntatore ptr che punta al primo elemento dell'array
    srand((unsigned) time(NULL)); // Inizializzo i numeri casuali

    printf("Numero studenti a cui si desidera inserire il voto (minimo 4 e massimo 200): ");
    scanf("%d", &students);
    // Controllo che il numero di studenti sia compreso tra 4 e 200
    while (students <= 3 || students > 200) {
        printf("Errore, devi inserire un numero compreso tra 4 e 200: ");
        scanf("%d", &students);
    }

    // Richiedo all'utente come preferisce inserire i voti
    printf("\nScelta modalita\' inserimento voti:");
    printf("\n\tPremere 0 per inserire i voti manualmente");
    printf("\n\tPremere 1 per inserire i voti casualmente in automatico ");
    scanf("%d", &mod);

    // Uso un case per controllare la scelta dell'utente
    switch (mod) {
    case 0 :
        for (i = 0; i < students; i++) {
            // Richiedo all'utente il voto dello studente
            printf("Inserisci il voto dello studente numero %d: ", i+1);
            scanf("%d", &mark[i]);
            // Controllo sia compreso tra 0 e 10
            while (mark[i] > 10 || mark[i] < 0) {
                printf("Errore, il voto deve essere compreso tra 0 e 10: ");
                scanf("%d", &mark[i]);
            }
        }
        break;
    case 1 :
        // Se viene premuto "1" inserisco i voti casualmente
        for (i = 0; i < students; i++)
            *(ptr + i) = (rand() % 10);
        break;
    default :
        printf("Errore, scelta non valida");
        return 1;
    }

    printf("\n\n");

    // Stampo i voti nelle quattro modalità differenti, con i vettori e con i puntatori
    printf("Voto 1: %d\n", *ptr); // Uso il puntatore e tramite l'operatore "*" stampo il contenuto a cui punta
    for (i = 1; i < (students - 2); i++) {
        printf("Voto %d: %d\n", i+1, mark[i]); // Uso l'indicizzazione con il vettore
    }
    printf("Voto %d: %d\n", i, ptr[i]); // Uso l'indicizzazione con il puntatore
    printf("Voto %d: %d\n", (i + 1), *(mark + i + 1)); // Uso il nome del vettore che è l'indirizzo di memoria del primo elemento e tramite l'operatore "*" stampo il contenuto a cui punta

    system("pause"); // Compatibile solo con Windows

    return 0;
}
