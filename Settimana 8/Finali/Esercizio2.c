/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it
    * Testo esercizio: Un’azienda deve gestire un certo numero di venditori che vendono un certo numero di prodotti. Una volta al giorno ognuno
      dei venditori fornisce al programma il proprio codice, il codice del prodotto venduto e la quantità del venduto giornaliero per quel prodotto.
      Scrivere un programma C che immagazzini i dati in una struttura dinamica e visualizzi le vendite totali dell’ultimo periodo per ognuno dei
      prodotti e per ognuno dei venditori. Il programma deve inoltre stilare una classifica sia dei prodotti che dei venditori riferita al singolo
      periodo e globale. Organizzare l’intero programma in funzioni.
*/

/*
    * Il programma � stato progettato per funzionare come gestionale di un magazzino per l'anno 2014 (fino a Ottobre compreso)
    * Non � possibile scegliere date dopo il 31 Ottobre 2014 e per comodità il programma funziona solo nell'anno attuale 2014
*/

// Includo le librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Verifico se il sistema che sto usando è Windows o altro, e a seconda del caso definisco CLEAR per il corretto funzionamento della funzione per la pulizia dello schermo
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif
// Definisco una macro per la pulizia del buffer
#define CLEAR_BUFFER do { c = getchar(); } while (c != '\n' && c != EOF);
#define MAX_CODE 10 // I codici dei venditori vanno da 0 a 10
#define MAX_PROD 20 // I codici dei prodotti vanno da 0 a 20

// Definisco un tipo di dato chiamato DATE_T che � formato da una struttura per la gestione della data
typedef struct
{
    int day;
    int month;
    int year;
} DATE_T;

// Definisco un tipo di dato chiamato DATE_T che è formato da una struttura (contenente a sua volta la struttura date) per la gestione dei dati
typedef struct {
    DATE_T date;
    int codice;
    int codiceProdotto;
    int n;
} GESTIONE_T;

// Dichiaro una variabile puntatore al tipo di dato GESTIONE_T
GESTIONE_T *gestione;

// Prototipi delle funzioni che verranno utilizzate
void menu(int *index);
int controllo(int val, int min, int max);
void add(GESTIONE_T *gestione,int *index);
void stampa(GESTIONE_T *gestione,int *index);
void classificaProdotti (GESTIONE_T *gestione, int *index);
void classificaVenditori (GESTIONE_T *gestione, int *index);
void exitmenu(int *index);


int main()
{
    int index = 0; // Index conterà il numero di elementi presenti
    srand ((unsigned) time(NULL));

    // Alloco lo spazio per la struttura di tipo GESTIONE_T
    gestione = (GESTIONE_T*) malloc(sizeof(GESTIONE_T));
    if (gestione == NULL) {
        printf("Errore durante l'allocazione della memoria");
        exit(EXIT_FAILURE);
    }
    // Stampo il menu usando la funzione "menu" passandogli l'indirizzo di index come argomento
    menu(&index);

    // Libero la memoria allocata dinamicamente
    free(gestione);

    system("pause"); // Compatibile solo con Windows

    return 0;
}

/*
 * Funzione menu
 * --------------------
 * Stampa il menu e permette all'utente di scegliere un opzione. L'input dell'utente viene controllato grazie alla funzione "controllo"
 * Non restituisce alcun dato essendo di tipo void, usa come parametro un puntatore ad intero che permette di controllare il numero di elementi
 */
void menu(int *index)
{
    int menu;

    system(CLEAR);

    printf("\t\t ---- MENU MAGAZZINO 2014 ----\n\n");
    printf("1 - Inserimento\n");
    printf("2 - Visualizza vendite\n");
    printf("3 - Classifica dei prodotti\n");
    printf("4 - Classifica dei venditori\n");
    printf("5 - Esci");

    printf("\nSelezionare un opzione: ");
    scanf("%d", &menu);
    menu = controllo(menu, 1, 5);

    switch (menu) {
    case 1 :
        add(gestione, index);
        break;
    case 2 :
        stampa(gestione, index);
        break;
    case 3 :
        classificaProdotti(gestione, index);
        break;
    case 4 :
        classificaVenditori(gestione, index);
        break;
    case 5 :
        exit(EXIT_SUCCESS);
    default :
        printf("Scelta non valida");
        exit(EXIT_FAILURE);
    }
}

