/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	float stipendio,tasse; // Dichiaro variabili di tipo reale perchè lo stipendio mensile quasi sicuramente sarà con la virgola

	printf("Inserire il proprio stipendio lordo: ");
	scanf("%f", &stipendio);

	while (stipendio < 0) { // Controllo che lo stipendio inserito sia positivo
		printf("Errore, devi inserire un numero positivo: ");
		scanf("%f", &stipendio);
	}

	if (stipendio <= 10000) // Se lo stipendio è minore di 10'000 €, non viene applicata una tassazione
		printf("\nIl tuo stipendio netto mensile e\' di %.2f euro\n", stipendio/12); // Definisco la precisione della spcifica di conversione (2 cifre dopo la virgola)

	if (stipendio > 10000 && stipendio <= 30000) { // Se lo stipendio è comperso tra 10'000 e 30'000 viene applicata una tassazione del 20% dopo i 10'000€.
		tasse = ((stipendio - 10000) * 0.2);
		stipendio = (stipendio - tasse) / 12;
		printf("\nIl tuo stipendio netto mensile e\' di %.2f euro\n", stipendio);
	}

	if (stipendio > 30000) { // Se lo stipendio è maggiore di 30'000 viene applicata una tassazione del 20% tra 10'000 e 30'000 e del 30% oltre
		tasse = ((stipendio - 30000) * (0.3)) + (20000 * 0.2);
		stipendio = (stipendio - tasse) / 12;
		printf("\nIl tuo stipendio netto mensile e\' di %.2f euro\n", stipendio);
	}

    system("pause"); // Compatibile solo con Windows

	return 0;

}
