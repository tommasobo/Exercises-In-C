/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
	
	char c;
	
	printf("Inserisci un carattere: ");
	scanf("%c", &c);
	printf("\n");
	
	if (isalpha(c)) {
		if (isupper(c)) {
			printf("Il carattere %c trasformato in minuscolo diventa %c\n",c,tolower(c));
			if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' )
				printf("Il carattere inserito e\' una lettera maiuscola ed e\' una vocale");
			else
				printf("Il carattere inserito e\' una lettera maiuscola  ed e\' una consonante");
		}
		else if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
			printf("Il carattere %c trasformato in maiuscolo diventa %c\n",c,toupper(c));
			printf("Il carattere inserito e\' una lettera minuscola  ed e\' una vocale");
		}
			else {
				printf("Il carattere %c trasformato in maiuscolo diventa %c\n",c,toupper(c));
				printf("Il carattere inserito e\' una lettera minuscola  ed e\' una consonante");
			}
	}
			
	else if (isdigit(c))
		printf("Il carattere inserito e' un numero");
	else 
		printf("Il carattere inserito non e\' ne\' un numero ne\' una lettera");
		
	printf("\nIl codice ASCII del carattere inserito e\': %d",c);
	
	system("pause");
	
	return 0;
	
}
