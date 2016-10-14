/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#define N_ELE 50 // Definisico il numero degli elementi degli array. In realtà ne basterebbero 32 dato che il numero massimo per un int nella architetture più moderne è 2^32-1


int main () {

	int resto[N_ELE], valore, numDecimale, i, j, k, temp;

	do {
		printf("Inserisci un valore positivo da convertire in binario: ");
		scanf("%d", &valore);
	} while (valore < 0);

    numDecimale = valore;
	if (valore == 0) // Se il numero inserito è 0, stampo immediatamente il risultato convertito in binario
		printf("\nIl codice binario corrispondente a %d e\': 0", numDecimale);
	else { // Se il numero inserito non è 0 uso un array per eseguire la conversione in binario
		for (i=0; valore >= 1; i++) {
			resto[i] = (valore % 2);
			valore = valore / 2;
		}
	}

    i  = i - 1; // Diminuisco di uno il valore di i per farlo corrispondere al numero dell'ultimo elemento usato nell array
    j = i;
    for (k=0; k <= i/2; k++, j--) {
        temp = resto[k];
        resto[k] = resto[j];
        resto[j] = temp;
    }

	printf("\nIl codice binario corrispondente a %d e\': ", numDecimale);
	for (k = 0; k <= i; k++) {
		printf("%d",resto[k]);
	}

    printf("\n\n");
    getchar();

	return 0;

}