/*
 * Funzione controllo
 * --------------------
 * Controlla che il numero inserito dall'utente sia valido.
 * Prende in ingresso tre valori: il numero su cui eseguire il controllo e i due estremi (inferiore e superiore) su cui fare il controllo
 * Restituisce il valore (un intero) dopo che il controllo è risultato valido
*/
int controllo(int val, int min, int max)
{
    int c;

    CLEAR_BUFFER
    while (val < min || val > max) {
        printf("Errore, il numero deve essere compreso tra %d e %d: ", min, max);
        scanf("%d", &val);
        CLEAR_BUFFER
    }

    return val;

}

/*
 * Funzione add
 * --------------------
 * La funzione permette di aggiungere un elemento (record) o in modalità manuale o in modalità automatica.
 * L'allocazione della memoria avviene dinamicamente
 * La modalità automatica riempe in automatico i dati riguardati l'ultimo mese di attività (Ottobre 2014)
 * La modalità manuale permette di scegliere i vari dati. E' presente il controllo sull'input dell'utente
*/
void add(GESTIONE_T *gestione, int *index)
{
    int scelta, j;
    int i = *index;

    system(CLEAR);
    printf("Per inserire manualmente un nuovo elemento digita 1.\n");
    printf("Per un inserimento casuale digita 0: ");
    scanf("%d",&scelta);
    scelta = controllo(scelta,0,1);

    if (scelta == 1) {
        gestione = (GESTIONE_T*) realloc(gestione, (*index+1) * sizeof(GESTIONE_T));
        if (gestione == NULL) {
            printf("Errore durante l'allocazione della memoria");
            exit(EXIT_FAILURE);
        }

        printf("\t\t ---- INSERIMENTO ----\n\n");
        printf("\nInserisci il tuo codice identificativo (0-10): ");
        scanf("%d", &gestione[i].codice);
        gestione[i].codice = controllo(gestione[i].codice, 0, MAX_CODE);

        printf("\nInserisci il codice del prodotto (0-20): ");
        scanf("%d", &gestione[i].codiceProdotto);
        gestione[i].codiceProdotto = controllo(gestione[i].codiceProdotto, 0, MAX_PROD);

        printf("\nInserisci il numero di oggetti venduti: ");
        scanf("%d", &gestione[i].n);
        gestione[i].n = controllo(gestione[i].n, 0, INT_MAX);

        printf("\nInserisci il giorno: ");
        scanf("%d", &gestione[i].date.day);
        gestione[i].date.day = controllo(gestione[i].date.day, 1, 31);

        printf("\nInserisci il mese in numero (1-10): ");
        scanf("%d", &gestione[i].date.month);
        gestione[i].date.month = controllo(gestione[i].date.month,  1, 10);

        gestione[i].date.year = 2014; // Decido che l'anno è il 2014

        (*index)++; // Aumento di uno index che mi tiene conto del numero di elementi presenti
        printf("Inserimento avvenuto con successo!\n");

    } else if (scelta == 0) {

        for (j = 0; j < 31; j++) {
            gestione = (GESTIONE_T*) realloc(gestione, (*index+1) * sizeof(GESTIONE_T));
            if (gestione == NULL) {
                printf("Errore durante l'allocazione della memoria");
                exit(EXIT_FAILURE);
            }
            gestione[j].codice = rand() % MAX_CODE;
            gestione[j].codiceProdotto = rand() % MAX_PROD;
            gestione[j].n = rand() % 100;
            gestione[j].date.day = j+1;
            gestione[j].date.month = 10;
            gestione[j].date.year = 2014;
            (*index)++;
        }
        printf("Inserimento avvenuto con successo!\n");
    }

    exitmenu(index);
}

/*
 * Funzione stampa
 * --------------------
 * Questa funzione permette di stampare a video il contenuto del database
 */
