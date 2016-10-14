#include <stdlib.h>
#include <stdio.h>

int fattoriale(int num);

int main () {

    int val, fatt;

    // Chiedo all'utente un numero e controllo sia valido
    printf("Inserisci il numero di cui vuoi fare il fattoriale: ");
    scanf("%d", &val);
    while (val < 0 ) {
        printf("Errore, il numero deve essere maggiore o uguale a zero: ");
        scanf("%d", &val);
    }

    // Calcolo il fattoriale usando la funzione fattoriale
    fatt = fattoriale(val);
    printf("Il fattoriale di %d e\': %d", val, fatt);

    printf("\n\n");

    system("pause");
    return 0;
}


int fattoriale (int num) {

    int ris, j = 0;
    int static i = 0;

// Se il valore è 0 allora il fattoriale è 1 e ritorno subito il valore
    if (num == 0)
        return 1;

// Calcolo il fattoriale richiamando la funzione stessa ma come argomento n-1
    ris = num * fattoriale (num - 1);

// Indento
    for (j = 0; j < i; j++) {
           printf("\t");
    }

    printf("%d * fattoriale %d = %d\n", num, (num - 1), ris);

    i++;

    return ris;
}
