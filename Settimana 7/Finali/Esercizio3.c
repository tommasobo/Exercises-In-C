+/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Nel programma ho usato alternativamente l'aritmetica dei puntatori e la notazione vettoriale
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main()
{
    int n, i, search, max, min, flag, temp, *ptr;

    // Inizializzo i numeri casuali
    srand((unsigned) time(NULL));

    // Chiedo all'utente il numero di elementi del vettore e controllo che sia positivo
    printf("Inserire il numero di elementi con cui si desidera lavorare: ");
    scanf("%d", &n);
    while (n <= 0 ) {
        printf("Errore, il numero di elementi deve essere positivo: ");
        scanf("%d", &n);
    }

    // Uso la funzione malloc per allocare n elementi di tipo intero in memoria
    ptr = (int*) malloc(n * sizeof(int));
    // Se l'allocazione è fallita stampo un errore e esco dal programma
    if (ptr == NULL) {
        printf("\nErrore durante l'allocazione di memoria");
        return 1;
    }

    // Inizializzo il vettore dinamico con dei numeri casuali compresi tra 0 e 100
    for (i = 0; i < n; i++)
        *(ptr + i) = rand() % 10;

    // Stampo il vettore dinamico
    printf("\nElmementi vettore allocato dinamicamente:\n");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);

    // Ricerca di un elemento
    flag = 0;
    printf("\n\nCerca la posizione di un elemento: ");
    scanf("%d", &search);
    // Controllo che l'elemento cercato sia positivo
    while (search < 0 || search > INT_MAX) {
        printf("Errore, l'elemento cercato deve essere positivo: ");
        scanf("%d", &search);
    }
    // Confronto l'elemento cercato con quelli presenti nell'array
    for (i = 0; i < n; i++)
        if (*(ptr + i) == search) {
            printf("L\'elemento %d si trova in posizione %d\n", search, i+1);
            flag = 1;
        }
    if (!flag)
        printf("L\'elemento %d non e\' stato trovato nel vettore\n", search);

    // Cerco il minimo e il massimo del vettore
    max = 0;
    min = 100;
    for (i = 0; i < n; i++) {
        if (ptr[i] > max)
            max = *(ptr + i);
        if (*(ptr + i) < min)
            min = ptr[i];
    }

    // Eseguo il reverse del vettore
    for (i = 0; i < (n/2); i++) {
        temp = *(ptr+n-i-1);
        ptr[n-i-1] = ptr[i];
        *(ptr + i) = temp;

    }

    // Stampo il minimo e il massimo
    printf("\nIl massimo e\' %d, il minimo e\' %d\n", max, min);

     // Stampo il vettore dinamico
    printf("\nElmementi vettore dopo il reverse:\n");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    printf("\n\n");

    // Libero la memoria allocata dinamicamente
    free(ptr);

    system("pause"); // Compatibile solo con Windows

    return 0;
}