void stampa(GESTIONE_T *gestione, int *index)
{
    int i, j, scelta, mese, giorno;
    i = (*index);
    system(CLEAR);

    printf("Premi 1 se vuoi visualizzare la classifica globale");
    printf("\nPremi 0 se vuoi visualizzare la classifica scegliendo il mese e giorno: ");
    scanf("%d", &scelta);
    scelta = controllo(scelta, 0, 1);

    if (scelta == 1) {
        if (i != 0)
            for (j = 0; j < i; j++) {
                    printf("\n\nInserito in data: %d/%d/%d", gestione[j].date.day, gestione[j].date.month, gestione[j].date.year);
                    printf("\n\tCodice venditore: %d - Codice prodotto: %d - Numero vendite: %d\n", (gestione + j)->codice, gestione[j].codiceProdotto, gestione[j].n);
            }
        else
            printf("Non ci sono elementi");
    }
    else {
        if (i != 0) {
            printf("Inserisci il mese da cui visualizzare la lista (Max 10): ");
            scanf("%d", &mese);
            mese = controllo(mese, 1, 10);

            printf("Inserisci il giorno da cui visualizzare la lista: ");
            scanf("%d", &giorno);
            giorno = controllo(giorno, 1, 31);

            for (j = 0; j < i; j++) { // Con un if controllo che vengano stampate solamente i dati inseriti dopo la data richiesta dall'utente
                if (gestione[j].date.month > mese ) {
                    printf("\n\nInserito in data: %d/%d/%d", gestione[j].date.day, gestione[j].date.month, gestione[j].date.year);
                    printf("\n\tCodice venditore: %d - Codice prodotto: %d - Numero vendite: %d\n", (gestione + j)->codice, gestione[j].codiceProdotto, gestione[j].n);
                }
                else if (gestione[j].date.month == mese && gestione[j].date.day >= giorno) {  // Se il mese è lo stesso confronto i giorni
                    printf("\n\nInserito in data: %d/%d/%d", gestione[j].date.day, gestione[j].date.month, gestione[j].date.year);
                    printf("\n\tCodice venditore: %d - Codice prodotto: %d - Numero vendite: %d\n", (gestione + j)->codice, gestione[j].codiceProdotto, gestione[j].n);
                }
            }
        } else
            printf("Non ci sono elementi");
    }
    exitmenu(index);

}

/*
 * Funzione exitmenu
 * --------------------
 * Questa funzione chiede all'utente se vuole tornare al menu o se vuole uscire dal programma
 */
void exitmenu(int *index)
{
    int option;

    printf("\n\nPremi 0 per tornare al main o 1 per uscire: ");
    scanf("%d", &option);
    option = controllo(option, 0, 1);

    if (option == 0)
        menu(index);
    else if (option == 1)
        exit(EXIT_SUCCESS);
}

/*
 * Funzione classificaProdotti
 * --------------------
 * Questa funzione stampa i prodotti classificandoli da quello più venduto a quello menu venduto
 */
void classificaProdotti(GESTIONE_T *gestione, int *index)
{
    int scelta, giorno, mese, vet[21] = {0}, j, i, k, max, temp; // Il vettore vet è un array di appoggio in cui salvero le vendite per i 20 prodotti
    i = *index;
    system(CLEAR);

    if (i != 0) { // Controllo che ci sia almeno un elemento nel database
        printf("Premi 1 se vuoi visualizzare la classifica globale");
        printf("\nPremi 0 se vuoi visualizzare la classifica scegliendo il mese e giorno: ");
        scanf("%d", &scelta);
        scelta = controllo(scelta, 0, 1);

        // Uso un vettore temporaneo per aumentare  il numero di volte che ogni prodotto viene venduto
        if (scelta == 1) {
            for (j = 0; j < i; j++) {
                temp = gestione[j].codiceProdotto;
                vet[temp] = vet[temp] + gestione[j].n;
            }

            printf("\n\t\t ---- CLASSIFICA PER PRODOTTO GLOBALE ----\n");

            // Inizio due cicli for per scorrere l'array vet e per trovare il massimo al suo interno
            for (k = 0; k < MAX_PROD; k++) {
                for (j = 0; j < MAX_PROD; j++) {
                    if (vet[j] > max) {
                        max = vet[j];
                        temp = j; // Salvo la posizione del massimo in temp
                    }
                }
                if (vet[temp] != 0) // Se il contenuto di vet[temp] è stato modificato e quindi non è più 0, allora lo stampo
                    printf("\n%d): Codice Prodotto #%d con %d vendite.", k+1, temp, vet[temp]);
                max = -1; // Imposto nuovamente il massimo a -1
                vet[temp] = 0; // Imposto a 0 il precedente massimo in modo che non al prossimo ciclo for non sia valutato
            }

        } else {
            printf("Inserisci il mese da cui visualizzare la lista (Max 10): ");
            scanf("%d", &mese);
            mese = controllo(mese, 1, 10);

            printf("Inserisci il giorno da cui visualizzare la lista: ");
            scanf("%d", &giorno);
            giorno = controllo(giorno, 1, 31);

            // Uso un vettore temporaneo per aumentare  il numero di volte che ogni prodotto viene venduto dopo aver controllato di usare solamente la data successiva a quella inserita dall'utente
            for (j = 0; j < i; j++) {
                if (gestione[j].date.month > mese ) {
                    temp = gestione[j].codiceProdotto;
                    vet[temp] = vet[temp] + gestione[j].n;
                }
                else if (gestione[j].date.month == mese && gestione[j].date.day >= giorno) { // Se i mesi corrispondono controllo i giorni
                    temp = gestione[j].codiceProdotto;
                    vet[temp] = vet[temp] + gestione[j].n;
                }
            }

            printf("\n\t\t ---- CLASSIFICA PER PRODOTTO DAL %d/%d/2014 ----\n", giorno, mese);

            // Inizio due cicli for per scorrere l'array vet e per trovare il massimo al suo interno
            for (k = 0; k < MAX_PROD; k++) {
                for (j = 0; j < MAX_PROD; j++) {
                    if (vet[j] > max) {
                        max = vet[j];
                        temp = j; // Salvo la posizione del massimo in temp
                    }
                }
                if (vet[temp] != 0) // Se il contenuto di vet[temp] è stato modificato e quindi non è più 0, allora lo stampo
                    printf("\n%d): Codice Prodotto #%d con %d vendite.", k+1, temp, vet[temp]);
                max = -1; // Imposto nuovamente il massimo a -1
                vet[temp] = 0; // Imposto a 0 il precedente massimo in modo che non al prossimo ciclo for non sia valutato
            }
        }
    } else
        printf("Non sono presenti elementi");
    exitmenu(index);
}

