/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, **ptr; // Dichiaro ptr come puntatore di puntatore a carattere
    int i = 0, esci = 0, fine = 0, j, k, z;

    // Alloco lo spazio per il puntatore che punta alla prima parola
    ptr = (char**) malloc(sizeof(char*));
    // Controllo che la memoria venga allocata correttamente e in caso contrario stampo un errore
    if (ptr == NULL) {
        printf("Errore, memoria richiesta non disponibile");
        return 1;
    }

    // Richiedo all'utente di inserire una frase
    printf("Inserire una frase: ");

    for (i = 0; esci != 1; i++) { // i indica il numero delle parole che sono state inserite
        // Rialloco la memoria destinata ai puntatori che puntano alle parole e controllo che venga allocata correttamente
        ptr = (char**) realloc(ptr, (i+1) * sizeof(char*));
        if (ptr == NULL) {
            printf("Errore, memoria richiesta non disponibile");
            return 1;
        }
        // Alloco lo spazio per il primo carattere delle prima frase e controllo che venga allocata correttamente
        *(ptr + i) = (char*) malloc(sizeof(char));
        if (ptr[i] == NULL) {
            printf("Errore, memoria richiesta non disponibile");
            return 1;
        }

        fine = 0; // fine diventa uguale a 1 quando l'utente digita uno spazio finendo la parola
        for (j = 0; fine != 1; j++) {
            // Per ogni carattere che viene inserito rialloco lo spazio destinato ai caratteri per quella parola
            ptr[i] = (char*) realloc(ptr[i], (j+1) * sizeof(char));
            if (ptr[i] == NULL) {
                printf("Errore, memoria richiesta non disponibile");
                return 1;
            }

            c = getchar(); // Salvo momentaneamente il carattere che viene inserito in c
            if (c != '\n' && c!= ' ') // Se è diverso da uno spazio o da invio lo salzo
                ptr[i][j] = c;
            // Se è uguale a "Invio" imposto fine e esci a 1 in modo da uscire da entrambi i cicli for
            // Cambio il carattere di andata a capo con uno spazio per facilitare l'inversione della parola
            else if (c == '\n') {
                esci = fine = 1;
                ptr[i][j] = ' ';
            }
            // Se il carattere è uno spazio pongo fine a 1 in modo da terminare la parola e salvo lo spazio
            else if (c == ' ') {
                fine = 1;
                ptr[i][j] = ' ';
            }
        }
        // Aumento j (il numero di caratteri) e alloco un nuovo spazio di memoria e inserisco il carattere di terminazione '\0'
        j++;
        if (!(ptr[i] = (char*) realloc(ptr[i], (j + 1 ) * sizeof(char))))
            exit(1);
            *(ptr[i]+j) = '\0';
    }

    // Stampo la frase inserita inizialmente dall'utente
    printf("\nFrase inserita dall\'utente: ");
    for (k = 0; k < i; k++) {
        for (z = 0; ptr[k][z] != '\0'; z++)
            putchar(ptr[k][z]);
    }

    // Stampo la frase al contrario invertendo l'ordine delle parole
    printf("\nFrase stampata al contrario: ");
    for (k = i-1; k >= 0; k--) {
        for (z = 0; ptr[k][z] != '\0'; z++)
            putchar(ptr[k][z]);
    }
    printf("\n\n");

    // Dealloco la memoria
    for(j=0;j<i-1;j++)
        free(ptr[j]);
    free(ptr);

    system ("pause"); // Compatibile solo con Windows

    return 0;
}

