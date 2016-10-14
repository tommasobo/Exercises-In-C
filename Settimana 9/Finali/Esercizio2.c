/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Scrivere un programma C che legga una sequenza di caratteri e la stampi invertita; implementare sia
      una funzione ricorsiva che una iterativa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // Definisco la lunghezza massima della stringa (compreso il carattere di terminazione di stringa)

// Dichiaro i prototipi delle funzioni
void rev (char* str);
void reverse(char s[]);

int main() {

    char str[MAX]; // Dichiaro un array di char di lunghezza 100
    int length;

    printf("Inserisci una stringa (max 99 caratteri): ");
    fgets(str, MAX, stdin);
    length = strlen(str) - 1; // Tolgo l'ultimo carattere che viene salvato dalla fgets ovvero l'andata a capo sostituendolo con il terminatore di stringa
    if (str[length] == '\n')
        str[length] = '\0';


    printf("\nStringa invertita ricorsivamente: ");
    rev(str); // Chiarmo la funzione rev passandole come argomento la stringa str

    printf("\n\n");
    reverse(str); // Chiarmo la funzione reverse passandole come argomento la stringa str

    printf("\n");
    system("pause"); // Compatibile solo con Windows
    return 0;
}

void rev (char* str) {

    char c = *str;

    if (c != '\0') { // Se il carattere è diverso dal terminatore di stringa richiamo la funzione rev analizzando il carattere successivo (str + 1)
            rev(str + 1);
        putchar(c); // Una volta arrivati al passo base, "scorro" le funzioni aperte nello stack all'indietro andando a stampare i caratteri al contrario
    }
}


void reverse(char s[])
{
    int length = strlen(s); // Calcolo la lunghezza della stringa s e l'assegno alla variabile length
    int i;

    printf("Stringa invertita iterativamente: ");
    for (i = length - 1; i >= 0; i--) // Stampo la stringa al contrario partendo dall'ultimo elemento fino ad arrivare al primo (indice 0)
        putchar(s[i]);

}