/*
 * Funzione classificaVenditori
 * --------------------
 * Questa funzione stampa i venditori classificandoli da quello che ha venduto di più a quello che ha venduto meno
 * Il funzionamento è analogo a quello della funzione classificaProdotti che è già stato commentato
 */
void classificaVenditori(GESTIONE_T *gestione, int *index)
{
    int scelta, giorno, mese, vet[11] = {0}, j, i, k, max, temp;
    i = *index;
    system(CLEAR);

    if (i != 0) {
        printf("Premi 1 se vuoi visualizzare la classifica globale");
        printf("\nPremi 0 se vuoi visualizzare la classifica scegliendo il mese e giorno: ");
        scanf("%d", &scelta);
        scelta = controllo(scelta, 0, 1);

        // Uso un vettore temporaneo per contare il numero di volte che ogni prodotto è stato venduto
        if (scelta == 1) {
            for (j = 0; j < i; j++) {
                temp = gestione[j].codice;
                vet[temp] = vet[temp] + gestione[j].n;
            }

            printf("\n\t\t ---- CLASSIFICA PER VENDITORE GLOBALE ----\n");

            for (k = 0; k < MAX_CODE; k++) {
                for (j = 0; j < MAX_CODE; j++) {
                    if (vet[j] > max) {
                        max = vet[j];
                        temp = j;
                    }
                }
                if (vet[temp] != 0)
                    printf("\n%d): Codice Venditore #%d con %d vendite.", k+1, temp, vet[temp]);
                max = 0;
                vet[temp] = 0;
            }

        } else {
            printf("Inserisci il mese da cui visualizzare la lista (Max 10): ");
            scanf("%d", &mese);
            mese = controllo(mese, 1, 10);

            printf("Inserisci il giorno da cui visualizzare la lista: ");
            scanf("%d", &giorno);
            giorno = controllo(giorno, 1, 31);

            // Uso un vettore temporaneo per aumentare contare il numero di volte che ogni prodotto appare
            for (j = 0; j < i; j++) {
                if (gestione[j].date.month > mese ) {
                    temp = gestione[j].codice;
                    vet[temp]++;
                }
                else if (gestione[j].date.month == mese && gestione[j].date.day >= giorno) {
                    temp = gestione[j].codice;
                    vet[temp]++;
                }
            }

            printf("\n\t\t ---- CLASSIFICA PER VENDITORE DAL %d/%d/2014 ----\n", giorno, mese);

            for (k = 0; k < MAX_CODE; k++) {
                for (j = 0; j < MAX_CODE; j++) {
                    if (vet[j] > max) {
                        max = vet[j];
                        temp = j;
                    }
                }
                if (vet[temp] != 0)
                    printf("\n%d): Codice Prodotto #%d con %d vendite.", k+1, temp, vet[temp]);
                max = -1;
                vet[temp] = 0;
            }
        }
    } else
        printf("Non sono presenti elementi");

    exitmenu(index);
}
