/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>


int main()
{

    int num, x;

    printf("Inserisci un numero positivo intero: ");
    scanf("%d", &num);

    while (num <= 0) { // Controllo se il numero inserito è positivo
        printf("Errore, devi inserire un numero maggiore di zero: ");
        scanf("%d", &num);
    }

	if (num == 1) // Se il numero è 1, esiste un solo divisore e stampo la stringa specifica per questo singolo caso.
        printf("Il divisore di %d e\': ",num);
    else // Se il numero è maggiore di uno, stampo la stringa generelizzata.
        printf("I divisori di %d sono: ",num);

	for (x=1; x <= num/2; x++) { // Faccio un ciclo da 1 a num/2 in quanto da num/2 a num l'unico divisore è num stesso
		if (num % x == 0) { // Controllo che il resto sia 0 e in caso positivo stampo il divisore
            printf("%d, ",x);
		}
	}
	printf("%d. ",num); // Stampo il numero stesso che è anche l'ultimo divisore di se stesso

	printf("\n\n");
	getchar(); // Uso la funzione getchar per evitare la chiusuara del programma

	return 0;

}
