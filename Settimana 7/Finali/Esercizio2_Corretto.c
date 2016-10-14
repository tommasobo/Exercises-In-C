/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Versione 2: corretto mancato uso valore di ritorno della scanf

    * Richiedo che il numero di studenti sia almeno 4 in modo da utilizzare le quattro modalità per stampare il voto
    * Salvo i voti una volta con l'indicizzazione dei vettori e una volta con l'aritmetica dei puntatori
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int mark[200], students, mod, i,check;
    int *ptr; // Dichiaro un puntatore ad intero
    char ch;

    ptr = mark; // Inizializzo il puntatore ptr che punta al primo elemento dell'array
    srand((unsigned) time(NULL)); // Inizializzo i numeri casuali

    printf("Numero studenti a cui si desidera inserire il voto (minimo 4 e massimo 200): ");
    check = scanf("%d", &students);
    // Controllo che il numero di studenti sia compreso tra 4 e 200 e che l'input inserito sia valido grazie a check
    while (students <= 3 || students > 200 || check != 1) {
        while ((ch = getchar() != '\n') && (ch != EOF)); // Pulisco il buffer
        printf("Errore, devi inserire un numero compreso tra 4 e 200: ");
        check = scanf("%d", &students); // Controllo che il valore di ritorno della scanf sia uguale a 1 (match eseguito con successo)
    }

    // Richiedo all'utente come preferisce inserire i voti
    printf("\nScelta modalita\' inserimento voti:");
    printf("\n\tPremere 0 per inserire i voti manualmente");
    printf("\n\tPremere 1 per inserire i voti casualmente in automatico ");
    /* Non serve eseguire il controllo sul valore di ritorno della scanf in questo caso dato che eventuali valori non corretti
    inseriti dall'utente rientrano nel caso di default dello switch */
    scanf("%d", &mod);

    // Uso un case per controllare la scelta dell'utente
    switch (mod) {
    case 0 :
        for (i = 0; i < students; i++) {
            // Richiedo all'utente il voto dello studente
            printf("Inserisci il voto dello studente numero %d: ", i+1);
            check = scanf("%d", &mark[i]); // Lo salvo usando l'indicizzazione dei vettori
            // Controllo sia compreso tra 0 e 10 e che l'input inserito sia valido
            while (mark[i] > 10 || mark[i] < 0 || check != 1) {
                while ((ch = getchar() != '\n') && (ch != EOF)); // Pulisco il buffer
                printf("Errore, il voto deve essere compreso tra 0 e 10: ");
                check = scanf("%d", &mark[i]); // Controllo che il valore di ritorno della scanf sia uguale a 1 (match eseguito con successo)
            }
        }
        break;
    case 1 :
        // Se viene premuto "1" inserisco i voti casualmente
        for (i = 0; i < students; i++)
            *(ptr + i) = (rand() % 10); // Salvo i voti usando l'aritmetica dei puntatori
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
    printf("Voto %d: %d\n", i+1, ptr[i]); // Uso l'indicizzazione con il puntatore
    printf("Voto %d: %d\n", (i + 2), *(mark + i + 1)); // Uso il nome del vettore che è l'indirizzo di memoria del primo elemento e tramite l'operatore "*" stampo il contenuto a cui punta

    system("pause"); // Compatibile solo con Windows

    return 0;
}
