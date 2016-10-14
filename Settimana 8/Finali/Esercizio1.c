/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Si scriva una funzione in C, denominata cerca, che ricerchi la presenza di un elemento in un vettore di interi.
      La funzione riceve in ingresso tre parametri: 1. un vettore di interi vettore[] nel quale ricercare il valore; 2. un valore intero dimensione
      che indica quanti elementi contiene il vettore; 3. il valore intero elem che deve essere ricercato. La funzione deve restituire:
      1. se il valore elem è presente nel vettore, allora la funzione restituisce l’indice della posizione nella quale si trova tale valore;
      2. se il valore elem è presente più volte, si restituisca l’indice di tutte le occorrenze; 3. se il valore elem non è presente nel vettore,
      si restituisca -1. Si modifichi poi la funzione cerca definendo la funzione cerca_vettore_ordinato che faccia le stesse cose descritte
      in precedenza ma su un vettore ordinato

*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define CLEAR_BUFFER do { c = getchar(); } while (c != '\n' && c != EOF); // Dichiaro una macro per pulire il buffer
#define ERR -1

// Prototipi delle funzioni
int* cerca(int *vect, int n, int valore);
int* cerca_vettore_ordinato(int *vect, int n, int valore);

int main()

{
    int *vect, *ptr, *vect1, *ptr1;
    int n, i, cercato, ris, c;

   srand((unsigned) time(NULL)); // Inizializzo i numeri casuali

    // Chiedo all'utente quanti elementi vuole inserire nell'array e controllo che l'input sia valido
    printf("Inserisci il numero di elementi del vettore: ");
    ris = scanf("%d", &n);
    CLEAR_BUFFER
    while (n <= 0 || n > INT_MAX || ris != 1) {
        printf("Errore, devi inserire un numero positivo valido: ");
        ris = scanf("%d", &n);
        CLEAR_BUFFER
    }

    // Alloco dinamicamente un array di interi composto da n elementi e controllo la corretta allocazione
    vect = (int*) malloc(n * sizeof(int));
    if (vect == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        return 1;
    }

    printf("\n\t\t ---- VETTORE NON ORDINATO ----\n\n");
    // Riempio il vettore con numeri casuali da 0 a 100
    for (i = 0; i < n; i++) {
        *(vect + i) = rand() % 100;
    }

    // Richiedo all'utente il numero da cercare ed eseguo un controllo per verificare che il numero inserito sia valido
    printf("\nInserisci un numero da cercare: ");
    ris = scanf("%d", &cercato);
    CLEAR_BUFFER
    while (n <= 0 || n > INT_MAX || ris != 1) {
        printf("Errore, devi inserire un numero positivo valido: ");
        ris = scanf("%d", &cercato);
        CLEAR_BUFFER
    }

    // Chiamo la funzione cerca passando come argomenti il vettore, la sua lunghezza e il numero da cercare
    ptr = cerca(vect, n, cercato);

    // Se il primo valore dell'array è diverso da -1, significa che il valore cercato è stato trovato almeno una volta
    if (ptr[0] != -1) {
        for (i = 0; i < n && ptr[i] != ERR; i++) // Scorro finchè non trovo -1
            printf("\nCorrispondenza in posizione: %d", ptr[i]+1); //Inizio a contare le posizioni da 1
    } else
        printf("\nIl valore cercato non e\' stato trovato (codice errore: %d)",ptr[0]);

    // Stampo il risultato
    printf("\n\nComposizione del vettore: ");
    for (i = 0; i < n; i++)
        printf("%d ", vect[i]);
    printf("\n\n\n");

    // Seconda parte programma
    printf("\t      VETTORE ORDINATO IN MODO CRESCENTE\n\n");
    // Alloco dinamicamente un array di interi composto da n elementi e controllo la corretta allocazione
    vect1 = (int*) malloc(n * sizeof(int));
    if (vect1 == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        return 1;
    }

    // Riempio il vettore con numeri casuali crescenti
    for (i = 0; i < n; i++) {
        *(vect1 + i) = (rand() % 10) + (i * 10);
    }

    // Richiedo all'utente il numero da cercare ed eseguo un controllo per verificare che il numero inserito sia valido
    printf("Inserisci un numero da cercare: ");
    ris = scanf("%d", &cercato);
    while (n <= 0 || n > INT_MAX || ris != 1) {
        printf("Errore, devi inserire un numero positivo valido: ");
        ris = scanf("%d", &cercato);
        CLEAR_BUFFER
    }

    // Eseguo le stesse operazioni di prima ma usando la funzione cerca_vettore_ordinato
    ptr1 = cerca_vettore_ordinato(vect1, n, cercato);

    if (ptr1[0] != -1) {
        for (i = 0; i < n && ptr1[i] != ERR; i++)
            printf("\nCorrispondenza in posizione: %d", ptr1[i]+1); //Inizio a contare le posizioni da 1
    } else
        printf("\nIl valore cercato non e\' stato trovato (codice errore: %d)\n\n",ptr1[0]);

    // Stampo il risultato
    printf("\n\nComposizione del vettore: ");
    for (i = 0; i < n; i++)
        printf("%d ", vect1[i]);

    // Libero tutte le aree di memoria allocate dinamicamente
    free(ptr);
    free(ptr1);
    free(vect);
    free(vect1);

    system("pause"); // Compatibile solo con Windows

    return 0;
}

// La funzione restituisce un puntatore ad intero e ha come parametri un vettore, la sua lunghezza e il numero da cercare
int* cerca(int *vect, int n, int valore)
{
    int i, j = 0, *ptr;

    ptr = (int*) malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }

    // Scorro il vettore per verificare se c'è una corrispondenza
    for (i = 0; i < n; i++)
        if (valore == vect[i]) { // Se trovo il vettore aumento mi salvo in un vettore ptr la sua posizione e aumento j
            ptr[j++] = i;
            ptr = (int*) realloc(ptr, (sizeof(int) * (j+1))); // Rialloco la grandezza del vettore ptr se trovo un nuovo elemento
            if (ptr == NULL) {
                printf("Errore durante l'allocazione dinamica della memoria");
                exit(EXIT_FAILURE);
            }
        }
    ptr = (int*) realloc(ptr, (sizeof(int) * (j+1)));
    if (ptr == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    ptr[j] = ERR; // Alla fine aggiungo il numero -1 che mi fa capire quando sono finite le corrispondenze

        return ptr; // Restituisco il puntatore ptr
}

// La funzione restituisce un puntatore ad intero e ha come parametri un vettore, la sua lunghezza e il numero da cercare
int* cerca_vettore_ordinato(int *vect, int n, int valore)
{
    int i, j = 0, *ptr1;

    ptr1 = (int*) malloc(sizeof(int));
    if (ptr1 == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n && valore >= vect[i]; i++) // Scorre il vettore fino alla fine o fino a quando il valore diventa minore di quelli contenuti sull'array
        if (valore == vect[i]) {
            ptr1[j++] = i;
            ptr1 = (int*) realloc(ptr1, (sizeof(int) * (j+1)));
            if (ptr1 == NULL) {
                printf("Errore durante l'allocazione dinamica della memoria");
                exit(EXIT_FAILURE);
            }
        }

    ptr1 = (int*) realloc(ptr1, (sizeof(int) * (j+1)));
    if (ptr1 == NULL) {
        printf("Errore durante l'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }
    ptr1[j] = ERR; // Alla fine aggiungo il numero -1 che mi fa capire quando sono finite le corrispondenze

        return ptr1;
}

