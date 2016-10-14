/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define MAX 100

int main()
{
    int n, i, j, max, maxtemp, conta[MAX] = {0}, temp;
    int **ptr;

    // Inizializzo i numeri casuali
    srand((unsigned) time(NULL));

    // Richiedo all'utente il numero di vettori che desidera allocare
    printf("Quanti vettori si desidera allocare: ");
    scanf("%d", &n);

    // Controllo che il numero sia positivo e entro il range massimo degli interi
    while (n <= 0 || n > INT_MAX) {
        printf("Errore, devi inserire un intero valido maggiore di zero: ");
        scanf("%d", &n);
    }


    // Alloco n celle di memoria di tipo puntatore ad intero
    ptr = (int**)malloc(n * sizeof(int*));
    // Controllo che esista lo spazio richiesto, e in caso negativo stampo un errore
    if (ptr == NULL) {
        printf("Errore, memoria richiesta non disponibile");
        return 1;
    }

    // Genero per gli n puntatori creati dei vettori allocati dinamicamente con la funzione malloc di lunghezza da 2 a n+1;
    for (i = 0; i < n; i++) {
        ptr[i] = (int*)malloc((i+2)*sizeof(int));
        if (ptr[i] == NULL) {
            printf("Errore, memoria richiesta non disponibile");
            return 1;
        }
        // Riempio casualmente i vettori con dei numeri compresi tra 0 e MAX (100)
        for (j = 0; j < (i + 2); j++) {
             *(ptr[i] + j) = rand() % MAX;
        }
    }

    // Cerco il massimo scorrendo i vari vettori e salvando il numero più grande in una variabile max
    max = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < (i + 2); j++)
            if (ptr[i][j] > max)
                max = ptr[i][j];

    }

    // Cerco il valore ripetuto più volte fra tutti i vettori.
    // Uso un vettore "conta" in cui le posizioni del vettore corrispondono al numero di volte che si ripetono i valori di ptr[i]
    temp = maxtemp = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < (i + 2); j++) {
            temp = ptr[i][j];
            conta[temp]++;
        }
    // Salvo in maxtemp il valore massimo che rappresenta la posizione del numero che si ripete più volte
    for (i = 0; i < MAX; i++) {
        if (conta[i] > maxtemp)
            maxtemp = conta[i];
    }

     // Stampo i vettori generati
    for (i = 0; i < n; i++) {
        printf("Array %d)", i+1);
        for (j = 0; j < (i + 2); j++)
            printf(" %d ", ptr[i][j]);
        printf("\n");
    }

    // Stampo il massimo e il valore ripetuto più volte
    printf("\n\nIl massimo e\': %d", max);
    for (i = 0; i < MAX; i++)
        if (conta[i] == maxtemp)
            printf("\nIl valore piu\' ripetuto e\' %d per %d volte", i, maxtemp);

    // Libero la memoria allocata dinamicamente usando la funzione free
    for (i = 0; i < n;i++){
        free(*(ptr + i));
    }
    free(ptr);

    system("pause"); // Compatibile solo con Windows

    return 0;
}
