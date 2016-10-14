/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    double num1,num2,tot; // Utilizzo delle variabili double per il fattoriale in quanto si tratta di numeri generalmente abbastanza grandi
    int check,i,n;
    char c; // Utilizzo una variabile di tipo char per un controllo che verrà fatta sui dati in input

    do {
        printf("Inserisci un intero positivo: ");
        check = scanf("%d%c",&n,&c);
        getchar();
        fflush(stdin); // Pulisco il buffer della tastiera. Notare che questa funzione è compatibile solo con Windows
    } while (check != 2 || c!= '\n' || n<0); // Controllo che il numero sia un intero positivo e che il carattere successivo al numero sia "invio" (e non magari una virgola)

    num1 = num2 = tot = n; // Assegno a varie variabili che verranno usate successivamente il valore del numero inserito dall'utente
    printf("\nCalcolo il fattoriale usando il ciclo while \n");
    if (num1 <= 1) // Se il numero inserito è 0 o 1 restituisco immediatamente il risultato
		printf("Il fattoriale e\': 1\n\n");
	else { // Se il numero è maggiore di 1 uso un ciclo while per calcolare il fattoriale
		while (n>1) { // Fino a quando n è maggiore di 1 procedo a calcolare il fattoriale
			num1 = num1*(n-1); // Calcolo il fattoriale
			n--; // Diminuisco di 1 il valore di n, quando (n-1) = 1 interrompo il ciclo

		}

		printf("Il fattoriale e\': %lg\n\n",num1); // Stampo il fattoriale usando un modificatore di lunghezza per i double
	}

    printf("Calcolo il fattoriale usando il ciclo for \n");
    if (num2 <=1 ) // Se il numero inserito è 0 o 1 restituisco immediatamente il risultato
        printf("Il fattoriale e\': 1\n\n");
    else {
        for (i=1; (num2 - i)>0; i++) { //Fino a quando (n-1) è maggiore di 0 calcolo il fattoriale entrando nel ciclo for
            tot = tot*(num2 - i);
        }
        printf("Il fattoriale e\': %lg\n\n",tot);
    }



    system("pause"); // Compatibile solo con Windows

    return 0;


}
