/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <math.h> // Uso la funzione math.h per utilizzare la funzione pow
#define N_ELE 50 // Definisico il numero degli elementi degli array. In realtà ne basterebbero 32 dato che il numero massimo per un int nella architetture più moderne è 2^32-1


int main () {

	int resto[N_ELE], valore, numDecimale, i, j, k, temp, comp2;

	printf("Inserisci un valore positivo da convertire in binario: ");
    scanf("%d", &valore);

    numDecimale = valore; // Salvo la variabile valore in numDecimale in quanto in seguito la variabile valore verrà cambiata
	if (valore == 0) { // Se il numero inserito è 0, stampo immediatamente il risultato convertito in binario
		printf("\nIl codice binario corrispondente a %d e\': 0", numDecimale);
		return 0; // Esco immediatamente dal programma in quanto non ho bisogno di eseguirne il resto
	}

	if (valore > 0){ // Se il numero inserito è maggiore di zero uso un array per eseguire la conversione in binario
		for (i=0; valore >= 1; i++) {
			resto[i] = (valore % 2); // Salvo nella posizione i dell'array il resto tra il valore e 2
			valore = valore / 2; // Trovo il nuovo valore dividendolo per due
		}
		printf("\nIl codice binario corrispondente a %d e\': ", numDecimale);
	}

	else if (valore < 0) { // Se il numero inserito è negativo uso il complemento a due per trovare il corrispondente binario
        comp2 = pow(2,16); // Utilizzo il complemento a due usando 16 bit
        comp2 = comp2 + valore; // Trovo comp2 = 2^k + (-valore) con k uguale a 16 bit
        for (i=0; comp2 >= 1; i++) {
			resto[i] = (comp2 % 2); // Salvo nella posizione i dell'array il resto tra il valore trovato col complemento a due e 2
			comp2 = comp2 / 2; // Trovo il nuovo valore di comp2 dividendolo per due
        }
        printf("\nIl codice binario corrispondente a %d usando il complemento a 2 a 16 bit e\':\n", numDecimale);
	}

    i  = i - 1; // Diminuisco di uno il valore di i per farlo corrispondere al numero dell'ultimo elemento usato nell array
    j = i; // Assegno a j il valore di i
    for (k=0; k <= i/2; k++, j--) { // Eseguo un ciclo for che mi permette di invertire gli elementi dellì'array
        temp = resto[k]; // Salvo il primo elemento in una variabile temp
        resto[k] = resto[j]; // Salvo l'ultimo elemento nella posizione 0
        resto[j] = temp; // Salvo nell'ultimo elelmento il contenuto di temp e quindi del primo elemento dell'array
    }

	for (k = 0; k <= i; k++) { // Uso un ciclo for per stampare gli elementi realmente utilizzati dall'array
		printf("%d",resto[k]);
	}

    printf("\n\n");
    system("pause"); // Compatibile solo con Windows

	return 0;

}
