/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>


int main() {

	int array[4], num; // Inizializzo un array composto da 4 elementi in cui salverò le varie componenti del numero

	printf("Inserisci un numero intero maggiore di mille: ");
	scanf("%d", &num);

	while (num < 1000) { // Il numero inserito deve essere maggiore di 1000, se non lo è lo chiedo nuovamente all'utente
		printf("Errore, devi inserire un numero maggiore di 1000: ");
		scanf("%d", &num);
	}

	array[0] = (num / 1000); // Per trovare le migliaia basta semplicemente dividere il numero per 1000.
	array[1] = ((num % 1000) / 100); // Per le centinaia, prima calcolo il resto tra il numero e 1000 e poi lo divido per dieci
	array[2] = (((num % 1000) % 100) / 10); // Per le decine, prima calcolo il resto tra il numero e 1000, poi trovo il resto tra il nuovo numero e 100 e infine divido per dieci.
	array[3] = (((num % 1000) % 100) % 10); // Per le unità, prima calcolo il resto tra il numero e 1000, poi trovo il resto tra il nuovo numero e 100 e infine il resto tra il numero trovato e dieci

	printf("\nMigliaia: %d\nCentinaia: %d\nDecine: %d\nUnita: %d\n", array[0], array[1], array[2], array[3]); // Stampo gli elementi contenuti nell'array

	system("pause"); // Compatibile solo con Windows

	return 0;
}
