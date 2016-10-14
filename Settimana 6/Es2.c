/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 101

int main()
{
    char stringa[MAX];
    int i, j, conta, contac, contav;

    printf("Inserisci la tua stringa di massimo cento caratteri: "); // Se vengono inseriti più di 100 caratteri, quelli extra sono ignorati
    fgets(stringa, MAX, stdin); // La funzione fgets legge il flusso in input finchè il tasto invio non è premuto o sono stati letti (MAX-1) caratteri

    printf("\nLa tua stringa e\': %s", stringa);

    // Controllo per ognuna delle lettere dell’alfabeto, il numero di volte che la lettera compare nella stringa
    for (i=97; i < 123;i++) { // Eseguo un ciclo for a partire dal codice asci della lettera 'a' fino ad arrivare al codice asci della 'z'
        conta = 0; // Utilizzo una variabile conta per contare il numero di corrispondenze con la lettera che si sta confrontando
        for (j=0; j<(MAX-1) && stringa[j] != '\0'; j++) // Continuo il ciclo for fino a quando raggiungo il terminatore di stringa o l'ultimo carattere
            if (i == stringa[j] || (i-32) == stringa[j]) // Confronto la lettera del primo ciclo for e la sua corrispondente maiuscola con la lettere della mia stringa
                conta++;
        if (conta > 0)
            printf("La lettere %c appare %d volte.\n", i, conta);
    }

    // Controllo quante vocali e consonanti sono presenti nella stringa
    contac = contav = 0;
    for (i=0; i < (MAX-1) && stringa[i] != '\0'; i++) {
        tolower(stringa[i]); // Trasformo tutte le lettere della mia stringa in minuscolo per ridurre il numero di controlli da eseguire
        if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u')
            contav++; // Se c'è una corrispondenza tra la lettera attuale della stringa e una vocale aumento contav
        else if (isalpha(stringa[i])) // Altrimenti se il carattere considerato è una lettera, è sicuramente una consonante
            contac++;
    }

    // Stampo il numero di vocali e consonanti
    printf("\n\n");
    printf("Numero vocali: %d\nNumero consonanti: %d\n\n", contav, contac);

    system("pause");

    return 0;
}
