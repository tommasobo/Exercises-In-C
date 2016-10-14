/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Includo la libreria ctype che mi permette di fare dei controlli sui caratteri


int main() {

	char c;

	printf("Inserisci un carattere: ");
	scanf("%c", &c);
	printf("\n");

	if (isalpha(c)) { // Controllo se il carattere è una lettera
		if (isupper(c)) { // Controllo se la lettera è maiuscola
			printf("Il carattere \"%c\" trasformato in minuscolo diventa \"%c\"\n",c,tolower(c)); // Usp la funzione tolower per stampare la lettera corrispondente in minuscolo
			if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' ) // Controllo se si tratta di una vocale
				printf("Il carattere inserito e\' una lettera maiuscola ed e\' una vocale");
			else // Altrimenti stampo che è una consonante
				printf("Il carattere inserito e\' una lettera maiuscola  ed e\' una consonante");
		}
		else { // Se non è una lettera maiuscola
			printf("Il carattere \"%c\" trasformato in maiuscolo diventa \"%c\"\n",c,toupper(c)); // Uso la funzione toupper per stampare la lettera corrispondente in maiuscolo
			if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') // Controllo se la lettera minuscola è una vocale
				printf("Il carattere inserito e\' una lettera minuscola  ed e\' una vocale");
			else
				printf("Il carattere inserito e\' una lettera minuscola  ed e\' una consonante");
		}

	}

	else if (isdigit(c)) // Altrimenti controllo se è un numero
		printf("Il carattere inserito e' un numero");

	else  // Se non è nè un numero nè una vocale
		printf("Il carattere inserito non e\' ne\' un numero ne\' una lettera");

	printf("\nIl codice ASCII del carattere inserito e\': %d\n\n",c); // Visualizzo il codice ASCII del carattere stampondolo come un intero

	system("pause"); // Compatibile solo con Windows

	return 0;

}
